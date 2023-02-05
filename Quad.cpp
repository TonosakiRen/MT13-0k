#include "Quad.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Matrix3x3.h"

Quad::Quad() {

}

Quad::Quad(int width, int height) {
	this->LeftTop = {-width / 2.0f ,height / 2.0f};
	this->RightTop = { width / 2.0f ,height / 2.0f };
	this->LeftBottom = { -width / 2.0f ,-height / 2.0f };
	this->RightBottom = { width / 2.0f ,-height / 2.0f };

}

Quad::Quad(Vec2 LeftTop, Vec2 RightTop, Vec2 LeftBottom, Vec2 RightBottom) {
	this->LeftTop = LeftTop;
	this->RightTop = RightTop;
	this->LeftBottom = LeftBottom;
	this->RightBottom = RightBottom;

}

Quad::Quad(Vec2 LeftTop, int width, int height) {
	this->LeftTop = LeftTop;
	this->RightTop = { LeftTop.x + width,LeftTop.y };
	this->LeftBottom = { LeftTop.x ,LeftTop.y - height };
	this->RightBottom = { LeftTop.x + width ,LeftTop.y - height };

}

Quad::Quad(int width, int height , Vec2 pos) {
	this->LeftTop = Vec2{ -width / 2.0f ,height / 2.0f } + pos;
	this->RightTop = Vec2{ width / 2.0f ,height / 2.0f } + pos;
	this->LeftBottom = Vec2{ -width / 2.0f ,-height / 2.0f } + pos;
	this->RightBottom = Vec2{ width / 2.0f ,-height / 2.0f } + pos;

}

void Quad::WidthAdd(float add) {

	this->LeftTop.x = this->LeftTop.x - add / 2.0f;
	this->RightTop.x = this->RightTop.x + add / 2.0f;
	this->LeftBottom.x = this->LeftBottom.x - add / 2.0f;
	this->RightBottom.x = this->RightBottom.x + add / 2.0f;
}

void Quad::VerticalAdd(float add) {

	this->LeftTop.y = this->LeftTop.y + add / 2.0f;
	this->RightTop.y = this->RightTop.y + add / 2.0f;
	this->LeftBottom.y = this->LeftBottom.y - add / 2.0f;
	this->RightBottom.y = this->RightBottom.y - add / 2.0f;
}

void Quad::WidthVerticalAdd(float add) {

	this->LeftTop.x = this->LeftTop.x - add / 2.0f;
	this->RightTop.x = this->RightTop.x + add / 2.0f;
	this->LeftBottom.x = this->LeftBottom.x - add / 2.0f;
	this->RightBottom.x = this->RightBottom.x + add / 2.0f;
	this->LeftTop.y = this->LeftTop.y + add / 2.0f;
	this->RightTop.y = this->RightTop.y + add / 2.0f;
	this->LeftBottom.y = this->LeftBottom.y - add / 2.0f;
	this->RightBottom.y = this->RightBottom.y - add / 2.0f;
}


Quad Quad:: operator+(const Vec2& s) const {
	return{ this->LeftTop + s,this->RightTop + s ,this->LeftBottom + s ,this->RightBottom + s };
}

Quad Quad:: operator-(const Vec2& s) const {
	return{ this->LeftTop - s,this->RightTop - s ,this->LeftBottom - s ,this->RightBottom - s };
}

Quad Quad:: operator*(const float& s) const {
	return{ this->LeftTop * s,this->RightTop * s ,this->LeftBottom * s ,this->RightBottom * s };
}


Quad Quad:: operator*(const Matrix3x3& s) const {
	return{ this->LeftTop * s,this->RightTop * s ,this->LeftBottom * s ,this->RightBottom * s };
}