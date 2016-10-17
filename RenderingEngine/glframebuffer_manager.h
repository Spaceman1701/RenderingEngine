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
					typedef std::unordered_map<IRenderPass*, int> BufferMap;
					typedef std::unordered_map<std::string, int> TextureMap;
				private:
					BufferMap bufferMap;
					TextureMap textureMap;
					int getAttachment(int value);
				public:
					void createFrameBuffer(IRenderPass* pass, FrameBufferPrototype& fbp, GLTargetSelector& targetSelector);
					int getFrameBuffer(IRenderPass* pass);
					int getFBTexture(std::string& id);
				};
			}
		}
	}
}