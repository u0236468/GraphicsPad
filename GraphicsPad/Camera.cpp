#include "Camera.h"
#include <glm\gtx\transform.hpp>

const float MOVEMENT_SPEED = 0.1f;

Camera::Camera() : viewDirection(0.0f, 0.0f, -1.0f), UP(0.0f, 1.0f, 0.0f)
{
	
}

void Camera::mouseUpdate(const glm::vec2& newMousePosition)
{
	glm::vec2 mouseDelta = newMousePosition - oldMousePosition;
	//the if statement is to fix the Camera jumping
	if (glm::length(mouseDelta) > 50.0f)
	{
		oldMousePosition = newMousePosition;
		return;
	}
	
	const float ROTATIONAL_SPEED = 0.5f;
	//horizontal and vertical update
	glm::vec3 toRotateAround = glm::cross(viewDirection, UP);
	glm::mat4 rotator = glm::rotate(-mouseDelta.x * ROTATIONAL_SPEED, UP) *
						glm::rotate(-mouseDelta.y * ROTATIONAL_SPEED, toRotateAround);

	viewDirection = glm::mat3(rotator) * viewDirection;

	oldMousePosition = newMousePosition;
}

glm::mat4 Camera::getWorldToViewMatrix() const
{
	return glm::lookAt(position, position + viewDirection, UP);
}

void Camera::moveForward()
{
	position += MOVEMENT_SPEED * viewDirection;
}

void Camera::moveBackward()
{
	position += -MOVEMENT_SPEED * viewDirection;
}

void Camera::strafeLeft()
{
	glm::vec3 strafeDirection = glm::cross(viewDirection, UP);
	position += -MOVEMENT_SPEED * strafeDirection;
}
void Camera::strafeRight()
{
	glm::vec3 strafeDirection = glm::cross(viewDirection, UP);
	position += MOVEMENT_SPEED * strafeDirection;
}
void Camera::moveUp()
{
	position += MOVEMENT_SPEED * UP;
}
void Camera::moveDown()
{
	position += -MOVEMENT_SPEED * UP;
}

/*#include <Camera.h>
#include <MeRenderer.h>
#include <glm\gtc\matrix_transform.hpp>

glm::mat4 Camera::getWorldToViewMatrix() const
{ 
	return glm::lookAt(position, position + viewDirection, up);
}

glm::mat4 Camera::getViewToProjectionMatrix() const
{ 
	return glm::perspective(
		fieldOfView,
		aspectRatio == 0 ? ((float)renderer.width())/renderer.height() : aspectRatio,
		nearPlane, farPlane);
}

glm::mat4 Camera::getWorldToProjection() const
{ 
	return getViewToProjectionMatrix() * getWorldToViewMatrix(); 
}*/