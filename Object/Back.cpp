#include "Back.h"

namespace
{
	// ステージにギミックが一つしかないときの描画座標
	constexpr int kTrapOnlyHandleX = 200;
	constexpr int kTrapOnlyHandleY = 200;
	constexpr int kTrapOnlyTextX = 50;
	constexpr int kTrapOnlyTextY = 300;
	// ステージに膨らんだりするギミックしかないときの描画座標
	constexpr int kTrapOnlyInflateHandleX = 300;
	constexpr int kTrapOnlyInflateHandleY = 200;
	constexpr int kTrapOnlyInflateHandleX2 = 150;
	constexpr int kTrapOnlyInflateHandleY2 = 200;

	// ステージギミックの説明描画座標
	// 即死
	constexpr int kTrapDeathHandleX = 200;		// 画像
	constexpr int kTrapDeathHandleY = 200;
	constexpr int kTrapDeathTextX = 50;			// テキスト
	constexpr int kTrapDeathTextY = 300;
	// 時間差罠
	constexpr int kTrapLagHandleX = 200;		// 画像
	constexpr int kTrapLagHandleY = 650;
	constexpr int kTrapLagTextX = 50;			// テキスト
	constexpr int kTrapLagTextY = 750;
	// 膨らむ罠
	constexpr int kTrapInflateHandleX = 1750;	// 画像
	constexpr int kTrapInflateHandleY = 200;
	constexpr int kTrapInflateHandleX2 = 1600;
	constexpr int kTrapInflateHandleY2 = 200;
	constexpr int kTrapInflateTextX = 1550;		// テキスト
	constexpr int kTrapInflateTextY = 300;
	// ショット
	constexpr int kTrapShotHandleX = 1700;		// 画像
	constexpr int kTrapShotHandleY = 650;
	constexpr int kTrapShotTextX = 1550;		// テキスト
	constexpr int kTrapShotTextY = 750;

	// チュートリアル描画の座標
	// 上ボタン
	constexpr int kUpButtonHandleX = 200;// 画像
	constexpr int kUpButtonHandleY = 200;
	// 下ボタン
	constexpr int kDownButtonHandleX = 200;// 画像
	constexpr int kDownButtonHandleY = 650;
	// 右ボタン
	constexpr int kRightButtonHandleX = 1700;// 画像
	constexpr int kRightButtonHandleY = 200;
	// 左ボタン
	constexpr int kLeftButtonHandleX = 1700;// 画像
	constexpr int kLeftButtonHandleY = 650;
	// テキスト一列目
	constexpr int kFirstButtonTextX = 100;
	constexpr int kUpButtonTextY = 300;
	constexpr int kDownButtonTextY = 750;
	// テキスト二列目
	constexpr int kSecondButtonTextX = 1600;
	constexpr int kRightButtonTextY = 300;
	constexpr int kLeftButtonTextY = 750;

	// ボタン画像の左上座標
	constexpr int kButtonHandlePosX = 3;
	constexpr int kUpButtonHandlePosY = 31;// 上
	constexpr int kDownButtonHandlePosY = 35;// 下
	constexpr int kRightButtonHandlePosY = 33;// 右
	constexpr int kLeftButtonHandlePosY = 37;// 左

	// 背景の描画サイズ
	constexpr float kSize = 3.3f;

	// ボタンハンドルの一辺
	constexpr int kLengthHandle = 16;

	// テキスト
	const char* const kGuideOpenText = ":ギミック説明";
	const char* const kGuideCloseText = ":閉じる";
	const char* const kExplanGimmickDeath = "当たってはいけません";
	const char* const kExplanGimmickTimeRug = "左右上下に一定時間いると\n死んでしまいます";
	const char* const kExplanGimmickInflate = "膨らんでいるときに\n当たってはいけません";
	const char* const kExplanGimmickArrow = "矢が発射されます";
	const char* const kUpTutorialText = "上方向へ進む";
	const char* const kDownTutorialText = "下方向へ進む";
	const char* const kRightTutorialText = "右方向へ進む";
	const char* const kLeftTutorialText = "左方向へ進む";
	const char* const kTutorialText = "操作説明あり";
}

