#pragma once
#include "stdinc.h"
#include "engine.h"
namespace engine {
	namespace core {
		namespace render {
			class IRenderer {
			public:
				virtual void init(EngineConfig& config) = 0;
				virtual void draw(CommandList& commands) = 0;
				virtual ~IRenderer() {};
			};
		}
	}
}