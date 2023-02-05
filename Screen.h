#pragma once
#include <Novice.h>
#include "Vec2.h"
#include "Quad.h"
#include "Matrix3x3.h"
#include "Circle.h"
#include "Randam.h"

static const int SCREEN_WIDTH = 480;
static const int SCREEN_HEIGHT = 960;
const int Floor = 0;

class Screen
{
public:

	Matrix3x3 cameraMatrix;
	Matrix3x3 viewMatrix;
	Matrix3x3 orthoMatrix;
	Matrix3x3 viewportMatrix;
	Matrix3x3 wvpVpMatrix;
	Quad cameraQuad;
	Quad screenQuad;
	Quad viewportQuad;

	int width;
	int height;
	Vec2 worldCenter;
	Vec2 initialCameraPos;
	Vec2 scroll;
	Vec2 screenShake;
	Vec2 screenShakeNum;
	Vec2 screenSaveShakeNum;
	int shakeFrame;
	//どこからスクロールするか
	Vec2 scrollFixedValue;
	//マップの横幅がスクリーンの幅何枚ぶんか
	int mapSheetsNum;


	Vec2 zoom;

	Screen();
	//スクロール
	void Update();
	//シェイク
	void SetShake(int x, int y , int frame);
	void ShakeSetZero();
	//ポーズ
	bool isPause;

	/// <summary>
	/// 四角形を描画する
	/// </summary>
	/// <param name="x">描画する四角形の左上座標 X</param>
	/// <param name="y">描画する四角形の左上座標 Y</param>
	/// <param name="w">描画する四角形の横幅</param>
	/// <param name="h">描画する四角形の縦幅</param>
	/// <param name="angle">描画する四角形の回転角</param>
	/// <param name="color">描画する四角形の色</param>
	/// <param name="fillMode">塗りつぶしモード</param>
	/// <param name="shake">shakeするか</param>
	void DrawBox(float x, float y, int w, int h, float angle, unsigned int color, FillMode fillMode,bool shake = true);
	
	/// <summary>
	/// 四角形を描画する
	/// </summary>
	/// <param name="quad">描画する四角形</param>
	/// <param name="angle">描画する四角形の回転角</param>
	/// <param name="color">描画する四角形の色</param>
	/// <param name="fillMode">塗りつぶしモード</param>
	/// <param name="shake">shakeするか</param>
	void DrawBox(const Quad& quad, float angle, unsigned int color, FillMode fillMode, bool shake = true);