Back::Back() :
	m_handle(-1),
	m_verX(0),
	m_verY(0),
	m_textHandle(0),
	m_gimmickHandle(0),
	m_gimmickHandle2(0),
	m_buttonHandle(0),
	m_buttonPauseLeftNum(0),
	m_buttonPauseTopNum(0),
	m_buttonHandleLeftNum(0),
	m_buttonHandleTopNum(0),
	m_buttonHandleX(0),
	m_buttonHandleY(0),
	m_buttohHandleDisplayTime(0),
	m_buttonHandleTime(0),
	m_D_padButtonHandle(0),
	m_D_padPosX(0),
	m_D_padPosY(0)
{
	for (int y = 0; y < kVariable::BackHeight; y++)
	{
		for (int x = 0; x < kVariable::BackWidth; x++)
		{
			m_back[y][x] = 0;
		}
	}
}

Back::~Back()
{
}

// 初期化
void Back::init()
{
	// 背景ハンドル
	m_handle = draw::MyLoadGraph("data/tileset/inca_back2.png");
	// 切り取る左上の頂点
	m_verX = 0;
	m_verY = 0;

	// フォント
	m_textHandle = CreateFontToHandle("Silver", 50, -1, -1);

	// ステージ説明用描画
	m_gimmickHandle = draw::MyLoadGraph("data/tileset/stage.png");// 即死以外
	m_gimmickHandle2 = draw::MyLoadGraph("data/Trap.png");// 即死トラップ

	// ボタン描画
	m_buttonHandle = draw::MyLoadGraph("data/button.png");

	// 切り取り頂点
	// ポーズボタン
	m_buttonPauseLeftNum = 10;// 左
	m_buttonPauseTopNum = 14;// 上
	// ABXY1ボタン
	m_buttonHandleLeftNum = 1;// 左
	m_buttonHandleTopNum = 21;// 上
	// 描画時間
	m_buttohHandleDisplayTime = 30;// 描画
	m_buttonHandleTime = 60;// 全体
	m_D_padButtonHandle = kUpButtonHandlePosY;// 十字キー描画左上切り取り座標
	m_D_padPosX = kUpButtonHandleX;// 十字キー描画X座標
	m_D_padPosY = kUpButtonHandleY;// 十字キー描画Y座標


	// 背景配列のサイズ取得
	for (int y = 0; y < kVariable::BackHeight; y++)
	{
		for (int x = 0; x < kVariable::BackWidth; x++)
		{
			m_back[y][x] = kBack::backs[y][x];
		}
	}
}

// 終了
void Back::end()
{
	DeleteGraph(m_handle);
	DeleteFontToHandle(m_textHandle);
	DeleteGraph(m_gimmickHandle);
	DeleteGraph(m_gimmickHandle2);
	DeleteGraph(m_buttonHandle);
}

void Back::update()
{
	// ボタン表示時間
	m_buttonHandleTime--;
	if (m_buttonHandleTime <= 0)
	{
		m_buttonHandleTime = 60;
	}
}

// 描画
void Back::draw()
{
	for (int y = 0; y < kVariable::BackHeight; y++)
	{
		for (int x = 0; x < kVariable::BackWidth; x++)
		{
			if (m_back[y][x] == 0)
			{
				m_verX = 4;
				m_verY = 1;
			}
			if (m_back[y][x] == 1)
			{
				m_verX = 0;
				m_verY = 1;
			}
			draw::MyDrawRectRotaGraph((x * kVariable::DrawBackWidth) + (kVariable::DrawBackWidth / 2),
				(y * kVariable::DrawBackWidth) + (kVariable::DrawBackWidth / 2),
				m_verX * 32, m_verY * 32,
				32, 32,
				kSize, 0.0f,
				m_handle, true, false);
		}
	}
}

void Back::drawMenuGuide()
{
	draw::MyDrawRectRotaGraph(1550, 70, 
		m_buttonPauseLeftNum * kLengthHandle, m_buttonPauseTopNum * kLengthHandle,
		kLengthHandle, kLengthHandle,
		5.0f, 0.0f, m_buttonHandle, true, false);
	DrawFormatStringToHandle(1600, 50, kColor::White, m_textHandle, ":メニュー画面");
}

void Back::drawCloseGuide()
{
	DrawFormatStringToHandle(150, 50, kColor::White, 
		m_textHandle, kGuideCloseText);
	// ボタン描画
	drawButton(100, 50);
	drawPushButton(2, 0, m_buttonHandleTopNum);
}

void Back::drawOpenGuide()
{
	DrawFormatStringToHandle(150, 50, kColor::White, 
		m_textHandle, kGuideOpenText);

	// ボタン描画
	drawButton(100, 50);
	drawPushButton(2, 0, m_buttonHandleTopNum);
	drawMenuGuide();
}

