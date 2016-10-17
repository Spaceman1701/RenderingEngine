#pragma once
#include "cubedrawpass.h"
#include "math_util.h"
#include <string>
#include <stdio.h>
using namespace engine::core::render;

void CubeDrawPass::createShaderProgram()
{
	std::string vertexSrc =
		"#version 330 core \n"
		"layout(location = 0) in vec3 vert;"
		"uniform mat4 pMat;"
		"void main() {"
		"vec3 vertMov = vec3(vert.x, vert.y, vert.z - 7.0);"
		"gl_Position = pMat*vec4(vertMov, 1.0);"
		"}";
	std::string pixelSrc =
		"#version 330 core \n"
		"out vec3 color;"
		"void main() {"
		"color = vec3(1, 1, 1);"
		"}";
	GLint result = GL_FALSE;
	int infoLogLength;

	GLuint vertexShaderHandle = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
	char const* vertexShaderPointer = vertexSrc.c_str();
	glShaderSource(vertexShaderHandle, 1, &vertexShaderPointer, NULL);
	glCompileShader(vertexShaderHandle);

	glGetShaderiv(vertexShaderHandle, GL_COMPILE_STATUS, &result);
	glGetShaderiv(vertexShaderHandle, GL_INFO_LOG_LENGTH, &infoLogLength);
	if (infoLogLength > 0) {
		std::vector<char> VertexShaderErrorMessage(infoLogLength + 1);
		glGetShaderInfoLog(vertexShaderHandle, infoLogLength, NULL, &VertexShaderErrorMessage[0]);
		printf("%s\n", &VertexShaderErrorMessage[0]);
	}

	printf("vertex shader success! \n");
	char const* fragmentShaderPointer = pixelSrc.c_str();
	glShaderSource(fragmentShaderHandle, 1, &fragmentShaderPointer, NULL);
	glCompileShader(fragmentShaderHandle);

	glGetShaderiv(fragmentShaderHandle, GL_COMPILE_STATUS, &result);
	glGetShaderiv(fragmentShaderHandle, GL_INFO_LOG_LENGTH, &infoLogLength);
	if (infoLogLength > 0) {
		std::vector<char> FragmentShaderErrorMessage(infoLogLength + 1);
		glGetShaderInfoLog(fragmentShaderHandle, infoLogLength, NULL, &FragmentShaderErrorMessage[0]);
		printf("%s\n", &FragmentShaderErrorMessage[0]);
	}

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShaderHandle);
	glAttachShader(shaderProgram, fragmentShaderHandle);
	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &result);
	glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
	if (infoLogLength > 0) {
		std::vector<char> ProgramErrorMessage(infoLogLength + 1);
		glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
	}

}

CubeDrawPass::CubeDrawPass() {
	pMat = createProjectionMatrix(0.01f, 10.0f, 45.0f, 4.0f / 3.0f);
}

FrameBufferPrototype CubeDrawPass::registerOutputFrameBuffer() {
	GLfloat g_vertex_buffer_data[] = {
		-1.0f,-1.0f,-1.0f, // triangle 1 : begin
		-1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f, // triangle 1 : end
		1.0f, 1.0f,-1.0f, // triangle 2 : begin
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f, // triangle 2 : end
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f
	};

	glGenVertexArrays(1, &vbo);
	glBindVertexArray(vbo);
	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	glDisable(GL_CULL_FACE);
	createShaderProgram();

	return FrameBufferPrototype(0, 0);
}
void CubeDrawPass::doPass(IRenderer* renderer) {
	glUseProgram(shaderProgram);
	GLfloat pmat[16];
	pMat.rawMatrix(pmat);
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "pMat"), 1, GL_FALSE, pmat);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
	glUseProgram(0);
}
CubeDrawPass::~CubeDrawPass() {
	glDeleteVertexArrays(1, &vbo);
}