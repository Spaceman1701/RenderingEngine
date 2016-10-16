#pragma once
#include "render_target.h"
#include "depth_target.h"
#include "framebuffer_prototype.h"
namespace engine {
	namespace core {
		namespace render {
			class IRenderTargetManager {
				virtual ~IRenderTargetManager() {}
				virtual bool registerOutputBuffer(FrameBufferPrototype& fbp) = 0;
			};
		}
	}
}