#include "../../engine/headers/MatrixUtils.h"

// CONSTANTS -------------------------------------------------------------------------------------------------
const double MatrixUtils::PI = 3.14159265358979323846;

const vector<float>* MatrixUtils::identityMatrix = new vector<float> {
	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f
};
// IMPLEMENTATION ---------------------------------------------------------------------------------------------
vector<float>* MatrixUtils::p_suppMatrix(new vector<float>(16));
vector<float>* MatrixUtils::mul_p_suppMatrix(new vector<float>(16));

float MatrixUtils::Cotangent(float angle) {
	return (float)(1.0 / tan(angle));
}

float MatrixUtils::DegreesToRadians(float degrees) {
	return degrees * (float)(MatrixUtils::PI / 180);
}

float MatrixUtils::RadiansToDegrees(float radians) {
	return radians * (float)(180 / MatrixUtils::PI);
}

void MatrixUtils::LoadIdentity(vector<float> &m) {
	m = *identityMatrix;
}

void MatrixUtils::CopyMatrix(vector<float> &res, const vector<float> &src) {
	for (int w = 0; w < 16; w++) {
		res[w] = src[w];
	}
}

void MatrixUtils::MultiplyMatrices(vector<float> &res, const vector<float> &m1, const vector<float> &m2) {
	LoadIdentity(*mul_p_suppMatrix);
	unsigned int row, column, row_offset;

	for (row = 0, row_offset = 0; row < 4; row++, row_offset = row * 4) {
		for (column = 0; column < 4; ++column) {
			mul_p_suppMatrix->at(row_offset + column) =
				(m1[row_offset + 0] * m2[column + 0]) +
				(m1[row_offset + 1] * m2[column + 4]) +
				(m1[row_offset + 2] * m2[column + 8]) +
				(m1[row_offset + 3] * m2[column + 12]);
		}
	}

	res = *p_suppMatrix;
}

void MatrixUtils::ScaleMatrix(vector<float> &m, float x, float y, float z) {
	m[0] *= x;
	m[5] *= y;
	m[10] *= z;
}

void MatrixUtils::TranslateMatrix(vector<float> &m, float x, float y, float z) {
	m[3] += x;
	m[7] += y;
	m[11] += z;
}

void MatrixUtils::RotateAboutX(vector<float> &m, float angle) {
	LoadIdentity(*p_suppMatrix);
	float sine = (float)sin(angle);
	float cosine = (float)cos(angle);

	p_suppMatrix->at(5) = cosine;
	p_suppMatrix->at(6) = -sine;
	p_suppMatrix->at(9) = sine;
	p_suppMatrix->at(10) = cosine;

	MultiplyMatrices(m, *p_suppMatrix, m);
}

void MatrixUtils::RotateAboutY(vector<float> &m, float angle) {
	LoadIdentity(*p_suppMatrix);
	float sine = (float)sin(angle);
	float cosine = (float)cos(angle);

	p_suppMatrix->at(0) = cosine;
	p_suppMatrix->at(8) = sine;
	p_suppMatrix->at(2) = -sine;
	p_suppMatrix->at(10) = cosine;

	MultiplyMatrices(m, *p_suppMatrix, m);
}

void MatrixUtils::RotateAboutZ(vector<float> &m, float angle) {
	LoadIdentity(*p_suppMatrix);
	float sine = (float)sin(angle);
	float cosine = (float)cos(angle);

	p_suppMatrix->at(0) = cosine;
	p_suppMatrix->at(1) = -sine;
	p_suppMatrix->at(4) = sine;
	p_suppMatrix->at(5) = cosine;

	MultiplyMatrices(m, *p_suppMatrix, m);
}

void MatrixUtils::CreateProjectionMatrix(vector<float> &m, const float fovy, const float aspect_ratio, const float near_plane, const float far_plane) {
	LoadIdentity(*p_suppMatrix);

	const float
		y_scale = Cotangent(DegreesToRadians(fovy / 2)),
		x_scale = y_scale / aspect_ratio,
		frustum_length = far_plane - near_plane;

	p_suppMatrix->at(0) = x_scale;
	p_suppMatrix->at(5) = y_scale;
	p_suppMatrix->at(10) = -((far_plane + near_plane) / frustum_length);
	p_suppMatrix->at(11) = -1;
	p_suppMatrix->at(14) = -((2 * near_plane * far_plane) / frustum_length);

	m = *p_suppMatrix;
}