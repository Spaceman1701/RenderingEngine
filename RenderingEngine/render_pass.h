#pragma once
#include "stdinc.h"
#include "renderer.h"
#include "framebuffer_prototype.h"
#include <string>
namespace engine {
	namespace core {
		namespace render {
			class IRenderer;
			class IRenderPass {
			protected:
				std::string name;
			public:
				virtual FrameBufferPrototype registerOutputFrameBuffer() = 0;
				virtual void doPass(IRenderer* renderer) = 0;
				virtual ~IRenderPass() {}
			};
		}
	}
}