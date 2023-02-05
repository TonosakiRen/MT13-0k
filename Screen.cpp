#include "Screen.h"
#include <math.h>

Screen::Screen() {
	width = SCREEN_WIDTH;
	height = SCREEN_HEIGHT;
	worldCenter.x = 0;
	worldCenter.y = SCREEN_HEIGHT;
	screenShake.setZero();
	screenShakeNum.setZero();
	screenSaveShakeNum.setZero();
	shakeFrame = 0;
	initialCameraPos = { SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 - Floor };
	scroll.setZero();
	scrollFixedValue = { SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 };
	mapSheetsNum = 2;
	isPause = false;
	zoom = { 1.0f, 1.0f };
	screenQuad = { SCREEN_WIDTH ,SCREEN_HEIGHT };
	viewportQuad = { {0,0},SCREEN_WIDTH,SCREEN_HEIGHT };
};

void Screen::Update() {

	//x軸スクロール
	//if (player.x >= scrollFixedValue.x && player.x <= stageWidth - (width - scrollFixedValue.x)) {
	//	scroll.x = player.x - scrollFixedValue.x;
	//}
	//if (player.x < scrollFixedValue.x) {
	//	scroll.x = 0;
	//}
	//if (player.x >= stageWidth - (width - scrollFixedValue.x)) {
	//	scroll.x = stageWidth - width;
	//}
	////y軸スクロール
	//if (true) {
	//	scroll.y = 0.0f;
	//}
	//shake
	if (isPause == false) {
		if (int(screenShakeNum.x) != 0 || int(screenShakeNum.y) != 0) {
			screenShake.x = Randam::RAND(-screenShakeNum.x / 2.0f, screenShakeNum.x / 2.0f);
			screenShake.y = Randam::RAND(-screenShakeNum.y / 2.0f, screenShakeNum.y / 2.0f);
			screenShakeNum = { screenShakeNum.x - screenSaveShakeNum.x / shakeFrame,screenShakeNum.y - screenSaveShakeNum.y / shakeFrame };
		}
	}
	Vec2 cameraPos = scroll + initialCameraPos;
	cameraMatrix = Matrix3x3::MakeWorldMatrix(1.0f, 1.0f, 0.0f, cameraPos);
	cameraQuad = screenQuad * cameraMatrix;
	viewMatrix = cameraMatrix.Inverse();
	orthoMatrix = Matrix3x3::MakeOrthographicMatrix(screenQuad);
	viewportMatrix = Matrix3x3::MakeViewportMatrix(viewportQuad);
	wvpVpMatrix = viewMatrix * orthoMatrix * viewportMatrix;

};

void Screen::SetShake(int x, int y, int frame) {
	screenShakeNum = { x * 1.0f,y * 1.0f };
	screenSaveShakeNum = { x * 1.0f,y * 1.0f };
	shakeFrame = frame;
}

void Screen::ShakeSetZero() {
	screenShake.setZero();
}

void Screen::DrawBox(float x, float y, int w, int h, float angle, unsigned int color, FillMode fillMode, bool shake) {
	Vec2 tmp(x, y);
	if (shake == true) {
		tmp = tmp + screenShake;
	}
	tmp = tmp * wvpVpMatrix ;
	Novice::DrawBox(static_cast<int>(tmp.x), static_cast<int>(tmp.y), w, h, angle, color, fillMode);
}

void Screen::DrawBox(const Quad& quad, float angle, unsigned int color, FillMode fillMode, bool shake) {
	Vec2 tmp(quad.LeftTop.x , quad.LeftTop.y);
	if (shake == true) {
		tmp = tmp + screenShake;
	}
	tmp = tmp * wvpVpMatrix ;
	Novice::DrawBox(static_cast<int>(tmp.x), static_cast<int>(tmp.y), static_cast<int>(quad.GetWidth()), static_cast<int>(quad.GetHeight()), angle, color, fillMode);
}

void Screen::DrawTriangle(float x1, float y1, float x2, float y2, float x3, float y3, unsigned int color, FillMode fillMode, bool shake) {
	Vec2 tmp1(x1 , y1 );
	Vec2 tmp2(x2 , y2 );
	Vec2 tmp3(x3 , y3 );
	if (shake == true) {
		tmp1 = tmp1 + screenShake;
		tmp2 = tmp2 + screenShake;
		tmp3 = tmp3 + screenShake;
	}
	tmp1 = tmp1 * wvpVpMatrix;
	tmp2 = tmp2 * wvpVpMatrix;
	tmp3 = tmp3 * wvpVpMatrix;
	Novice::DrawTriangle(static_cast<int>(tmp1.x), static_cast<int>(tmp1.y), static_cast<int>(tmp2.x), static_cast<int>(tmp2.y), static_cast<int>(tmp3.x), static_cast<int>(tmp3.y), color, fillMode);
}

