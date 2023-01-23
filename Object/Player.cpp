#include "Player.h"
#include "../Util/Pad.h"

Player::Player() :
	m_posX(0),
	m_posY(0),
	m_flameX(0),
	m_flameY(0),
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
	m_posX = 0;
	m_posY = 0;
	m_flameX = 0;
	m_flameY = 0;
	m_speedX = 0;
	m_speedY = 0;
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
	m_flameX += m_speedX;
	m_flameY -= m_speedY;
}

void Player::draw()
{
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_player[y][x] == 1)
			{
				DrawBox(m_flameX + x * DRAW_WIDTH, m_flameY + y * DRAW_WIDTH,
						(m_flameX + x * DRAW_WIDTH) + DRAW_WIDTH, (m_flameY + y * DRAW_WIDTH) + DRAW_WIDTH,
						GetColor(255, 0, 255), true);
					
			}
		}
	}
	DrawFormatString(600, 0, GetColor(255, 0, 0), "m_posX:%d", m_posX);
	DrawFormatString(600, 50, GetColor(255, 0, 0), "m_posY:%d", m_posY);
	DrawFormatString(600, 100, GetColor(255, 0, 0), "m_flameX:%d", m_flameX);
	DrawFormatString(600, 150, GetColor(255, 0, 0), "m_flameY:%d", m_flameY);


}

void Player::operation(bool colL, bool colR, bool colUp, bool colDown)
{
	if (Pad::isPress(PAD_INPUT_LEFT))
	{
		if (!colL)
		{
			m_flameX -= 40;
			m_posX = m_flameX / DRAW_WIDTH;
		}
		
	}
	if (Pad::isPress(PAD_INPUT_RIGHT))
	{
		if (!colR)
		{
			m_flameX += 40;
			m_posX = m_flameX / DRAW_WIDTH;
		}
	}
	if (Pad::isPress(PAD_INPUT_UP))
	{
		if (!colUp)
		{
			m_flameY -= 40;
			m_posY = m_flameY / DRAW_WIDTH;
		}
	}
	if (Pad::isPress(PAD_INPUT_DOWN))
	{
		if (!colDown)
		{
			m_flameY += 40;
			m_posY = m_flameY / DRAW_WIDTH;
		}
	}
}
