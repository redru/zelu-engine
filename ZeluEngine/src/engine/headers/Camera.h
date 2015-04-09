#pragma once
#include <vector>
#include <iostream>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/glm.hpp>


#include "../../engine/headers/MatrixUtils.h"

class Camera {

public:
	Camera();
	~Camera();

	void updateCamera();

	void move(float x_upset, float y_upset, float z_upset);
	void rotate(float x_rotation_degrees, float y_rotation_degrees, float z_rotation_degrees);
	void setAspectRatio(float aspect_ratio);
	vector<float>& getMvpMatrix();
	glm::mat4 getMatrix();

private:
	glm::mat4* mvp_matrix;
	const glm::mat4* identity_matrix;
	

	float fov = 45.0f;
	float near_z = 1.0f;
	float far_z = 100.0f;
	float aspect_ratio = 0.0f;

	float x_cam = 0.0f;
	float y_cam = 0.0f;
	float z_cam = 0.0f;

	float x_rotation = 0;
	float y_rotation = 0;
	float z_rotation = 0;

};