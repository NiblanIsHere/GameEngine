#pragma once

#include "glad/glad.h"
#include "stb/stb_image.h"

#include <iostream>
#include <string>
#include <vector>


class Texture
{

private:

	const char* folderPath = "resources/textures/";

public:

	enum
	{
		NEAREST,
		LINEAR
	};

	unsigned int texture;

	GLuint LoadTexture(int textureFilter, const char* texturePath);

};