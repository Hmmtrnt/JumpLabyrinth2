#include "Player.h"
#include "../Util/Pad.h"

namespace
{
	constexpr int motionCount = 45;
}

Player::Player() :
	m_posX(0),
	m_posY(0),
	m_frameX(0),
	m_frameY(0),
	m_speedX(0),
	m_speedY(0),
	m_handle(-1),
	m_handle2(-1),
	m_handlenumX(-1),
	m_verXPlayer(0),
	m_verYPlayer(0),
	m_frameCount(0),
	m_rota(0.0f)
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
	m_verXPlayer = 0;
	m_verYPlayer = 0;
	m_frameCount = motionCount;
	m_rota = 0.0f;
	m_handle = draw::MyLoadGraph("data/AnimationSheet_Character.png");

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
	DeleteGraph(m_handle);
	DeleteGraph(m_handle2);
}

void Player::update()
{
	m_frameX += m_speedX;
	m_posX = m_frameX / DRAW_WIDTH;
	m_frameY += m_speedY;
	m_posY = m_frameY / DRAW_WIDTH;
	
	//motion();
	//standMotion();
	//jumpMotion();
}

void Player::draw()
{
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_player[y][x] == 1)
			{
				if (Pad::isPress(PAD_INPUT_DOWN) == 0 &&
					Pad::isPress(PAD_INPUT_RIGHT) == 0 &&
					Pad::isPress(PAD_INPUT_LEFT) == 0)
				{
					// 上
					if (Pad::isTrigger(PAD_INPUT_UP) == 1)
					{
						m_rota = PI / 1;
						//	printfDx("上\n");
					}
				}
				if (Pad::isPress(PAD_INPUT_UP) == 0 &&
					Pad::isPress(PAD_INPUT_RIGHT) == 0 &&
					Pad::isPress(PAD_INPUT_LEFT) == 0)
				{
					// 下
					if (Pad::isTrigger(PAD_INPUT_DOWN) == 1)
					{
						m_rota = 0;
						//	printfDx("下\n");
					}
				}
				if (Pad::isPress(PAD_INPUT_DOWN) == 0 &&
					Pad::isPress(PAD_INPUT_UP) == 0 &&
					Pad::isPress(PAD_INPUT_LEFT) == 0)
				{
					// 右
					if (Pad::isTrigger(PAD_INPUT_RIGHT) == 1)
					{
						m_rota = PI / -2;
						//	printfDx("右\n");
					}
				}
				if (Pad::isPress(PAD_INPUT_DOWN) == 0 &&
					Pad::isPress(PAD_INPUT_UP) == 0 &&
					Pad::isPress(PAD_INPUT_RIGHT) == 0)
				{
					// 左
					if (Pad::isTrigger(PAD_INPUT_LEFT) == 1)
					{
						m_rota = PI / 2;
						//	printfDx("左\n");
					}
				}
				
				if (m_rota == PI / 2)
				{
					draw::MyDrawRectRotaGraph((m_frameX + (x * DRAW_WIDTH)) + (DRAW_WIDTH / 2), (m_frameY + (y * DRAW_WIDTH)) + (DRAW_WIDTH / 2),
						m_verXPlayer * 32, m_verYPlayer * 32,
						32, 32,
						1.3f, m_rota,
						m_handle, true, true);

				}
				else
				{
					draw::MyDrawRectRotaGraph((m_frameX + (x * DRAW_WIDTH)) + (DRAW_WIDTH / 2), (m_frameY + (y * DRAW_WIDTH)) + (DRAW_WIDTH / 2),
						m_verXPlayer * 32, m_verYPlayer * 32,
						32, 32,
						1.3f, m_rota,
						m_handle, true, false);
				}
				motion();
			}
		}
	}
	DrawFormatString(600, 0, GetColor(255, 0, 0), "m_frameCount:%d", m_frameCount);
	DrawFormatString(600, 50, GetColor(255, 0, 0), "m_verXPlayer:%d", m_verXPlayer);
	DrawFormatString(600, 100, GetColor(255, 0, 0), "m_verYPlayer:%d", m_verYPlayer);
	//DrawFormatString(600, 150, GetColor(255, 0, 0), "m_flameY:%d", m_frameY);
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
		if (Pad::isPress(PAD_INPUT_DOWN) == 0 &&
			Pad::isPress(PAD_INPUT_RIGHT) == 0 &&
			Pad::isPress(PAD_INPUT_UP) == 0)
		{
			if (Pad::isTrigger(PAD_INPUT_LEFT) == 1)
			{
				if (!colL)
				{
					m_speedX = -40;
				}

			}
		}
		if (Pad::isPress(PAD_INPUT_UP) == 0 &&
			Pad::isPress(PAD_INPUT_DOWN) == 0 &&
			Pad::isPress(PAD_INPUT_LEFT) == 0)
		{
			if (Pad::isTrigger(PAD_INPUT_RIGHT) == 1)
			{
				if (!colR)
				{
					m_speedX = 40;
				}
			}
		}
		if (Pad::isPress(PAD_INPUT_DOWN) == 0 &&
			Pad::isPress(PAD_INPUT_RIGHT) == 0 &&
			Pad::isPress(PAD_INPUT_LEFT) == 0)
		{
			if (Pad::isTrigger(PAD_INPUT_UP) == 1)
			{
				if (!colUp)
				{
					m_speedY = -40;
				}
			}
		}
		if (Pad::isPress(PAD_INPUT_UP) == 0 &&
			Pad::isPress(PAD_INPUT_RIGHT) == 0 &&
			Pad::isPress(PAD_INPUT_LEFT) == 0)
		{
			if (Pad::isTrigger(PAD_INPUT_DOWN) == 1)
			{
				if (!colDown)
				{
					m_speedY = 40;
				}
			}
		}
#endif
	}
}

void Player::motion()
{
	m_frameCount--;

	if (m_speedX != 0 || m_speedY != 0)
	{
		
		m_frameCount = motionCount;
	}
	if (m_speedX == 0 && m_speedY == 0)
	{
		if (m_frameCount <= 0 && m_verXPlayer != 1)
		{
			m_verXPlayer = 1;
			m_verYPlayer = 0;
			m_frameCount = motionCount;
		}
		else if (m_frameCount <= 0 && m_verXPlayer != 0)
		{
			m_verXPlayer = 0;
			m_verYPlayer = 0;
			m_frameCount = motionCount;
		}
	}
}

void Player::standMotion()
{
	m_frameCount--;

	if (m_speedX != 0 || m_speedY != 0)
	{
		m_verXPlayer = 0;
		m_verYPlayer = 0;
		m_frameCount = motionCount;
	}

	if (m_frameCount <= 0 && m_verXPlayer != 1)
	{
		m_verXPlayer = 1;
		m_frameCount = motionCount;
	}
	else if (m_frameCount <= 0 && m_verXPlayer != 0)
	{
		m_verXPlayer = 0;
		m_frameCount = motionCount;
	}
}

void Player::jumpMotion()
{

	if (m_speedX != 0 || m_speedY != 0)
	{
		m_verXPlayer = 2;
		m_verYPlayer = 5;
		m_frameCount = motionCount;
	}
	else if (m_speedX == 0 && m_speedY == 0 && m_verXPlayer == 2 && m_verYPlayer == 5)
	{
		m_verXPlayer = 0;
		m_verYPlayer = 0;
		standMotion();
	}

}
