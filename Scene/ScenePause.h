#pragma once
#include "../Util/common.h"


class ScenePause
{
public:
	ScenePause();
	virtual ~ScenePause();

	void init();			// 初期化
	void end();				// 終了
	void updatePause();		// ポーズ更新
	void drawPause();		// ポーズ表示

	void updateClearPause();// クリアポーズ更新
	void drawClearPause();	// クリアポーズ表示

	// 押した回数の情報取得
	int GetPushNum(){ return m_pushNum; }

private:
	// テキストハンドル
	int m_textHandle;
	// 矢印の位置
	int m_posCursor;		// ポーズ画面
	int m_posClearCursorY;	// クリア画面
	// 押した回数
	int m_pushNum;
	// クリア時のポーズ位置
	int m_posClearPauseX;		// 左上座標
	int m_posClearPauseY;
	int m_sizeClearPauseX;		// サイズ座標
	int m_sizeClearPauseY;
	int m_posClearTextX;		// クリアポーズ画面のテキスト座標
	int m_posClearCursorX;		// クリアポーズ画面のカーソル位置
	int m_posClearTextY1;		// 項目1
	int m_posClearTextY2;		// 2
	int m_posClearTextY3;		// 3
	int m_itemNum;

	// 音ハンドル
	int m_cursorSound;		// カーソル移動音
	int m_cursorNotSound;	// カーソル移動できない音

	bool isInit = false;
};