// セレクト画面
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class Back;

class SceneSelect : public SceneBase
{
public:
	SceneSelect();
	virtual ~SceneSelect();

	virtual void init();			// 初期化
	virtual void end();				// 終了処理
	virtual SceneBase* update();	// 更新処理
	virtual void draw();			// 描画

private:
	// ステージ選択時の数
	int m_stageSelect;
	// テキストハンドル
	int m_textHandle;
	int m_textHandle2;

	// 現存するステージ数
	int m_createStage;

	// タイトル画面に戻るかどうか
	bool m_pushTitle;

	Back* m_pBack;
};