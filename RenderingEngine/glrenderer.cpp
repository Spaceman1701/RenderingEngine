#include "glrenderer.h"
#include <iostream>

using namespace engine::core::render::gl;
using namespace engine::core;

void error_callback(int error, const char* desc) {
	std::cout << "ERROR: " << error << ", " << desc << std::endl;
}

void GLRenderer::createWindow(int res_x, int res_y, bool fullscreen) {
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	vidMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	if (fullscreen) {
		window = glfwCreateWindow(res_x, res_y, "GLRENDERER", glfwGetPrimaryMonitor(), NULL);
	}
	else {
		std::cout << "Attempt window creation!" << std::endl;
		window = glfwCreateWindow(res_x, res_y, "test", NULL, NULL);
	}

	if (!window) {
		//something is wrong
		std::cout << "window init failed!" << std::endl;
	}

	glfwMakeContextCurrent(window);
}
void GLRenderer::init(EngineConfig& config) {
	if (!glfwInit()) {
		std::cout << "glfw init failed!" << std::endl;
	}
	glfwSetErrorCallback(error_callback);
	createWindow(config.getResolutionWidth(), config.getResolutionHeight(), config.getFullscreen());
	if (glewInit() != GLEW_OK) {
		std::cout << "glew init failed!" << std::endl;
		//something is wrong
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