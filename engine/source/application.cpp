#include "application.h"


void Application::setup(bool& isRunningPtr)
{
	// Get the pointer of the running state
	isRunning = &isRunningPtr;

	// Create window
	windowClass.CreateWindow();
}

void Application::update()
{
	// Check for press on X to quit application
	if (glfwWindowShouldClose(windowClass.window))
		*isRunning = false;

	// Swap the windows buffers
	glfwSwapBuffers(windowClass.window);
	// Update input events
	glfwPollEvents();
}

void Application::end()
{

}