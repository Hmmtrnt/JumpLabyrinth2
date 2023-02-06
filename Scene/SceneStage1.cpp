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
	//m_pManager->initTest(1, 12, 40, 480, kStage::stage1[STAGE_HEIGHT][STAGE_WIDTH]);
}

void SceneStage1::end()
{
	m_pManager->end();
}

SceneBase* SceneStage1::update()
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
		return(new SceneStage1);
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

void SceneStage1::draw()
{
	m_pManager->draw();
}
