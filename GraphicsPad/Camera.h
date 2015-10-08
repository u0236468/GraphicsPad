#pragma once
#include <glm\glm.hpp>

class Camera
{
	glm::vec3 position;
	glm::vec3 viewDirection;
	const glm::vec3 UP;
	glm::vec2 oldMousePosition;
	//static float const MOVEMENT_SPEED;
public:
	Camera();
	void mouseUpdate(const glm::vec2& newMousePosition);
	glm::mat4 getWorldToViewMatrix() const;

	void Camera::moveForward();
	void Camera::moveBackward();
	void Camera::strafeLeft();
	void Camera::strafeRight();
	void Camera::moveUp();
	void Camera::moveDown();

};

/*#ifndef ENGINE_CAMERA_H
#define ENGINE_CAMERA_H
#include <glm\glm.hpp>
//#include <ExportImport.h>

class ME_DLL_SHARED Camera
{
	glm::vec3 position;
	glm::vec3 viewDirection;
	glm::vec3 up;
	float nearPlane;
	float farPlane;
	float fieldOfView;
	float aspectRatio;
public:
	Camera::Camera() : 
		viewDirection(-0.699327409f, -0.636076927f, -0.326101959f), // TODO: config file
		position(10.7958260f, 7.94535112f, 5.97761059f), up(0.0f, 1.0f, 0.0f),
		nearPlane(0.1f), farPlane(100.0f), fieldOfView(60.0f), aspectRatio(0) {}
		//viewDirection(0.0f, 0.0f, -1.0f), // TODO: config file
		//position(0.0f, 0.0f, 10.0f), up(0.0f, 1.0f, 0.0f),
		//nearPlane(0.1f), farPlane(100.0f), fieldOfView(60.0f), aspectRatio(0) {}
	// TODO: inline as much of this as possible
	// TODO: take all these out and just make the data members public
	void setPosition(const glm::vec3& position) { this->position = position; }
	glm::vec3& getPosition() { return position; }
	void setViewDirection(const glm::vec3& direction) { viewDirection = direction; }
	glm::vec3& getViewDirection() { return viewDirection; }
	void setNearPlane(float value) { nearPlane = value; }
	float getNearPlane() const { return nearPlane; }
	void setFarPlane(float value) { farPlane = value; }
	float getFarPlane() const { return farPlane; }
	void setFieldOfView(float value) { fieldOfView = value; }
	float getFieldOfView() const { return fieldOfView; }
	// When aspect ratio is 0, then default is to uwe the windows width / height
	void setAspectRatio(float value) { aspectRatio = value; }
	float getAspectRatio() const { return aspectRatio; }
	//void mouseUpdate(const glm::vec2& newMousePosition);
	glm::mat4 getWorldToViewMatrix() const;
	glm::mat4 getViewToProjectionMatrix() const;
	glm::mat4 getWorldToProjection() const;
};

#endif*/