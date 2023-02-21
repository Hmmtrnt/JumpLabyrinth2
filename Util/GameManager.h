// ゲームマネージャー
#pragma once
#include "common.h"
#include <memory>

class Player;
class Stage;
class Back;
class ScenePause;
class collisionStage;
class Shot;

class GameManager
{
public:
	GameManager();
	virtual ~GameManager();

	// 初期化一覧
	void initCommon();			// 共通の初期化

	void initManager(int posX, int posY, int frameX, int frameY, 
		const int stage[][kVariable::StageWidth], int stageHeight, int stageWidth);			// 初期化

	void initManagerInShot(int posX, int posY, int frameX, int frameY,
		const int stage[][kVariable::StageWidth], int stageHeight, int stageWidth);

	void end();					// 終了
	void update();				// 更新

	void updateTest(int &frameX, int &frameY);

	void updateNoShot();		// 弾の処理が入っていない更新
	void updatePause();			// ポーズ画面の更新処理
	void draw();				// 描画
	void drawInShot();			// 弾が入った描画

	// 当たり判定
	// プレイヤーとの
	void collision();			// 全体
	void collisionR();			// 右
	void collisionL();			// 左
	void collisionUP();			// 上
	void collisionBottom();		// 下
	void collisionBulge();		// 膨らんだら即死判定
	void collisionTimeLag();	// 時間差で反応
	
	void collisionGameOver();	// ギミック6:即死判定
	void collisionGameClear();	// ゲームクリア

	// 針の描画
	void drawNeedle();

	// ゲームオーバーモーション
	void GameOverMotion();


	// ポーズ画面の項目を押した情報取得
	int GetPushPause() { return m_pushPause; }

	// ゲームオーバー
	bool GameOver;
	// ゲームクリア
	bool GameClear;


private:
	// しぼんだり、膨らんだりする処理
	void EnemyElasticity();

	// どこの項目を選択したか
	int m_pushPause;
	// ギミックの当たり判定が変わる時間
	int m_gimmickFrame;
	// しぼんでいる時間
	int m_shrink;
	// 膨らんている時間
	int m_inflate;

	// ゲームオーバーのカウントダウン
	int m_GameOverCount;

	// フレームカウント
	int m_frameCountGameOver;

	// 針のグラフィックハンドル
	int m_handleNeedle;

	// 回転角度
	float m_rota;

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

	// ポーズボタンが押されたかどうか
	bool m_pushFlag;

	Player* m_pPlayer;
	Stage* m_pStage;
	Back* m_pBack;
	ScenePause* m_pPause;
	std::shared_ptr<collisionStage> m_pColStage;
	Shot* m_pShot;
};

