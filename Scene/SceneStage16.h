// ステージ16
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"
#include <memory>

class GameManager;
class Shot;
class Back;
class Player;

class SceneStage16 : public SceneBase
{
public:
	SceneStage16();
	virtual ~SceneStage16();

	virtual void init();			// 初期化
	void initShot();				// 弾を初期位置に戻す
	virtual void end();				// 終了
	virtual SceneBase* update();	// 更新
	virtual void draw();			// 描画

	void collisionShot();			// 弾の当たり判定

private:
	// ゲームマネージャーポインタ
	GameManager* m_pManager;
	Shot* m_pShot;
	Back* m_pBack;
	Player* m_pPlayer;

	// フレームカウント
	int m_frameCount;
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

	// サイズ
	int m_size;

	// フレームカウント
	int m_frameCountShot;
};

