// ゲームマネージャー
#pragma once
#include "common.h"

class Player;
class Enemy;
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
	// プレイヤーとの
	void collision();			// 全体
	void collisionR();			// 右
	void collisionL();			// 左
	void collisionUP();			// 上
	void collisionBottom();		// 下
	void collisionBulge();		// 膨らんだら即死判定
	void collisionTimeLag();	// 時間差で反応
	void collisionEnemy();		// 敵
	void collisionGameOver();	// ゲームオーバー
	void collisionGameClear();	// ゲームクリア

	// エネミーとの
	void colEnemy();			// 全体
	void colEnemyR();			// 右
	void colEnemyL();			// 左
	void colEnemyUP();			// 上
	void colEnemyBottom();		// 下

	// ゲームオーバー
	bool GameOver;
	// ゲームクリア
	bool GameClear;


private:
	// しぼんだり、膨らんだりする処理
	void EnemyElasticity();

	// ギミックの当たり判定が変わる時間
	int m_gimmickFrame;
	// しぼんでいる時間
	int m_shrink;
	// 膨らんている時間
	int m_inflate;

	// ゲームオーバーのカウントダウン
	int m_GameOverCount;

	

	// 隣を通ったかどうか
	bool colNextFlag;
	bool colFlagL;
	bool colFlagR;
	bool colFlagUp;
	bool colFlagBottom;

	// プレイヤー当たり判定
	bool colL;			// 左
	bool colR;			// 右
	bool colUp;			// 上
	bool colBottom;		// 下

	// エネミー当たり判定
	bool colNL;			// 左
	bool colNR;			// 右
	bool colNUp;		// 上
	bool colNBottom;	// 下

	Player* m_pPlayer;
	Enemy* m_pEnemy;
	Stage* m_pStage;
};

