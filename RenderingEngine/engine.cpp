#include "engine.h"
using namespace engine::core;

Engine::Engine(bool fullscreen, int resolution_x, int resolution_y, bool vsync, int num_vblanks) : 
	config(fullscreen, resolution_x, resolution_y, vsync, num_vblanks){

}

void Engine::run(engine::scene::Scene* scene) {

}

bool Engine::start(engine::scene::Scene* scene) {
	return true;
}
EngineConfig Engine::getConfig() {
	return config;
}
void Engine::setConfig(EngineConfig config) {
	this->config = config;
}