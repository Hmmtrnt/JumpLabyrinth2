// ステージ16
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class GameManager;

class SceneStage16 : public SceneBase
{
public:
	SceneStage16();
	virtual ~SceneStage16();

	virtual void init();			// 初期化
	virtual void end();				// 終了
	virtual SceneBase* update();	// 更新
	virtual void draw();			// 描画

private:
	// ゲームマネージャーポインタ
	GameManager* m_pManager;

	// フレームカウント
	int m_frameCount;
	// キャラの座標
	int m_posX;				// X座標
	int m_posY;				// Y座標
	// キャラの移動フレーム
	int m_frameX;			// X座標
	int m_frameY;			// Y座標
};

