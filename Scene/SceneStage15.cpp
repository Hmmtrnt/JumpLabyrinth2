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
	m_frameCount = 90;
	m_posX = 1;
	m_posY = 1;

	m_frameX = 68;
	m_frameY = 68;

	m_pushHelp = false;

	m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
		kStage::stage15, kVariable::StageWidth, kVariable::StageWidth);
	SceneStageBase::init();
}

SceneBase* SceneStage15::update()
{
	// �t�F�[�h����
	if (isFading())
	{
		bool isOut = isFadingOut();
		SceneBase::updateFade();
		// �t�F�[�h�A�E�g�I�����ɃV�[���؂�ւ�
		//if (!isFading() && isOut &&
		//	m_pManager->GetPushPause() == 1 && m_pManager->GameClear)// ������
		if (!isFading() && isOut &&
			m_pManager->GetPushPause() == 2 && m_pManager->GameClear)
		{
			return (new SceneSelect);
			printfDx("�Z���N�g��ʂ�\n");
		}
		if (!isFading() && isOut &&
			m_pManager->GetPushPause() == 3 && m_pManager->GameClear)
		{
			return (new SceneStage15);
			printfDx("���g���C\n");
		}

		if (!isFading() && isOut &&
			(m_pManager->GetPushPause() == 1 && !m_pManager->GameClear))	return (new SceneSelect);
		if (!isFading() && isOut &&
			(m_pManager->GetPushPause() == 2 || m_pManager->GameOver))	return (new SceneStage15);
	}

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

	//if (m_pManager->GetPushPause() == 1)
	//{
	//}

	//if (!isFading())
	//{
	//	// �t�F�[�h�A�E�g�J�n
	//	if (m_pManager->GameClear)				startFadeOut();
	//	if (m_pManager->GameOver)				startFadeOut();
	//	if (m_pManager->GetPushPause() == 2)	startFadeOut();
	//	if (m_pManager->GetPushPause() == 3)	startFadeOut();
	//}

	SceneStageBase::update();

	return this;
}

void SceneStage15::draw()
{
	//m_pManager->draw();

	SceneStageBase::draw();

	if (m_pushHelp == false)
	{
		m_pBack->drawHelp();
	}

	if (m_pushHelp == true)
	{
		m_pBack->drawExplan12_15();
	}

	//SceneBase::drawFade();
}
