#include "stdinc.h"
#include "glrenderer.h"
#include "framebuffer_prototype.h"

using namespace engine::core::render::gl;
using namespace engine::core;

void GLRenderer::init(EngineConfig& config, GLFWwindow* window) {
	inited = true;
	if (config.getVsync()) {
		glfwSwapInterval(config.getNumVBlank());
	}
	for (AbstractRenderPass* pass: renderPasses) {
		fbm.createFrameBuffer(pass, pass->registerOutputFrameBuffer(), renderTargetSelector);
	}
}

void GLRenderer::draw(CommandList& renderCommands) {
	currentGeometry = &renderCommands;
	for (AbstractRenderPass* pass : renderPasses) {
		//glBindFramebuffer(GL_FRAMEBUFFER, fbm.getFrameBuffer(pass));
		pass->doPass(this);
	}
	glfwSwapBuffers(window);

}

int GLRenderer::getRenderTexture(std::string& id) {
	return fbm.getFBTexture(id);
}

GLRenderer::~GLRenderer() {
	glfwDestroyWindow(window);
	glfwTerminate();
}

void GLRenderer::addRenderPass(AbstractRenderPass* pass) {
	if (!inited) {
		renderPasses.push_back(pass);
	}
}

void GLRenderer::renderGeometry() {
	for (RenderingCommand rc : *currentGeometry) {

	}
}