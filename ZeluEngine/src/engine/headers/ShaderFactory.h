#pragma once
#include <iostream>
#include <GL\glew.h>

#include "ZeluEngine.h"
#include "FileUtils.h"
#include "ShaderProgram.h"

class ShaderFactory {

public:
	ShaderFactory();

	void createShader(std::string vertex_shader_path, std::string fragment_shader_path, std::string shader_name);

private:
	void checkCompileError(GLuint shader);

};