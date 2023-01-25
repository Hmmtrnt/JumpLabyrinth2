// エネミー
#pragma once
#include "../Util/common.h"

class Enemy
{
public:
	Enemy();
	virtual ~Enemy();

	void init();
	void end();
	void update();
	void draw();

	// エネミーの配列の位置
	int m_posX;			// X座標
	int m_posY;			// Y座標
	// エネミーの移動フレーム
	int m_flameX;		// X座標
	int m_flameY;		// Y座標
	// エネミーの移動速度
	int m_speedX;		// X座標
	int m_speedY;		// Y座標

	// プレイヤーの配列の受け渡し
	int m_enemy[ENEMY_HEIGHT][ENEMY_WIDTH];

private:

};

