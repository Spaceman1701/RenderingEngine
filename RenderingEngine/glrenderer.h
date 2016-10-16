#pragma once
#include "renderer.h"
#include <glew.h>
#include <glfw3.h>
#include "gltarget_selector.h"
#include "render_pass.h";
#include <vector>
namespace engine {
	namespace core {
		namespace render {
			namespace gl {
				class GLRenderer : public IRenderer {
					typedef std::vector<AbstractRenderPass*> RenderPassList;
				private:
					GLFWwindow* window;
					GLTargetSelector selector;
					RenderPassList renderPasses;
					bool inited = false;
				public:
					void addRenderPass(AbstractRenderPass* pass);
					void init(EngineConfig& config, GLFWwindow* window);
					void draw(CommandList& renderCommands);
					~GLRenderer();
				};
			}
		}
	}
}