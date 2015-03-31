#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>

#include "Model.h"

class RenderHandlerInterface {

public:
	// Setup function
	virtual void setup(Model& model) = 0;

	// Render function
	virtual void render(glm::mat4& transformation_matrix, int count) = 0;

};