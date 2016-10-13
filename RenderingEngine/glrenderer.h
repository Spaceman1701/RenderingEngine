#pragma once
#include "renderer.h"
#include <glew.h>
#include <glfw3.h>
namespace engine {
	namespace core {
		namespace render {
			namespace gl {
				class GLRenderer : public IRenderer {
				private:
					GLFWwindow* window;
				public:
					void init(EngineConfig& config, GLFWwindow* window);
					void draw(CommandList& renderCommands);
					~GLRenderer();
				};
			}
		}
	}
}