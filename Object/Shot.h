// エネミー
#pragma once
#include "../Util/common.h"

class Shot
{
public:
	Shot();
	virtual ~Shot();

	void init();
	void end();
	void update();
	void draw();

	void moveWidth(bool colL, bool colR);
	void moveHeight(bool colUp, bool colDown);

	// テスト関数
	void operation(bool colL, bool colR, bool colUp, bool colDown);


	// エネミーの配列の位置
	int m_posX;			// X座標
	int m_posY;			// Y座標
	// エネミーの移動フレーム
	int m_frameX;		// X座標
	int m_frameY;		// Y座標
	// エネミーの移動速度
	int m_speedX;		// X座標
	int m_speedY;		// Y座標

	int m_stopFrame;	// 壁についたときに止まっている時間

	// エネミーの配列の受け渡し
	int m_enemy[SHOT_HEIGHT][SHOT_WIDTH];

private:
	
	int m_handleArrow;

};

