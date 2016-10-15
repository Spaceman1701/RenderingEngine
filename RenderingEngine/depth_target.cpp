#include "depth_target.h"

using namespace engine::core::render;

DepthTarget::DepthTarget(DepthTargetType type, std::string id) {
	this->type = type;
	this->id = id;
}

DepthTarget::DepthTarget(DepthTarget& dt) {
	this->type = dt.type;
	this->id = id;
}

DepthTargetType DepthTarget::getType() {
	return type;
}
std::string DepthTarget::getId() {
	return id;
}