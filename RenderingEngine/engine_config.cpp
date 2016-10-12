#include "engine_config.h"

using namespace engine::core;

EngineConfig::EngineConfig(bool fullscreen, int resolution_width, int resolution_height, bool vsync, int num_vblank) {
	this->resolution_width = resolution_width;
	this->resultion_height = resolution_height;
	this->window_fullscreen = fullscreen;
	this->vsync = vsync;
	this->num_vblank = num_vblank;
}

EngineConfig::EngineConfig(EngineConfig& other) {
	resolution_width = other.resolution_width;
	resultion_height = other.resultion_height;
	window_fullscreen = other.window_fullscreen;
	vsync = other.vsync;
	num_vblank = other.num_vblank;
}

int EngineConfig::getResolutionWidth() {
	return resolution_width;
}
int EngineConfig::getResolutionHeight() {
	return resultion_height;
}
bool EngineConfig::getFullscreen() {
	return window_fullscreen;
}

bool EngineConfig::getVsync() {
	return vsync;
}
int EngineConfig::getNumVBlank() {
	return num_vblank;
}

void EngineConfig::setResolutionWidth(int width) {
	this->resolution_width = width;
}

void EngineConfig::setResolutionHeight(int height) {
	this->resultion_height = height;
}

void EngineConfig::setFullscreen(bool fullscreen) {
	this->window_fullscreen = fullscreen;
}

void EngineConfig::setVsync(bool vsync) {
	this->vsync = vsync;
}

void EngineConfig::setNumVBlank(int num_vblank) {
	this->num_vblank = num_vblank;
}