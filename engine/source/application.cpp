#include "application.h"


void Application::setup(bool& isRunningPtr)
{
	// Get the pointer of the running state
	isRunning = &isRunningPtr;

	// Create window
	windowClass.CreateWindow();

	// Meshes (NOT FINAL!) i need to add a obj loader for this.
	std::vector <float> va {-0.5,-0.5,0,0,0, 0.5,-0.5,0,1,0, 0,0.5,0,0.5,1};
	std::vector <unsigned int> ia {0,1,2};
	std::vector <float> vb{-0.5,-0.5,0,0,0, 0.5,-0.5,0,1,0, -0.5,0.5,0,0,1, 0.5,0.5,0,1,1};
	std::vector <unsigned int> ib{0,1,2,3,2,1};

	meshManagerClass.AddMesh(va, ia, "tri");
	meshManagerClass.AddMesh(vb, ib, "quad");

	meshManagerClass.AddMeshObject("quad", 2);
	meshManagerClass.AddMeshObject("quad", 3);
	meshManagerClass.meshObjects[1].position = vec3(0, -0.5, 0);
	meshManagerClass.meshObjects[1].rotation = vec3(90, 0, 0);
	meshManagerClass.meshObjects[1].scale = vec3(5, 5, 5);
	// -------------------

	// Setup classes
	rendererClass.setup(meshManagerClass);
	playerClass.setup(rendererClass, meshManagerClass, *windowClass.window);
}

void Application::update()
{
	// Get deltaTime
	deltaTime = glfwGetTime() - timePrev;
	timePrev = glfwGetTime();

	// Check for press on X to quit application
	if (glfwWindowShouldClose(windowClass.window) or glfwGetKey(windowClass.window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		*isRunning = false;
	// Wireframe mode key (will change)
	if (glfwGetKey(windowClass.window, GLFW_KEY_F1) == GLFW_PRESS) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	if (glfwGetKey(windowClass.window, GLFW_KEY_F2) == GLFW_PRESS) glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

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