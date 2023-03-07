#include "ScenePause.h"
#include "../Util/Pad.h"

namespace
{
	// 座標
	constexpr int kWidthText = 850;		// テキスト
	constexpr int kWidthCursor = 750;	// カーソル
}

ScenePause::ScenePause() :
	m_textHandle(-1),
	m_posCursorX(0),
	m_posCursorY(0),
	m_posClearCursorX(0),
	m_posClearCursorY(0),
	m_pushNum(0),
	m_posClearPauseX(0),
	m_posClearPauseY(0),
	m_sizeClearPauseX(0),
	m_sizeClearPauseY(0),
	m_posClearTextX(0),
	m_pauseCursorNum(0),
	m_clearCursorNum(0),
	m_posClearTextY1(0),
	m_posClearTextY2(0),
	m_posClearTextY3(0),
	m_itemNum(0),
	m_cursorSound(-1),
	m_cursorNotSound(-1),
	m_isCursorInit(false),
	m_FillBox(false)
{
}

ScenePause::~ScenePause()
{
}

void ScenePause::init()
{
	m_textHandle = CreateFontToHandle("Silver", 90, -1, -1);
	m_posCursorX = 800;
	m_posCursorY = 500;
	m_posClearCursorX = 750;
	m_posClearCursorY = 400;
	m_pushNum = 0;
	m_posClearPauseX = 700;
	m_posClearPauseY = 250;
	m_sizeClearPauseX = 1200;
	m_sizeClearPauseY = 700;
	m_posClearTextX = 800;
	m_pauseCursorNum = 495;
	m_clearCursorNum = 395;
	m_posClearTextY1 = 400;
	m_posClearTextY2 = 500;
	m_posClearTextY3 = 600;
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

void ScenePause::updatePause()
{
	if (m_pushNum >= 0 && m_pushNum <= 1)
	{
		if (Pad::isTrigger(PAD_INPUT_UP))
		{
			if (m_pushNum <= 0)
			{
				PlaySoundMem(m_cursorNotSound, DX_PLAYTYPE_BACK, true);
				m_pushNum = 0;
			}
			else
			{
				PlaySoundMem(m_cursorSound, DX_PLAYTYPE_BACK, true);
				m_pauseCursorNum -= 100;
				m_pushNum--;
			}
		}
		if (Pad::isTrigger(PAD_INPUT_DOWN))
		{
			if (m_pushNum >= 1)
			{
				PlaySoundMem(m_cursorNotSound, DX_PLAYTYPE_BACK, true);
				m_pushNum = 1;
			}
			else
			{
				PlaySoundMem(m_cursorSound, DX_PLAYTYPE_BACK, true);
				m_pauseCursorNum += 100;
				m_pushNum++;
			}
		}
	}
	if (Pad::isPress(PAD_INPUT_2))
	{
		m_FillBox = true;
	}
}

void ScenePause::drawPause()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, kColor::Black, true);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	DrawBox(700, 350, 1150, 700, kColor::Yellow, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawBox(700, 350, 1150, 700, kColor::Black, false);
	DrawStringToHandle(850 + 2, 402, "PAUSE", kColor::Black, m_textHandle);
	DrawStringToHandle(850, 400, "PAUSE", kColor::White, m_textHandle);

	m_posCursorX = 800;
	m_posCursorY = m_pauseCursorNum;
	for (int y = 0; y < 5; y++)
	{
		DrawBox(m_posCursorX, m_posCursorY, m_posCursorX + 250, m_posCursorY + 70, kColor::Black, m_FillBox);
		m_posCursorX++;
		m_posCursorY++;
	}

	DrawStringToHandle(kWidthText + 2, 502, "RETIRE", kColor::Black, m_textHandle);
	if (m_FillBox && m_pushNum == 0)
	{
		DrawStringToHandle(kWidthText, 500, "RETIRE", kColor::White, m_textHandle);
	}
	DrawStringToHandle(kWidthText + 12, 602, "RETRY", kColor::Black, m_textHandle);
	if (m_FillBox && m_pushNum == 1)
	{
		DrawStringToHandle(kWidthText + 10, 600, "RETRY", kColor::White, m_textHandle);
	}
	//DrawStringToHandle(kWidthCursor, m_posCursor, "→", kColor::White, m_textHandle);

	

	// 確認描画
	//DrawFormatString(0, 0, kColor::Black, "%d", m_pushNum);
}

