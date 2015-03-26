#include "../../engine/headers/ShaderProgram.h"

ShaderProgram::ShaderProgram(GLuint vertexShaderId, GLuint fragmentShaderId, GLuint programId) {
	this->vertexShaderId = vertexShaderId;
	this->fragmentShaderId = fragmentShaderId;
	this->programId = programId;

	uniformsLocList = new map < string, GLuint > {};
}

void ShaderProgram::putUniformLoc(string name, GLuint locationId) {
	uniformsLocList->insert(std::pair< string, GLuint >(name, locationId));
}

GLuint ShaderProgram::getUniformLoc(string name) {
	return uniformsLocList->find(name)->second;
}

GLuint ShaderProgram::getProgramId() {
	return programId;
}