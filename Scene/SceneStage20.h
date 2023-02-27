// ステージ20
#pragma once
//#include "SceneBase.h"
#include "SceneStageBase.h"

class Shot;

class SceneStage20 : public SceneStageBase
{
public:
	SceneStage20();
	virtual ~SceneStage20();

	virtual void init();			// 初期化
	void initShot();				// 弾の初期化
	virtual void end();				// 終了
	virtual SceneBase* update();	// 更新
	virtual void draw();			// 描画

	void collisionShot();			// 弾の当たり判定

private:
	// ポインタ
	Shot* m_pShot;				// ショット

	// 弾の座標
	int m_shotPosX;			// X座標
	int m_shotPosY;			// Y座標
	int m_shotPosX2;		// X座標
	int m_shotPosY2;		// Y座標
	int m_shotPosX3;		// X座標
	int m_shotPosY3;		// Y座標
	int m_shotPosX4;		// X座標
	int m_shotPosY4;		// Y座標

	// 弾が壁に当たる座標
	int m_colShotY;			// Y座標
	int m_colShotX2;		// X座標
	int m_colShotX3;		// X座標
	int m_colShotY4;		// X座標

	// サイズ
	int m_size;
	// ショットのフレームカウント
	int m_frameCountShot;

	// ヘルプを押したかの真偽
	bool m_pushHelp;
};