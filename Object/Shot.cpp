#include "Shot.h"
#include "../Util/Pad.h"

Shot::Shot() :
	m_handle(0),
	m_posX(0),
	m_posY(0),
	m_speedX(0),
	m_speedY(0)
{

}

Shot::~Shot()
{
}

// èâä˙âª(é¿å±óp)
void Shot::init()
{
	m_handle = draw::MyLoadGraph("data/arrow4.png");

	m_speedX = 0;
	m_speedY = 0;
}

void Shot::end()
{

}

void Shot::update()
{

}

void Shot::draw()
{
	
}
