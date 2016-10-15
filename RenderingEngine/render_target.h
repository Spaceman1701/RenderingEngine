#pragma once
#include "render_target_types.h"
#include <string>
namespace engine {
	namespace core {
		namespace render {
			class RenderTarget {
			private:
				TargetType type;
				std::string id;
			public:
				RenderTarget(TargetType t, std::string id);
				RenderTarget(RenderTarget& r);
				
				TargetType getTargetType();
				std::string getId();
			};
		}
	}
}