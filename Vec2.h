#pragma once
struct Vec2
{
	/// メンバ変数

	float x; //成分x
	float y; //成分y



/// メンバ関数

	/// <summary>
	/// デフォルトコンストラクタ
	/// </summary>
	Vec2();


	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="nx"> x成分</param>
	/// <param name="ny"> y成分</param>
	 Vec2(float nx, float ny);

	/// <summary>
	/// 長さを求める関数
	/// </summary>
	/// <returns>float型</returns>
	float Length() const;

	/// <summary>
	/// 長さの2乗を求める関数
	/// </summary>
	/// <returns>float型</returns>
	float LengthSquare() const;

	/// <summary>
	/// ベクトルの角度
	/// </summary>
	/// <returns>float型</returns>
	float GetTheta() const;

	/// <summary>
	/// 引数のベクトルとの内積
	/// </summary>
	/// <param name="other"> Vec2</param>
	/// <returns>float型</returns>
	 float Dot(const Vec2& other) const;

	/// <summary>
	/// 引数のベクトルとの外積
	/// </summary>
	/// <param name="other"> Vec2</param>
	/// <returns>float型</returns>
	 float Cross(const Vec2& other) const;

	/// <summary>
	/// 引数のベクトルとの距離
	/// </summary>
	/// <param name="other"> Vec2</param>
	/// <returns>float型</returns>
	float DistanceFrom(const Vec2& other) const;

	/// <summary>
	/// 正規化
	/// </summary>
	/// <returns>Vec2型</returns>
	Vec2 Normalized() const;

	/// <summary>
	/// ゼロベクトルであるか
	/// </summary>
	/// <returns>true: 0である   false: 0でない</returns>
	 bool isZero() const;

	/// <summary>
	/// ゼロベクトルにする
	/// </summary>
	void setZero();

	/// <summary>
	/// ベクトルの回転
	/// </summary>
	/// <param name="t"> 回転角度ラジアン</param>
	/// <returns>Vec2型</returns>
	Vec2 Rotation(float t) const;

	/// <summary>
	/// ベクトルのベクトルを回転
	/// </summary>
	/// <param name="radius">半径</param>
	/// <param name="t">回転角度ラジアン</param>
	/// <returns></returns>
	Vec2 AroundRotation(float radius , float t) const;


	/// <summary>
	/// 単項 + 
	/// </summary>
	/// <returns>Vec2型</returns>
	Vec2 operator +() const;

	/// <summary>
	/// 単項 - 
	/// </summary>
	/// <returns>Vec2型</returns>
	 Vec2 operator -() const;

	/// <summary>
	/// 2項 + 
	/// </summary>
	/// <param name="other"> Vec2</param>
	/// <returns>Vec2型</returns>
	 Vec2 operator +(const Vec2& other) const;

	/// <summary>
	/// 2項 - 
	/// </summary>
	/// <param name="other"> Vec2</param>
	/// <returns>Vec2型</returns>
	 Vec2 operator -(const Vec2& other) const;

	/// <summary>
	/// 2項 * 
	/// </summary>
	/// <param name="s"> s倍</param>
	/// <returns>Vec2型</returns>
	Vec2 operator *(float s) const;

	/// <summary>
	/// 2項 / 
	/// </summary>
	/// <param name="s">  1 / s倍</param>
	/// <returns>Vec2型</returns>
	 Vec2 operator /(float s) const;

	/// <summary>
	/// 複合代入演算 +=
	/// </summary>
	/// <param name="other"> Vec2</param>
	/// <returns>Vec2型</returns>
	Vec2& operator +=(const Vec2& other);

	/// <summary>
	/// 複合代入演算 -=
	/// </summary>
	/// <param name="other"> Vec2</param>
	/// <returns>Vec2型</returns>
	Vec2& operator -=(const Vec2& other);

	/// <summary>
	/// 複合代入演算 *= 
	/// </summary>
	/// <param name="s"> s倍</param>
	/// <returns>Vec2型</returns>
	Vec2& operator *=(float s);

	/// <summary>
	/// 複合代入演算 /= 
	/// </summary>
	/// <param name="s"> 1 / s倍</param>
	/// <returns>Vec2型</returns>
	Vec2& operator /=(float s);


	/// <summary>
	/// 行列2x2とVEC2の掛け算
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Vec2 operator *(const class Matrix3x3& other) const;

};

