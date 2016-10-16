#pragma once
namespace engine {
	namespace core {
		namespace render {
			enum TargetType { //Some of these may not work, but they pppprrrroobbbbaallly will
				RGBA2, RGB4, RGBA4, RGB5, R8, RG8, RGB8, RGBA8, RGB10, RGB12, RGBA12, R16, RG16, RGB16, RGBA16, //unsigned normalized int
				R8_SNORM, RG8_SNORM, RGB8_SNORM, RGBA8_SNORM, R16_SNORM, RG16_SNORM, RGB16_SNORM, RGBA16_SNORM, //signed normalized
				R8UI, RG8UI, RGB8UI, RGBA8UI, R16UI, RG16UI, RGB16UI, RGBA16UI, R32UI, RG32UI, RGB32UI, RGBA32UI, //unsigned integral
				R8I, RG8I, RGB8I, RGBA8I, R16I, RG16I, RGB16I, RGBA16I, R32I, RG32I, RGB32I, RGBA32I, //signed integral
				R16F, RG16F, RGB16F, RGBA16F, R32F, RG32F, RGB32F, RGBA32F //floating point
			};
			enum DepthTargetType {
				DEPTH16, DEPTH24, DEPTH32F, DEPTH24_STENCIL8, DEPTH32F_STENCIL8, NONE
			};
		}
	}
}