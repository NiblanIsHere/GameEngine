#include "application.h"


void Application::setup(bool& isRunningPtr)
{
	// Get the pointer of the running state
	isRunning = &isRunningPtr;

	// Create window
	windowClass.CreateWindow();

	rendererClass.setup();
	playerClass.setup(rendererClass, *windowClass.window);
}

void Application::update()
{
	// Get deltaTime
	deltaTime = glfwGetTime() - timePrev;
	timePrev = glfwGetTime();

	// Check for press on X to quit application
	if (glfwWindowShouldClose(windowClass.window) or glfwGetKey(windowClass.window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		*isRunning = false;

	playerClass.update(deltaTime);

	// Render loop
	rendererClass.update();

	// Swap the windows buffers
	glfwSwapBuffers(windowClass.window);
	// Update input events
	glfwPollEvents();
}

void Application::end()
{
	rendererClass.end();
}