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
		fbm.createFrameBuffer(pass, pass->registerOutputFrameBuffer());
	}
}

void GLRenderer::draw(CommandList& renderCommands) {
	glfwSwapBuffers(window);
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