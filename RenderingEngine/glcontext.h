#pragma once
#include "context.h"
#include <glew.h>
#include <glfw3.h>
#include "glrenderer.h"
namespace engine {
	namespace core {
		namespace render {
			namespace gl {
				class GLContext : public IContext {
				private:
					const GLFWvidmode* vidMode;
					GLFWwindow* window;
					int num_monitors;
					GLRenderer* renderer;
					
				public:
					bool init(EngineConfig& config);
					int getKey(int key);
					void draw(CommandList& renderingCommands);
					~GLContext();
				};
			}
		}
	}
}