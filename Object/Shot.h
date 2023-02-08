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
	void draw();		// 描画

private:
	// 画像ハンドル
	int m_handle;

	// 弾の位置
	int m_posX;
	int m_posY;

	// 弾の速さ
	int m_speedX;
	int m_speedY;
};