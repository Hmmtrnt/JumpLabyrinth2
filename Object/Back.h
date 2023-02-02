#pragma once
#include "../Util/common.h"

class Back
{
public:
	Back();
	virtual ~Back();

	void init();		// 初期化
	void end();			// 終了
	void draw();		// 描画

private:
	// 背景配列のサイズ取得
	int m_back[BACK_HEIGHT][BACK_WIDTH];
	// 背景ハンドル
	int m_handle;
	// 切り取る左上の頂点
	int m_verX;			// 横
	int m_verY;			// 縦
};

