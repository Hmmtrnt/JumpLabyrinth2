#include "SceneStage6.h"
#include "SceneSelect.h"
#include "../Util/GameManager.h"

SceneStage6::SceneStage6() :
	m_frameCount(0)
{
	m_pManager = new GameManager;
}

SceneStage6::~SceneStage6()
{
	delete m_pManager;
}

void SceneStage6::init()
{
	m_frameCount = 90;
	m_pManager->init6();
}

void SceneStage6::end()
{
	m_pManager->end();
}

SceneBase* SceneStage6::update()
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
		return(new SceneStage6);
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

void SceneStage6::draw()
{
	m_pManager->draw();
}
