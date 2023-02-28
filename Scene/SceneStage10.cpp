#include "SceneStage10.h"
#include "SceneSelect.h"
#include "../Util/GameManager.h"
#include"../Object/Back.h"

SceneStage10::SceneStage10() :
	m_pushHelp(false)
{
}

void SceneStage10::init()
{
	m_frameCount = 90; 
	m_posX = 1;
	m_posY = 12;

	m_frameX = 68;
	m_frameY = 816;

	m_pushHelp = false;

	m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
		kStage::stage10, kVariable::StageWidth, kVariable::StageWidth);
	SceneStageBase::init();
}

SceneBase* SceneStage10::CreateRetryStage()
{
	return new SceneStage10;
}

SceneBase* SceneStage10::update()
{
	SceneBase* pScene = updateBefore();

	m_pManager->updateNoShot();

	if (Pad::isTrigger(PAD_INPUT_4))
	{
		if (m_pushHelp == false)
		{
			m_pushHelp = true;
		}
		else if (m_pushHelp == true)
		{
			m_pushHelp = false;
		}
	}

	SceneStageBase::update();

	return pScene;
}

void SceneStage10::draw()
{
	SceneStageBase::draw();

	if (m_pushHelp == false)
	{
		m_pBack->drawHelp();
	}

	if (m_pushHelp == true)
	{
		m_pBack->drawExplan6And10();
	}
}
