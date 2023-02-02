#include "SceneStage2.h"
#include "SceneSelect.h"
#include "../Util/GameManager.h"

SceneStage2::SceneStage2() :
	m_frameCount(0)
{
	m_pManager = new GameManager;
}

SceneStage2::~SceneStage2()
{
	delete m_pManager;
}

void SceneStage2::init()
{
	m_frameCount = 90;
	m_pManager->init2();
}

void SceneStage2::end()
{
	m_pManager->end();
}

SceneBase* SceneStage2::update()
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

void SceneStage2::draw()
{
	m_pManager->draw();
}
