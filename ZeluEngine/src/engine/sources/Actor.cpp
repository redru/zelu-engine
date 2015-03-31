#include "../headers/Actor.h"

Actor::Actor() {
	this->model = NULL;
	this->render_handler = NULL;

	scalation_matrix = new glm::mat4{ 1 };
	rotation_matrix = new glm::mat4{ 1 };
	rotation_support_matrix = new glm::mat4{ 1 };
	translation_matrix = new glm::mat4{ 1 };

	std::cout << "Actor - Creation complete (NULL initializazion)." << std::endl;
}

Actor::Actor(Model& model, RenderHandlerInterface& render_handler, bool active) {
	this->model = &model;
	this->render_handler = &render_handler;
	this->active = active;

	scalation_matrix = new glm::mat4{ 1 };
	rotation_matrix = new glm::mat4{ 1 };
	rotation_support_matrix = new glm::mat4{ 1 };
	translation_matrix = new glm::mat4{ 1 };

	std::cout << "Actor - Creation complete." << std::endl;
}

Actor::~Actor() {

}


void Actor::renderHandlerSetup() {
	render_handler->setup(*model);
}

void Actor::render() {
	glm::mat4 tmp{ 1 };
	render_handler->render(tmp, model->getUnifiedData().size() / 7 / 3);
}

void Actor::updateTransformations() {
	*scalation_matrix = glm::scale(glm::mat4(1.0f), glm::vec3{ x_sca, y_sca, z_sca });
	*rotation_support_matrix = glm::rotate(*scalation_matrix, y_rot, glm::vec3{ 0.0f, 1.0f, 0.0f });
	*rotation_matrix = glm::rotate(*rotation_support_matrix, x_rot, glm::vec3{ 1.0f, 0.0f, 0.0f });
	*translation_matrix = glm::translate(*rotation_matrix, glm::vec3{ x_pos, y_pos, z_pos });
}