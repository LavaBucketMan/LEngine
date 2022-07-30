#ifndef LENGINE_H_
#define LENGINE_H_

#ifndef UNICODE
#define UNICODE
#endif

#include "include.h"

static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

class LEngine
{
public:
	void init(int GLFW_V_MAJOR, int GLFW_V_MINOR);

	void createWindow(int W_WINDOW, int H_WINDOW, char T_WINDOW[10]);

private:
	int ErrEx() { return -1; }
};

void LEngine::init(int GLFW_V_MAJOR, int GLFW_V_MINOR) {
	if (GLFW_V_MAJOR < 3 || GLFW_V_MINOR < 3)
	{
		printf("[ERROR]  GLFW_V_MAJOR / GLFW_V_MINOR IS UNRECOGNIZABLE!\n");
		ErrEx();
	}
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLFW_V_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLFW_V_MINOR);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

void LEngine::createWindow(int W_WINDOW, int H_WINDOW, char T_WINDOW[10]) {
	GLFWwindow* window = glfwCreateWindow(W_WINDOW, H_WINDOW, T_WINDOW, NULL, NULL);
	if (window == NULL)
	{
		printf("[ERROR]  FAILED TO CREATE WINDOW!\n");
		glfwTerminate();
		ErrEx();
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		printf("[ERROR]  FAILED TO INITIALIZE GLAD!\n");
		ErrEx();
	}

	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
}

static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

#endif