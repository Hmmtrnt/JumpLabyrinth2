// シーンステージの基底クラス
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class GameManager;
class Back;

class SceneStageBase : public SceneBase
{
public:
	SceneStageBase();
	virtual ~SceneStageBase();

	virtual void init() = 0;			// 初期化
	virtual void end() = 0;				// 終了
	virtual SceneBase* update() = 0;	// 更新
	virtual void draw() = 0;			// 描画

protected:
	// ポインタ
	GameManager* m_pManager;	// ゲームマネージャー
	Back* m_pBack;				// 背景

	// フレームカウント
	int m_frameCount;
	// キャラの座標
	int m_posX;				// X座標
	int m_posY;				// Y座標
	// キャラの移動フレーム
	int m_frameX;			// X座標
	int m_frameY;			// Y座標
};

