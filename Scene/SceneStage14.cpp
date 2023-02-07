#include "SceneStage14.h"
#include "SceneSelect.h"
#include "../Util/GameManager.h"

SceneStage14::SceneStage14() :
	m_frameCount(0),
	m_posX(0),
	m_posY(0),
	m_frameX(0),
	m_frameY(0)
{
	m_pManager = new GameManager;
}

SceneStage14::~SceneStage14()
{
	delete m_pManager;
}

void SceneStage14::init()
{
	m_frameCount = 90;
	m_posX = 6;
	m_posY = 7;
	m_frameX = 240;
	m_frameY = 280;

	m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
		kStage::stage14, kVariable::StageWidth, kVariable::StageWidth);
}

void SceneStage14::end()
{
	m_pManager->end();
}

SceneBase* SceneStage14::update()
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
		return(new SceneStage14);
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

void SceneStage14::draw()
{
	m_pManager->draw();
}
