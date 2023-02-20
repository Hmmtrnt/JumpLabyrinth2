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

	// ヘルプ描画
	void drawHelp();
	void drawExplan2_5();
	void drawExplan6();
	void drawExplan7_10();
	void drawExplan11();
	void drawExplan12_15();
	void drawExplan16();
	void drawExplan17_20();

private:
	// 背景配列のサイズ取得
	int m_back[kVariable::BackHeight][kVariable::BackWidth];
	// 背景ハンドル
	int m_handle;
	// 切り取る左上の頂点
	int m_verX;			// 横
	int m_verY;			// 縦

	// テキストハンドル
	int m_textHandle;

	// ギミック描画のハンドル
	int m_gimmickHandle;
	int m_gimmickHandle2;
};