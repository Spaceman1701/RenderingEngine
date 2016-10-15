#pragma once
#include "render_target.h"
#include "depth_target.h"
namespace engine {
	namespace core {
		namespace render {
			class IRenderTargetManager {
				virtual ~IRenderTargetManager() {}
				virtual void registerRenderTarget(RenderTarget rt) = 0;
				virtual void registerDepthTarget(DepthTarget dt) = 0;
			};
		}
	}
}