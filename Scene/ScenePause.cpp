#include "ScenePause.h"
#include "../Util/Pad.h"
#include "../Object/ParticleBase.h"

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
	m_CursorPosX(0),
	m_CursorPosY(0),
	m_movePosX(0),
	m_vecPauseX(0),
	m_cursorSound(-1),
	m_cursorNotSound(-1),
	m_isCursorInit(false),
	m_FillBox(false),
	m_isStage20(false),
	m_flowerFrame(0),
	m_particleCount(0),
	m_particlePosX(0),
	m_particlePosY(0)
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
	m_posClearPauseX = 2700;
	m_posClearPauseY = 250;
	m_sizeClearPauseX = 500;
	m_sizeClearPauseY = 450;
	m_posClearTextX = -1150;
	m_pauseCursorNum = 495;
	
	m_isStage20 = m_stageSelectNum == 20;
	
	m_clearCursorNum = 395;
	m_posClearTextY1 = 400;
	m_posClearTextY2 = 500;
	m_posClearTextY3 = 600;
	m_movePosX = -1200;
	m_vecPauseX = 100;
	m_cursorSound = LoadSoundMem("sound/cursorSound.mp3");
	m_cursorNotSound = LoadSoundMem("sound/landingSound.mp3");

	for (auto& pParticle : m_particle)
	{
		pParticle = std::make_shared<ParticleBase>();
	}
	m_flowerFrame = kParticle::FlowerInterval;
	m_particleCount = 0;
	m_particlePosX = 450;
	m_particlePosY = 250;
}

void ScenePause::end()
{
	DeleteFontToHandle(m_textHandle);
	DeleteSoundMem(m_cursorSound);
	DeleteSoundMem(m_cursorNotSound);
}

void ScenePause::updatePause()
{
	// カーソル移動
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
	// 決定した時の処理
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

	int posX = 800;
	int posY = 495;
	for (int y = 0; y < 2; y++)
	{
		for (int x = 0; x < 2; x++)
		{
			DrawBox(posX, posY, posX + 250, posY + 70, kColor::Black, false);
			posX++;
			posY++;
		}
		posX = 800;
		posY -= 2;
		posY += 100;
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
}

void ScenePause::updateClearPause()
{
	if (m_isStage20)
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
	movePause();

	particle(150);
}

void ScenePause::drawClearPause()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, kColor::Black, true);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	DrawBox(m_posClearPauseX, m_posClearPauseY, 
		m_posClearPauseX + m_sizeClearPauseX, m_posClearPauseY + m_sizeClearPauseY, kColor::Yellow, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawBox(m_posClearPauseX, m_posClearPauseY, 
		m_posClearPauseX + m_sizeClearPauseX, m_posClearPauseY + m_sizeClearPauseY, kColor::Black, false);

	m_posClearCursorX = m_movePosX;
	m_posClearCursorY = m_clearCursorNum;
	if (m_isStage20)
	{
		m_posClearCursorY = m_clearCursorNum - 5;
	}

	for (int y = 0; y < 5; y++)
	{
		DrawBox(m_posClearCursorX, m_posClearCursorY, m_posClearCursorX + 400, m_posClearCursorY + 70, kColor::Black, m_FillBox);
		m_posClearCursorX++;
		m_posClearCursorY++;
	}
	
	// カーソル未選択の枠
	if (!m_isStage20)
	{
		m_CursorPosX = m_movePosX;
		m_CursorPosY = 395;

		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 2; x++)
			{
				DrawBox(m_CursorPosX, m_CursorPosY, m_CursorPosX + 400, m_CursorPosY + 70, kColor::Black, false);
				m_CursorPosX++;
				m_CursorPosY++;
			}
			m_CursorPosX = m_movePosX;
			m_CursorPosY -= 2;
			m_CursorPosY += 100;
		}
	}
	else
	{
		m_CursorPosX = m_movePosX;
		m_CursorPosY = 495;
		for (int y = 0; y < 2; y++)
		{
			for (int x = 0; x < 2; x++)
			{
				DrawBox(m_CursorPosX, m_CursorPosY, m_CursorPosX + 400, m_CursorPosY + 70, kColor::Black, false);
				m_CursorPosX++;
				m_CursorPosY++;
			}
			m_CursorPosX = m_movePosX;
			m_CursorPosY -= 2;
			m_CursorPosY += 100;
		}
	}

	// メニューの文字描画
	if (m_isStage20)
	{
		DrawStringToHandle(m_posClearTextX - 48, m_posClearTextY1 + 2, "CONGRATULATION!", kColor::Black, m_textHandle);
		DrawStringToHandle(m_posClearTextX - 50, m_posClearTextY1, "CONGRATULATION!", kColor::White, m_textHandle);
		if (!m_isCursorInit)
		{
			m_clearCursorNum = 500;
			m_isCursorInit = true;
		}
		
		drawParticle();
	}
	else
	{
		DrawStringToHandle(m_posClearTextX + 12, m_posClearTextY1 + 2, "NEXT STAGE", kColor::Black, m_textHandle);
		if (m_FillBox && m_pushNum == 0)
		{
			DrawStringToHandle(m_posClearTextX + 10, m_posClearTextY1, "NEXT STAGE", kColor::White, m_textHandle);
		}
	}
	
	DrawStringToHandle(m_posClearTextX + 12, 302, "GAMECLEAR!", kColor::Black, m_textHandle);
	DrawStringToHandle(m_posClearTextX + 10, 300, "GAMECLEAR!", kColor::White, m_textHandle);
	
	DrawStringToHandle(m_posClearTextX - 18, m_posClearTextY2 + 2, "STAGE SELECT", kColor::Black, m_textHandle);
	if ((m_FillBox && m_pushNum == 1 && !m_isStage20) || (m_FillBox && m_pushNum == 0 && m_isStage20))
	{
		DrawStringToHandle(m_posClearTextX - 20, m_posClearTextY2, "STAGE SELECT", kColor::White, m_textHandle);
	}
	
	DrawStringToHandle(m_posClearTextX + 82, m_posClearTextY3 + 2, "RETRY", kColor::Black, m_textHandle);

	if ((m_FillBox && m_pushNum == 2 && !m_isStage20) || (m_FillBox && m_pushNum == 1 && m_isStage20))
	{
		DrawStringToHandle(m_posClearTextX + 80, m_posClearTextY3, "RETRY", kColor::White, m_textHandle);
	}
}

