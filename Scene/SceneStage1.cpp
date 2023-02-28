#include "SceneStage1.h"
#include "SceneSelect.h"
#include "../Util/GameManager.h"
#include"../Object/Back.h"

void SceneStage1::init()
{
	m_posX = 1;
	m_posY = 12;

	m_frameX = 68;
	m_frameY = 816;

	m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY, 
						 kStage::stage1, kVariable::StageWidth, kVariable::StageWidth);
	SceneStageBase::init();
}

SceneBase* SceneStage1::CreateRetryStage()
{
	return new SceneStage1;
}

SceneBase* SceneStage1::update()
{
	SceneBase* pScene = updateBefore();

	m_pManager->updateNoShot();

	SceneStageBase::update();

	return pScene;
}

void SceneStage1::draw()
{
	SceneStageBase::draw();
	m_pBack->drawMenuGuide();
}
