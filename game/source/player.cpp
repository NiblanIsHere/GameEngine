#include "player.h"


void Player::setup(Renderer& rendererClassPtr, MeshManager& meshManagerClassPtr, GLFWwindow& windowRef)
{
	rendererClass = &rendererClassPtr;
	meshManagerClass = &meshManagerClassPtr;

	window = &windowRef;

	// Create player mesh
	mesh = meshManagerClass->AddMeshObject("tri", 1);
	meshManagerClass->meshObjects[mesh].scale = vec3(0.5,1,1);
}

void Player::update(double deltaTime)
{
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		rotation.y += sensitivity * deltaTime;
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		rotation.y -= sensitivity * deltaTime;
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		rotation.x += sensitivity * deltaTime;
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		rotation.x -= sensitivity * deltaTime;

	float yaw = radians(rotation.x);
	float pitch = radians(rotation.y);

	vec3 forward = vec3(sin(yaw), 0, cos(yaw));

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		position += moveSpeed * forward * vec3(deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		position -= moveSpeed * forward * vec3(deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		position += moveSpeed * rendererClass->cameraClass.GetRightVector() * vec3(deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		position -= moveSpeed * rendererClass->cameraClass.GetRightVector() * vec3(deltaTime);
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		position += moveSpeed * vec3(0,1,0) * vec3(deltaTime);
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		position -= moveSpeed * vec3(0,1,0) * vec3(deltaTime);


	meshManagerClass->meshObjects[mesh].position.x = position.x;
	meshManagerClass->meshObjects[mesh].position.y = position.y;
	meshManagerClass->meshObjects[mesh].position.z = 0-position.z;
	meshManagerClass->meshObjects[mesh].rotation = vec3(0, 0-rendererClass->cameraClass.rotation.x, 0);

	// I will change this to use a rotation matrix, but for the time, i will use the camera forward vector.
	rendererClass->cameraClass.position = position - rendererClass->cameraClass.GetForwardVector()*vec3(2);
	rendererClass->cameraClass.rotation = rotation;
}