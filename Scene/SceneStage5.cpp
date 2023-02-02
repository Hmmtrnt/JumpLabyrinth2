#include "SceneStage5.h"
#include "SceneSelect.h"
#include "../Util/GameManager.h"

SceneStage5::SceneStage5() :
	m_frameCount(0)
{
	m_pManager = new GameManager;
}

SceneStage5::~SceneStage5()
{
	delete m_pManager;
}

void SceneStage5::init()
{
	m_frameCount = 90;
	m_pManager->init5();
}

void SceneStage5::end()
{
	m_pManager->end();
}

SceneBase* SceneStage5::update()
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

void SceneStage5::draw()
{
	m_pManager->draw();
}
