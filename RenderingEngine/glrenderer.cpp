#include "stdinc.h"
#include "glrenderer.h"
#include "framebuffer_prototype.h"
#include <glew.h>
#include <glfw3.h>


using namespace engine::core::render::gl;
using namespace engine::core;

void GLRenderer::init(EngineConfig& config, GLFWwindow* window) {
	inited = true;
	this->window = window;
	glViewport(0, 0, config.getResolutionWidth(), config.getResolutionHeight());
	glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
	cubeDrawPass = new CubeDrawPass();
	renderPasses.push_back(cubeDrawPass);
	if (config.getVsync()) {
		glfwSwapInterval(config.getNumVBlank());
	}
	for (IRenderPass* pass: renderPasses) {
		fbm.createFrameBuffer(pass, pass->registerOutputFrameBuffer(), renderTargetSelector);
	}

}

void GLRenderer::draw(CommandList& renderCommands) {
	currentGeometry = &renderCommands;
	for (IRenderPass* pass : renderPasses) {
		//glBindFramebuffer(GL_FRAMEBUFFER, fbm.getFrameBuffer(pass));
		pass->doPass(this);
	}
	glfwSwapBuffers(window);
	glClear(GL_COLOR_BUFFER_BIT);
}

int GLRenderer::getRenderTexture(std::string& id) {
	return fbm.getFBTexture(id);
}

GLRenderer::~GLRenderer() {
	glfwDestroyWindow(window);
	glfwTerminate();
}

void GLRenderer::addRenderPass(IRenderPass* pass) {
	if (!inited) {
		renderPasses.push_back(pass);
	}
}

void GLRenderer::renderGeometry() {
	for (RenderingCommand rc : *currentGeometry) {

	}
}