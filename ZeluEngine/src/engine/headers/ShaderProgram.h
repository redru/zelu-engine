#pragma once
#include <GL\glew.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class ShaderProgram {

public:
	ShaderProgram(GLuint vertexShaderId, GLuint fragmentShaderId, GLuint programId);

	void putUniformLoc(string name, GLuint locationId);

	GLuint getUniformLoc(string name);

	GLuint getProgramId();

private:
	GLuint vertexShaderId, fragmentShaderId, programId;

	map<string, GLuint>* uniformsLocList;
};