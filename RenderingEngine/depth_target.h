#pragma once
#include "stdinc.h"
#include "render_target_types.h"
#include <string>

namespace engine {
	namespace core {
		namespace render {
			class DepthTarget {
			private:
				DepthTargetType type;
				std::string id;
				int width;
				int height;
			public:
				DepthTarget(int width, int height, DepthTargetType type, std::string id);
				DepthTarget(DepthTarget& dt);
				DepthTarget(); //empty target

				DepthTargetType getType();
				std::string getId();

				int getWidth();
				int getHeight();
			};
		}
	}
}