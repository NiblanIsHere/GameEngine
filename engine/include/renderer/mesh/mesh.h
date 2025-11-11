#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include <vector>

using namespace glm;

class Mesh
{
private:

public:

	vec3 position = vec3(0);
	vec3 rotation = vec3(0);
	vec3 scale = vec3(1);

	unsigned int textureIndex = 0;

	std::vector <float> vertices = {};
	std::vector <unsigned int> indices = {};

	mat4 GetModelMatrix();

};