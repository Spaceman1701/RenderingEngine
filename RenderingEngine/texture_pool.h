#pragma once
#include <unordered_map>
#include "texture.h"
#include <inttypes.h>
namespace engine {
	namespace graphics {
		class TexturePool {
		private:
			std::unordered_map<uint16_t, ITexture*> data;
		};
	}
}