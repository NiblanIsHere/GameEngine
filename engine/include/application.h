#pragma once

#include "renderer/window.h"
#include "renderer/renderer.h"
#include "player.h"

#include "GLFW/glfw3.h"


class Application
{
private:
	// Run state pointer
	bool* isRunning = nullptr;

	// Classes
	Window windowClass;
	Renderer rendererClass;
	Player playerClass;

	double timePrev = 0;
	double deltaTime = 0;

public:

	void setup(bool& isRunningPtr);
	void update();
	void end();

};