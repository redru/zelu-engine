#pragma once
#include <vector>
#include <iostream>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>

#include "../../engine/headers/MatrixUtils.h"

using namespace std;
using namespace glm;

class Camera {

public:
	Camera();
	~Camera();

	void updateCamera();

	void move(float upsetX, float upsetY, float upsetZ);
	void rotate(float xRotationDegrees, float yRotationDegrees, float zRotationDegrees);
	void setAspectRatio(float aspectRatio);
	vector<float>& getMvpMatrix();
	glm::mat4 getMatrix();

private:
	mat4* mvpMatrix;
	const mat4* identityMatrix;

	float fov = 45.0f, nearZ = 1.0f, farZ = 100.0f;
	float aspectRatio = 0.0f;

	float xCam = 0.0f, yCam = 0.0f, zCam = 0.0f;
	float xRotation = 0, yRotation = 0, zRotation = 0;

};