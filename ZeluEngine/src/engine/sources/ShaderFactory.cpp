#include "../../engine/headers/ShaderFactory.h"

ShaderFactory::ShaderFactory() {

}

void ShaderFactory::createShader(std::string vertex_shader_path, std::string fragment_shader_path, std::string shader_name) {
	string vertexShaderSource{ FileUtils::readFile(vertex_shader_path) };
	const char* c_vertexShaderSource = vertexShaderSource.c_str();
	string fragmentShaderSource{ FileUtils::readFile(fragment_shader_path) };
	const char* c_fragmentShaderSource = fragmentShaderSource.c_str();

	GLenum ErrorCheckValue = glGetError();

	GLuint VertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(VertexShaderId, 1, &c_vertexShaderSource, NULL);
	glCompileShader(VertexShaderId);
	checkCompileError(VertexShaderId);

	GLuint FragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(FragmentShaderId, 1, &c_fragmentShaderSource, NULL);
	glCompileShader(FragmentShaderId);
	checkCompileError(FragmentShaderId);

	GLuint ProgramId = glCreateProgram();
	glAttachShader(ProgramId, VertexShaderId);
	glAttachShader(ProgramId, FragmentShaderId);
	glLinkProgram(ProgramId);

	ErrorCheckValue = glGetError();
	if (ErrorCheckValue != GL_NO_ERROR)
	{
		cout << "Error creating shader program: " << ErrorCheckValue << endl;

		exit(-1);
	}

	ShaderProgram shad{ VertexShaderId, FragmentShaderId, ProgramId };

	GLint uniforms = 0;
	glGetProgramiv(ProgramId, GL_ACTIVE_UNIFORMS, &uniforms);
	for (GLint i = 0; i < uniforms; i++) {
		int name_len = -1, num = -1;
		GLenum type = GL_ZERO;
		char name[100];
		glGetActiveUniform(ProgramId, GLuint(i), sizeof(name) - 1, &name_len, &num, &type, name);
		shad.putUniformLoc(name, glGetUniformLocation(ProgramId, name));
	}

	ZeluEngine::getInstance().putShaderProgram(shader_name, shad);
}

void ShaderFactory::checkCompileError(GLuint shader) {
	GLint isCompiled = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(shader, maxLength, &maxLength, &errorLog[0]);
		cout << "SHADER ERROR:\n" << string{ errorLog.begin(), errorLog.end() } << endl;

		// Provide the infolog in whatever manor you deem best.
		// Exit with failure.
		glDeleteShader(shader); // Don't leak the shader.
		exit(-1);
	}
}