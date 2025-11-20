#pragma once

#include "glad/glad.h"
#include "glm/glm.hpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace glm;

class Shader
{
private:

	std::string shaderCode;

	std::string ReadFile(const char* fileName);

public:

	std::string shaderFolder = "resources/shaders/";
	unsigned int shaderProgram;

	void CreateShaderProgram(const char* vertexShaderName, const char* fragmentShaderName);

	void setFloat(const char* variableName, float value);
	void setVec3(const char* variableName, vec3 value);

};