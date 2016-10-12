#pragma once
namespace engine {
	namespace core {
		namespace render {
			class IRenderer {
				virtual void init() = 0;
				virtual void draw() = 0;
			};
		}
	}
}