void Back::drawExplan2_5()
{
	drawMenuGuide();
	drawCloseGuide();

	drawExplanDeath(kTrapDeathHandleX, kTrapDeathHandleY, 
		kTrapDeathTextX, kTrapDeathTextY);
}

void Back::drawExplan6And10()
{
	drawMenuGuide();
	drawCloseGuide();

	drawExplanLagTrap(kTrapOnlyHandleX, kTrapOnlyHandleY,
		kTrapOnlyTextX, kTrapOnlyTextY);
}

void Back::drawExplan7_9()
{
	drawMenuGuide();
	drawCloseGuide();

	drawExplanDeath(kTrapDeathHandleX, kTrapDeathHandleY,
		kTrapDeathTextX, kTrapDeathTextY);
	drawExplanLagTrap(kTrapLagHandleX, kTrapLagHandleY,
		kTrapLagTextX, kTrapLagTextY);
}

void Back::drawExplan11()
{
	drawMenuGuide();
	drawCloseGuide();

	drawExplanInflateTrap(kTrapOnlyInflateHandleX, kTrapOnlyInflateHandleY,
		kTrapOnlyInflateHandleX2, kTrapOnlyInflateHandleY2,
		kTrapOnlyTextX, kTrapDeathTextY);
}

void Back::drawExplan12_15()
{
	drawMenuGuide();
	drawCloseGuide();

	drawExplanDeath(kTrapDeathHandleX, kTrapDeathHandleY,
		kTrapDeathTextX, kTrapDeathTextY);
	drawExplanLagTrap(kTrapLagHandleX, kTrapLagHandleY,
		kTrapLagTextX, kTrapLagTextY);
	drawExplanInflateTrap(kTrapInflateHandleX, kTrapInflateHandleY,
		kTrapInflateHandleX2, kTrapInflateHandleY2,
		kTrapInflateTextX, kTrapInflateTextY);
}

void Back::drawExplan16()
{
	drawMenuGuide();
	drawCloseGuide();

	drawExplanShotTrap(kTrapOnlyHandleX, kTrapOnlyHandleY, 
		kTrapOnlyTextX, kTrapOnlyTextY);
}

void Back::drawExplan17_20()
{
	drawMenuGuide();
	drawCloseGuide();

	drawExplanDeath(kTrapDeathHandleX, kTrapDeathHandleY, 
		kTrapDeathTextX, kTrapDeathTextY);
	drawExplanLagTrap(kTrapLagHandleX, kTrapLagHandleY, 
		kTrapLagTextX, kTrapLagTextY);
	drawExplanInflateTrap(kTrapInflateHandleX, kTrapInflateHandleY, 
		kTrapInflateHandleX2, kTrapInflateHandleY2, 
		kTrapInflateTextX, kTrapInflateTextY);
	drawExplanShotTrap(kTrapShotHandleX, kTrapShotHandleY, 
		kTrapShotTextX, kTrapShotTextY);
}

void Back::drawTutorial()
{
	// ボタン描画
	for (int i = 0; i < 4; i++)
	{
		draw::MyDrawRectRotaGraph(m_D_padPosX, m_D_padPosY,
			kButtonHandlePosX * kLengthHandle, m_D_padButtonHandle * kLengthHandle,
			kLengthHandle * 2, kLengthHandle * 2,
			4.0f, 0.0f, m_buttonHandle, true, false);
		if (i == 0)
		{// 上
			m_D_padButtonHandle = kUpButtonHandlePosY;
			m_D_padPosX = kUpButtonHandleX;
			m_D_padPosY = kUpButtonHandleY;
		}
		if (i == 1)
		{// 下
			m_D_padButtonHandle = kDownButtonHandlePosY;
			m_D_padPosX = kDownButtonHandleX;
			m_D_padPosY = kDownButtonHandleY;
		}
		if (i == 2)
		{// 右
			m_D_padButtonHandle = kRightButtonHandlePosY;
			m_D_padPosX = kRightButtonHandleX;
			m_D_padPosY = kRightButtonHandleY;
		}
		if (i == 3)
		{// 左
			m_D_padButtonHandle = kLeftButtonHandlePosY;
			m_D_padPosX = kLeftButtonHandleX;
			m_D_padPosY = kLeftButtonHandleY;
		}
	}

	// 上ボタン描画
	DrawStringToHandle(kFirstButtonTextX, kUpButtonTextY, kUpTutorialText, kColor::White, m_textHandle);

	// 下ボタン描画
	DrawStringToHandle(kFirstButtonTextX, kDownButtonTextY, kDownTutorialText, kColor::White, m_textHandle);

	// 右ボタン描画
	DrawStringToHandle(kSecondButtonTextX, kRightButtonTextY, kRightTutorialText, kColor::White, m_textHandle);

	// 左ボタン描画
	DrawStringToHandle(kSecondButtonTextX, kLeftButtonTextY, kLeftTutorialText, kColor::White, m_textHandle);
}

