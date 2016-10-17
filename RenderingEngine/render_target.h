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
				int width;
				int height;
			public:
				RenderTarget(int width, int height, TargetType t, std::string id);
				RenderTarget(RenderTarget* r);
				
				TargetType getTargetType() const;
				std::string getId() const;

				int getWidth() const;
				int getHeight() const;
			};
		}
	}
}