#include "renderer/window.h"


int Window::CreateWindow()
{
	// Initialize GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create window
	window = glfwCreateWindow(1920/2, 1080/2, "Hello Window!", NULL, NULL);
	// Check for errors
	if (window == NULL)
	{
		std::cout << "Error: Failed to create GLFW window (window = NULL)" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Use window
	glfwMakeContextCurrent(window);

	return 0;
}