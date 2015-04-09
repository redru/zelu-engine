#include "../headers/Actor.h"

Actor::Actor() {
	active = false;

	transform_matrix = new glm::mat4{ 1 };

	std::cout << "Actor - Creation complete (NULL initializazion)." << std::endl;
}

Actor::Actor(Model& model, Texture& texture, RenderHandlerInterface& render_handler, bool active) {
	initialize(model, texture, render_handler, active);

	transform_matrix = new glm::mat4{ 1 };

	std::cout << "Actor - Creation complete." << std::endl;
}

Actor::~Actor() {

}

void Actor::initialize(Model& model, Texture& texture, RenderHandlerInterface& render_handler, bool active) {
	this->model = &model;
	this->texture = &texture;
	this->render_handler = &render_handler;
	this->active = active;
}

void Actor::renderHandlerSetup() {
	render_handler->setup(*model, *texture);
}

void Actor::render() {
	render_handler->render(*transform_matrix);
}

void Actor::updateTransformations() {
	glm::mat4 scalation_matrix = glm::scale(glm::mat4(1.0f), glm::vec3{ x_sca, y_sca, z_sca });
	glm::mat4 rotation_x = glm::rotate(glm::mat4(1.0f), x_rot, glm::vec3{ 1.0f, 0.0f, 0.0f });
	glm::mat4 rotation_y = glm::rotate(rotation_x, y_rot, glm::vec3{ 0.0f, 1.0f, 0.0f });
	glm::mat4 translation_matrix = glm::translate(glm::mat4(1.0f), glm::vec3{ x_pos, y_pos, z_pos });

	*transform_matrix = translation_matrix * rotation_y * scalation_matrix;
}