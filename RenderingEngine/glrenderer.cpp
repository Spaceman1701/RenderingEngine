#include "stdinc.h"
#include "glrenderer.h"

using namespace engine::core::render::gl;
using namespace engine::core;

void error_callback(int error, const char* desc) {
	LOG_ERROR << "ERROR: " << error << ", " << desc;
}

void GLRenderer::createWindow(int res_x, int res_y, bool fullscreen) {
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	vidMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	if (fullscreen) {
		window = glfwCreateWindow(res_x, res_y, "GLRENDERER", glfwGetPrimaryMonitor(), NULL);
	}
	else {
		window = glfwCreateWindow(res_x, res_y, "test", NULL, NULL);
	}

	if (!window) {
		LOG_ERROR << "window init failed!";
	}

	glfwMakeContextCurrent(window);
}
void GLRenderer::init(EngineConfig& config) {
	if (!glfwInit()) {
		LOG_ERROR << "glfw init failed!";
	}
	glfwSetErrorCallback(error_callback);
	createWindow(config.getResolutionWidth(), config.getResolutionHeight(), config.getFullscreen());
	if (glewInit() != GLEW_OK) {
		LOG_ERROR << "glew init failed!";
	}

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