void ScenePause::movePause()
{
	// ポーズの移動
	m_posClearTextX += m_vecPauseX;
	m_posClearPauseX -= m_vecPauseX;
	m_movePosX += m_vecPauseX;
	// ポーズの移動限界座標
	if (m_posClearTextX >= 800)
	{
		m_posClearTextX = 800;
	}
	if (m_posClearPauseX <= 700)
	{
		m_posClearPauseX = 700;
	}
	if (m_movePosX >= 750)
	{
		m_movePosX = 750;
	}
}

void ScenePause::particle(int count)
{
	for (auto& pParticle : m_particle)
	{
		if (!pParticle->isExist())	continue;
		pParticle->update();
	}

	m_flowerFrame--;
	if (m_flowerFrame <= 0)
	{
		m_particleCount = 0;
		// 花火のようなパーティクル
		for (auto& pParticle : m_particle)
		{
			if (pParticle->isExist()) continue;

			float randSin = static_cast<float>(GetRand(360)) / 360.0f;
			randSin *= DX_TWO_PI_F;
			float randSpeed = static_cast<float>(GetRand(200)) / 10.0f + 1.0f;

			Vec2 pos;
			pos.x = m_particlePosX + cosf(randSin) * 2.0f;
			pos.y = m_particlePosY + sinf(randSin) * 2.0f;

			Vec2 vec;
			vec.x = cosf(randSin) * randSpeed;
			vec.y = sinf(randSin) * randSpeed;

			pParticle->start(pos);
			pParticle->setVec(vec);
			pParticle->setRadius(2.0f);
			pParticle->setColor(kColor::Yellow);
			pParticle->setGravity(0.4f);

			m_particleCount++;
			if (m_particleCount >= count)
			{
				if (first)
				{
					first = false;
					second = true;
					m_particlePosX = 1500;
					m_particlePosY = 350;
				}
				else if (second)
				{
					second = false;
					third = true;
					m_particlePosX = 500;
					m_particlePosY = 700;
				}
				else if (third)
				{
					third = false;
					first = true;
					m_particlePosX = 450;
					m_particlePosY = 250;
				}
				break;
			}
		}
		m_flowerFrame = kParticle::FlowerInterval;
	}
}

void ScenePause::drawParticle()
{
	for (auto& pParticle : m_particle)
	{
		if (!pParticle->isExist())	continue;
		pParticle->draw();
	}
}
