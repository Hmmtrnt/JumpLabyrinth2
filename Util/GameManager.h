// ゲームマネージャー
#pragma once
#include "common.h"

class Player;
class Stage;
class Back;
class ScenePause;
class Shot;

class GameManager
{
public:
	GameManager();
	virtual ~GameManager();

	// 初期化一覧
	void initCommon();// 共通の初期化

	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="posX">プレイヤーの配列のX座標</param>
	/// <param name="posY">プレイヤーの配列のY座標</param>
	/// <param name="frameX">プレイヤーのフレーム座標のX座標</param>
	/// <param name="frameY">プレイヤーのフレーム座標のY座標</param>
	/// <param name="stage">ステージの配列</param>
	/// <param name="stageHeight">ステージの高さ</param>
	/// <param name="stageWidth">ステージの横幅</param>
	void initManager(int posX, int posY, int frameX, int frameY, 
		const int stage[][kVariable::StageWidth], int stageHeight, int stageWidth);

	void end();// 終了

	/// <summary>
	/// 全体的な更新処理
	/// </summary>
	/// <param name="frameX">プレイヤーのX座標</param>
	/// <param name="frameY">プレイヤーのY座標</param>
	void update(int &frameX, int &frameY);

	void updatePause();// ポーズ画面の更新処理
	void draw();// 描画

	// 当たり判定
	// プレイヤーとの
	void collision();// 全体
	void collisionR();// 右
	void collisionL();// 左
	void collisionUP();// 上
	void collisionBottom();// 下
	void collisionBulge();// ギミック5:膨らんだら即死判定
	void collisionTimeLag();// ギミック7:時間差で反応
	void collisionGameOver();// ギミック6:即死判定
	void collisionGameClear();// ゲームクリア

	// 針の描画
	void drawNeedle();

	// ゲームオーバーモーション
	void GameOverMotion();


	// ポーズ画面の項目を押した情報取得
	int GetPushPause() { return m_pushPause; }
	// ポーズボタンが押されたかの情報取得
	int GetPushPauseOpen() { return m_pushFlag; }

	// ゲームオーバー
	bool GameOver;
	// ゲームクリア
	bool GameClear;

	// プレイヤーがどのトラップにやられたか
	bool m_burnTrap;
	bool m_needleTrap;
	bool m_inflateTrap;

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

	// 時間差トラップのカウントダウン
	int m_timeLagCount;
	// ゲームオーバーになってからのカウント
	int m_gameOverCount;
	// フレームカウント
	int m_frameCountGameOver;

	// 針のグラフィックハンドル
	int m_handleNeedle;

	// 音のハンドル
	int m_goalSound;	// ゴール音
	int m_decideSound;	// 決定音

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

	// ポーズボタンが押されたかどうかの真偽
	bool m_pushFlag;

	// 音が流れたかどうかの真偽
	bool m_playSound;

	Player* m_pPlayer;
	Stage* m_pStage;
	Back* m_pBack;
	ScenePause* m_pPause;
	Shot* m_pShot;
};