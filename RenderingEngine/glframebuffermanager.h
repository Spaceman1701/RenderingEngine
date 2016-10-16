#pragma once
#include "render_pass.h"
#include <unordered_map>
namespace engine {
	namespace core {
		namespace render {
			namespace gl {
				class GLFrameBufferManager {
					typedef std::unordered_map<AbstractRenderPass*, int> bufferMap;
				public:
					void createFrameBuffer(AbstractRenderPass* pass, FrameBufferPrototype& fbp);
					void bindFrameBuffer();
				};
			}
		}
	}
}