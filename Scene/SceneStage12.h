// ステージ12
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class GameManager;

class SceneStage12 : public SceneBase
{
public:
	SceneStage12();
	virtual ~SceneStage12();

	virtual void init();			// 初期化
	virtual void end();				// 終了
	virtual SceneBase* update();	// 更新
	virtual void draw();			// 描画

private:
	// ゲームマネージャーポインタ
	GameManager* m_pManager;

	// フレームカウント
	int m_frameCount;
};

