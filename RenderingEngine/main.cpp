#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include <inttypes.h>
//define TEST to run tests... not the best system, but it should be okay
//#define TEST 0
#ifdef TEST
#include "test.h"
#endif //TEST

int main() {
#ifdef TEST

	std::cout << "started in test mode!" << std::endl;
	test::runAllTests();
	std::cin.ignore();
	return 0;
#endif // TEST
	std::cout << "starting" << std::endl;
	if (!glfwInit()) {
		std::cout << "failed glfw init" << std::endl;
		
	}
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	GLFWwindow* window = glfwCreateWindow(640, 480, "OpenGL and shit", NULL, NULL);
	if (!window) {
		std::cout << "failed to create OpenGL contexts" << std::endl;
	}
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK) {
		std::cout << "failed to init glew... feelsbadman" << std::endl;
	}
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	static const float g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};

	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	bool quit = false;
	glfwSwapInterval(1);
	while (!quit) {
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwWindowShouldClose(window)) {
			quit = true;
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glDrawArrays(GL_TRIANGLES, 0, 3); 
		glDisableVertexAttribArray(0);

		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
}