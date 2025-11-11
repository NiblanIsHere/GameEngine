#pragma once

#include "renderer/window.h"
#include "renderer/renderer.h"
#include "renderer/mesh/mesh_manager.h"
#include "player.h"

#include "GLFW/glfw3.h"
#include "glad/glad.h"

#include <vector>

class Application
{
private:
	// Run state pointer
	bool* isRunning = nullptr;

	// Classes
	Window windowClass;
	Renderer rendererClass;
	MeshManager meshManagerClass;
	Player playerClass;

	// Time variables
	double timePrev = 0;
	double deltaTime = 0;

public:

	void setup(bool& isRunningPtr);
	void update();
	void end();

};