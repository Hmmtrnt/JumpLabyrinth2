// ステージ14
#pragma once
//#include "SceneBase.h"
#include "SceneStageBase.h"

class SceneStage15 : public SceneStageBase
{
public:
	SceneStage15();
	virtual ~SceneStage15(){}

	virtual void init();			// 初期化
	virtual SceneBase* update();	// 更新
	virtual void draw();			// 描画

private:
	// ヘルプを押したかの真偽
	bool m_pushHelp;
};