void Screen::DrawLine(float x1, float y1, float x2, float y2, unsigned int color, bool shake) {
	Vec2 tmp1(x1, y1);
	Vec2 tmp2(x2, y2);
	if (shake == true) {
		tmp1 = tmp1 + screenShake;
		tmp2 = tmp2 + screenShake;
	}
	tmp1 = tmp1 * wvpVpMatrix;
	tmp2 = tmp2 * wvpVpMatrix;
	Novice::DrawLine(static_cast<int>(tmp1.x), static_cast<int>(tmp1.y), static_cast<int>(tmp2.x), static_cast<int>(tmp2.y), color);
}

void Screen::DrawEllipse(float x, float y, float radiusX, float radiusY, float angle, unsigned int color, FillMode fillMode, bool shake) {
	Vec2 tmp(x , y);
	if (shake == true) {
		tmp = tmp + screenShake;
	}
	tmp = tmp * wvpVpMatrix;
	Novice::DrawEllipse(static_cast<int>(tmp.x), static_cast<int>(tmp.y), static_cast<int>(radiusX * zoom.x), static_cast<int>(radiusY * zoom.y), angle, color, fillMode);
}

void Screen::DrawEllipse(const Vec2& a, float radiusX, float radiusY, float angle, unsigned int color, FillMode fillMode, bool shake) {
	Vec2 tmp(a.x, a.y);
	if (shake == true) {
		tmp = tmp + screenShake;
	}
	tmp = tmp * wvpVpMatrix ;
	Novice::DrawEllipse(static_cast<int>(tmp.x), static_cast<int>(tmp.y), static_cast<int>(radiusX * zoom.x), static_cast<int>(radiusY * zoom.y), angle, color, fillMode);
}

void Screen::DrawEllipse(const Circle& a, float angle, unsigned int color, FillMode fillMode, bool shake) {
	Vec2 tmp(a.pos.x, a.pos.y );
	if (shake == true) {
		tmp = tmp + screenShake;
	}
	tmp = tmp * wvpVpMatrix;
	Novice::DrawEllipse(static_cast<int>(tmp.x), static_cast<int>(tmp.y), static_cast<int>(a.radius * zoom.x), static_cast<int>(a.radius * zoom.y), angle, color, fillMode);
}

void Screen::DrawSprite(int x, int y, int textureHandle, float scaleX, float scaleY, float angle, unsigned int color, bool shake) {
	Vec2 tmp(static_cast<float>(x) , static_cast<float>(y));
	if (shake == true) {
		tmp = tmp + screenShake;
	}
	tmp = tmp * wvpVpMatrix;
	Novice::DrawSprite(static_cast<int>(x), static_cast<int>(y), textureHandle, scaleX, scaleY, angle, color);
}

void Screen::DrawSpriteRect(int x, int y, int srcX, int srcY, int srcW, int srcH, int textureHandle, float scaleX, float scaleY, float angle, unsigned int color, bool shake) {
	Vec2 tmp(static_cast<float>(x), static_cast<float>(y));
	if (shake == true) {
		tmp = tmp + screenShake;
	}
	tmp = tmp * wvpVpMatrix;
	Novice::DrawSpriteRect(static_cast<int>(tmp.x) , static_cast<int>(tmp.y) ,srcX, srcY, srcW, srcH, textureHandle, scaleX, scaleY, angle, color);
}

void Screen::DrawQuad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, int srcX, int srcY, int srcW, int srcH, int textureHandle, unsigned int color, bool shake) {
	Vec2 tmp1(x1 , y1 );
	Vec2 tmp2(x2 , y2 );
	Vec2 tmp3(x3 , y3 );
	Vec2 tmp4(x4 , y4 );
	if (shake == true) {
		tmp1 = tmp1 + screenShake;
		tmp2 = tmp2 + screenShake;
		tmp3 = tmp3 + screenShake;
		tmp4 = tmp4 + screenShake;
	}
	tmp1 = tmp1 * wvpVpMatrix ;
	tmp2 = tmp2 * wvpVpMatrix ;
	tmp3 = tmp3 * wvpVpMatrix ;
	tmp4 = tmp4 * wvpVpMatrix ;
	Novice::DrawQuad(static_cast<int>(tmp1.x), static_cast<int>(tmp1.y), static_cast<int>(tmp2.x), static_cast<int>(tmp2.y), static_cast<int>(tmp3.x), static_cast<int>(tmp3.y), static_cast<int>(tmp4.x), static_cast<int>(tmp4.y), srcX, srcY, srcW, srcH, textureHandle, color);
}

void Screen::DrawQuad(const Quad& quad, int srcX, int srcY, int srcW, int srcH, int textureHandle, unsigned int color, bool isFlip, bool shake) {
	Quad tmp = quad ;
	if (shake == true) {
		tmp = tmp + screenShake;
	}
	tmp = tmp * wvpVpMatrix;
	if (isFlip == false) {
		Novice::DrawQuad(static_cast<int>(tmp.LeftTop.x), static_cast<int>(tmp.LeftTop.y), static_cast<int>(tmp.RightTop.x), static_cast<int>(tmp.RightTop.y), static_cast<int>(tmp.LeftBottom.x), static_cast<int>(tmp.LeftBottom.y), static_cast<int>(tmp.RightBottom.x), static_cast<int>(tmp.RightBottom.y), srcX, srcY, srcW, srcH, textureHandle, color);
	}
	else {
		Novice::DrawQuad(static_cast<int>(tmp.RightTop.x), static_cast<int>(tmp.RightTop.y), static_cast<int>(tmp.LeftTop.x), static_cast<int>(tmp.LeftTop.y), static_cast<int>(tmp.RightTop.x), static_cast<int>(tmp.RightTop.y), static_cast<int>(tmp.LeftBottom.x), static_cast<int>(tmp.LeftBottom.y), srcX, srcY, srcW, srcH, textureHandle, color);
	}
}

