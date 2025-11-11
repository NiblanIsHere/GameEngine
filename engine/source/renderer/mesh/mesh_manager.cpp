#include "renderer/mesh/mesh_manager.h"


void MeshManager::AddMesh(std::vector <float>& vertices, std::vector <unsigned int>& indices, const char* name)
{
	// Crate mesh data
	meshData data;
	data.vertices = &vertices;
	data.indices = &indices;
	// Add mesh to mem
	meshes[name] = data;
}

unsigned int MeshManager::AddMeshObject(const char* meshName, unsigned int textureID)
{
	// Create a mesh object
	Mesh meshObject;
	// Add mesh data to mesh object
	meshObject.vertices = *meshes[meshName].vertices;
	meshObject.indices = *meshes[meshName].indices;
	meshObject.textureIndex = textureID;
	// Add mesh object to scene
	meshObjects.push_back(meshObject);

	return meshObjects.size() - 1;
}