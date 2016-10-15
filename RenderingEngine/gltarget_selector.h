#pragma once
#include <unordered_map>
#include "render_target_types.h"
#include "depth_target.h"
namespace engine {
	namespace core {
		namespace render {
			namespace gl {
				class GLTargetSelector {
					typedef std::unordered_map<TargetType, int> TargetMap;
					typedef std::unordered_map<DepthTargetType, int> DepthMap;
				private:
					TargetMap targetMap;
					DepthMap depthMap;
					void add(TargetType rt, int type);
					void add(DepthTargetType dt, int type);
				public:
					GLTargetSelector();
					int getRenderTargetType(TargetType type);
					int getDepthTargetType(DepthTargetType type);
				};
			}
		}
	}
}