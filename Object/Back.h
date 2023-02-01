#pragma once
#include "../Util/common.h"

class Back
{
public:
	Back();
	virtual ~Back();

	void init();
	void draw();

private:
	// 背景サイズ取得
	int m_back[BACK_HEIGHT][BACK_WIDTH];
	// 背景ハンドル
	int m_handle;
	// 切り取る左上の頂点
	int m_verX;
	int m_verY;
};

