#include "../../engine/headers/Camera.h"

// CONSTRUCTORS AND DESTRUCTORS -------------------------------------------------------------------
Camera::Camera() {
	mvpMatrix = new mat4{ 1 };
	identityMatrix = new mat4{ 1 };

	cout << "Camera - Creation complete." << endl;
}

Camera::~Camera() { }
// IMPLEMENTATIONS --------------------------------------------------------------------------------
void Camera::updateCamera() {
	if (aspectRatio != 0.0f) {
		glm::mat4 Projection = glm::perspective(fov, aspectRatio, nearZ, farZ);
		glm::mat4 ViewTranslate = glm::translate(glm::mat4(1.0f), glm::vec3{xCam, yCam, zCam});
		glm::mat4 ViewRotateX = glm::rotate(ViewTranslate, yRotation, glm::vec3{0.0f, 1.0f, 0.0f});
		glm::mat4 View = glm::rotate(ViewRotateX, xRotation, glm::vec3{ 1.0f, 0.0f, 0.0f });
		glm::mat4 Model = glm::mat4(1.0f);
	
		*mvpMatrix = Projection * View * Model;
	} else {
		*mvpMatrix = *identityMatrix;
	}
}

void Camera::move(float upsetX, float upsetY, float upsetZ) {
	xCam += upsetX;
	yCam += upsetY;
	zCam += upsetZ;
}

void Camera::rotate(float xRotationDegrees, float yRotationDegrees, float zRotationDegrees) {
	xRotation += float(xRotationDegrees * MatrixUtils::PI / 180);
	yRotation += float(yRotationDegrees * MatrixUtils::PI / 180);
	zRotation += float(zRotationDegrees * MatrixUtils::PI / 180);
}

void Camera::setAspectRatio(float aspectRatio) {
	this->aspectRatio = aspectRatio;
}

glm::mat4 Camera::getMatrix() {
	return *mvpMatrix;
}