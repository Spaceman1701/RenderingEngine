#include "gltarget_selector.h"
#include "render_target_types.h"
#include <glew.h>

using namespace engine::core::render::gl;
using namespace engine::core::render;

int GLTargetSelector::getRenderTargetType(TargetType type) {
	return targetMap[type];
}

int GLTargetSelector::getDepthTargetType(DepthTargetType type) {
	return depthMap[type];
}

GLTargetSelector::GLTargetSelector() {
	add(RGBA2, GL_RGBA2);
	add(RGB4, GL_RGB4);
	add(RGBA4, GL_RGBA4);
	add(RGB5, GL_RGB5);
	add(R8, GL_R8);
	add(RG8, GL_RG8);
	add(RGB8, GL_RGB8);
	add(RGBA8, GL_RGBA8);
	add(RGB10, GL_RGB10);
	add(RGB12, GL_RGB12);
	add(R16, GL_R16);
	add(RG16, GL_RG16);
	add(RGB16, GL_RGB16);
	add(RGBA16, GL_RGBA16); //unsigned normalized int

	add(R8_SNORM, GL_R8_SNORM);
	add(RG8_SNORM, GL_RG8_SNORM);
	add(RGB8_SNORM, GL_RGB8_SNORM);
	add(RGBA8_SNORM, GL_RGBA8_SNORM);
	add(R16_SNORM, GL_R16_SNORM);
	add(RG16_SNORM, GL_RG16_SNORM);
	add(RGB16_SNORM, GL_RGB16_SNORM);
	add(RGBA16_SNORM, GL_RGBA16_SNORM); //signed normalized

	add(R8UI, GL_R8UI);
	add(RG8UI, GL_RG8UI);
	add(RGB8UI, GL_RGB8UI);
	add(RGBA8UI, GL_RGBA8UI);
	add(R16UI, GL_R16UI);
	add(RG16UI, GL_RG16UI);
	add(RGB16UI, GL_RGB16UI);
	add(RGBA16UI, GL_RGBA16UI);
	add(R32UI, GL_R32UI);
	add(RG32UI, GL_RG32UI);
	add(RGB32UI, GL_RGB32UI);
	add(RGBA32UI, GL_RGBA32UI); //unsigned integral

	add(R8I, GL_R8I);
	add(RG8I, GL_RG8I);
	add(RGB8I, GL_RGB8I);
	add(RGBA8I, GL_RGBA8I);
	add(R16I, GL_R16I);
	add(RG16I, GL_RG16I);
	add(RGB16I, GL_RGB16I);
	add(RGBA16I, GL_RGBA16I);
	add(R32I, GL_R32I);
	add(RG32I, GL_RG32I);
	add(RGB32I, GL_RGB32I);
	add(RGBA32I, GL_RGBA32I); //signed integral

	add(R16F, GL_R16F);
	add(RG16F, GL_RG16F);
	add(RGB16F, GL_RGB16F);
	add(RGBA16F, GL_RGBA16F);
	add(R32F, GL_R32F);
	add(RG32F, GL_RG32F);
	add(RGB32F, GL_RGB32F);
	add(RGBA32F, GL_RGBA32F); //floating point

	add(DEPTH16, GL_DEPTH_COMPONENT16);
	add(DEPTH24, GL_DEPTH_COMPONENT24);
	add(DEPTH32F, GL_DEPTH_COMPONENT32F);
	add(DEPTH24_STENCIL8, GL_DEPTH24_STENCIL8);
	add(DEPTH32F_STENCIL8, GL_DEPTH32F_STENCIL8); //depth

}

void GLTargetSelector::add(TargetType rt, int type) {
	targetMap[rt] = type;
}

void GLTargetSelector::add(DepthTargetType dt, int type) {
	depthMap[dt] = type;
}