#include "renderer/window.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// Resize the viewport
	glViewport(0, 0, width, height);
}

int Window::CreateWindow()
{
	// Initialize GLFW
	glfwInit();
	// Tell GLFW what opengl version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	// Create window
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	window = glfwCreateWindow(mode->width, mode->height, "Hello Window!", glfwGetPrimaryMonitor(), NULL);
	// Check for errors
	if (window == NULL)
	{
		std::cout << "Error: Failed to create GLFW window (window = NULL)" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Use window
	glfwMakeContextCurrent(window);
	// Resize viewport when window resize
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// Initialize GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Error: Failed to initialize GLAD" << std::endl;
		return -1;
	}

	return 0;
}