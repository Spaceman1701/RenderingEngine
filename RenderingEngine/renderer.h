#pragma once
#include "stdinc.h"
#include "engine.h"
#include "engine_config.h"
#include "render_pass.h"
namespace engine {
	namespace core {
		namespace render {
			class IRenderPass;

			class IRenderer {
			public:
				virtual void addRenderPass(IRenderPass* pass) = 0;
				virtual void draw(CommandList& commands) = 0;
				virtual ~IRenderer() {};
				virtual void renderGeometry() = 0;
			};
		}
	}
}