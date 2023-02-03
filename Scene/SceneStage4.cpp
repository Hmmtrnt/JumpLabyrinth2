#include "SceneStage4.h"
#include "SceneSelect.h"
#include "../Util/GameManager.h"

SceneStage4::SceneStage4() :
	m_frameCount(0)
{
	m_pManager = new GameManager;
}

SceneStage4::~SceneStage4()
{
	delete m_pManager;
}

void SceneStage4::init()
{
	m_frameCount = 90;
	m_pManager->init4();
}

void SceneStage4::end()
{
	m_pManager->end();
}

SceneBase* SceneStage4::update()
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
		return(new SceneStage4);
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

void SceneStage4::draw()
{
	m_pManager->draw();
}
