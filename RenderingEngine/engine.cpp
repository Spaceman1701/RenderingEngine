#include "engine.h"
#include "glrenderer.h"
using namespace engine::core;
using namespace engine::core::render;

Engine::Engine(bool fullscreen, int resolution_x, int resolution_y, bool vsync, int num_vblanks) : 
	config(fullscreen, resolution_x, resolution_y, vsync, num_vblanks){
	this->shouldQuit = false;
	renderer = new gl::GLRenderer();
}

void Engine::quit() {
	this->shouldQuit = true;
}

void Engine::run(engine::scene::Scene* scene) {
	renderer->init(config);
	CommandList renderCommands;
	while (!shouldQuit) {
		//scene->update(0.0f); //DeltaT no
		//scene->draw(renderCommands);

		renderer->draw(renderCommands); //multithread later
		renderCommands.clear();
	}
	
	delete renderer; //probably do cleanup 
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