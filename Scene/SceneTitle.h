// タイトル画面
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class Back;
class Player;
class Stage;

class SceneTitle : public SceneBase
{
public:
	SceneTitle();
	virtual ~SceneTitle();

	virtual void init();			// 初期化
	virtual void end();				// 終了処理
	virtual SceneBase* update();	// 更新処理
	virtual void draw();			// 描画

private:
	// テキストハンドル
	int m_textHandle;
	// テキストの点滅
	int m_textFlashCount;		// フレーム
	int m_textShow;				// 表示
	int m_textHide;				// 非表示

	// フォントのデータ
	int m_fontTitle;			// タイトル
	int m_fontGuide;			// タイトル以外

	// プレイヤー座標
	int m_posX;			// X座標
	int m_posY;			// Y座標

	// 音のハンドル
	int m_pushSound;		// 押したとき
	int m_backGroundSound;	// bgm

	// 無操作時間
	int m_waitingTime;

	Back* m_pBack;
	Player* m_pPlayer;
	Stage* m_pStage;
};

