#define _USE_MATH_DEFINES
#include "Matrix3x3.h"
#include "Vec2.h"
#include "math.h"
#include <Novice.h>
Matrix3x3::Matrix3x3() {
	m[0][0] = 0;
	m[0][1] = 0;
	m[0][2] = 0;
	m[1][0] = 0;
	m[1][1] = 0;
	m[1][2] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 0;
};

Matrix3x3::Matrix3x3(float a, float b, float c, float d) {
	m[0][0] = a;
	m[0][1] = b;
	m[0][2] = 0;
	m[1][0] = c;
	m[1][1] = d;
	m[1][2] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
}

Matrix3x3::Matrix3x3(float a, float b, float c, float d, float e, float f, float g, float h, float i) {
	m[0][0] = a;
	m[0][1] = b;
	m[0][2] = c;
	m[1][0] = d;
	m[1][1] = e;
	m[1][2] = f;
	m[2][0] = g;
	m[2][1] = h;
	m[2][2] = i;
}

Matrix3x3 Matrix3x3::Inverse() {
	Matrix3x3 mat;
	float det;

	det = m[0][0] * m[1][1] * m[2][2] + m[0][1] * m[1][2] * m[2][0] + m[0][2] * m[1][0] * m[2][1] - m[0][2] * m[1][1] * m[2][0] - m[0][1] * m[1][0] * m[2][2] - m[0][0] * m[1][2] * m[2][1];

	mat.m[0][0] = m[1][1] * m[2][2] - m[1][2] * m[2][1];
	mat.m[0][1] = -(m[0][1] * m[2][2] - m[0][2] * m[2][1]);
	mat.m[0][2] = m[0][1] * m[1][2] - m[0][2] * m[1][1];
	mat.m[1][0] = -(m[1][0] * m[2][2] - m[1][2] * m[2][0]);
	mat.m[1][1] = m[0][0] * m[2][2] - m[0][2] * m[2][0];
	mat.m[1][2] = -(m[0][0] * m[1][2] - m[0][2] * m[1][0]);
	mat.m[2][0] = m[1][0] * m[2][1] - m[1][1] * m[2][0];
	mat.m[2][1] = -(m[0][0] * m[2][1] - m[0][1] * m[2][0]);
	mat.m[2][2] = m[0][0] * m[1][1] - m[0][1] * m[1][0];

	mat = mat * (1.0f / det);

	return mat;
}


Matrix3x3 Matrix3x3::operator +(const Matrix3x3& other) const {

	Matrix3x3 mat;
	mat.m[0][0] = this->m[0][0] + other.m[0][0];
	mat.m[0][1] = this->m[0][1] + other.m[0][1];
	mat.m[0][2] = this->m[0][2] + other.m[0][2];
	mat.m[1][0] = this->m[1][0] + other.m[1][0];
	mat.m[1][1] = this->m[1][1] + other.m[1][1];
	mat.m[1][2] = this->m[1][2] + other.m[1][2];
	mat.m[2][0] = this->m[2][0] + other.m[2][0];
	mat.m[2][1] = this->m[2][1] + other.m[2][1];
	mat.m[2][2] = this->m[2][2] + other.m[2][2];
	return mat;
}

Matrix3x3 Matrix3x3::operator -(const Matrix3x3& other) const {
	Matrix3x3 mat;
	mat.m[0][0] = this->m[0][0] - other.m[0][0];
	mat.m[0][1] = this->m[0][1] - other.m[0][1];
	mat.m[0][2] = this->m[0][2] - other.m[0][2];
	mat.m[1][0] = this->m[1][0] - other.m[1][0];
	mat.m[1][1] = this->m[1][1] - other.m[1][1];
	mat.m[1][2] = this->m[1][2] - other.m[1][2];
	mat.m[2][0] = this->m[2][0] - other.m[2][0];
	mat.m[2][1] = this->m[2][1] - other.m[2][1];
	mat.m[2][2] = this->m[2][2] - other.m[2][2];
	return mat;
}

Matrix3x3 Matrix3x3::operator *(const Matrix3x3& other) const {
	Matrix3x3 mat;
	mat.m[0][0] = this->m[0][0] * other.m[0][0] + this->m[0][1] * other.m[1][0] + this->m[0][2] * other.m[2][0];
	mat.m[0][1] = this->m[0][0] * other.m[0][1] + this->m[0][1] * other.m[1][1] + this->m[0][2] * other.m[2][1];
	mat.m[0][2] = this->m[0][0] * other.m[0][2] + this->m[0][1] * other.m[1][2] + this->m[0][2] * other.m[2][2];
	mat.m[1][0] = this->m[1][0] * other.m[0][0] + this->m[1][1] * other.m[1][0] + this->m[1][2] * other.m[2][0];
	mat.m[1][1] = this->m[1][0] * other.m[0][1] + this->m[1][1] * other.m[1][1] + this->m[1][2] * other.m[2][1];
	mat.m[1][2] = this->m[1][0] * other.m[0][2] + this->m[1][1] * other.m[1][2] + this->m[1][2] * other.m[2][2];
	mat.m[2][0] = this->m[2][0] * other.m[0][0] + this->m[2][1] * other.m[1][0] + this->m[2][2] * other.m[2][0];
	mat.m[2][1] = this->m[2][0] * other.m[0][1] + this->m[2][1] * other.m[1][1] + this->m[2][2] * other.m[2][1];
	mat.m[2][2] = this->m[2][0] * other.m[0][2] + this->m[2][1] * other.m[1][2] + this->m[2][2] * other.m[2][2];
	return mat;
}

