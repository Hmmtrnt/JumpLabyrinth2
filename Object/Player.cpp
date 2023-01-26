#include "Player.h"
#include "../Util/Pad.h"

Player::Player() :
	m_posX(0),
	m_posY(0),
	m_frameX(0),
	m_frameY(0),
	m_speedX(0),
	m_speedY(0)
{
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			m_player[y][x] = 0;
		}
	}
}

Player::~Player()
{
}

void Player::init()
{
	m_posX = 11;
	m_posY = 12;
	m_frameX = 440;
	m_frameY = 480;
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			m_player[y][x] = kPlayer::playr[y][x];
		}
	}
}

void Player::end()
{
}

void Player::update()
{
	m_frameX += m_speedX;
	m_posX = m_frameX / DRAW_WIDTH;
	m_frameY += m_speedY;
	m_posY = m_frameY / DRAW_WIDTH;
	
}

void Player::draw()
{
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_player[y][x] == 1)
			{
				DrawBox(m_frameX + x * DRAW_WIDTH, m_frameY + y * DRAW_WIDTH,
						(m_frameX + x * DRAW_WIDTH) + DRAW_WIDTH, (m_frameY + y * DRAW_WIDTH) + DRAW_WIDTH,
						kColor::Peach, true);
					
			}
		}
	}
	DrawFormatString(600, 0, GetColor(255, 0, 0), "m_posX:%d", m_posX);
	DrawFormatString(600, 50, GetColor(255, 0, 0), "m_posY:%d", m_posY);
	DrawFormatString(600, 100, GetColor(255, 0, 0), "m_flameX:%d", m_frameX);
	DrawFormatString(600, 150, GetColor(255, 0, 0), "m_flameY:%d", m_frameY);


}

void Player::operation(bool colL, bool colR, bool colUp, bool colDown)
{
	
	if (colL || colR)
	{
		m_speedX = 0;
	}
	if (colUp || colDown)
	{
		m_speedY = 0;
	}

	if (m_speedX == 0 && m_speedY == 0)
	{
#if false
		// デバッグ用
		if (Pad::isTrigger(PAD_INPUT_LEFT))
		{
			if (!colL)
			{
				m_frameX += -40;
			}

		}
		if (Pad::isTrigger(PAD_INPUT_RIGHT))
		{
			if (!colR)
			{
				m_frameX += 40;
			}
		}
		if (Pad::isTrigger(PAD_INPUT_UP))
		{
			if (!colUp)
			{
				m_frameY += -40;
			}
		}
		if (Pad::isTrigger(PAD_INPUT_DOWN))
		{
			if (!colDown)
			{
				m_frameY += 40;
			}
		}
#else
		// 正規用
		if (Pad::isPress(PAD_INPUT_LEFT))
		{
			if (!colL)
			{
				m_speedX = -40;
			}

		}
		if (Pad::isPress(PAD_INPUT_RIGHT))
		{
			if (!colR)
			{
				m_speedX = 40;
			}
		}
		if (Pad::isPress(PAD_INPUT_UP))
		{
			if (!colUp)
			{
				m_speedY = -40;
			}
		}
		if (Pad::isPress(PAD_INPUT_DOWN))
		{
			if (!colDown)
			{
				m_speedY = 40;
			}
		}
#endif
	}
}
