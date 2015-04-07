#include "../headers/GridLines.h"

GridLines::GridLines() {
	vertexData = new vector < float >{240 * 8};
	vector<float>::iterator it;

	it = vertexData->begin();

	float MIN_VERTEX = -50;
	float MAX_VERTEX = 50;

	for (int count = -30, i = 0; count < 30; count++) {
		for (unsigned e = 0; e < 4; e++) {
			if (e == 2) {
				vertexData->insert(it, MIN_VERTEX);
			}
			else if (e == 3) {
				vertexData->insert(it, MAX_VERTEX);
			}
			else {
				vertexData->insert(it, (float)count);
			}

			i++;
			it = vertexData->begin() + i;
			vertexData->insert(it, 0);
			i++;
			it = vertexData->begin() + i;

			if (e == 0) {
				vertexData->insert(it, MIN_VERTEX);
			}
			else if (e == 1) {
				vertexData->insert(it, MAX_VERTEX);
			}
			else {
				vertexData->insert(it, (float)count);
			}

			i++;
			it = vertexData->begin() + i;
			vertexData->insert(it, 1.0f);
			i++;
			it = vertexData->begin() + i;
			vertexData->insert(it, 1.0f);
			i++;
			it = vertexData->begin() + i;
			vertexData->insert(it, 1.0f);
			i++;
			it = vertexData->begin() + i;
			vertexData->insert(it, 1.0f);
			i++;
			it = vertexData->begin() + i;
			vertexData->insert(it, 1.0f);
			i++;
			it = vertexData->begin() + i;
		}
	}

	openglMeshSetup();
}

GridLines::~GridLines() {
	GLenum ErrorCheckValue = glGetError();

	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &VboId);

	glBindVertexArray(0);
	glDeleteVertexArrays(1, &VaoId);

	ErrorCheckValue = glGetError();

	if (ErrorCheckValue != GL_NO_ERROR) {
		std::cout << "Error destroying object Triangle: " << ErrorCheckValue << std::endl;
		exit(-1);
	}
}

void GridLines::openglMeshSetup() {
	GLenum ErrorCheckValue = glGetError();
	const size_t BufferSize = vertexData->size() * sizeof(float);
	const size_t VertexSize = 8 * sizeof(float);
	const size_t RgbOffset = 4 * sizeof(float);

	glGenBuffers(1, &VboId);
	glBindBuffer(GL_ARRAY_BUFFER, VboId);
	glBufferData(GL_ARRAY_BUFFER, BufferSize, &vertexData->front(), GL_STATIC_DRAW);

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

void GridLines::draw() {
	glBindVertexArray(VaoId);

	ZeluEngine& engine{ ZeluEngine::getInstance() };
	ShaderProgram& prog{ engine.getShaderProgram(CONSTANTS::SHADER_STRUCT) };
	glUniformMatrix4fv(prog.getUniformLoc("u_mvpMatrix"), 1, false, (GLfloat*)&engine.getCamera().getMatrix());
	glUniformMatrix4fv(prog.getUniformLoc("u_transformationMatrix"), 1, false, (GLfloat*)&glm::mat4{1.0f} );

	glUseProgram(prog.getProgramId());
	glDrawArrays(GL_LINES, 0, 240);

	glBindVertexArray(0);
}