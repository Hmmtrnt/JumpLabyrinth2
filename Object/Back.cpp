#include "Back.h"

namespace
{
	constexpr float kSize = 3.3f;
	const char* const kGuideOpenText = "Yボタン:ギミック説明";
	const char* const kGuideCloseText = "Yボタン:閉じる";
	const char* const kExplanText = "ギミック説明";
	const char* const kExplanGimmickDeath = "このブロックに当たると\n死んでしまいます";
	const char* const kExplanGimmickTimeRug = "このブロックの左右上下に\n一定時間いると\n死んでしまいます";
	const char* const kExplanGimmickInflate = "このブロックが左のように\n縮んでいると\n着地できます\nしかし、右のように\n膨らんでいると\n死んでしまいます";
	const char* const kExplanGimmickArrow = "このブロックから矢が\n左右上下いずれかの\n方向に発射され、\n当たると死んでしまいます";
}

Back::Back() :
	m_handle(-1),
	m_verX(0),
	m_verY(0),
	m_textHandle(0),
	m_gimmickHandle(0),
	m_gimmickHandle2(0)
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

	DrawFormatStringToHandle(1500, 50, kColor::White, m_textHandle, "START:メニュー画面");

}

void Back::drawHelp()
{
	DrawFormatStringToHandle(50, 50, kColor::White, m_textHandle, kGuideOpenText);
}

void Back::drawExplan2_5()
{
	DrawFormatStringToHandle(50,50, kColor::White, m_textHandle, kGuideCloseText);
	DrawFormatStringToHandle(50, 100, kColor::White, m_textHandle, kExplanText);
	draw::MyDrawRectRotaGraph(200, 200, 
		13 * 16, 13 * 16,
		16, 16,
		4.2f, 0.0f, 
		m_gimmickHandle2, true, false);

	DrawFormatStringToHandle(50, 300, 
		kColor::White, m_textHandle, 
		kExplanGimmickDeath);

}

void Back::drawExplan6()
{
	DrawFormatStringToHandle(50, 50, kColor::White, m_textHandle, kGuideCloseText);
	DrawFormatStringToHandle(50, 100, kColor::White, m_textHandle, kExplanText);

	draw::MyDrawRectRotaGraph(200, 200,
		0, 0,
		32, 32,
		2.0f, 0.0f,
		m_gimmickHandle, true, false);

	DrawFormatStringToHandle(50, 300, 
		kColor::White, m_textHandle, 
		kExplanGimmickTimeRug);
}

void Back::drawExplan7_10()
{
	DrawFormatStringToHandle(50, 50, kColor::White, m_textHandle, kGuideCloseText);
	DrawFormatStringToHandle(50, 100, kColor::White, m_textHandle, kExplanText);
	draw::MyDrawRectRotaGraph(200, 200,
		13 * 16, 13 * 16,
		16, 16,
		4.2f, 0.0f,
		m_gimmickHandle2, true, false);

	DrawFormatStringToHandle(50, 300,
		kColor::White, m_textHandle,
		kExplanGimmickDeath);

	draw::MyDrawRectRotaGraph(200, 650,
		0, 0,
		32, 32,
		2.0f, 0.0f,
		m_gimmickHandle, true, false);

	DrawFormatStringToHandle(50, 750,
		kColor::White, m_textHandle,
		kExplanGimmickTimeRug);
}

void Back::drawExplan11()
{
	DrawFormatStringToHandle(50, 50, kColor::White, m_textHandle, kGuideCloseText);
	DrawFormatStringToHandle(50, 100, kColor::White, m_textHandle, kExplanText);
	draw::MyDrawRectRotaGraph(300, 200,
		64, 0,
		32, 32,
		4.0f, 0.0f,
		m_gimmickHandle, true, false);
	draw::MyDrawRectRotaGraph(150, 200,
		96, 0,
		32, 32,
		2.0f, 0.0f,
		m_gimmickHandle, true, false);
	DrawFormatStringToHandle(50, 300,
		kColor::White, m_textHandle,
		kExplanGimmickInflate);
}

void Back::drawExplan12_15()
{
	DrawFormatStringToHandle(50, 50, kColor::White, m_textHandle, kGuideCloseText);
	DrawFormatStringToHandle(50, 100, kColor::White, m_textHandle, kExplanText);
	draw::MyDrawRectRotaGraph(200, 200,
		13 * 16, 13 * 16,
		16, 16,
		4.2f, 0.0f,
		m_gimmickHandle2, true, false);

	DrawFormatStringToHandle(50, 300,
		kColor::White, m_textHandle,
		kExplanGimmickDeath);

	draw::MyDrawRectRotaGraph(200, 650,
		0, 0,
		32, 32,
		2.0f, 0.0f,
		m_gimmickHandle, true, false);

	DrawFormatStringToHandle(50, 750,
		kColor::White, m_textHandle,
		kExplanGimmickTimeRug);

	draw::MyDrawRectRotaGraph(1750, 200,
		64, 0,
		32, 32,
		4.0f, 0.0f,
		m_gimmickHandle, true, false);
	draw::MyDrawRectRotaGraph(1600, 200,
		96, 0,
		32, 32,
		2.0f, 0.0f,
		m_gimmickHandle, true, false);
	DrawFormatStringToHandle(1500, 300,
		kColor::White, m_textHandle,
		kExplanGimmickInflate);
}

void Back::drawExplan16()
{
	DrawFormatStringToHandle(50, 50, kColor::White, m_textHandle, kGuideCloseText);
	DrawFormatStringToHandle(50, 100, kColor::White, m_textHandle, kExplanText);
	draw::MyDrawRectRotaGraph(200, 200,
		32, 0,
		32, 32,
		2.0f, 0.0f,
		m_gimmickHandle, true, false);

	DrawFormatStringToHandle(50, 300,
		kColor::White, m_textHandle,
		kExplanGimmickArrow);
}

void Back::drawExplan17_20()
{
	DrawFormatStringToHandle(50, 50, kColor::White, m_textHandle, kGuideCloseText);
	DrawFormatStringToHandle(50, 100, kColor::White, m_textHandle, kExplanText);
	draw::MyDrawRectRotaGraph(200, 200,
		13 * 16, 13 * 16,
		16, 16,
		4.2f, 0.0f,
		m_gimmickHandle2, true, false);

	DrawFormatStringToHandle(50, 300,
		kColor::White, m_textHandle,
		kExplanGimmickDeath);

	draw::MyDrawRectRotaGraph(200, 650,
		0, 0,
		32, 32,
		2.0f, 0.0f,
		m_gimmickHandle, true, false);

	DrawFormatStringToHandle(50, 750,
		kColor::White, m_textHandle,
		kExplanGimmickTimeRug);

	draw::MyDrawRectRotaGraph(1750, 200,
		64, 0,
		32, 32,
		4.0f, 0.0f,
		m_gimmickHandle, true, false);
	draw::MyDrawRectRotaGraph(1600, 200,
		96, 0,
		32, 32,
		2.0f, 0.0f,
		m_gimmickHandle, true, false);
	DrawFormatStringToHandle(1500, 300,
		kColor::White, m_textHandle,
		kExplanGimmickInflate);

	draw::MyDrawRectRotaGraph(1700, 650,
		32, 0,
		32, 32,
		2.0f, 0.0f,
		m_gimmickHandle, true, false);

	DrawFormatStringToHandle(1500, 750,
		kColor::White, m_textHandle,
		kExplanGimmickArrow);
}
