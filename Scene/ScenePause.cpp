#include "ScenePause.h"
#include "../Util/Pad.h"

ScenePause::ScenePause() :
	m_textHandle(-1),
	m_posArrow(0),
	m_pushNum(0)
{
}

ScenePause::~ScenePause()
{
}

void ScenePause::init()
{
	m_textHandle = CreateFontToHandle(NULL, 50, 4);
	m_posArrow = 200;
	m_pushNum = 0;
}

void ScenePause::end()
{
	DeleteFontToHandle(m_textHandle);
}

void ScenePause::update()
{
	if (m_pushNum >= 0 && m_pushNum <= 2)
	{
		if (Pad::isTrigger(PAD_INPUT_UP) == 1)
		{
			if (m_pushNum <= 0)
			{
				m_pushNum = 0;
			}
			else
			{
				m_posArrow -= 70;
				m_pushNum--;
			}
		}
		if (Pad::isTrigger(PAD_INPUT_DOWN) == 1)
		{
			if (m_pushNum >= 2)
			{
				m_pushNum = 2;
			}
			else
			{
				m_posArrow += 70;
				m_pushNum++;
			}
		}
	}
}

void ScenePause::pauseDraw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(100, 100, 700, 600, kColor::LightBlue, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawBox(100, 100, 700, 600, kColor::Black, false);
	DrawStringToHandle(200, 200, "設定", kColor::Black, m_textHandle);
	DrawStringToHandle(200, 270, "リタイア", kColor::Black, m_textHandle);
	DrawStringToHandle(200, 340, "リトライ", kColor::Black, m_textHandle);
	DrawStringToHandle(150, m_posArrow, "→", kColor::Black, m_textHandle);

	// 確認描画
	//DrawFormatString(0, 0, kColor::Black, "%d", m_pushNum);
}

void ScenePause::GameOverDraw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(100, 100, 700, 600, kColor::LightBlue, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawBox(100, 100, 700, 600, kColor::Black, false);
	DrawStringToHandle(200, 200, "設定", kColor::Black, m_textHandle);
	DrawStringToHandle(200, 270, "リタイア", kColor::Black, m_textHandle);
	DrawStringToHandle(200, 340, "リトライ", kColor::Black, m_textHandle);
	DrawStringToHandle(150, m_posArrow, "→", kColor::Black, m_textHandle);
}

