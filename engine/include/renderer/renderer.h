#pragma once

#include "renderer/shader/shader.h"
#include "renderer/shader/buffer_objects.h"
#include "renderer/texture.h"
#include "renderer/mesh/mesh_manager.h"
#include "renderer/mesh/mesh.h"
#include "renderer/camera.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <vector>

class Renderer
{
private:

	Shader test_Shader;
	BufferObjects test_BufferObjects;

	std::vector <float> testVertices = {};
	std::vector <unsigned int> testIndices = {};

public:

	MeshManager* meshManagerClass;

	Texture textureClass;
	Camera cameraClass;

	void setup(MeshManager& meshManagerClassPtr);
	void update();
	void end();

};