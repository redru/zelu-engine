#pragma once
#include <GL\glew.h>
#include <iostream>

#include "../../engine/headers/ZeluEngine.h"
#include "../../engine/headers/RenderHandlerInterface.h"

#include "Constants.h"

class TexturedRenderHandler : public RenderHandlerInterface {

public:
	TexturedRenderHandler();

	virtual void setup(Model& model);
	virtual void render(glm::mat4& transformation_matrix, int count);

private:
	GLuint VaoId, VboId;

};