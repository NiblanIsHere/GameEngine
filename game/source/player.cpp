#include "player.h"


void Player::setup(Renderer& rendererClassPtr, GLFWwindow& windowRef)
{
	rendererClass = &rendererClassPtr;

	window = &windowRef;
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

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		position += moveSpeed * rendererClass->cameraClass.GetForwardVector() * vec3(deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		position -= moveSpeed * rendererClass->cameraClass.GetForwardVector() * vec3(deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		position += moveSpeed * rendererClass->cameraClass.GetRightVector() * vec3(deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		position -= moveSpeed * rendererClass->cameraClass.GetRightVector() * vec3(deltaTime);
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		position += moveSpeed * vec3(0,1,0) * vec3(deltaTime);
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		position -= moveSpeed * vec3(0,1,0) * vec3(deltaTime);

	rendererClass->cameraClass.position = position;
	rendererClass->cameraClass.rotation = rotation;
}