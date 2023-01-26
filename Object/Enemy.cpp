#include "Enemy.h"

Enemy::Enemy() :
	m_posX(0),
	m_posY(0),
	m_frameX(0),
	m_frameY(0),
	m_speedX(0),
	m_speedY(0)
{
	for (int y = 0; y < ENEMY_HEIGHT; y++)
	{
		for (int x = 0; x < ENEMY_WIDTH; x++)
		{
			m_enemy[y][x] = 0;
		}
	}
}

Enemy::~Enemy()
{
}

void Enemy::init()
{
	m_posX = 1;
	m_posY = 12;
	m_frameX = 40;
	m_frameY = 480;
	m_speedX = 0;
	m_speedY = 0; 
	for (int y = 0; y < ENEMY_HEIGHT; y++)
	{
		for (int x = 0; x < ENEMY_WIDTH; x++)
		{
			m_enemy[y][x] = kEnemy::enemy[y][x];
		}
	}
}

void Enemy::end()
{
}

void Enemy::update()
{
	m_frameX += m_speedX;
	m_posX = m_frameX / DRAW_WIDTH;
	m_frameY += m_speedY;
	m_posY = m_frameY / DRAW_WIDTH;
}

void Enemy::draw()
{
	for (int y = 0; y < ENEMY_HEIGHT; y++)
	{
		for (int x = 0; x < ENEMY_WIDTH; x++)
		{
			if (m_enemy[y][x] == 1)
			{
				DrawBox(m_frameX + x * DRAW_WIDTH, m_frameY + y * DRAW_WIDTH,
					(m_frameX + x * DRAW_WIDTH) + DRAW_WIDTH, (m_frameY + y * DRAW_WIDTH) + DRAW_WIDTH,
					kColor::Green, true);
			}
		}
	}

	DrawFormatString(600, 250, GetColor(255, 0, 0), "m_posX:%d", m_posX);
	DrawFormatString(600, 300, GetColor(255, 0, 0), "m_posY:%d", m_posY);
	DrawFormatString(600, 350, GetColor(255, 0, 0), "m_flameX:%d", m_frameX);
	DrawFormatString(600, 400, GetColor(255, 0, 0), "m_flameY:%d", m_frameY);

}

void Enemy::moveWidth(bool colL, bool colR)
{
	if (colL)
	{
		m_speedX = 40;
	}
	if (colR)
	{
		m_speedX = -40;
	}
}

void Enemy::moveHeight(bool colUp, bool colDown)
{
	if (colUp)
	{
		m_speedY = 20;
	}
	if (colDown)
	{
		m_speedY = -20;
	}
}