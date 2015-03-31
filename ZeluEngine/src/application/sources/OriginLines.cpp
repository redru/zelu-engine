#include "../headers/OriginLines.h"

OriginLines::OriginLines() {
	vertexData = new vector < float >{
		  0.0f,   0.0f,   0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f,
		100.0f,   0.0f,   0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f,
		  0.0f,   0.0f,   0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		  0.0f, 100.0f,   0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		  0.0f,   0.0f,   0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		  0.0f,   0.0f, 100.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f
	};

	openglMeshSetup();
}

OriginLines::~OriginLines() {
	GLenum ErrorCheckValue = glGetError();

	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &VboId);

	glBindVertexArray(0);
	glDeleteVertexArrays(1, &VaoId);

	ErrorCheckValue = glGetError();

	if (ErrorCheckValue != GL_NO_ERROR) {
		cout << "Error destroying object Triangle: " << ErrorCheckValue << endl;
		exit(-1);
	}
}

void OriginLines::openglMeshSetup() {
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
		cout << "Error creating Triangle buffers: " << ErrorCheckValue << endl;
		exit(-1);
	}
}

void OriginLines::draw() {
	glBindVertexArray(VaoId);

	ZeluEngine& engine{ ZeluEngine::getInstance() };
	ShaderProgram& prog{ ZeluEngine::getInstance().getShaderProgram(CONSTANTS::SHADER_STRUCT) };
	glUniformMatrix4fv(prog.getUniformLoc("u_mvpMatrix"), 1, false, (GLfloat*)&engine.getCamera().getMatrix());

	glUseProgram(prog.getProgramId());
	glDrawArrays(GL_LINES, 0, 6);

	glBindVertexArray(0);
}