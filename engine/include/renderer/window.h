#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>


class Window
{
private:

public:

	GLFWwindow* window;

	int CreateWindow();

};