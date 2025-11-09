#pragma once

#include "renderer/shader/shader.h"
#include "renderer/shader/buffer_objects.h"
#include "renderer/camera.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <vector>

class Renderer
{
private:

	Camera cameraClass;

	Shader test_Shader;
	BufferObjects test_BufferObjects;

	std::vector <float> testVertices = {-0.5,-0.5,0,0,0, 0.5,-0.5,0,0,0, -0.5,0.5,0,0,0, 0.5,0.5,0,0,0};
	std::vector <unsigned int> testIndices = {0,2,1, 2,1,3};

public:

	void setup();
	void update();
	void end();

};