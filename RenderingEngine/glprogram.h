#pragma once
#include <glew.h>
#include <string>
namespace engine {
	namespace graphics {
		namespace gl {
			class GLProgram {
			private:
				GLuint handle;
			public:
				GLProgram(std::string vertexSrc, std::string pixelSrc);
				~GLProgram();
				void bind();
				void unbind();
			};
		}
	}
}