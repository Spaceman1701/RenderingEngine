#pragma once
#include "scene.h"
#include "engine_config.h"
#include "renderer.h"
namespace engine {
	namespace core {
		using namespace render;
		class Engine {
		private:
			EngineConfig config;
			IRenderer* renderer;

			void run(engine::scene::Scene* scene);
		public:
			Engine(bool fullscreen, int resolution_x, int resolution_y, bool vsync, int num_vblanks);
			bool start(engine::scene::Scene* scene);
			EngineConfig getConfig();
			void setConfig(EngineConfig config);
		};
	}
}