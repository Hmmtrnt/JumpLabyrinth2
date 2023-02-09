#include "Shot.h"
#include "../Util/Pad.h"


namespace
{
	constexpr float kShotSize = 1.7f;
	constexpr int kVec = kVariable::DrawWidth;
}

Shot::Shot() :
	m_handle(0),
	m_rota(0.0f),
	m_posX(0),
	m_posY(0),
	m_speedX(0),
	m_speedY(0),
	m_frameCount(0)
{

}

Shot::~Shot()
{
}

// èâä˙âª(é¿å±óp)
void Shot::init(int posX, int posY)
{
	m_handle = draw::MyLoadGraph("data/arrow4.png");

	m_rota = 0;

	m_posX = posX;
	m_posY = posY;

	m_speedX = 0;
	m_speedY = 0;

	m_frameCount = 60;
}

void Shot::end()
{
	DeleteGraph(m_handle);
}

void Shot::update()
{

}

void Shot::draw(int &posX, int &posY)
{
	draw::MyDrawRectRotaGraph(m_posX + (kVariable::DrawWidth / 2), m_posY + (kVariable::DrawWidth / 2),
		0, 0,
		40, 40,
		kShotSize, m_rota,
		m_handle, true , false);
}

void Shot::shotRight(int posX, int posY, int sizeX, int stagePosX)
{
	m_frameCount--;

	m_posX += m_speedX;

	if (stagePosX <= m_posX + sizeX)
	{
		m_speedX = 0;
	}
	else
	{
		m_speedX = kVec;
	}
	if (m_frameCount <= 0)
	{
		m_frameCount = 0;
		init(posX, posY);
	}
}

void Shot::shotLeft(int &posX, int &stagePosX)
{
	posX += m_speedX;

	if (stagePosX >= posX)
	{
		m_speedX = 0;
	}
	else
	{
		m_speedX = -kVec;
	}
	
}

void Shot::shotUp(int posX, int posY, int stagePosY)
{
	m_frameCount--;

	m_posY += m_speedY;

	if (stagePosY >= m_posY && m_frameCount > 0)
	{
		m_speedY = 0;
	}
	else
	{
		m_speedY = -kVec;
	}
	if (m_frameCount <= 0)
	{
		m_frameCount = 0;
		init(posX, posY);
	}
}

void Shot::shotBottom(int &posY, int &sizeY, int &stagePosY)
{
	posY += m_speedY;

	if (stagePosY <= posY + sizeY)
	{
		m_speedY = 0;
	}
	else
	{
		m_speedY = kVec;
	}
}