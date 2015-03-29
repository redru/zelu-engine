#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>

class RenderHandlerInterface {

public:
	// Setup function
	virtual void setup() = 0;

	// Render function
	virtual void render(glm::mat4& transformation_matrix) = 0;

};