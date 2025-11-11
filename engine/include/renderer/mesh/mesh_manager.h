#pragma once

#include "renderer/mesh/mesh.h"

#include "vector"
#include "map"

struct meshData
{
	std::vector <float>* vertices;
	std::vector <unsigned int>* indices;
};

class MeshManager
{
private:

	std::map <const char*, meshData> meshes = {};
	

public:

	std::vector <Mesh> meshObjects = {};

	void AddMesh(std::vector <float>& vertices, std::vector <unsigned int>& indices, const char* name);
	unsigned int AddMeshObject(const char* meshName, unsigned int textureID);

};