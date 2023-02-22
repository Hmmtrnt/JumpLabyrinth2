﻿#include "ScenePause.h"
#include "../Util/Pad.h"

ScenePause::ScenePause() :
	m_textHandle(-1),
	m_posArrow(0),
	m_pushNum(0),
	m_cursorSound(0),
	m_cursorNotSound(0)
{
}

ScenePause::~ScenePause()
{
}

void ScenePause::init()
{
	m_textHandle = CreateFontToHandle("Silver", 90, -1, -1);
	m_posArrow = 400;
	m_pushNum = 0;
	m_cursorSound = LoadSoundMem("sound/cursorSound.mp3");
	m_cursorNotSound = LoadSoundMem("sound/landingSound.mp3");
	ChangeVolumeSoundMem(100, m_cursorNotSound);
}

void ScenePause::end()
{
	DeleteFontToHandle(m_textHandle);
	DeleteSoundMem(m_cursorSound);
	DeleteSoundMem(m_cursorNotSound);
}

void ScenePause::update()
{
	if (m_pushNum >= 0 && m_pushNum <= 2)
	{
		if (Pad::isTrigger(PAD_INPUT_UP) == 1)
		{
			if (m_pushNum <= 0)
			{
				PlaySoundMem(m_cursorNotSound, DX_PLAYTYPE_BACK, true);
				m_pushNum = 0;
			}
			else
			{
				PlaySoundMem(m_cursorSound, DX_PLAYTYPE_BACK, true);
				m_posArrow -= 100;
				m_pushNum--;
			}
		}
		if (Pad::isTrigger(PAD_INPUT_DOWN) == 1)
		{
			if (m_pushNum >= 2)
			{
				PlaySoundMem(m_cursorNotSound, DX_PLAYTYPE_BACK, true);
				m_pushNum = 2;
			}
			else
			{
				PlaySoundMem(m_cursorSound, DX_PLAYTYPE_BACK, true);
				m_posArrow += 100;
				m_pushNum++;
			}
		}
	}
}

void ScenePause::pauseDraw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(550, 350, 1350, 700, kColor::LightBlue, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawBox(550, 350, 1350, 700, kColor::Black, false);
	DrawStringToHandle(700, 400, "ここの項目何にしよう？", kColor::Black, m_textHandle);
	DrawStringToHandle(700, 500, "リタイア", kColor::Black, m_textHandle);
	DrawStringToHandle(700, 600, "リトライ", kColor::Black, m_textHandle);
	DrawStringToHandle(600, m_posArrow, "→", kColor::Black, m_textHandle);

	// 確認描画
	//DrawFormatString(0, 0, kColor::Black, "%d", m_pushNum);
}


