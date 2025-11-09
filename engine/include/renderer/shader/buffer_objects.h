#pragma once

#include "glad/glad.h"

#include <vector>


class BufferObjects
{
private:
public:

	unsigned int VBO, VAO, EBO;

	void CreateBufferObjects(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);

};

