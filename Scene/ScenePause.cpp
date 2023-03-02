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
	m_posCursor(0),
	m_posClearCursor(0),
	m_pushNum(0),
	m_posClearPauseX(0),
	m_posClearPauseY(0),
	m_sizeClearPauseX(0),
	m_sizeClearPauseY(0),
	m_posClearTextX(0),
	m_posClearCursorX(0),
	m_posClearTextY1(0),
	m_posClearTextY2(0),
	m_posClearTextY3(0),
	m_cursorSound(-1),
	m_cursorNotSound(-1)
{
}

ScenePause::~ScenePause()
{
}

void ScenePause::init()
{
	m_textHandle = CreateFontToHandle("Silver", 90, -1, -1);
	m_posCursor = 400;
	m_posClearCursor = 400;
	m_pushNum = 0;
	m_posClearPauseX = 650;
	m_posClearPauseY = 250;
	m_sizeClearPauseX = 1250;
	m_sizeClearPauseY = 700;
	m_posClearTextX = 800;
	m_posClearCursorX = 700;
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
				m_posCursor -= 100;
				m_pushNum--;
			}
		}
		if (Pad::isTrigger(PAD_INPUT_DOWN) == 1)
		{
			if (m_pushNum >= 1)
			{
				PlaySoundMem(m_cursorNotSound, DX_PLAYTYPE_BACK, true);
				m_pushNum = 1;
			}
			else
			{
				PlaySoundMem(m_cursorSound, DX_PLAYTYPE_BACK, true);
				m_posCursor += 100;
				m_pushNum++;
			}
		}
	}
}

void ScenePause::drawPause()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(700, 350, 1150, 600, kColor::Black, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawBox(700, 350, 1150, 600, kColor::Black, false);
	DrawStringToHandle(kWidthText, 400, "リタイア", kColor::White, m_textHandle);
	DrawStringToHandle(kWidthText, 500, "リスタート", kColor::White, m_textHandle);
	DrawStringToHandle(kWidthCursor, m_posCursor, "→", kColor::White, m_textHandle);

	// 確認描画
	//DrawFormatString(0, 0, kColor::Black, "%d", m_pushNum);
}

void ScenePause::updateClearPause()
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
				m_posClearCursor -= 100;
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
				m_posClearCursor += 100;
				m_pushNum++;
			}
		}
	}
}

void ScenePause::drawClearPause()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, kColor::Black, true);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
	DrawBox(m_posClearPauseX, m_posClearPauseY, 
		m_sizeClearPauseX, m_sizeClearPauseY, kColor::Yellow, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawBox(m_posClearPauseX, m_posClearPauseY, 
		m_sizeClearPauseX, m_sizeClearPauseY, kColor::Black, false);

	DrawStringToHandle(m_posClearTextX - 18, 302, "ゲームクリア!", kColor::Black, m_textHandle);
	DrawStringToHandle(m_posClearTextX -20, 300, "ゲームクリア!", kColor::White, m_textHandle);
	DrawStringToHandle(m_posClearTextX + 2, m_posClearTextY1 + 2, "次のステージへ", kColor::Black, m_textHandle);
	DrawStringToHandle(m_posClearTextX, m_posClearTextY1, "次のステージへ", kColor::White, m_textHandle);
	DrawStringToHandle(m_posClearTextX + 2, m_posClearTextY2 + 2, "セレクト画面へ", kColor::Black, m_textHandle);
	DrawStringToHandle(m_posClearTextX, m_posClearTextY2, "セレクト画面へ", kColor::White, m_textHandle);
	DrawStringToHandle(m_posClearTextX + 2, m_posClearTextY3 + 2, "リトライ", kColor::Black, m_textHandle);
	DrawStringToHandle(m_posClearTextX, m_posClearTextY3, "リトライ", kColor::White, m_textHandle);
	DrawStringToHandle(m_posClearCursorX + 2, m_posClearCursor + 2, "→", kColor::Black, m_textHandle);
	DrawStringToHandle(m_posClearCursorX, m_posClearCursor, "→", kColor::White, m_textHandle);

	// 確認描画
	//DrawFormatString(0, 0, kColor::Black, "%d", m_pushNum);
}