#include "renderer/camera.h"


void Camera::SetMatrices(unsigned int shaderProgram)
{
	// Camera
	float yaw = rotation.x - 90;
	float pitch = rotation.y;
	// Forward vector
	glm::vec3 cameraFront = {
		cos(glm::radians(yaw)) * cos(glm::radians(pitch)),
		sin(glm::radians(pitch)),
		sin(glm::radians(yaw)) * cos(glm::radians(pitch))
	};

	cameraFront = glm::normalize(cameraFront);

	position.z = 0 - position.z;

	glm::vec3 cameraTarget = position + cameraFront;
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

	glm::mat4 view = glm::lookAt(position, cameraTarget, up);
	glm::mat4 projection = glm::perspective(glm::radians(fov), float(1920) / float(1080), nearPlane, farPlane);

	// Send to the vertex shader
	int viewLoc = glGetUniformLocation(shaderProgram, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

	int projectionLoc = glGetUniformLocation(shaderProgram, "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

	position.z = 0 - position.z;
}

vec3 Camera::GetForwardVector()
{
	float yaw = radians(rotation.x);
	float pitch = radians(0 - rotation.y);

	return vec3(
		cos(pitch) * sin(yaw),
	   -sin(pitch),
		cos(pitch) * cos(yaw)
	);
}

vec3 Camera::GetRightVector()
{
	float yaw = radians(rotation.x);
	float pitch = radians(0 - rotation.y);

	return vec3(
		cos(yaw),
		0,
	   -sin(yaw)
	);
}