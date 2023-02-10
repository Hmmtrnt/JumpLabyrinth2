// エネミー
#pragma once
#include "../Util/common.h"

class Shot
{
public:
	Shot();
	virtual ~Shot();

	void init();		// 初期化(初期化)
	void end();			// 終了
	void update();		// 更新
	void draw(int &posX, int &posY);		// 描画

	// 射線
	void shotRight(int &posX, int &stagePosX);			// 右
	void shotLeft(int &posX, int &stagePosX);			// 左
	void shotUp(int &posY, int &stagePosY);				// 上
	void shotBottom(int &posY, int &stagePosY);			// 下

	// 射線②
	void shotRight2(int& posX, int& stagePosX);			// 右

	// 弾の位置
	int m_posX;
	int m_posY;

	int getSpeedX() { return m_speedX; }
	int getSpeedY() { return m_speedY; }

	// 弾の速さ
	int m_speedX;
	int m_speedY;
	int m_speedX2;
	int m_speedY2;
	int m_speedX3;

private:
	// 画像ハンドル
	int m_handle;

	// 回転率
	float m_rota;

	

	int m_frameCount;
};