#pragma once
#include <iostream>
#include <vector>
#include <GL\glew.h>

# include "Constants.h"
#include "../../engine/headers/ZeluEngine.h"

using namespace std;

class OriginLines {

public:
	OriginLines();
	~OriginLines();

	void openglMeshSetup();
	void draw();

private:
	GLuint VaoId, VboId;
	vector<float>* vertexData;
};