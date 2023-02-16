// セレクト画面
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"
#include <vector>

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

	// ステージ数
	int m_stageNum;
	int m_stageNum2;

	// セレクト項目の位置
	int m_selectPos;

	// タイトル画面に戻るかどうか
	bool m_pushTitle;

	Back* m_pBack;

	//std::vector<int> m_stageNum;

};