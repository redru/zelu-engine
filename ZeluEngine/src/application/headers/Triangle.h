#pragma once
#include <iostream>
#include <vector>
#include "GL\glew.h"
#include "../../engine/headers/ZeluEngine.h"

using namespace std;

class Triangle {

public:
	Triangle();
	~Triangle();

	void openglMeshSetup();
	void draw();

private:
	GLuint VaoId, VboId;
	vector<float>* vertexData;
};