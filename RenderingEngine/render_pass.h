#pragma once
#include "stdinc.h"
#include "renderer.h"
#include "framebuffer_prototype.h"
#include <string>
namespace engine {
	namespace core {
		namespace render {
			class AbstractRenderPass {
			protected:
				std::string name;
			public:
				virtual void registerOutputs(FrameBufferPrototype& fbo) = 0;
				virtual void doPass(IRenderer* renderer) = 0;
				virtual ~AbstractRenderPass() {}
			};
		}
	}
}