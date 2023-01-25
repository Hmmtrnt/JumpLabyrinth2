#include "Enemy.h"

Enemy::Enemy() :
	m_posX(0),
	m_posY(0),
	m_flameX(0),
	m_flameY(0),
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
	m_flameX = 40;
	m_flameY = 480;
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
	/*m_flameX += m_speedX;
	m_posX = m_flameX / DRAW_WIDTH;*/
	
}

void Enemy::draw()
{
	for (int y = 0; y < ENEMY_HEIGHT; y++)
	{
		for (int x = 0; x < ENEMY_WIDTH; x++)
		{
			if (m_enemy[y][x] == 1)
			{
				DrawBox(m_flameX + x * DRAW_WIDTH, m_flameY + y * DRAW_WIDTH,
					(m_flameX + x * DRAW_WIDTH) + DRAW_WIDTH, (m_flameY + y * DRAW_WIDTH) + DRAW_WIDTH,
					kColor::Green, true);
			}
		}
	}
}