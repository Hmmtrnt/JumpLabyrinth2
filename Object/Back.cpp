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

	// 背景の描画サイズ
	constexpr float kSize = 3.3f;

	// ボタンハンドルの一辺
	constexpr int kLengthHandle = 16;

	// テキスト
	const char* const kGuideOpenText = "Yボタン:ギミック説明";
	const char* const kGuideCloseText = "Yボタン:閉じる";
	const char* const kExplanText = "ギミック説明";
	const char* const kExplanGimmickDeath = "当たってはいけません";
	const char* const kExplanGimmickTimeRug = "左右上下に一定時間いると\n死んでしまいます";
	const char* const kExplanGimmickInflate = "膨らんでいるときに\n当たってはいけません";
	const char* const kExplanGimmickArrow = "矢が発射されます";
}

Back::Back() :
	m_handle(-1),
	m_verX(0),
	m_verY(0),
	m_textHandle(0),
	m_gimmickHandle(0),
	m_gimmickHandle2(0),
	m_buttonHandle(0),
	m_buttonHnadleLeftNum(0),
	m_buttonHnadleTopNum(0)
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

	m_textHandle = CreateFontToHandle("Silver", 50, -1, -1);

	m_gimmickHandle = draw::MyLoadGraph("data/tileset/inca_front.png");
	m_gimmickHandle2 = draw::MyLoadGraph("data/Textures-16.png");

	m_buttonHandle = draw::MyLoadGraph("data/button.png");
	m_buttonHnadleLeftNum = 10;
	m_buttonHnadleTopNum = 14;

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
				draw::MyDrawRectRotaGraph((x * kVariable::DrawBackWidth) + (kVariable::DrawBackWidth / 2),
					(y * kVariable::DrawBackWidth) + (kVariable::DrawBackWidth / 2),
					m_verX * 32, m_verY * 32,
					32, 32,
					kSize, 0.0f,
					m_handle, true, false);
			}
			if (m_back[y][x] == 1)
			{
				m_verX = 0;
				m_verY = 1;
				draw::MyDrawRectRotaGraph((x * kVariable::DrawBackWidth) + (kVariable::DrawBackWidth / 2),
					(y * kVariable::DrawBackWidth) + (kVariable::DrawBackWidth / 2),
					m_verX * 32, m_verY * 32,
					32, 32,
					kSize, 0.0f,
					m_handle, true, false);
			}
		}
	}
}

void Back::drawMenuGuide()
{
	draw::MyDrawRectRotaGraph(1550, 70, 
		m_buttonHnadleLeftNum * kLengthHandle, m_buttonHnadleTopNum * kLengthHandle,
		kLengthHandle, kLengthHandle,
		5.0f, 0.0f, m_buttonHandle, true, false);
	DrawFormatStringToHandle(1600, 50, kColor::White, m_textHandle, ":メニュー画面");
}

void Back::drawHelpGuide()
{
	DrawFormatStringToHandle(50, 50, kColor::White, m_textHandle, kGuideCloseText);
	DrawFormatStringToHandle(50, 100, kColor::White, m_textHandle, kExplanText);
}

void Back::drawHelp()
{
	DrawFormatStringToHandle(50, 50, kColor::White, 
		m_textHandle, kGuideOpenText);
	drawMenuGuide();
}

void Back::drawExplan2_5()
{
	drawMenuGuide();
	drawHelpGuide();

	drawExplanDeath(kTrapDeathHandleX, kTrapDeathHandleY, 
		kTrapDeathTextX, kTrapDeathTextY);
}

void Back::drawExplan6And10()
{
	drawMenuGuide();
	drawHelpGuide();

	drawExplanLagTrap(kTrapOnlyHandleX, kTrapOnlyHandleY,
		kTrapOnlyTextX, kTrapOnlyTextY);
}

void Back::drawExplan7_9()
{
	drawMenuGuide();
	drawHelpGuide();

	drawExplanDeath(kTrapDeathHandleX, kTrapDeathHandleY,
		kTrapDeathTextX, kTrapDeathTextY);
	drawExplanLagTrap(kTrapLagHandleX, kTrapLagHandleY,
		kTrapLagTextX, kTrapLagTextY);
}

void Back::drawExplan11()
{
	drawMenuGuide();
	drawHelpGuide();

	drawExplanInflateTrap(kTrapOnlyInflateHandleX, kTrapOnlyInflateHandleY,
		kTrapOnlyInflateHandleX2, kTrapOnlyInflateHandleY2,
		kTrapOnlyTextX, kTrapDeathTextY);
}

void Back::drawExplan12_15()
{
	drawMenuGuide();
	drawHelpGuide();

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
	drawHelpGuide();

	drawExplanShotTrap(kTrapOnlyHandleX, kTrapOnlyHandleY, 
		kTrapOnlyTextX, kTrapOnlyTextY);
}

void Back::drawExplan17_20()
{
	drawMenuGuide();
	drawHelpGuide();

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