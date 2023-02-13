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
	void drawR(int &posX, int &posY);		// 右向き描画
	void drawL(int& posX, int& posY);		// 左向き描画
	void drawU(int& posX, int& posY);		// 上向き描画
	void drawB(int& posX, int& posY);		// 下向き描画
	void drawR2(int& posX, int& posY);		// 右向き描画②
	void drawL2(int& posX, int& posY);		// 左向き描画②

	// 変数の確認
	void drawTest();

	// 射線
	void shotRight(int &posX, int &stagePosX);			// 右
	void shotLeft(int &posX, int &stagePosX);			// 左
	void shotUp(int &posY, int &stagePosY);				// 上
	void shotBottom(int &posY, int &stagePosY);			// 下

	// 射線②
	void shotRight2(int& posX, int& stagePosX);			// 右
	void shotLeft2(int& posX, int& stagePosX);			// 左

private:
	// 弾の速さ
	int m_speedX;
	int m_speedY;
	int m_speedX2;
	int m_speedY2;
	int m_speedX3;
	int m_speedX4;

	// 画像ハンドル
	int m_handle;

	// 回転率
	float m_rota;

	// 発射するフレーム数
	int m_frameCount;

	// ポーズ画面を開いたかどうか
	bool m_pushPause;
};