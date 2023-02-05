#pragma once
#include "Vec2.h"
class Quad {
public:
	Vec2 LeftTop;
	Vec2 RightTop;
	Vec2 LeftBottom;
	Vec2 RightBottom;

public:

	Quad();
	/// <summary>
	/// 0,0中心
	/// </summary>
	/// <param name="width">横幅</param>
	/// <param name="height">縦幅</param>
	Quad(int width, int height);
	Quad(Vec2 LeftTop, Vec2 RightTop, Vec2 LeftBottom, Vec2 RightBottom);
	Quad(Vec2 LeftTop, int width, int height);
	Quad(int width, int height,Vec2 pos);

	/// <summary>
	/// 横幅
	/// </summary>
	/// <returns></returns>
	float GetWidth() const { return RightTop.DistanceFrom(LeftTop); }
	/// <summary>
	/// 縦幅
	/// </summary>
	/// <returns></returns>
	float GetHeight() const { return LeftTop.DistanceFrom(LeftBottom); }

	/// <summary>
	/// 真ん中(斜め無理)
	/// </summary>
	/// <returns></returns>
	Vec2 GetCenter() const { return { LeftTop.x + GetWidth() / 2.0f,LeftTop.y - GetHeight() / 2.0f }; }

	/// <summary>
	/// 幅に足す
	/// </summary>
	/// <param name="add">足す値</param>
	void WidthAdd(float add);

	/// <summary>
	/// 高さに足す
	/// </summary>
	/// <param name="add">足す値</param>
	void VerticalAdd(float add);

	/// <summary>
	/// 幅と高さに足す
	/// </summary>
	/// <param name="add">足す値</param>
	void WidthVerticalAdd(float add);

	Quad operator + (const Vec2& s) const;
	Quad operator - (const Vec2& s) const;
	Quad operator * (const float& s)const;
	Quad operator * (const Matrix3x3& s)const;
};

