// ステージ5
#pragma once
//#include "SceneBase.h"
#include "SceneStageBase.h"

class SceneStage5 : public SceneStageBase
{
public:
	SceneStage5();
	virtual ~SceneStage5(){}

	virtual void init();			// 初期化
	virtual SceneBase* CreateRetryStage();	// シーンリトライ
	virtual SceneBase* update();	// 更新
	virtual void draw();			// 描画

private:
	// ヘルプを押したかの真偽
	bool m_pushHelp;
};

