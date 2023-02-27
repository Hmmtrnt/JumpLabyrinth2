// ステージ1ファイル
#pragma once
//#include "SceneBase.h"
#include "SceneStageBase.h"

class SceneStage1 : public SceneStageBase
{
public:
	SceneStage1(){}
	virtual ~SceneStage1(){}

	virtual void init();			// 初期化
	virtual void end();				// 終了
	virtual SceneBase* update();	// 更新
	virtual void draw();			// 描画
};

