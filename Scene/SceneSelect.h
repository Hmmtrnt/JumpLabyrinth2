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

	void difficultyDraw();	// 難易度表示
	void difficulty1Draw();	// 難易度1
	void difficulty2Draw();	// 難易度2
	void difficulty3Draw();	// 難易度3
	void difficulty4Draw();	// 難易度4
	void difficulty5Draw();	// 難易度5
	void difficulty6Draw();	// 難易度6

	// テキストハンドル
	int m_textHandle;
	int m_textHandle2;

	// 現存するステージ数
	int m_createStage;

	// ステージ数
	int m_stageNum;
	int m_stageNumText;

	// セレクト項目の位置
	int m_selectPos;

	// カーソルの示す座標
	int m_cursorX;		// X座標
	int m_cursorY;		// Y座標

	// カーソルの表示位置
	int m_cursorPosX;	// X座標
	int m_cursorPosY;	// Y座標
	int m_cursorPosW;	// 横幅
	int m_cursorPosH;	// 縦幅

	// ステージハンドル
	int m_stageH1;
	int m_stageH2;
	int m_stageH3;
	int m_stageH4;
	int m_stageH5;
	int m_stageH6;
	int m_stageH7;
	int m_stageH8;
	int m_stageH9;
	int m_stageH10;
	int m_stageH11;
	int m_stageH12;
	int m_stageH13;
	int m_stageH14;
	int m_stageH15;
	int m_stageH16;
	int m_stageH17;
	int m_stageH18;
	int m_stageH19;
	int m_stageH20;

	// 選択されているステージハンドル
	int m_centerStageH;

	// 難易度を表示する星ハンドル
	int m_starTest;

	// ボタンの描画ハンドル
	int m_buttonHandle;

	// 音ハンドル
	int m_cursorSound;		// カーソル移動音
	int m_decideSound;		// 決定音
	int m_backGroundSound;	// bgm

	// bgmが鳴っているか真偽
	bool m_playSound;
	// タイトル画面に戻るか真偽
	bool m_pushTitle;

	Back* m_pBack;
};