// ゲームマネージャー
#pragma once
#include "common.h"

class Player;
class Stage;

class GameManager
{
public:
	GameManager();
	virtual ~GameManager();

	void init();
	void end();
	void update();
	void draw();

	// 当たり判定
	void collision();			// 全体
	void collisionR();			// 右
	void collisionL();			// 左
	void collisionUP();			// 上
	void collisionBottom();		// 下

private:

	bool colL;
	bool colR;
	bool colUp;
	bool colDown;

	Player* m_pPlayer;
	Stage* m_pStage;
};

