#pragma once
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>

#include "RenderHandlerInterface.h"
#include "Model.h"

class Actor {

public:
	Actor();
	Actor(Model& model, RenderHandlerInterface& render_handler, bool active);
	~Actor();

	// Methods for transformations -------------------------------------------
	void scale(float x_scale_upset, float y_scale_upset, float z_scale_upset);
	void rotate(float x_rot_upset, float y_rot_upset, float z_rot_upset);
	void translate(float x_pos_upset, float y_pos_upset, float z_pos_upset);
	void translateToPosition(float x_pos, float y_pos, float z_pos);
	void updateTransformations();

	// Methods for accessing the render_handler ------------------------------
	void renderHandlerSetup();
	void render();

	// Getters / Setters -----------------------------------------------------
	void setRenderHandler(RenderHandlerInterface& render_handler);
	RenderHandlerInterface& getRenderHandler();

	void setModel(Model& model);
	Model& getModel();

	void setActive(bool active);
	bool isActive();

protected:
	float x_start = 0.0f, y_start = 0.0f, z_start = 0.0f;

	float x_pos = 0.0f, y_pos = 0.0f, z_pos = 0.0f;
	float x_sca = 1.0f, y_sca = 1.0f, z_sca = 1.0f;
	float x_rot = 0.0f, y_rot = 0.0f, z_rot = 0.0f;

	float x_acc = 0.0f, y_acc = 0.0f, z_acc = 0.0f;
	float x_vel = 0.0f, y_vel = 0.0f, z_vel = 0.0f;

	bool active;

	glm::mat4* scalation_matrix;
	glm::mat4* rotation_matrix;
	glm::mat4* rotation_support_matrix;
	glm::mat4* translation_matrix;

	RenderHandlerInterface* render_handler;
	Model* model;

};

/* INLINED METHODS */
inline void Actor::scale(float x_scale_upset, float y_scale_upset, float z_scale_upset) {
	this->x_sca += x_scale_upset;
	this->y_sca += y_scale_upset;
	this->z_sca += z_scale_upset;
}

inline void Actor::rotate(float x_rot_upset, float y_rot_upset, float z_rot_upset) {
	this->x_rot += x_rot_upset;
	this->y_rot += y_rot_upset;
	this->z_rot += z_rot_upset;
}

inline void Actor::translate(float x_pos_upset, float y_pos_upset, float z_pos_upset){
	this->x_pos += x_pos_upset;
	this->y_pos += y_pos_upset;
	this->z_pos += z_pos_upset;
}

inline void Actor::translateToPosition(float x_pos, float y_pos, float z_pos) {
	this->x_pos = x_pos;
	this->y_pos = y_pos;
	this->z_pos = z_pos;
}

/* GETTERS / SETTERS */
inline void Actor::setActive(bool active) {
	this->active = active;
}

inline bool Actor::isActive() {
	return active;
}

inline void Actor::setRenderHandler(RenderHandlerInterface& render_handler) {
	this->render_handler = &render_handler;
}

inline RenderHandlerInterface& Actor::getRenderHandler() {
	return *this->render_handler;
}

inline void Actor::setModel(Model& model) {
	this->model = &model;
}

inline Model& Actor::getModel() {
	return *this->model;
}
// ---------------------------------------------------------------------------