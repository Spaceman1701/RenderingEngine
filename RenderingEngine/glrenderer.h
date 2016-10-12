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
					const GLFWvidmode* vidMode;
					GLFWwindow* window;
					int num_monitors;

					void createWindow(int res_x, int res_y, bool fullscreen, int monitor);
				public:
					void init(EngineConfig& config);
					void draw(CommandList& renderCommands);
					~GLRenderer();
				};
			}
		}
	}
}