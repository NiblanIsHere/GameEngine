#pragma once

#include "glad/glad.h"

#include <vector>


class BufferObjects
{
private:
public:

	unsigned int VBO, VAO, EBO;

	void CreateBufferObjects(std::vector <float> vertices, std::vector <unsigned int> indices);

};

