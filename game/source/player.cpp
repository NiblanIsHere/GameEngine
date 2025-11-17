#include "player.h"


void Player::setup(Renderer& rendererClassPtr, MeshManager& meshManagerClassPtr, GLFWwindow& windowRef)
{
	rendererClass = &rendererClassPtr;
	meshManagerClass = &meshManagerClassPtr;

	window = &windowRef;
}

void Player::update(double deltaTime)
{
	// Player Rotation
	// ---------------

	static double lastMouseX = 0.0;
	static double lastMouseY = 0.0;
	static bool firstMouse = true;
	static bool mouseMode = false;
	static float sensMultiplier = 0.1;

	if (glfwRawMouseMotionSupported()) {
		glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
	}
	
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Get current mouse position
	double mouseX, mouseY;
	glfwGetCursorPos(window, &mouseX, &mouseY);

	if (firstMouse)
	{
		lastMouseX = mouseX;
		lastMouseY = mouseY;
		firstMouse = false;
	}

	// Calculate offset
	double offsetX = mouseX - lastMouseX;
	double offsetY = lastMouseY - mouseY;

	// Update last mouse position
	lastMouseX = mouseX;
	lastMouseY = mouseY;
	// Apply sensitivity
	offsetX *= sensitivity * sensMultiplier;
	offsetY *= sensitivity * sensMultiplier;
	// Apply rotation
	rotation.x += static_cast<float>(offsetX);
	rotation.y += static_cast<float>(offsetY);

	// Clamp pitch
	if (rotation.y > 89.9f)
		rotation.y = 89.9f;
	if (rotation.y < -89.9f)
		rotation.y = -89.9f;
	// Clamp Yaw
	if (rotation.x > 180)
		rotation.x -= 360;
	if (rotation.x < -180)
		rotation.x += 360;

	// Player Movement
	// ---------------
	float yaw = radians(0-rotation.x);
	float pitch = radians(rotation.y);

	vec3 forward = vec3(sin(yaw), 0, cos(yaw));
	vec3 right = vec3(cos(yaw), 0, -sin(yaw));
	vec3 inputDir = vec3(0);

	// Movement inputs
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		inputDir += forward;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		inputDir -= forward;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		inputDir += right;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		inputDir -= right;
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		inputDir += vec3(0,1,0);
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		inputDir -= vec3(0,1,0);

	// Normalize inputDir and play walk animation
	if (inputDir != vec3(0))
		inputDir = normalize(inputDir);

	// Apply player movement to position
	position += inputDir * moveSpeed * vec3(deltaTime);

	rendererClass->cameraClass.position = position + vec3(0,1.85,0);
	rendererClass->cameraClass.rotation = rotation;
}