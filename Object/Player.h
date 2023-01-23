// プレイヤー
#pragma once
#include "../Util/common.h"

class Player
{
public:
	Player();
	virtual ~Player();

	void init();		// 初期化
	void end();			// 終了
	void update();		// 更新
	void draw();		// 描画

	// プレイヤー操作
	void operation(bool colL,bool colR, bool colUp, bool colDown);

	// プレイヤーの配列の位置
	int m_posX;			// X座標
	int m_posY;			// Y座標
	// プレイヤーの移動フレーム
	int m_flameX;		// X座標
	int m_flameY;		// Y座標
	
	int m_speedX;
	int m_speedY;

	// プレイヤーの配列の受け渡し
	int m_player[PLAYER_HEIGHT][PLAYER_WIDTH];

private:

};