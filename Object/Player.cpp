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
	m_handleEffect(-1),
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
	m_handle2 = draw::MyLoadGraph("data/moveChar2.png");
	m_handleEffect = draw::MyLoadGraph("data/charEffect2.png");

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
				if (m_rota == PI / 2 && m_speedX == 0 && m_speedY == 0)
				{
					draw::MyDrawRectRotaGraph((m_frameX + (x * DRAW_WIDTH)) + (DRAW_WIDTH / 2), (m_frameY + (y * DRAW_WIDTH)) + (DRAW_WIDTH / 2),
						m_verXPlayer * 32, m_verYPlayer * 32,
						32, 32,
						1.3f, m_rota,
						m_handle, true, true);

				}
				else if (m_speedX == 0 && m_speedY == 0)
				{
					draw::MyDrawRectRotaGraph((m_frameX + (x * DRAW_WIDTH)) + (DRAW_WIDTH / 2), (m_frameY + (y * DRAW_WIDTH)) + (DRAW_WIDTH / 2),
						m_verXPlayer * 32, m_verYPlayer * 32,
						32, 32,
						1.3f, m_rota,
						m_handle, true, false);
				}
				motion(x, y);
			}
		}
	}
	/*DrawFormatString(600, 0, GetColor(255, 0, 0), "m_frameCount:%d", m_frameCount);
	DrawFormatString(600, 50, GetColor(255, 0, 0), "m_verXPlayer:%d", m_verXPlayer);
	DrawFormatString(600, 100, GetColor(255, 0, 0), "m_verYPlayer:%d", m_verYPlayer);
	DrawFormatString(600, 150, GetColor(255, 0, 0), "m_flameY:%d", m_frameY);*/
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
		// �f�o�b�O�p
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
		// ���K�p
		if (Pad::isPress(PAD_INPUT_DOWN) == 0 &&
			Pad::isPress(PAD_INPUT_RIGHT) == 0 &&
			Pad::isPress(PAD_INPUT_LEFT) == 0)
		{
			// ��
			if (Pad::isTrigger(PAD_INPUT_UP) == 1)
			{
				m_rota = PI / 1;
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
			// ��
			if (Pad::isTrigger(PAD_INPUT_DOWN) == 1)
			{
				m_rota = 0;
				if (!colDown)
				{
					m_speedY = 40;
				}
			}
		}
		if (Pad::isPress(PAD_INPUT_DOWN) == 0 &&
			Pad::isPress(PAD_INPUT_UP) == 0 &&
			Pad::isPress(PAD_INPUT_LEFT) == 0)
		{
			// �E
			if (Pad::isTrigger(PAD_INPUT_RIGHT) == 1)
			{
				m_rota = PI / -2;
				if (!colR)
				{
					m_speedX = 40;
				}
			}
		}
		if (Pad::isPress(PAD_INPUT_DOWN) == 0 &&
			Pad::isPress(PAD_INPUT_UP) == 0 &&
			Pad::isPress(PAD_INPUT_RIGHT) == 0)
		{
			// ��
			if (Pad::isTrigger(PAD_INPUT_LEFT) == 1)
			{
				m_rota = PI / 2;
				if (!colL)
				{
					m_speedX = -40;
				}
			}
		}
#endif
	}
}

void Player::motion(int x, int y)
{
	m_frameCount--;

	// �ړ����̃L�����̌�����
	if (m_speedX != 0 || m_speedY != 0)
	{
		draw::MyDrawRectRotaGraph((m_frameX + (x * DRAW_WIDTH)) + (DRAW_WIDTH / 2), (m_frameY + (y * DRAW_WIDTH)) + (DRAW_WIDTH / 2),
			0, 0,
			40, 40,
			1.0f, m_rota,
			m_handle2, true, false);
		m_frameCount = motionCount;
	}

	if (m_speedY == -40)
	{
		draw::MyDrawRectRotaGraph((m_frameX + (x * DRAW_WIDTH)) + (DRAW_WIDTH / 2), (m_frameY + (y * DRAW_WIDTH)) + (DRAW_WIDTH / 2),
			0, 0,
			40, 40,
			1.0f, m_rota,
			m_handleEffect, true, false);
	}
	if (m_speedY == 40)
	{
		draw::MyDrawRectRotaGraph((m_frameX + (x * DRAW_WIDTH)) + (DRAW_WIDTH / 2), (m_frameY + (y * DRAW_WIDTH)) + (DRAW_WIDTH / 2),
			0, 0,
			40, 40,
			1.0f, m_rota,
			m_handleEffect, true, false);
	}
	if (m_speedX == -40)
	{
		draw::MyDrawRectRotaGraph((m_frameX + (x * DRAW_WIDTH)) + (DRAW_WIDTH / 2), (m_frameY + (y * DRAW_WIDTH)) + (DRAW_WIDTH / 2),
			0, 0,
			40, 40,
			1.0f, m_rota,
			m_handleEffect, true, false);
	}
	if (m_speedX == 40)
	{
		draw::MyDrawRectRotaGraph((m_frameX + (x * DRAW_WIDTH)) + (DRAW_WIDTH / 2), (m_frameY + (y * DRAW_WIDTH)) + (DRAW_WIDTH / 2),
			0, 0,
			40, 40,
			1.0f, m_rota,
			m_handleEffect, true, false);
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