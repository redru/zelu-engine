#include "../../engine/headers/Camera.h"

// CONSTRUCTORS AND DESTRUCTORS -------------------------------------------------------------------
Camera::Camera() {
	mvp_matrix = new glm::mat4{ 1 };
	identity_matrix = new glm::mat4{ 1 };

	std::cout << "Camera - Creation complete." << std::endl;
}

Camera::~Camera() {
	std::cout << "Camera - Destructor." << std::endl;
}
// IMPLEMENTATIONS --------------------------------------------------------------------------------
void Camera::updateCamera() {
	if (aspect_ratio != 0.0f) {
		glm::mat4 Projection = glm::perspective(fov, aspect_ratio, near_z, far_z);
		/*glm::mat4 ViewTranslate = glm::translate(glm::mat4(1.0f), glm::vec3{ x_cam, y_cam, z_cam });
		glm::mat4 ViewRotateX = glm::rotate(ViewTranslate, y_rotation, glm::vec3{ 0.0f, 1.0f, 0.0f });
		glm::mat4 View = glm::rotate(ViewRotateX, x_rotation, glm::vec3{ 1.0f, 0.0f, 0.0f });*/
		/*glm::mat4 ViewTranslate = glm::translate(glm::mat4(1.0f), glm::vec3{ x_cam, y_cam, z_cam });
		glm::mat4 ViewRotateX = glm::rotate(ViewTranslate, x_rotation, glm::vec3{ 1.0f, 0.0f, 0.0f });
		glm::mat4 View = glm::rotate(ViewRotateX, y_rotation, glm::vec3{ 0.0f, 1.0f, 0.0f });*/
		/*glm::mat4 ViewTranslate = glm::rotate(glm::mat4(1.0f), x_rotation, glm::vec3{ 1.0f, 0.0f, 0.0f });
		glm::mat4 ViewRotateX = glm::rotate(ViewTranslate, y_rotation, glm::vec3{ 0.0f, 1.0f, 0.0f });
		glm::mat4 View = glm::translate(ViewRotateX, glm::vec3{ x_cam, y_cam, z_cam });*/
		/*glm::mat4 translation = glm::translate(glm::mat4(1.0f), glm::vec3{ x_cam, y_cam, z_cam });
		glm::mat4 scalation = glm::scale(glm::mat4(1.0f), glm::vec3{ 1.0f, 1.0f, 1.0f });
		glm::mat4 rotation_x = glm::rotate(glm::mat4(1.0f), x_rotation, glm::vec3{ 1.0f, 0.0f, 0.0f });
		glm::mat4 rotation_y = glm::rotate(rotation_x, x_rotation, glm::vec3{ 0.0f, 1.0f, 0.0f });
		glm::mat4 View = translation * rotation_y * scalation;*/
		glm::mat4 View = glm::lookAt(
			glm::vec3(x_cam, y_cam, z_cam), // Camera is at (x, y, z), in World Space
			glm::vec3(x_look, y_look, z_look), // and looks at (x, y, z)
			glm::vec3(0.0f, 1.0f, 0.0f)  // Head is up (set to 0,-1,0 to look upside-down)
			);

		*mvp_matrix = Projection * View;
	} else {
		*mvp_matrix = *identity_matrix;
	}
}

void Camera::move(float x_upset, float y_upset, float z_upset) {
	x_cam += x_upset;
	y_cam += y_upset;
	z_cam += z_upset;
}

void Camera::rotate(float x_rotation_degrees, float y_rotation_degrees, float z_rotation_degrees) {
	x_rotation += float(x_rotation_degrees * MatrixUtils::PI / 180);
	y_rotation += float(y_rotation_degrees * MatrixUtils::PI / 180);
	z_rotation += float(z_rotation_degrees * MatrixUtils::PI / 180);
}

void Camera::setAspectRatio(float aspect_ratio) {
	this->aspect_ratio = aspect_ratio;
}

glm::mat4 Camera::getMatrix() {
	return *mvp_matrix;
}