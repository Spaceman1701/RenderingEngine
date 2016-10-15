#pragma once
#include "stdinc.h"
#include "renderer.h"
#include <string>
namespace engine {
	namespace core {
		namespace render {
			class AbstractRenderPass {
			protected:
				std::string name;
			public:
				virtual void registerOutputs()
				virtual void doPass(IRenderer* renderer) = 0;
				virtual ~AbstractRenderPass() {}
			};
		}
	}
}