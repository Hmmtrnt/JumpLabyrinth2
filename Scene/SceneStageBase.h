// シーンステージの基底クラス
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class GameManager;
class Shot;
class Back;

class SceneStageBase : public SceneBase
{
public:
	SceneStageBase();
	virtual ~SceneStageBase();

	virtual void init();				// 初期化
	virtual void end();					// 終了
	virtual SceneBase* update();		// 更新
	virtual void draw();				// 描画

	//virtual SceneBase* CreateRetryStage() = 0;	// シーン遷移の場所
	virtual SceneBase* updateBefore();// シーン遷移

	void playerInit();			// プレイヤーの初期化
	void stageInit();			// ステージの初期化
	void shotInit();			// ショットの初期化
	void updateGame();			// ゲームの更新処理
	void updateShot();			// ショットの処理
	void drawGuide();			// 各ステージのガイド描画
	void drawShot();			// ショットの描画
	void collisionShot();

protected:
	// ポインタ
	GameManager* m_pManager;	// ゲームマネージャー
	Back* m_pBack;				// 背景
	Shot* m_pShot;				// ショット

	// ステージを保存する
	//int m_stage[kVariable::StageWidth][kVariable::StageWidth];

	// キャラの座標
	int m_posX;				// X座標
	int m_posY;				// Y座標
	// キャラの移動フレーム
	int m_frameX;			// X座標
	int m_frameY;			// Y座標

	// 弾の座標
	int m_shotPosX;			// X座標
	int m_shotPosY;			// Y座標
	int m_shotPosX2;		// X座標
	int m_shotPosY2;		// Y座標
	int m_shotPosX3;		// X座標
	int m_shotPosY3;		// Y座標
	int m_shotPosX4;		// X座標
	int m_shotPosY4;		// Y座標
	int m_shotPosX5;		// X座標
	int m_shotPosY5;		// Y座標
	int m_shotPosX6;		// X座標
	int m_shotPosY6;		// Y座標

	// 弾が壁に当たる座標
	int m_colShotX;			// X座標
	int m_colShotY;			// Y座標
	int m_colShotX2;		// X座標
	int m_colShotY2;		// Y座標
	int m_colShotX3;		// X座標
	int m_colShotY3;		// Y座標
	int m_colShotX4;		// X座標
	int m_colShotY4;		// Y座標
	int m_colShotX5;		// X座標
	int m_colShotY5;		// Y座標
	int m_colShotX6;		// X座標
	int m_colShotY6;		// Y座標

	// サイズ
	int m_size;
	// ショットのフレームカウント
	int m_frameCountShot;

	// 画面効果用スクリーンハンドル
	int m_screenHandle;
	float m_quakeX;	// 横ブレ
	int m_quakeTime;
	// bgm
	int m_backGroundSound;

	// ブレの変数に代入したかどうか
	bool m_isAllocation;
	// ヘルプを押したかの真偽
	bool m_pushHelp;
	// ステージにショット処理が入っているかどうか
	bool m_inShot;
	// bgmが鳴っているかどうか
	bool m_playSound;
};