void ScenePause::updateClearPause()
{
	if (m_stageSelectNumTest == 20)
	{
		m_itemNum = 1;
	}
	else
	{
		m_itemNum = 2;
	}
	if (m_pushNum >= 0 && m_pushNum <= m_itemNum)
	{
		if (Pad::isTrigger(PAD_INPUT_UP))
		{
			if (m_pushNum <= 0)
			{
				PlaySoundMem(m_cursorNotSound, DX_PLAYTYPE_BACK, true);
				m_pushNum = 0;
			}
			else
			{
				PlaySoundMem(m_cursorSound, DX_PLAYTYPE_BACK, true);
				m_clearCursorNum -= 100;
				m_pushNum--;
			}
		}
		if (Pad::isTrigger(PAD_INPUT_DOWN))
		{
			if (m_pushNum >= m_itemNum)
			{
				PlaySoundMem(m_cursorNotSound, DX_PLAYTYPE_BACK, true);
				m_pushNum = m_itemNum;
			}
			else
			{
				PlaySoundMem(m_cursorSound, DX_PLAYTYPE_BACK, true);
				m_clearCursorNum += 100;
				m_pushNum++;
			}
		}
	}
	if (Pad::isPress(PAD_INPUT_2))
	{
		m_FillBox = true;
	}
}

void ScenePause::drawClearPause()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, kColor::Black, true);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	DrawBox(m_posClearPauseX, m_posClearPauseY, 
		m_sizeClearPauseX, m_sizeClearPauseY, kColor::Yellow, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawBox(m_posClearPauseX, m_posClearPauseY, 
		m_sizeClearPauseX, m_sizeClearPauseY, kColor::Black, false);
	if (m_stageSelectNumTest == 20)
	{
		DrawStringToHandle(m_posClearTextX - 48, m_posClearTextY1 + 2, "CONGRATULATION!", kColor::Black, m_textHandle);
		DrawStringToHandle(m_posClearTextX - 50, m_posClearTextY1, "CONGRATULATION!", kColor::White, m_textHandle);
		if (!m_isCursorInit)
		{
			m_clearCursorNum = 500;
			m_isCursorInit = true;
		}
	}
	else
	{
		DrawStringToHandle(m_posClearTextX + 12, m_posClearTextY1 + 2, "NEXT STAGE", kColor::Black, m_textHandle);
		if (m_FillBox && m_pushNum == 0)
		{
			DrawStringToHandle(m_posClearTextX + 10, m_posClearTextY1, "NEXT STAGE", kColor::White, m_textHandle);
		}
	}

	m_posClearCursorX = 750;
	m_posClearCursorY = m_clearCursorNum;
	for (int y = 0; y < 5; y++)
	{
		DrawBox(m_posClearCursorX, m_posClearCursorY, m_posClearCursorX + 400, m_posClearCursorY + 70, kColor::Black, m_FillBox);
		m_posClearCursorX++;
		m_posClearCursorY++;
	}
	
	DrawStringToHandle(m_posClearTextX + 12, 302, "GAMECLEAR!", kColor::Black, m_textHandle);
	DrawStringToHandle(m_posClearTextX + 10, 300, "GAMECLEAR!", kColor::White, m_textHandle);
	
	bool isStage20 = m_stageSelectNumTest == 20;
	
	DrawStringToHandle(m_posClearTextX - 18, m_posClearTextY2 + 2, "SELECT SCENE", kColor::Black, m_textHandle);
	if ((m_FillBox && m_pushNum == 1 && !isStage20) || (m_FillBox && m_pushNum == 0 && isStage20))
	{
		DrawStringToHandle(m_posClearTextX - 20, m_posClearTextY2, "SELECT SCENE", kColor::White, m_textHandle);
	}
	
	DrawStringToHandle(m_posClearTextX + 82, m_posClearTextY3 + 2, "RETRY", kColor::Black, m_textHandle);

	if ((m_FillBox && m_pushNum == 2 && !isStage20) || (m_FillBox && m_pushNum == 1 && isStage20))
	{
		DrawStringToHandle(m_posClearTextX + 80, m_posClearTextY3, "RETRY", kColor::White, m_textHandle);
	}
	
	/*DrawStringToHandle(m_posClearCursorX + 2, m_posClearCursorY + 2, "→", kColor::Black, m_textHandle);
	DrawStringToHandle(m_posClearCursorX, m_posClearCursorY, "→", kColor::White, m_textHandle);*/

	
	//printfDx("%d\n", m_posCursorNum);

	// 確認描画
	//DrawFormatString(0, 0, kColor::Black, "%d", m_pushNum);
}