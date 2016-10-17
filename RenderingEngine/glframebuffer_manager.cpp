#include "glframebuffer_manager.h"
#include "render_pass.h"
#include "framebuffer_prototype.h"
#include <glew.h>
//#include <glfw3.h>
#include <vector>
using namespace engine::core::render::gl;
using namespace engine::core::render;

int GLFrameBufferManager::getAttachment(int value) {
	GLint max;
	glGetIntegerv(GL_MAX_COLOR_ATTACHMENTS, &max);
	if (value >= max) {
		return -1;
	}
	return 0x8CE0 + value;
}
void GLFrameBufferManager::createFrameBuffer(AbstractRenderPass* pass, FrameBufferPrototype& fbp, GLTargetSelector& targetSelector) { //GPU MEMORY LEAK HERE.. lol
	std::vector<int> textures;
	std::vector<RenderTarget> renderTargetList = fbp.getBufferList();
	GLuint currentTex;
	for (RenderTarget target : renderTargetList) {
		glGenTextures(1, &currentTex);
		glBindTexture(GL_TEXTURE_2D, currentTex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		
		glTexImage2D(GL_TEXTURE_2D, 0, targetSelector.getRenderTargetType(target.getTargetType()), 
			target.getWidth(), target.getHeight(), 0, GL_BGRA, GL_UNSIGNED_BYTE, NULL);

		textures.push_back(currentTex);
		textureMap[target.getId()] = currentTex;
	}
	

	GLuint buffer;
	glGenFramebuffers(1, &buffer);
	glBindFramebuffer(GL_FRAMEBUFFER, buffer);

	for (int i = 0; i < textures.size(); i++) {
		glFramebufferTexture2D(GL_FRAMEBUFFER, getAttachment(i), GL_TEXTURE_2D, textures[i], 0);
	}
	DepthTarget dt = fbp.getDepthTarget();
	if (dt.getType() != NONE) {

		glBindTexture(GL_TEXTURE_2D, 0);
		GLuint depthTex;
		glGenTextures(GL_TEXTURE_2D, &depthTex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, targetSelector.getDepthTargetType(dt.getType()),
			dt.getWidth(), dt.getHeight(), 0, GL_BGRA, GL_UNSIGNED_BYTE, NULL);
		glBindTexture(GL_TEXTURE_2D, 0);

		if (dt.getType() == DEPTH16 || dt.getType() == DEPTH24 || dt.getType() == DEPTH32F) {
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthTex, 0);
		}
		else {
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_TEXTURE_2D, depthTex, 0);
		}
		textureMap[dt.getId()] = depthTex;
	}
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	bufferMap[pass] = buffer;
}

int GLFrameBufferManager::getFrameBuffer(AbstractRenderPass* pass) {
	return bufferMap[pass];
}
int GLFrameBufferManager::getFBTexture(std::string& id) {
	return textureMap[id];
}