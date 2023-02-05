#define _USE_MATH_DEFINES
#include <math.h>
#include "Vec2.h"
#include "Matrix3x3.h"
#include <assert.h>
Vec2::Vec2() : x(0), y(0) {

}

 Vec2::Vec2(float nx, float ny) : x(nx), y(ny) {

}

float Vec2::Length() const {
    return sqrtf(LengthSquare());
}

 float Vec2::LengthSquare() const {
    return Dot(*this);
}

 float Vec2::GetTheta() const {
     return atan2f(y,x);
}

 float Vec2::Dot(const Vec2& other) const {
    return x * other.x + y * other.y;
}

 float Vec2::Cross(const Vec2& other) const {
    return x * other.y - y * other.x;
}

float Vec2::DistanceFrom(const Vec2& other) const {
    return (other - *this).Length();
}

Vec2 Vec2::Normalized() const {
    if (Length() != 0)
        return *this / Length();
    else
        return *this;
}

bool Vec2::isZero() const {
    return x == 0.0 && y == 0.0;
}

void Vec2::setZero() {
    x = 0.0;
    y = 0.0;
}

Vec2 Vec2::Rotation(float t) const {
    return{ x * cosf(t) - y * sinf(t) ,x * sinf(t) + y * cosf(t) };
}

Vec2 Vec2::AroundRotation(float radius, float t) const {
    Vec2 tmp(radius, 0.0f);
     tmp= tmp.Rotation(t);
     tmp = tmp + *this;
    return{tmp};
}


 Vec2 Vec2::operator +() const {
    return *this;
}

 Vec2 Vec2::operator -() const {
    return{ -x, -y };
}

 Vec2 Vec2::operator +(const Vec2& other) const {
    return{ x + other.x, y + other.y };
}

Vec2 Vec2::operator -(const Vec2& other) const {
    return{ x - other.x, y - other.y };
}

Vec2 Vec2::operator *(float s) const {
    return{ x * s, y * s };
}

 Vec2 Vec2::operator /(float s) const {
    return{ x * 1 / s, y * 1 / s };
}

Vec2& Vec2::operator +=(const Vec2& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vec2& Vec2::operator -=(const Vec2& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vec2& Vec2::operator *=(float s) {
    x *= s;
    y *= s;
    return *this;
}

Vec2& Vec2::operator /=(float s) {
    x /= s;
    y /= s;
    return *this;
}

Vec2 Vec2::operator *(const Matrix3x3& other) const {
    Vec2 result;
    result.x = x * other.m[0][0] + y * other.m[1][0] + 1.0f * other.m[2][0];
    result.y = x * other.m[0][1] + y * other.m[1][1] + 1.0f * other.m[2][1];
    float w = x * other.m[0][2] + y * other.m[1][2] + 1.0f * other.m[2][2];
    assert(w != 0.0f);
    result.x /= w;
    result.y /= w;
    return result;
}