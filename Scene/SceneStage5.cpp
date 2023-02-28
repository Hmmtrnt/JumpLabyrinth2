#include "SceneStage5.h"
#include "SceneSelect.h"
#include "../Util/GameManager.h"
#include"../Object/Back.h"

SceneStage5::SceneStage5() :
	m_pushHelp(false)
{
}

void SceneStage5::init()
{
	m_frameCount = 90;
	m_posX = 1;
	m_posY = 1;

	m_frameX = 68;
	m_frameY = 68;

	m_pushHelp = false;

	m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
		kStage::stage5, kVariable::StageWidth, kVariable::StageWidth);
	SceneStageBase::init();
}

SceneBase* SceneStage5::CreateRetryStage()
{
	return new SceneStage5;
}

SceneBase* SceneStage5::update()
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

void SceneStage5::draw()
{

	SceneStageBase::draw();

	if (!m_pushHelp)
	{
		m_pBack->drawHelp();
	}

	if (m_pushHelp)
	{
		m_pBack->drawExplan2_5();
	}
}