	/// <summary>
	/// 三角形を描画する
	/// </summary>
	/// <param name="x1">描画する三角形の頂点1 X</param>
	/// <param name="y1">描画する三角形の頂点1 Y</param>
	/// <param name="x2">描画する三角形の頂点2 X</param>
	/// <param name="y2">描画する三角形の頂点2 Y</param>
	/// <param name="x3">描画する三角形の頂点3 X</param>
	/// <param name="y3">描画する三角形の頂点3 Y</param>
	/// <param name="color">描画する三角形の色</param>
	/// <param name="fillMode">塗りつぶしモード</param>
	/// <param name="shake">shakeするか</param>
	void DrawTriangle(float x1, float y1, float x2, float y2, float x3, float y3, unsigned int color, FillMode fillMode, bool shake = true);
	/// <summary>
	/// 線を描画する
	/// </summary>
	/// <param name="x1">描画する線の始点座標 X</param>
	/// <param name="y1">描画する線の始点座標 Y</param>
	/// <param name="x2">描画する線の終点座標 X</param>
	/// <param name="y2">描画する線の終点座標 Y</param>
	/// <param name="color">描画する三角形の色</param>
	/// <param name="shake">shakeするか</param>
	void DrawLine(float x1, float y1, float x2, float y2, unsigned int color, bool shake = true);
	/// <summary>
	/// 楕円を描画する
	/// </summary>
	/// <param name="x">楕円の中心座標 X</param>
	/// <param name="y">楕円の中心座標 Y</param>
	/// <param name="radiusX">楕円の半径 X</param>
	/// <param name="radiusY">楕円の半径 Y</param>
	/// <param name="angle">楕円の回転角(rad)</param>
	/// <param name="color">楕円の色</param>
	/// <param name="shake">shakeするか</param>
	void DrawEllipse(float x, float y, float radiusX, float radiusY, float angle, unsigned int color, FillMode fillMode, bool shake = true);
	/// <summary>
	/// 楕円を描画する
	/// </summary>
	/// <param name="a">楕円の中心座標 </param>
	/// <param name="radiusX">楕円の半径 X</param>
	/// <param name="radiusY">楕円の半径 Y</param>
	/// <param name="angle">楕円の回転角(rad)</param>
	/// <param name="color">楕円の色</param>
	/// <param name="shake">shakeするか</param>
	void DrawEllipse(const Vec2& a, float radiusX, float radiusY, float angle, unsigned int color, FillMode fillMode, bool shake = true);
	/// <summary>
	/// 楕円を描画する
	/// </summary>
	/// <param name="a">楕円の中心座標 </param>
	/// <param name="angle">楕円の回転角(rad)</param>
	/// <param name="color">楕円の色</param>
	/// <param name="shake">shakeするか</param>
	void DrawEllipse(const Circle& a, float angle, unsigned int color, FillMode fillMode, bool shake = true);
	/// <summary>
	/// スプライトを描画する
	/// </summary>
	/// <param name="x">描画するスプライトの左上座標 X</param>
	/// <param name="y">描画するスプライトの左上座標 Y</param>
	/// <param name="textureHandle">テクスチャのハンドル</param>
	/// <param name="scale">描画するスプライトの倍率 X</param>
	/// <param name="scale">描画するスプライトの倍率 Y</param>
	/// <param name="angle">描画するスプライトの回転角</param>
	/// <param name="color">描画するスプライトの色</param>
	/// <param name="shake">shakeするか</param>
	void DrawSprite(int x, int y, int textureHandle, float scaleX, float scaleY, float angle, unsigned int color, bool shake = true);
	/// <summary>
	/// スプライトの指定矩形部分のみを描画を描画する
	/// </summary>
	/// <param name="x">描画するスプライトの左上座標 X</param>
	/// <param name="y">描画するスプライトの左上座標 X</param>
	/// <param name="srcX">画像上の描画したい範囲左上座標 X</param>
	/// <param name="srcY">画像上の描画したい範囲左上座標 Y</param>
	/// <param name="srcW">画像上の描画したい範囲横幅</param>
	/// <param name="srcH">画像上の描画したい範囲縦幅</param>
	/// <param name="textureHandle">テクスチャのハンドル</param>
	/// <param name="scale">描画するスプライトの倍率 X</param>
	/// <param name="scale">描画するスプライトの倍率 Y</param>
	/// <param name="angle">描画するスプライトの回転角</param>
	/// <param name="color">描画するスプライトの色</param>
	/// <param name="shake">shakeするか</param>
	void DrawSpriteRect(int x, int y, int srcX, int srcY, int srcW, int srcH, int textureHandle, float scaleX, float scaleY, float angle, unsigned int color, bool shake = true);
	/// <summary>
	/// 四角形描画
	/// </summary>
	/// <param name="x1">描画する四角形の左上座標 X</param>
	/// <param name="y1">描画する四角形の左上座標 Y</param>
	/// <param name="x2">描画する四角形の右上座標 X</param>
	/// <param name="y2">描画する四角形の右上座標 Y</param>
	/// <param name="x3">描画する四角形の左下座標 X</param>
	/// <param name="y3">描画する四角形の左下座標 Y</param>
	/// <param name="x4">描画する四角形の右下座標 X</param>
	/// <param name="y4">描画する四角形の右下座標 Y</param>
	/// <param name="srcX">画像上の描画したい範囲左上座標 X</param>
	/// <param name="srcY">画像上の描画したい範囲左上座標 Y</param>
	/// <param name="srcW">画像上の描画したい範囲横幅</param>
	/// <param name="srcH">画像上の描画したい範囲縦幅</param>
	/// <param name="textureHandle">テクスチャのハンドル</param>
	/// <param name="color">描画するスプライトの色</param>
	/// <param name="shake">shakeするか</param>
	void DrawQuad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, int srcX, int srcY, int srcW, int srcH, int textureHandle, unsigned int color, bool shake = true);
	/// <summary>
	/// 四角形描画
	/// </summary>
	/// <param name="quad">描画する四角形</param>
	/// <param name="srcX">画像上の描画したい範囲左上座標 X</param>
	/// <param name="srcY">画像上の描画したい範囲左上座標 Y</param>
	/// <param name="srcW">画像上の描画したい範囲横幅</param>
	/// <param name="srcH">画像上の描画したい範囲縦幅</param>
	/// <param name="textureHandle">テクスチャのハンドル</param>
	/// <param name="color">描画するスプライトの色</param>
	/// <param name="isFlip">反転するか</param>
	/// <param name="shake">shakeするか</param>
	void DrawQuad(const Quad& quad, int srcX, int srcY, int srcW, int srcH, int textureHandle, unsigned int color, bool isFlip = false, bool shake = true);
	/// <summary>
	/// スクリーン座標で四角形描画
	/// </summary>
	/// <param name="quad">描画する四角形</param>
	/// <param name="srcX">画像上の描画したい範囲左上座標 X</param>
	/// <param name="srcY">画像上の描画したい範囲左上座標 Y</param>
	/// <param name="srcW">画像上の描画したい範囲横幅</param>
	/// <param name="srcH">画像上の描画したい範囲縦幅</param>
	/// <param name="textureHandle">テクスチャのハンドル</param>
	/// <param name="color">描画するスプライトの色</param>
	/// <param name="shake">shakeするか</param>
	void ScreenDrawQuad(const Quad& quad, int srcX, int srcY, int srcW, int srcH, int textureHandle, unsigned int color, bool shake = true);
	/// <summary>
	/// アニメーション四角形描画
	/// </summary>
	/// <param name="quad">描画する四角形</param>
	/// <param name="srcX">画像上の描画したい範囲左上座標 X（変数）</param>
	/// <param name="srcY">画像上の描画したい範囲左上座標 Y</param>
	/// <param name="srcW">画像上の描画したい範囲横幅</param>
	/// <param name="srcH">画像上の描画したい範囲縦幅</param>
	/// <param name="sheets">画像枚数</param>
	/// <param name="frame">何フレームで切り替えるか</param>
	/// <param name="animationframe">加算しているフレームの変数</param>
	/// <param name="textureHandle">テクスチャのハンドル</param>
	/// <param name="color">描画するスプライトの色</param>
	/// <param name="isFlip">反転するか</param>
	/// <param name="isAdd">アニメーションフレームを加算するか</param>
	/// <param name="isloop">ループするか</param>
	/// <param name="shake">shakeするか</param>
	void DrawQuadAnime(const Quad& quad, int& srcX, int srcY, int srcW, int srcH, int sheets, int frame, int& animationframe, int textureHandle, unsigned int color, bool isFlip = false ,bool isAdd = true ,bool isloop = true, bool shake = true);
	

	/// <summary>
	/// スクリーン座標でアニメーション四角形描画
	/// </summary>
	/// <param name="quad">描画する四角形</param>
	/// <param name="srcX">画像上の描画したい範囲左上座標 X（変数）</param>
	/// <param name="srcY">画像上の描画したい範囲左上座標 Y</param>
	/// <param name="srcW">画像上の描画したい範囲横幅</param>
	/// <param name="srcH">画像上の描画したい範囲縦幅</param>
	/// <param name="sheets">画像枚数</param>
	/// <param name="frame">何フレームで次の連番画像に移るか</param>
	/// <param name="animationframe">加算しているフレームの変数</param>
	/// <param name="textureHandle">テクスチャのハンドル</param>
	/// <param name="color">描画するスプライトの色</param>
	/// <param name="isFlip">反転をするか</param>
	/// <param name="isAdd">アニメーションフレームを加算するか</param>
	/// <param name="shake">shakeするか</param>
	void ScreenDrawQuadAnime(const Quad& quad, int& srcX, int srcY, int srcW, int srcH, int sheets, int frame, int& animationframe, int textureHandle, unsigned int color, bool hanten = false, bool isAdd = true, bool shake = true);
};


