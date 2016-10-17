#include "glprogram.h"
using namespace engine::graphics::gl;

GLProgram::GLProgram(std::string vertexSrc, std::string pixelSrc) {
	GLuint vertexShaderHandle = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
	char const* vertexShaderPointer = vertexSrc.c_str();
	glShaderSource(vertexShaderHandle, 1, &vertexShaderPointer, NULL);
	glCompileShader(vertexShaderHandle);

	char const* fragmentShaderPointer = pixelSrc.c_str();
	glShaderSource(fragmentShaderHandle, 1, &fragmentShaderPointer, NULL);
	glCompileShader(fragmentShaderHandle);

	handle = glCreateProgram();
	glAttachShader(handle, vertexShaderHandle);
	glAttachShader(handle, fragmentShaderHandle);
	glLinkProgram(handle);

}
void GLProgram::bind() {
	glUseProgram(handle);
}
void GLProgram::unbind() {
	glUseProgram(0);
}

GLProgram::~GLProgram() {
	glDeleteProgram(handle);
}