void Screen::ScreenDrawQuad(const Quad& quad, int srcX, int srcY, int srcW, int srcH, int textureHandle, unsigned int color, bool shake) {
	Novice::DrawQuad(
		static_cast<int>(quad.LeftTop.x + screenShake.x), static_cast<int>(quad.LeftTop.y - screenShake.y),
		static_cast<int>(quad.RightTop.x + screenShake.x), static_cast<int>(quad.RightTop.y - screenShake.y),
		static_cast<int>(quad.LeftBottom.x + screenShake.x), static_cast<int>(quad.LeftBottom.y - screenShake.y),
		static_cast<int>(quad.RightBottom.x + screenShake.x), static_cast<int>(quad.RightBottom.y - screenShake.y),
		srcX, srcY, srcW, srcH, textureHandle, color);
}

void Screen::DrawQuadAnime(const Quad& quad, int& srcX, int srcY, int srcW, int srcH, int sheets, int frame, int& animationframe, int textureHandle, unsigned int color, bool isFlip, bool isAdd, bool isloop, bool shake)
{
	Quad tmp = quad;
	if (shake == true) {
		tmp = tmp + screenShake;
	}
	tmp = tmp * wvpVpMatrix;
	if (animationframe % frame == 0 && animationframe != 0) {
		if (isPause == false) {
			srcX += srcW;
		}
	}

	if (srcX >= srcW * sheets) {
		if (isloop == true) {
			srcX = 0;
		}
		else {
			srcX = srcW * (sheets - 1);
		}

	}
	if (isFlip == true) {
		Novice::DrawQuad(static_cast<int>(tmp.RightTop.x),
			static_cast<int>(tmp.RightTop.y),
			static_cast<int>(tmp.LeftTop.x),
			static_cast<int>(tmp.LeftTop.y),
			static_cast<int>(tmp.RightBottom.x),
			static_cast<int>(tmp.RightBottom.y),
			static_cast<int>(tmp.LeftBottom.x),
			static_cast<int>(tmp.LeftBottom.y),
			srcX, srcY, srcW, srcH, textureHandle, color);
	}
	else {
		Novice::DrawQuad(static_cast<int>(tmp.LeftTop.x),
			static_cast<int>(tmp.LeftTop.y),
			static_cast<int>(tmp.RightTop.x),
			static_cast<int>(tmp.RightTop.y),
			static_cast<int>(tmp.LeftBottom.x),
			static_cast<int>(tmp.LeftBottom.y),
			static_cast<int>(tmp.RightBottom.x), static_cast<int>(tmp.RightBottom.y)
			, srcX, srcY, srcW, srcH, textureHandle, color);
	}
	if (isPause == false) {
		if (isAdd = true) {
			animationframe++;
		}
	}
}

void Screen::ScreenDrawQuadAnime(const Quad& quad, int& srcX, int srcY, int srcW, int srcH, int sheets, int frame, int& animationframe, int textureHandle, unsigned int color, bool isFlip, bool isAdd, bool shake) {
	Quad tmp = quad;
	if (shake == true) {
		tmp = tmp + screenShake;
	}
	tmp = tmp * wvpVpMatrix;

	if (animationframe % frame == 0 && animationframe != 0) {

		srcX += srcW;

	}
	if (srcX >= srcW * sheets) {

		srcX = 0;

	}
	if (isFlip == false) {
		Novice::DrawQuad(static_cast<int>(tmp.LeftTop.x),
			static_cast<int>(tmp.LeftTop.y),
			static_cast<int>(tmp.RightTop.x),
			static_cast<int>(tmp.RightTop.y),
			static_cast<int>(tmp.LeftBottom.x),
			static_cast<int>(tmp.LeftBottom.y),
			static_cast<int>(tmp.RightBottom.x),
			static_cast<int>(tmp.RightBottom.y), srcX, srcY, srcW, srcH, textureHandle, color);
		
	
	}else {
		Novice::DrawQuad(static_cast<int>(tmp.RightTop.x),
			static_cast<int>(tmp.RightTop.y),
			static_cast<int>(tmp.LeftTop.x),
			static_cast<int>(tmp.LeftTop.y),
			static_cast<int>(tmp.RightBottom.x),
			static_cast<int>(tmp.RightBottom.y),
			static_cast<int>(tmp.LeftBottom.x),
			static_cast<int>(tmp.LeftBottom.y), srcX, srcY, srcW, srcH, textureHandle, color);
	}
	if (isPause == false) {
		if (isAdd = true) {
			animationframe++;
		}
	}
}
