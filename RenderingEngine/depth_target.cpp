#include "depth_target.h"

using namespace engine::core::render;

DepthTarget::DepthTarget(int width, int height, DepthTargetType type, std::string id) {
	this->type = type;
	this->id = id;
	this->width = width;
	this->height = height;
}

DepthTarget::DepthTarget(DepthTarget& dt) {
	this->type = dt.type;
	this->id = id;
}

DepthTarget::DepthTarget() {
	this->type == NONE;
}

DepthTargetType DepthTarget::getType() {
	return type;
}
std::string DepthTarget::getId() {
	return id;
}

int DepthTarget::getWidth() {
	return width;
}

int DepthTarget::getHeight() {
	return height;
}