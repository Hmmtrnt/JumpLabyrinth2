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

	void drawMenuGuide();		// メニュー表示方法描画
	void drawHelpGuide();		// ギミック説明表示方法描画

	

	// ヘルプ描画
	void drawHelp();				// ヘルプボタン誘導描画
	void drawExplan2_5();			// 2から5ステージのギミック説明描画
	void drawExplan6And10();		// 6と10ステージのギミック説明描画
	void drawExplan7_9();			// 7から9ステージのギミック説明描画
	void drawExplan11();			// 11ステージのギミック説明描画
	void drawExplan12_15();			// 12から15ステージのギミック説明描画
	void drawExplan16();			// 16ステージのギミック説明描画
	void drawExplan17_20();			// 17から20ステージのギミック説明描画

private:
	// ギミック説明の描画
	void drawExplanDeath(int posXHandle, int posYHandle,
		int posXText, int posYText);		// 即死
	void drawExplanLagTrap(int posXHandle, int posYHandle,
		int posXText, int posYText);		// 時間差罠
	void drawExplanInflateTrap(int posXHandle, int posYHandle,
		int posXHandle2, int posYHandle2,
		int posXText, int posYText);	// 膨らむ罠
	void drawExplanShotTrap(int posXHandle, int posYHandle,
		int posXText, int posYText);	// ショットの罠

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

	// ボタンハンドル
	int m_buttonHandle;
	int m_buttonHnadleLeftNum;		// 左上座標のX軸
	int m_buttonHnadleTopNum;		// 左上座標のY軸
};