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

	unsigned int texture;

	GLuint LoadTexture(const char* texturePath);

};