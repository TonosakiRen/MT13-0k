#pragma once
#include "Quad.h"
static const int kRowHeight = 20;
static const int kColumnWidth = 55;

class Matrix3x3
{
public:

	float m[3][3];

public:

	//デフォルトコンストラクタ
	Matrix3x3();
	//引数ありコンストラクタ
	Matrix3x3(float a, float b, float c, float d);
	Matrix3x3(float a, float b, float c, float d, float e, float f, float g, float h, float i);

	Matrix3x3 Inverse();

	//行列の足し算
	Matrix3x3 operator +(const Matrix3x3& other) const;
	//行列の引き算
	Matrix3x3 operator -(const Matrix3x3& other) const;
	//行列の掛け算
	Matrix3x3 operator *(const Matrix3x3& other) const;
	//行列のスカラー倍
	Matrix3x3 operator *(const float& other) const;

	/// <summary>
	/// アフィン行列
	/// </summary>
	/// <param name="k">横幅倍率</param>
	/// <param name="l">縦幅倍率</param>
	/// <param name="theta">回転角度</param>
	/// <param name="a">ポジション</param>
	/// <returns></returns>
	static Matrix3x3 MakeWorldMatrix(float k, float l, float theta, Vec2& a);

	//転置
	static Matrix3x3 Transpose(Matrix3x3& mat);
	//平行移動行列
	static Matrix3x3 MakeTranslateMatrix(Vec2& a);
	//回転行列
	static Matrix3x3 MakeRotateMatrix(float theta);
	//拡縮行列
	static Matrix3x3 MakeScaleMatrix(float k, float l);

	//正射影行列
	static Matrix3x3 MakeOrthographicMatrix(Quad screen);

	//正射影行列
	static Matrix3x3 MakeViewportMatrix(Quad screen);

	
	//Matrix出力
	static void ScreenPrintf(int x, int y, Matrix3x3 matrix);

};