void Back::drawTutorialText()
{
	DrawStringToHandle(350, 800, kTutorialText, kColor::White, m_textHandle);
}

void Back::drawButton(int x, int y)
{
	// ボタン描画
	for (int i = 0; i < 4; i++)
	{
		draw::MyDrawRectRotaGraph(m_buttonHandleX, m_buttonHandleY,
			m_buttonHandleLeftNum * kLengthHandle, m_buttonHandleTopNum * kLengthHandle,
			kLengthHandle, kLengthHandle,
			2.0f, 0.0f, m_buttonHandle, true, false);
		if (i == 0)
		{
			m_buttonHandleX = x + 25;
			m_buttonHandleY = y + 25;
			m_buttonHandleTopNum = 22;
		}
		if (i == 1)
		{
			m_buttonHandleX = x - 25;
			m_buttonHandleY = y + 25;
			m_buttonHandleTopNum = 19;
		}
		if (i == 2)
		{
			m_buttonHandleX = x;
			m_buttonHandleY = y + 50;
			m_buttonHandleTopNum = 20;
		}
		if (i == 3)
		{
			m_buttonHandleX = x;
			m_buttonHandleY = y;
			m_buttonHandleTopNum = 21;
		}
	}
}

void Back::drawPushButton(int x, int y, int handleNum)
{
	// 押すべきボタン描画
	if (m_buttonHandleTime <= m_buttohHandleDisplayTime)
	{
		draw::MyDrawRectRotaGraph(m_buttonHandleX + x, m_buttonHandleY + y,
			m_buttonHandleLeftNum + 4 * kLengthHandle, handleNum * kLengthHandle,
			kLengthHandle, kLengthHandle,
			2.0f, 0.0f, m_buttonHandle, true, false);
	}
}

void Back::drawExplanDeath(int posXHandle, int posYHandle,
	int posXText, int posYText)
{
	draw::MyDrawRectRotaGraph(posXHandle, posYHandle,
		13 * 16, 13 * 16,
		16, 16,
		4.2f, 0.0f,
		m_gimmickHandle2, true, false);

	DrawFormatStringToHandle(posXText, posYText,
		kColor::White, m_textHandle,
		kExplanGimmickDeath);
}

void Back::drawExplanLagTrap(int posXHandle, int posYHandle,
	int posXText, int posYText)
{
	draw::MyDrawRectRotaGraph(posXHandle, posYHandle,
		0, 0,
		32, 32,
		2.0f, 0.0f,
		m_gimmickHandle, true, false);

	DrawFormatStringToHandle(posXText, posYText,
		kColor::White, m_textHandle,
		kExplanGimmickTimeRug);
}

void Back::drawExplanInflateTrap(int posXHandle, int posYHandle,
	int posXHandle2, int posYHandle2,
	int posXText, int posYText)
{
	draw::MyDrawRectRotaGraph(posXHandle, posYHandle,
		64, 0,
		32, 32,
		4.0f, 0.0f,
		m_gimmickHandle, true, false);
	draw::MyDrawRectRotaGraph(posXHandle2, posYHandle2,
		96, 0,
		32, 32,
		2.0f, 0.0f,
		m_gimmickHandle, true, false);

	DrawFormatStringToHandle(posXText, posYText,
		kColor::White, m_textHandle,
		kExplanGimmickInflate);
}

void Back::drawExplanShotTrap(int posXHandle, int posYHandle,
	int posXText, int posYText)
{
	draw::MyDrawRectRotaGraph(posXHandle, posYHandle,
		32, 0,
		32, 32,
		2.0f, 0.0f,
		m_gimmickHandle, true, false);

	DrawFormatStringToHandle(posXText, posYText,
		kColor::White, m_textHandle,
		kExplanGimmickArrow);
}