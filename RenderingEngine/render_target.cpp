#include "render_target.h"

using namespace engine::core::render;

RenderTarget::RenderTarget(int width, int height, TargetType t, std::string id) {
	this->type = t;
	this->id = id;
	this->width = width;
	this->height = height;
}

RenderTarget::RenderTarget(RenderTarget* r) {
	this->type = r->type;
	this->id = r->id;
}

TargetType RenderTarget::getTargetType() const{
	return type;
}
std::string RenderTarget::getId() const{
	return id;
}

int RenderTarget::getWidth() const {
	return width;
}

int RenderTarget::getHeight() const {
	return height;
}