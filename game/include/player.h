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

	vec3 position = vec3(0, 0,-5);
	vec2 rotation = vec2(0, 0);
	vec3 velocity = vec3(0, 0, 0);

	bool isGrounded = false;

	float sensitivity = 0.7;
	float moveSpeed = 5;

public:

	void setup(Renderer& rendererClassPtr, MeshManager& meshManagerClassPtr, GLFWwindow& windowRef);
	void update(double deltaTime);
	
};