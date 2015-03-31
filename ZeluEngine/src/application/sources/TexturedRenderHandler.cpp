#include "../headers/TexturedRenderHandler.h"

TexturedRenderHandler::TexturedRenderHandler() {

}

void TexturedRenderHandler::setup(Model& model) {
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

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, VertexSize, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, VertexSize, (GLvoid*)RgbOffset);

	glBindVertexArray(0);

	ErrorCheckValue = glGetError();
	if (ErrorCheckValue != GL_NO_ERROR) {
		std::cout << "Error creating Triangle buffers: " << ErrorCheckValue << std::endl;
		exit(-1);
	}
}

void TexturedRenderHandler::render(glm::mat4& transformation_matrix, int count) {
	glBindVertexArray(VaoId);

	ZeluEngine& engine{ ZeluEngine::getInstance() };
	ShaderProgram& prog{ engine.getShaderProgram(CONSTANTS::SHADER_STRUCT) };
	glUniformMatrix4fv(prog.getUniformLoc("u_mvpMatrix"), 1, false, (GLfloat*)&engine.getCamera().getMatrix());

	glUseProgram(prog.getProgramId());
	glDrawArrays(GL_LINES, 0, 240);

	glBindVertexArray(0);
}