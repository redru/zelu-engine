#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <memory>
#include <math.h>
#include <vector>

#include <GL/glew.h>

using namespace std;

class MatrixUtils {

public:
	static const double PI;

	static float Cotangent(float angle);
	static float DegreesToRadians(float degrees);
	static float RadiansToDegrees(float radians);

	static void LoadIdentity(vector<float> &m);
	static void CopyMatrix(vector<float> &res, const vector<float> &src);

	static void MultiplyMatrices(vector<float> &res, const vector<float> &m1, const vector<float> &m2);
	static void RotateAboutX(vector<float> &m, float angle);
	static void RotateAboutY(vector<float> &m, float angle);
	static void RotateAboutZ(vector<float> &m, float angle);
	static void ScaleMatrix(vector<float> &m, float x, float y, float z);
	static void TranslateMatrix(vector<float> &m, float x, float y, float z);

	static void CreateProjectionMatrix(vector<float> &m, const float fovy, const float aspect_ratio, const float near_plane, const float far_plane);

private:
	const static vector<float>* identityMatrix;
	static vector<float>* p_suppMatrix;
	static vector<float>* mul_p_suppMatrix;

};