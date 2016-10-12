#pragma once
#include "scene.h"
#include "engine_config.h"
namespace engine {
	namespace render {
		class Engine {
		private:
			EngineConfig config;

			void run();
		public:
			Engine(bool fullscreen, int resolution_x, int resolution_y, bool vsync, int num_vblanks);
			bool start(engine::scene::Scene* scene);
			EngineConfig getConfig();
			void setConfig();
		};
	}
}