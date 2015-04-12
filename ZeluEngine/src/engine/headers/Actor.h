#pragma once
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/glm.hpp>

#include "MatrixUtils.h"
#include "RenderHandlerInterface.h"
#include "Model.h"
#include "Texture.h"

class Actor {

public:
	Actor();
	Actor(Model& model, Texture& texture, RenderHandlerInterface& render_handler, std::string id, bool active = false);
	~Actor();

	void initialize(Model& model, Texture& texture, RenderHandlerInterface& render_handler, std::string id, bool active);

	// Methods for transformations -------------------------------------------
	void scale(float x_scale_upset, float y_scale_upset, float z_scale_upset);
	void rotate(float x_rot_upset, float y_rot_upset, float z_rot_upset);
	void translate(float x_pos_upset, float y_pos_upset, float z_pos_upset);
	void translateToPosition(float x_pos, float y_pos, float z_pos);
	void setStart(float x_start, float y_start, float z_start);
	void setVelocity(float x_vel, float y_vel, float z_vel);
	void setAcceleration(float x_acc, float y_acc, float z_acc);
	void updateTransformations();

	// Methods for accessing the render_handler ------------------------------
	void renderHandlerSetup();
	void render();

	// Getters / Setters -----------------------------------------------------
	inline void setRenderHandler(RenderHandlerInterface& render_handler) { this->render_handler = &render_handler; }
	inline RenderHandlerInterface& getRenderHandler() { return *this->render_handler; }

	inline void setModel(Model& model) { this->model = &model; }
	inline Model& getModel() { return *this->model; }

	inline void setTexture(Texture& texture) { this->texture = &texture; }
	inline Texture& getTexture() { return *this->texture; }

	inline void setId(std::string id) { this->id = id; }
	inline std::string getId() { return this->id; }

	inline void setActive(bool active) { this->active = active; }
	inline bool isActive() { return active; }

	inline void setGroup(int group) { this->group = group; }
	inline int getGroup() { return group; }

protected:
	std::string id;
	bool active;
	int group;

	float x_start = 0.0f, y_start = 0.0f, z_start = 0.0f;

	float x_pos = 0.0f, y_pos = 0.0f, z_pos = 0.0f;
	float x_sca = 1.0f, y_sca = 1.0f, z_sca = 1.0f;
	float x_rot = 0.0f, y_rot = 0.0f, z_rot = 0.0f;

	float x_acc = 0.0f, y_acc = 0.0f, z_acc = 0.0f;
	float x_vel = 0.0f, y_vel = 0.0f, z_vel = 0.0f;

	glm::mat4* scalation_matrix;
	glm::mat4* rotation_x;
	glm::mat4* rotation_y;
	glm::mat4* translation_matrix;
	glm::mat4* transform_matrix;

	RenderHandlerInterface* render_handler;
	Model* model;
	Texture* texture;

};

/* INLINED METHODS */
inline void Actor::scale(float x_scale_upset, float y_scale_upset, float z_scale_upset) {
	this->x_sca = x_scale_upset;
	this->y_sca = y_scale_upset;
	this->z_sca = z_scale_upset;
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

inline void Actor::setStart(float x_start, float y_start, float z_start) {
	this->x_start = x_start;
	this->y_start = y_start;
	this->z_start = z_start;
}

inline void Actor::setVelocity(float x_vel, float y_vel, float z_vel) {
	this->x_vel = x_vel;
	this->y_vel = y_vel;
	this->z_vel = z_vel;
}

inline void Actor::setAcceleration(float x_acc, float y_acc, float z_acc) {
	this->x_acc = x_acc;
	this->y_acc = y_acc;
	this->z_acc = z_acc;
}