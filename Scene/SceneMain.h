// メイン画面
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class GameManager;

class SceneMain : public SceneBase
{
public:
	SceneMain();
	virtual ~SceneMain();

	virtual void init();			// 初期化
	virtual void end();				// 終了処理
	virtual SceneBase* update();	// 更新処理
	virtual void draw();			// 描画処理

private:
	GameManager* m_pManager;
};