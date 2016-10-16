#pragma once
#include "texture.h"
#include <unordered_map>
using namespace engine::graphics;
namespace engine {
	namespace core {
		namespace render {
			namespace gl {
				class GLTextureFactory {
					typedef std::unordered_map<ITexture*, int> TextureMap;
				private:

				public:
					bool bindTexture(ITexture* tex);
				};
			}
		}
	}
}