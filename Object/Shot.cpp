#include "Shot.h"
#include "../Util/Pad.h"

Shot::Shot() :
	m_posX(0),
	m_posY(0),
	m_frameX(0),
	m_frameY(0),
	m_speedX(0),
	m_speedY(0),
	m_stopFrame(0),
	m_handleArrow(0)
{
	for (int y = 0; y < kVariable::ShotWidth; y++)
	{
		for (int x = 0; x < kVariable::ShotWidth; x++)
		{
			m_enemy[y][x] = 0;
		}
	}
}

Shot::~Shot()
{
}

// 初期化(実験用)
void Shot::init()
{
	// 左から右に行くときの座標
	m_posX = 0;
	m_posY = 12;
	m_frameX = 0;
	m_frameY = 480;
	// 下から上に行くときの座標
	/*m_posX = 1;
	m_posY = 13;
	m_frameX = 40;
	m_frameY = 520;*/
	m_speedX = 0;
	m_speedY = 0;
	m_stopFrame = 60;

	m_handleArrow = draw::MyLoadGraph("data/arrow4.png");
	
	for (int y = 0; y < kVariable::ShotWidth; y++)
	{
		for (int x = 0; x < kVariable::ShotWidth; x++)
		{
			m_enemy[y][x] = kShot::shot[y][x];
		}
	}
}

void Shot::end()
{
	DeleteGraph(m_handleArrow);
}

void Shot::update()
{
	m_frameX += m_speedX;
	m_posX = m_frameX / kVariable::DrawWidth;
	m_frameY += m_speedY;
	m_posY = m_frameY / kVariable::DrawWidth;
}

void Shot::draw()
{
	for (int y = 0; y < kVariable::ShotWidth; y++)
	{
		for (int x = 0; x < kVariable::ShotWidth; x++)
		{
			shotDraw(x, y);
		}
	}

	/*DrawFormatString(600, 250, GetColor(255, 0, 0), "m_posX:%d", m_posX);
	DrawFormatString(600, 300, GetColor(255, 0, 0), "m_posY:%d", m_posY);
	DrawFormatString(600, 350, GetColor(255, 0, 0), "m_flameX:%d", m_frameX);
	DrawFormatString(600, 400, GetColor(255, 0, 0), "m_flameY:%d", m_frameY);
	DrawFormatString(600, 450, GetColor(255, 0, 0), "m_stopFrame:%d", m_stopFrame);*/

}

void Shot::moveWidth(bool colL, bool colR)
{
	if (colL)
	{
		m_stopFrame--;
		m_speedX = 0;
		if (m_stopFrame <= 0)
		{
			m_speedX = 40;
			m_stopFrame = 0;
		}
	}
	if (colR)
	{
	
		m_stopFrame--;
		m_speedX = 0;
		if (m_stopFrame <= 0)
		{
			m_speedX = -40;
			m_stopFrame = 0;
		}
	}

	if (!colL && !colR)
	{
		m_stopFrame = 60;
	}
}

void Shot::moveHeight(bool colUp, bool colDown)
{
	if (colUp)
	{
		m_stopFrame--;
		m_speedY = 0;
		if (m_stopFrame <= 0)
		{
			m_speedY = 40;
			m_stopFrame = 0;
		}
	}
	if (colDown)
	{
		m_stopFrame--;
		m_speedY = 0;
		if (m_stopFrame <= 0)
		{
			m_speedY = -40;
			m_stopFrame = 0;
		}
	}
	if (!colUp && !colDown)
	{
		m_stopFrame = 60;
	}
}

void Shot::shotDraw(int x, int y)
{
	if (m_enemy[y][x] == 1)
	{
		// 右向き
		if (m_speedX == 40)
		{
			draw::MyDrawRectRotaGraph((m_frameX + (x * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2), 
									  (m_frameY + (y * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
									  0, 0,
									  40, 40,
									  1.0f, PI / 2,
									  m_handleArrow, true, false);
		}
		// 左向き
		if (m_speedX == -40)
		{
			draw::MyDrawRectRotaGraph((m_frameX + (x * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2), 
									  (m_frameY + (y * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
									  0, 0,
									  40, 40,
									  1.0f, PI / -2,
									  m_handleArrow, true, false);
		}
		// 下向き
		if (m_speedY == 40)
		{
			draw::MyDrawRectRotaGraph((m_frameX + (x * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2), 
									  (m_frameY + (y * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
									  0, 0,
									  40, 40,
									  1.0f, PI / 1,
									  m_handleArrow, true, false);
		}
		// 上向き
		if (m_speedY == -40)
		{
			draw::MyDrawRectRotaGraph((m_frameX + (x * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2), 
									  (m_frameY + (y * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
									  0, 0,
									  40, 40,
									  1.0f, 0,
									  m_handleArrow, true, false);
		}
	}
}
