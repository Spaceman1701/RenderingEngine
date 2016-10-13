#include "stdinc.h"
#include "glrenderer.h"

using namespace engine::core::render::gl;
using namespace engine::core;


void GLRenderer::init(EngineConfig& config, GLFWwindow* window) {

	if (config.getVsync()) {
		glfwSwapInterval(config.getNumVBlank());
	}
}

void GLRenderer::draw(CommandList& renderCommands) {
	glfwSwapBuffers(window);
}

GLRenderer::~GLRenderer() {
	glfwDestroyWindow(window);
	glfwTerminate();
}