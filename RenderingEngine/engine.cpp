#include "stdinc.h"
#include "engine.h"
#include "glcontext.h"
#include "input.h"

using namespace engine::core;
using namespace engine::core::render;

Engine::Engine(bool fullscreen, int resolution_x, int resolution_y, bool vsync, int num_vblanks) : 
	config(fullscreen, resolution_x, resolution_y, vsync, num_vblanks){
	plog::init(plog::verbose, "logs/log.elog");
	LOG_DEBUG << "engine init started";

	this->shouldQuit = false;
	context = new gl::GLContext();
}

void Engine::quit() {
	this->shouldQuit = true;
}

void Engine::run(engine::scene::Scene* scene) {
	context->init(config);
	CommandList renderCommands;
	while (!shouldQuit) {
		//scene->update(0.0f); //DeltaT no
		//scene->draw(renderCommands);

		context->draw(renderCommands); //multithread later
		renderCommands.clear();

		if (context->getKey(KEY_ESCAPE) == BUTTON_PRESS) {
			quit();
		}
	}
	delete context;
}

bool Engine::start(engine::scene::Scene* scene) {
	run(scene);
	return true;
}
EngineConfig Engine::getConfig() {
	return config;
}
void Engine::setConfig(EngineConfig config) {
	this->config = config;
}