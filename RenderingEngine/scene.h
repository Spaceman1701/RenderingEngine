#pragma once
namespace engine {
	namespace scene {
		class Scene {
			virtual ~Scene();
			virtual void update(float deltaT) = 0;
			virtual void draw() = 0;
		};
	}
}