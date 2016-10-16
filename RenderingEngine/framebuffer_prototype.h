#pragma once
#include <vector>
#include "render_target.h"
#include "depth_target.h"
namespace engine {
	namespace core {
		namespace render {
			typedef std::vector<RenderTarget> BufferList;
			class FrameBufferPrototype {
			private:
				unsigned int width;
				unsigned int height;
				BufferList colorBuffers;
				DepthTarget depthTarget;
			public:
				FrameBufferPrototype(int width, int height);
				bool addColorBuff(RenderTarget rt);
				bool setDepthTarget(DepthTarget dt);

				int getWidth();
				int getHeight();

				BufferList& getBufferList();
				DepthTarget& getDepthTarget();
			};
		}
	}
}