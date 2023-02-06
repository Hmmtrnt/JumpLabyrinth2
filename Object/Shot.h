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

	void moveWidth(bool colL, bool colR);
	void moveHeight(bool colUp, bool colDown);

	// テスト関数
	void operation(bool colL, bool colR, bool colUp, bool colDown);


	// 弾の配列の位置
	int m_posX;			// X座標
	int m_posY;			// Y座標
	// 弾の移動フレーム
	int m_frameX;		// X座標
	int m_frameY;		// Y座標
	// 弾の移動速度
	int m_speedX;		// X座標
	int m_speedY;		// Y座標

	int m_stopFrame;	// 壁についたときに止まっている時間

	// 弾の配列の受け渡し
	int m_enemy[kVariable::ShotHeight][kVariable::ShotWidth];

private:
	// 弾の描画
	void shotDraw(int x, int y);

	int m_handleArrow;

};

