#pragma once

#include "renderer/window.h"

#include "GLFW/glfw3.h"


class Application
{
private:
	// Run state pointer
	bool* isRunning = nullptr;

	// Classes
	Window windowClass;

public:

	void setup(bool& isRunningPtr);
	void update();
	void end();

};