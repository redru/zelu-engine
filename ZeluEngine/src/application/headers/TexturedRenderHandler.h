#pragma once
#include <GL\glew.h>
#include <iostream>

#include "../../engine/headers/ZeluEngine.h"
#include "../../engine/headers/RenderHandlerInterface.h"
#include "../../engine/headers/Model.h"
#include "../../engine/headers/Texture.h"

#include "Constants.h"

class TexturedRenderHandler : public RenderHandlerInterface {

public:
	TexturedRenderHandler();

	virtual void setup(Model& model, Texture& texture);
	virtual void render(glm::mat4& transformation_matrix);

private:
	int vertices_count;
	GLuint VaoId, VboId;

};