#pragma once
#include "render_pass.h"
#include <unordered_map>
#include "gltarget_selector.h"
#include <string>	
namespace engine {
	namespace core {
		namespace render {
			namespace gl {
				class GLFrameBufferManager {
					typedef std::unordered_map<AbstractRenderPass*, int> BufferMap;
					typedef std::unordered_map<std::string, int> TextureMap;
				private:
					BufferMap bufferMap;
					TextureMap textureMap;
					int getAttachment(int value);
				public:
					void createFrameBuffer(AbstractRenderPass* pass, FrameBufferPrototype& fbp, GLTargetSelector& targetSelector);
					int getFrameBuffer(AbstractRenderPass* pass);
					int getFBTexture(std::string& id);
				};
			}
		}
	}
}