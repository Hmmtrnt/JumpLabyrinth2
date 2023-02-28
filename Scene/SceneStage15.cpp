#include "SceneStage15.h"
#include "SceneSelect.h"
#include "../Util/GameManager.h"
#include"../Object/Back.h"

SceneStage15::SceneStage15() :
	m_pushHelp(false)
{
}

void SceneStage15::init()
{
	m_posX = 1;
	m_posY = 1;

	m_frameX = 68;
	m_frameY = 68;

	m_pushHelp = false;

	m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
		kStage::stage15, kVariable::StageWidth, kVariable::StageWidth);
	SceneStageBase::init();
}

SceneBase* SceneStage15::CreateRetryStage()
{
	return new SceneStage15;
}

SceneBase* SceneStage15::update()
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

void SceneStage15::draw()
{
	SceneStageBase::draw();

	if (m_pushHelp == false)
	{
		m_pBack->drawHelp();
	}

	if (m_pushHelp == true)
	{
		m_pBack->drawExplan12_15();
	}
}
