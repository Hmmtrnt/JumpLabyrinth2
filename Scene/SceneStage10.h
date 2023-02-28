// ステージ10
#pragma once
//#include "SceneBase.h"
#include "SceneStageBase.h"

class SceneStage10 : public SceneStageBase
{
public:
	SceneStage10();
	virtual ~SceneStage10(){}

	virtual void init();			// 初期化
	virtual SceneBase* CreateRetryStage();	// シーンリトライ
	virtual SceneBase* update();	// 更新
	virtual void draw();			// 描画

private:
	// ヘルプを押したかの真偽
	bool m_pushHelp;
};

