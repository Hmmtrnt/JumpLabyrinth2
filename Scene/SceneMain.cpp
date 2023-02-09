#include "SceneMain.h"
#include "SceneSelect.h"
#include "../Util/GameManager.h"

SceneMain::SceneMain() :
	m_frameCount(0)
{
}

SceneMain::~SceneMain()
{
}

void SceneMain::init()
{
	m_frameCount = 90;
	m_pManager->initP();
}

void SceneMain::end()
{
	m_pManager->end();
}

SceneBase* SceneMain::update()
{

	if (m_pManager->GetPushPause() == 1)
	{
	}
	else if (m_pManager->GetPushPause() == 2)
	{
		return(new SceneSelect);
	}
	else if (m_pManager->GetPushPause() == 3)
	{
		return(new SceneMain);
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

void SceneMain::draw()
{
}
