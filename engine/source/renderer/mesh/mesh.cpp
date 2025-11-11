#include "renderer/mesh/mesh.h"


mat4 Mesh::GetModelMatrix()
{
	// Make Matrix
	mat4 trans = mat4(1.0f);
	// Move
	trans = translate(trans, position);
	// Rotation
	trans = rotate(trans, radians(rotation.y), vec3(0,1,0));
	trans = rotate(trans, radians(rotation.x), vec3(1,0,0));
	trans = rotate(trans, radians(rotation.z), vec3(0,0,1));
	// Scale
	trans = glm::scale(trans, scale);

	return trans;
}