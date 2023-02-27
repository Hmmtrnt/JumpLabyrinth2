#include "SceneStageBase.h"
#include "SceneSelect.h"
#include "../Util/GameManager.h"
#include "../Object/Back.h"

SceneStageBase::SceneStageBase() :
	m_frameCount(0),
	m_posX(0),
	m_posY(0),
	m_frameX(0),
	m_frameY(0)
{
	m_pManager = new GameManager;
	m_pBack = new Back;
}

SceneStageBase::~SceneStageBase()
{
	delete m_pManager;
	delete m_pBack;
}

void SceneStageBase::init()
{
	m_pBack->init();
}

void SceneStageBase::end()
{
	m_pManager->end();
	m_pBack->end();
}

SceneBase* SceneStageBase::update()
{
	// �t�F�[�h����
	//if (isFading())
	//{
	//	bool isOut = isFadingOut();
	//	SceneBase::updateFade();
	//	// �t�F�[�h�A�E�g�I�����ɃV�[���؂�ւ�
	//	if (!isFading() && isOut &&
	//		(m_pManager->GetPushPause() == 2 || m_pManager->GameClear))	return (new SceneSelect);
	//	if (!isFading() && isOut &&
	//		(m_pManager->GetPushPause() == 3 || m_pManager->GameOver))	return (new SceneStage1);
	//}

	//m_pManager->updateNoShot();

	if (m_pManager->GetPushPause() == 1)
	{
	}

	if (!isFading())
	{
		// �t�F�[�h�A�E�g�J�n
		//if (m_pManager->GameClear)				startFadeOut();
		// �N���A�|�[�Y��ʂ̍��ڏ���
		if (m_pManager->GameClear && m_pManager->GetPushPause() == 1)				startFadeOut();// �|�[�Y��ʂ̍��ڇ@
		if (m_pManager->GameClear && m_pManager->GetPushPause() == 2)				startFadeOut();// �|�[�Y��ʂ̍��ڇA
		if (m_pManager->GameClear && m_pManager->GetPushPause() == 3)				startFadeOut();// �|�[�Y��ʂ̍��ڇB

		if (m_pManager->GameOver)				startFadeOut();// �Q�[���I�[�o�[
		if (m_pManager->GetPushPause() == 1)	startFadeOut();// �|�[�Y��ʂ̍��ڇ@
		if (m_pManager->GetPushPause() == 2)	startFadeOut();// �|�[�Y��ʂ̍��ڇA
	}

	return this;
}

void SceneStageBase::draw()
{
	m_pBack->draw();
	m_pManager->draw();

	SceneBase::drawFade();
}
