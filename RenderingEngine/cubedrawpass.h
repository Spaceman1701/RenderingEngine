#pragma once
#include "render_pass.h"
#include <glew.h>
#include "matrix4f.h"
using namespace engine::core::render;
using namespace engine::math;

class CubeDrawPass : public IRenderPass {
private:
	GLuint vbo;
	GLuint shaderProgram;
	Matrix4f pMat;
	float t;

	void createShaderProgram();
public:
	CubeDrawPass();
	FrameBufferPrototype registerOutputFrameBuffer();
	void doPass(IRenderer* renderer);
	~CubeDrawPass();
};