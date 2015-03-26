#pragma once
#include <iostream>
#include <GL\glew.h>

#include "FileUtils.h"
#include "ShaderProgram.h"

using namespace std;

class ShaderFactory {

public:
	ShaderFactory();

	ShaderProgram createShader(string vertexShaderPath, string fragmentShaderPath);

private:
	void checkCompileError(GLuint shader);

};