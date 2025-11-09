#pragma once

#include "glad/glad.h"

#include <iostream>
#include <fstream>
#include <string>

class Shader
{
private:

	std::string shaderCode;

	std::string ReadFile(const char* fileName);

public:

	std::string shaderFolder = "resources/shaders/";
	unsigned int shaderProgram;

	void CreateShaderProgram(const char* vertexShaderName, const char* fragmentShaderName);

};