#pragma once

#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

using namespace glm;

class Camera
{
private:

	vec3 position = vec3(0, 0, 1);
	vec2 rotation = vec2(0, 0);
	float fov = 90;
	float nearPlane = 0.1;
	float farPlane = 100;

public:

	void SetMatrices(unsigned int shaderProgram);

};