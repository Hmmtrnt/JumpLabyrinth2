#include "SceneStage11.h"
#include "SceneSelect.h"
#include "../Util/GameManager.h"

SceneStage11::SceneStage11() :
	m_frameCount(0),
	m_posX(0),
	m_posY(0),
	m_frameX(0),
	m_frameY(0)
{
	m_pManager = new GameManager;
}

SceneStage11::~SceneStage11()
{
	delete m_pManager;
}

void SceneStage11::init()
{
	m_frameCount = 90;
	m_posX = 11;
	m_posY = 1;
	m_frameX = 440;
	m_frameY = 40;

	m_pManager->init11(m_posX, m_posY, m_frameX, m_frameY);
}

void SceneStage11::end()
{
	m_pManager->end();
}

SceneBase* SceneStage11::update()
{
	m_pManager->updateNoShot();

	if (m_pManager->GetPushPause() == 1)
	{
	}
	else if (m_pManager->GetPushPause() == 2)
	{
		return(new SceneSelect);
	}
	else if (m_pManager->GetPushPause() == 3)
	{
		return(new SceneStage11);
	}

	if (m_pManager->GameOver)
	{
		m_frameCount--;

		if (m_frameCount <= 0)
		{
			return(new SceneSelect);
		}
	}
	if (m_pManager->GameClear)
	{
		return(new SceneSelect);
	}

	return this;
}

void SceneStage11::draw()
{
	m_pManager->draw();
}
