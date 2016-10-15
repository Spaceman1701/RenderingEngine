#include "render_target.h"

using namespace engine::core::render;

RenderTarget::RenderTarget(TargetType t, std::string id) {
	this->type = t;
	this->id = id;
}

RenderTarget::RenderTarget(RenderTarget& r) {
	this->type = r.type;
	this->id = r.id;
}

TargetType RenderTarget::getTargetType() {
	return type;
}
std::string RenderTarget::getId() {
	return id;
}