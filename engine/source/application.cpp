#include "application.h"


void Application::setup(bool& isRunningPtr)
{
	// Get the pointer of the running state
	isRunning = &isRunningPtr;

	// Create window
	windowClass.CreateWindow();

	// I will move this to a level loader later on
	objLoaderClass.LoadModel("resources/models/testScene.obj");
	meshManagerClass.AddMesh(objLoaderClass.vertices, objLoaderClass.indices, "testScene");
	objLoaderClass.LoadModel("resources/models/skyBox.obj");
	meshManagerClass.AddMesh(objLoaderClass.vertices, objLoaderClass.indices, "skyBox");
	objLoaderClass.LoadModel("resources/models/backpack.obj");
	meshManagerClass.AddMesh(objLoaderClass.vertices, objLoaderClass.indices, "backpack");
	int sceneMesh = meshManagerClass.AddMeshObject("testScene", 1);
	int headMesh = meshManagerClass.AddMeshObject("skyBox", 2);
	int backpackMesh = meshManagerClass.AddMeshObject("backpack", 3);
	meshManagerClass.meshObjects[headMesh].scale = vec3(1000, 1000, 1000);
	meshManagerClass.meshObjects[backpackMesh].position = vec3(0, 2, 0);
	meshManagerClass.meshObjects[backpackMesh].scale = vec3(0.5, 0.5, 0.5);


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