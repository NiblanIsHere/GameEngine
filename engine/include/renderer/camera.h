#pragma once

#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

using namespace glm;

class Camera
{
private:

	float nearPlane = 0.01;
	float farPlane = 2500;

public:

	vec3 position = vec3(0, 0, 0);
	vec2 rotation = vec2(0, 0);
	float fov = 90;

	void SetMatrices(unsigned int shaderProgram);
	vec3 GetForwardVector();
	vec3 GetRightVector();

};