#pragma once
#include "../Util/common.h"

class Back
{
public:
	Back();
	virtual ~Back();

	void init();// 初期化
	void end();// 終了
	void update();// 更新
	void draw();// 描画

	void drawMenuGuide();// メニュー表示方法描画
	void drawCloseGuide();// ギミック説明表示方法描画

	// ヘルプ描画
	void drawOpenGuide();// ヘルプボタン誘導描画
	void drawExplan2_5();// 2から5ステージのギミック説明描画
	void drawExplan6And10();// 6と10ステージのギミック説明描画
	void drawExplan7_9();// 7から9ステージのギミック説明描画
	void drawExplan11();// 11ステージのギミック説明描画
	void drawExplan12_15();// 12から15ステージのギミック説明描画
	void drawExplan16();// 16ステージのギミック説明描画
	void drawExplan17_20();// 17から20ステージのギミック説明描画

	void drawTutorial();// チュートリアル描画
	void drawTutorialText();// チュートリアルがあるかどうかの描画

private:
	// ギミック説明の描画
	
	/// <summary>
	/// 即死トラップの説明描画
	/// </summary>
	/// <param name="posXHandle">画像のX座標</param>
	/// <param name="posYHandle">画像のY座標</param>
	/// <param name="posXText">テキストのX座標</param>
	/// <param name="posYText">テキストのY座標</param>
	void drawExplanDeath(int posXHandle, int posYHandle,
		int posXText, int posYText);
	/// <summary>
	/// 時間差トラップの説明描画
	/// </summary>
	/// <param name="posXHandle">画像のX座標</param>
	/// <param name="posYHandle">画像のY座標</param>
	/// <param name="posXText">テキストのX座標</param>
	/// <param name="posYText">テキストのY座標</param>
	void drawExplanLagTrap(int posXHandle, int posYHandle,
		int posXText, int posYText);
	/// <summary>
	/// 膨らむトラップの説明描画
	/// </summary>
	/// <param name="posXHandle">デス判定画像のX座標</param>
	/// <param name="posYHandle">デス判定画像のY座標</param>
	/// <param name="posXHandle2">画像のX座標</param>
	/// <param name="posYHandle2">画像のY座標</param>
	/// <param name="posXText">テキストのX座標</param>
	/// <param name="posYText">テキストのY座標</param>
	void drawExplanInflateTrap(int posXHandle, int posYHandle,
		int posXHandle2, int posYHandle2,
		int posXText, int posYText);
	/// <summary>
	/// ショットトラップの説明描画
	/// </summary>
	/// <param name="posXHandle">画像のX座標</param>
	/// <param name="posYHandle">画像のY座標</param>
	/// <param name="posXText">テキストのX座標</param>
	/// <param name="posYText">テキストのY座標</param>
	void drawExplanShotTrap(int posXHandle, int posYHandle,
		int posXText, int posYText);

	/// <summary>
	/// ボタン描画
	/// </summary>
	/// <param name="x">X座標</param>
	/// <param name="y">Y座標</param>
	void drawButton(int x, int y);
	/// <summary>
	/// 押すべきボタンの描画
	/// </summary>
	/// <param name="handleNum">描画する画像の番号</param>
	void drawPushButton(int handleNum);

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
	// ポーズ
	int m_buttonPauseLeftNum;// 左上座標のX軸
	int m_buttonPauseTopNum;// 左上座標のY軸
	// ボタン
	int m_buttonHandleLeftNum;// 左上座標のX軸
	int m_buttonHandleTopNum;// 左上座標のY軸
	int m_buttonHandleX;// X座標
	int m_buttonHandleY;// Y座標
	int m_buttohHandleDisplayTime;// 表示時間
	int m_buttonHandleTime;// 全体時間
};