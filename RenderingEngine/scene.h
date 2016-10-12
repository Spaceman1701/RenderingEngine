#pragma once
#include "engine.h"
namespace engine {
	namespace core {
		class Engine;
	}
	namespace scene {
		class Scene {
		protected:
			core::Engine* engine;
		public:
			virtual ~Scene();
			virtual void update(float deltaT) = 0;
			virtual void draw() = 0;
		};
	}
}