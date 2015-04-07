#include "../headers/TexturedRenderHandler.h"

TexturedRenderHandler::TexturedRenderHandler() : vertices_count(0), VaoId(0), VboId(0) {

}

void TexturedRenderHandler::setup(Model& model) {
	// Get the total count of the faces
	vertices_count = model.getVerticesCount();

	GLenum ErrorCheckValue = glGetError();
	const size_t BufferSize = model.getUnifiedData().size() * sizeof(float);
	const size_t VertexSize = 8 * sizeof(float);
	const size_t RgbOffset = 3 * sizeof(float);

	glGenBuffers(1, &VboId);
	glBindBuffer(GL_ARRAY_BUFFER, VboId);
	glBufferData(GL_ARRAY_BUFFER, BufferSize, &model.getUnifiedData().front(), GL_STATIC_DRAW);

	glGenVertexArrays(1, &VaoId);
	glBindVertexArray(VaoId);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, VertexSize, 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, VertexSize, (GLvoid*)RgbOffset);

	glBindVertexArray(0);

	ErrorCheckValue = glGetError();
	if (ErrorCheckValue != GL_NO_ERROR) {
		std::cout << "Error creating Triangle buffers: " << ErrorCheckValue << std::endl;
		exit(-1);
	}
}

void TexturedRenderHandler::render(glm::mat4& transformation_matrix) {
	glBindVertexArray(VaoId);

	ZeluEngine& engine{ ZeluEngine::getInstance() };
	ShaderProgram& prog{ engine.getShaderProgram(CONSTANTS::SHADER_STRUCT) };
	glUniformMatrix4fv(prog.getUniformLoc("u_mvpMatrix"), 1, false, (GLfloat*)&engine.getCamera().getMatrix());
	glUniformMatrix4fv(prog.getUniformLoc("u_transformationMatrix"), 1, false, (GLfloat*)&transformation_matrix);

	glUseProgram(prog.getProgramId());
	glDrawArrays(GL_TRIANGLES, 0, vertices_count);

	glBindVertexArray(0);
}