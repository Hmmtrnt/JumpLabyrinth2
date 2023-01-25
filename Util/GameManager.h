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
	void collisionTimeLag();	// 時間差で反応
	void collisionGameOver();	// ゲームオーバー

private:
	// ゲームオーバーのカウントダウン
	int m_GameOverCount;

	// ゲームオーバー
	bool GameOver;

	// 隣を通ったかどうか
	bool colNextFlag;
	bool colFlagL;
	bool colFlagR;
	bool colFlagUp;
	bool colFlagDown;

	// 当たり判定
	bool colL;			// 左
	bool colR;			// 右
	bool colUp;			// 上
	bool colDown;		// 下

	Player* m_pPlayer;
	Stage* m_pStage;
};

