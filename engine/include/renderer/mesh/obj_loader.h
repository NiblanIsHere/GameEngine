#pragma once

#include "glm/glm.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace glm;

class objLoader
{
private:

	struct faceData
	{
		uvec3 vertex1;
		uvec3 vertex2;
		uvec3 vertex3;
	};

public:

	std::vector <float> vertices;
	std::vector <unsigned int> indices;

	void LoadModel(const char* filePath);

};