#pragma once
#include "stdinc.h"
#include "engine.h"
#include "engine_config.h"
namespace engine {
	namespace core {
		namespace render {
			class IRenderer {
			public:
				virtual void draw(CommandList& commands) = 0;
				virtual ~IRenderer() {};
			};
		}
	}
}