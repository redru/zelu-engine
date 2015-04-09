#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>

#include "Model.h"
#include "Texture.h"

class RenderHandlerInterface {

public:
	// Setup function
	virtual void setup(Model& model, Texture& texture) = 0;

	// Render function
	virtual void render(glm::mat4& transformation_matrix) = 0;

};