#include "SceneStage16.h"
#include "SceneSelect.h"
#include "../Util/GameManager.h"

SceneStage16::SceneStage16() :
	m_frameCount(0),
	m_posX(0),
	m_posY(0),
	m_frameX(0),
	m_frameY(0)
{
	m_pManager = new GameManager;
}

SceneStage16::~SceneStage16()
{
	delete m_pManager;
}

void SceneStage16::init()
{
	m_frameCount = 90;
	m_posX = 11;
	m_posY = 12;
	/*m_frameX = 440;
	m_frameY = 480;*/

	m_frameX = 748;
	m_frameY = 816;

	m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
		kStage::stage16, kVariable::StageWidth, kVariable::StageWidth);
}

void SceneStage16::end()
{
	m_pManager->end();
}

SceneBase* SceneStage16::update()
{
	m_pManager->update();

	if (m_pManager->GetPushPause() == 1)
	{
	}
	else if (m_pManager->GetPushPause() == 2)
	{
		return(new SceneSelect);
	}
	else if (m_pManager->GetPushPause() == 3)
	{
		return(new SceneStage16);
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

void SceneStage16::draw()
{
	m_pManager->draw();
}