Matrix3x3 Matrix3x3::operator *(const float& other) const {
	Matrix3x3 mat;
	mat.m[0][0] = m[0][0] * other;
	mat.m[0][1] = m[0][1] * other;
	mat.m[0][2] = m[0][2] * other;
	mat.m[1][0] = m[1][0] * other;
	mat.m[1][1] = m[1][1] * other;
	mat.m[1][2] = m[1][2] * other;
	mat.m[2][0] = m[2][0] * other;
	mat.m[2][1] = m[2][1] * other;
	mat.m[2][2] = m[2][2] * other;
	return mat;
}



Matrix3x3 Matrix3x3::Transpose(Matrix3x3& mat) {
	Matrix3x3 tmp;
	tmp.m[0][0] = mat.m[0][0];
	tmp.m[0][1] = mat.m[1][0];
	tmp.m[0][2] = mat.m[2][0];
	tmp.m[1][0] = mat.m[0][1];
	tmp.m[1][1] = mat.m[1][1];
	tmp.m[1][2] = mat.m[2][1];
	tmp.m[2][0] = mat.m[0][2];
	tmp.m[2][1] = mat.m[1][2];
	tmp.m[2][2] = mat.m[2][2];

	return tmp;
}
Matrix3x3 Matrix3x3::MakeTranslateMatrix(Vec2& a) {
	Matrix3x3 mat;
	mat.m[0][0] = 1;
	mat.m[0][1] = 0;
	mat.m[0][2] = 0;
	mat.m[1][0] = 0;
	mat.m[1][1] = 1;
	mat.m[1][2] = 0;
	mat.m[2][0] = a.x;
	mat.m[2][1] = a.y;
	mat.m[2][2] = 1;
	return mat;
}
Matrix3x3 Matrix3x3::MakeRotateMatrix(float theta) {
	Matrix3x3 mat;
	mat.m[0][0] = cosf(theta);
	mat.m[0][1] = sinf(theta);
	mat.m[0][2] = 0;
	mat.m[1][0] = -sinf(theta);
	mat.m[1][1] = cosf(theta);
	mat.m[1][2] = 0;
	mat.m[2][0] = 0;
	mat.m[2][1] = 0;
	mat.m[2][2] = 1;
	return mat;
}
Matrix3x3 Matrix3x3::MakeScaleMatrix(float k, float l) {
	Matrix3x3 mat;
	mat.m[0][0] = k;
	mat.m[0][1] = 0;
	mat.m[0][2] = 0;
	mat.m[1][0] = 0;
	mat.m[1][1] = l;
	mat.m[1][2] = 0;
	mat.m[2][0] = 0;
	mat.m[2][1] = 0;
	mat.m[2][2] = 1;
	return mat;
}
Matrix3x3 Matrix3x3::MakeWorldMatrix(float k, float l, float theta, Vec2& a) {
	Matrix3x3 S;
	S = MakeScaleMatrix(k, l);
	Matrix3x3 R;
	R = MakeRotateMatrix(theta);
	Matrix3x3 T;
	T = MakeTranslateMatrix(a);
	Matrix3x3 mat = S * R * T;
	return mat;
}

Matrix3x3 Matrix3x3::MakeOrthographicMatrix(Quad screen) {
	Matrix3x3 mat;
	mat.m[0][0] = 2.0f / (screen.RightTop.x - screen.LeftTop.x);
	mat.m[0][1] = 0.0f;
	mat.m[0][2] = 0.0f;
	mat.m[1][0] = 0.0f;
	mat.m[1][1] = 2.0f / (screen.LeftTop.y - screen.LeftBottom.y);
	mat.m[1][2] = 0.0f;
	mat.m[2][0] = (screen.LeftTop.x + screen.RightTop.x) / (screen.LeftTop.x - screen.RightTop.x);
	mat.m[2][1] = (screen.LeftTop.y + screen.LeftBottom.y) / (screen.LeftBottom.y - screen.LeftTop.y);
	mat.m[2][2] = 1.0f;
	return mat;
}

Matrix3x3 Matrix3x3::MakeViewportMatrix(Quad screen) {
	Matrix3x3 mat;
	mat.m[0][0] = screen.GetWidth() / 2.0f;
	mat.m[0][1] = 0.0f;
	mat.m[0][2] = 0.0f;
	mat.m[1][0] = 0.0f;
	mat.m[1][1] = -screen.GetHeight() / 2.0f;
	mat.m[1][2] = 0.0f;
	mat.m[2][0] = screen.LeftTop.x + (screen.GetWidth() / 2.0f);
	mat.m[2][1] = screen.LeftTop.y + (screen.GetHeight() / 2.0f);
	mat.m[2][2] = 1.0f;
	return mat;
}

void Matrix3x3::ScreenPrintf(int x, int y, Matrix3x3 matrix) {
	for (int row = 0; row < 3; ++row) {
		for (int column = 0; column < 3; ++column) {
			Novice::ScreenPrintf(x + column * kColumnWidth, y + row * kRowHeight, "%.02f", matrix.m[row][column]);
		}
	}
}
