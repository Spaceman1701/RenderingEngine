#pragma once
#include "renderer.h"
#include <glew.h>
#include <glfw3.h>
#include "gltarget_selector.h"
#include "render_pass.h"
#include "glframebuffer_manager.h"
#include <vector>
#include <string>
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
					GLFrameBufferManager fbm;
					GLTargetSelector renderTargetSelector;
					CommandList* currentGeometry;
					bool inited = false;
				public:
					void addRenderPass(AbstractRenderPass* pass);
					void init(EngineConfig& config, GLFWwindow* window);
					void draw(CommandList& renderCommands);
					int getRenderTexture(std::string& id);
					void renderGeometry();
					~GLRenderer();
				};
			}
		}
	}
}