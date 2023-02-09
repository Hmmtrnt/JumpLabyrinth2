// エネミー
#pragma once
#include "../Util/common.h"

class Shot
{
public:
	Shot();
	virtual ~Shot();

	void init(int posX, int posY);		// 初期化(初期化)
	void end();			// 終了
	void update();		// 更新
	void draw(int &posX, int &posY);		// 描画

	void shotRight(int posX, int posY, int sizeX ,int stagePosX);			// 右
	void shotLeft(int &posX, int &stagePosX);					// 左
	void shotUp(int posX, int posY, int stagePosY);				// 上
	void shotBottom(int &posY, int &sizeY, int &stagePosY);		// 下

	// 弾の位置
	int m_posX;
	int m_posY;

private:
	// 画像ハンドル
	int m_handle;

	// 回転率
	float m_rota;

	// 弾の速さ
	int m_speedX;
	int m_speedY;

	int m_frameCount;
};