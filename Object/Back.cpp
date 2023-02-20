#include "Back.h"

namespace
{
	constexpr float kSize = 3.3f;
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
	m_gimmickHandle = draw::MyLoadGraph("data/Textures-16.png");

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

}

void Back::drawHelp()
{
	DrawFormatStringToHandle(50, 50, kColor::White, m_textHandle, "Yボタン：ヘルプ");
}

void Back::drawExplan2_5()
{
	DrawFormatStringToHandle(50, 50, kColor::White, m_textHandle, "ギミック説明");
	draw::MyDrawRectRotaGraph(200, 200, 
		13 * 16, 13 * 16,
		16, 16,
		4.2f, 0.0f, 
		m_gimmickHandle2, true, false);

}

void Back::drawExplan6()
{
	DrawFormatStringToHandle(50, 50, kColor::White, m_textHandle, "ギミック説明");
}

void Back::drawExplan7_10()
{
	DrawFormatStringToHandle(50, 50, kColor::White, m_textHandle, "ギミック説明");
}

void Back::drawExplan11()
{
	DrawFormatStringToHandle(50, 50, kColor::White, m_textHandle, "ギミック説明");
}

void Back::drawExplan12_15()
{
	DrawFormatStringToHandle(50, 50, kColor::White, m_textHandle, "ギミック説明");
}

void Back::drawExplan16()
{
	DrawFormatStringToHandle(50, 50, kColor::White, m_textHandle, "ギミック説明");
}

void Back::drawExplan17_20()
{
	DrawFormatStringToHandle(50, 50, kColor::White, m_textHandle, "ギミック説明");
}
