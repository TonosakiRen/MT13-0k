#pragma once
#include "Vec2.h"
class Circle {
public:

	Vec2 pos;
	float radius;
public:
	Circle();
	/// <summary>
	/// 引数ありコンストラクタ
	/// </summary>
	/// <param name="a">中心座標</param>
	/// <param name="b">半径</param>
	Circle(Vec2 a,float b);
};