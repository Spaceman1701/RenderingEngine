#pragma once
#include "stdinc.h"
#include "engine_config.h"
namespace engine {
	namespace core {
		namespace render {
			class IContext {
			public:
				virtual bool init(EngineConfig& config) = 0;
				virtual int getKey(int key) = 0;
				virtual void draw(CommandList& renderingCommands) = 0;
				virtual ~IContext() {}
			};
		}
	}
}