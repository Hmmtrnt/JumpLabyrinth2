#include "SceneStage1.h"
#include "SceneSelect.h"
#include "../Util/GameManager.h"

SceneStage1::SceneStage1() :
	m_frameCount(0)
{
	m_pManager = new GameManager;
}

SceneStage1::~SceneStage1()
{
	delete m_pManager;
}

void SceneStage1::init()
{
	m_frameCount = 90;
	m_pManager->init1();
}

void SceneStage1::end()
{
	m_pManager->end();
}

SceneBase* SceneStage1::update()
{
	m_pManager->updateNoShot();

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

void SceneStage1::draw()
{
	m_pManager->draw();
}
