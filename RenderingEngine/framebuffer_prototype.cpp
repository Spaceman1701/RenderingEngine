#include "framebuffer_prototype.h"

using namespace engine::core::render;

FrameBufferPrototype::FrameBufferPrototype(int width, int height) {
	this->width = width;
	this->height = height;
}
bool FrameBufferPrototype::addColorBuff(RenderTarget rt) {
	if (rt.getHeight() != height || rt.getWidth() != width) {
		return false;
	}
	colorBuffers.push_back(rt);
	return true;
}
bool FrameBufferPrototype::setDepthTarget(DepthTarget dt) {
	if (dt.getWidth() != width || dt.getHeight() != height) {
		return false;
	}
	depthTarget = dt;
	return true;
}

int FrameBufferPrototype::getWidth() {
	return width;
}
int FrameBufferPrototype::getHeight() {
	return height;
}

BufferList& FrameBufferPrototype::getBufferList() {
	return colorBuffers;
}
DepthTarget& FrameBufferPrototype::getDepthTarget() {
	return depthTarget;
}