#pragma once

#include "renderer/renderer.h"
#include "renderer/mesh/mesh_manager.h"

#include "GLFW/glfw3.h"
#include "glm/glm.hpp"

using namespace glm;

class Player
{
private:

	Renderer* rendererClass = nullptr;
	MeshManager* meshManagerClass = nullptr;

	GLFWwindow* window;

	unsigned int mesh = 0;

	vec3 position = vec3(0, 0,-5);
	vec2 rotation = vec2(0, 0);

	float sensitivity = 140;
	float moveSpeed = 2;

public:

	void setup(Renderer& rendererClassPtr, MeshManager& meshManagerClassPtr, GLFWwindow& windowRef);
	void update(double deltaTime);
	
};