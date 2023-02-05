#include <Novice.h>
#include "Screen.h"
#include "Matrix3x3.h"
#include "Quad.h"
#include "Vec2.h"
Screen screen;
const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, SCREEN_WIDTH, SCREEN_HEIGHT);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Vec2 pos = { 160,960 };
	Vec2 pos2 = { 320,960 };

	Vec2 velocity = {0,0};
	Vec2 velocity2 = { 0,0 };

	Vec2 acceleration = { 0,0 };
	Vec2 acceleration2 = { 0,0 };

	float mass = 1;
	float mass2 = 1;

	float k = 0.6f;
	Vec2 gravity = {0.0f,-9.8f } ;
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {
			pos = { 160,960 };
			pos2 = { 320,960 };

			velocity = { 0,0 };
			velocity2 = { 0,0 };

			acceleration = { 0,0 };
			acceleration2 = { 0,0 };
		}

		Vec2 airResistance = { k * -velocity.x,k * -velocity.y };
		Vec2 airResistanceAccelerarion = airResistance / mass;

		acceleration = gravity + airResistanceAccelerarion;
		acceleration2 = gravity;

		velocity += (acceleration / 60.0f);
		velocity2 += (acceleration2 / 60.0f);

		pos += velocity ;
		pos2 += velocity2 ;

		screen.Update();
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		screen.DrawEllipse(pos, 10, 10, 0.0f, WHITE, kFillModeSolid);
		screen.DrawEllipse(pos2, 10, 10, 0.0f, WHITE, kFillModeSolid);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
