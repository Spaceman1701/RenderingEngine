#include "glcontext.h"
#include "engine_config.h"
using namespace engine::core::render::gl;
using namespace engine::core;

void error_callback(int error, const char* desc) {
	LOG_ERROR << "ERROR: " << error << ", " << desc;
}

bool GLContext::init(EngineConfig& config) {
	if (!glfwInit()) {
		LOG_ERROR << "glfw init failed!";
		glfwTerminate();
		return false;
	}
	glfwSetErrorCallback(error_callback);
	

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	vidMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	if (config.getFullscreen()) {
		window = glfwCreateWindow(config.getResolutionWidth(), config.getResolutionHeight(), "GLRENDERER",
			glfwGetMonitors(&num_monitors)[0], NULL);
	}
	else {
		window = glfwCreateWindow(config.getResolutionWidth(), config.getResolutionHeight(), "test", NULL, NULL);
	}

	if (!window) {
		LOG_ERROR << "window init failed!";
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		LOG_ERROR << "glew init failed!";
		glfwTerminate();
		return false;
	}

	renderer = new GLRenderer();
	renderer->init(config, window);
	return true;
}

int GLContext::getKey(int key) {
	return glfwGetKey(window, key);
}

void GLContext::draw(CommandList& renderingCommands) {
	renderer->draw(renderingCommands);
}

GLContext::~GLContext() {
	delete renderer;
	glfwDestroyWindow(window);
	glfwTerminate();
}