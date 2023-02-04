#include "SceneStage8.h"
#include "SceneSelect.h"
#include "../Util/GameManager.h"

SceneStage8::SceneStage8() :
	m_frameCount(0)
{
	m_pManager = new GameManager;
}

SceneStage8::~SceneStage8()
{
	delete m_pManager;
}

void SceneStage8::init()
{
	m_frameCount = 90;
	m_pManager->init8();
}

void SceneStage8::end()
{
	m_pManager->end();
}

SceneBase* SceneStage8::update()
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
		return(new SceneStage8);
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

void SceneStage8::draw()
{
	m_pManager->draw();
}