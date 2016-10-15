#pragma once
#include "render_target_types.h"
#include <string>

namespace engine {
	namespace core {
		namespace render {
			class DepthTarget {
			private:
				DepthTargetType type;
				std::string id;
			public:
				DepthTarget(DepthTargetType type, std::string id);
				DepthTarget(DepthTarget& dt);

				DepthTargetType getType();
				std::string getId();
			};
		}
	}
}