#include "SceneStageBase.h"
#include "SceneSelect.h"
#include "../Util/GameManager.h"
#include "../Object/Back.h"

namespace
{
	// BGM�̉���
	constexpr int kVolumeBgm = 100;
}

SceneStageBase::SceneStageBase() :
	m_frameCount(0),
	m_posX(0),
	m_posY(0),
	m_frameX(0),
	m_frameY(0),
	m_backGroundSound(-1),
	m_playSound(false)
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
	m_frameCount = 90;
	m_pBack->init();
	m_backGroundSound = LoadSoundMem("sound/stageBgm.mp3");
	ChangeVolumeSoundMem(kVolumeBgm, m_backGroundSound);
	m_playSound = false;
}

void SceneStageBase::end()
{
	m_pManager->end();
	m_pBack->end();
	DeleteSoundMem(m_backGroundSound);
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

	// �����p
	/*if (isFading())
	{
		bool isOut = isFadingOut();
		SceneBase::updateFade();

		if (!isFading() && isOut &&
			m_pManager->GetPushPause() == 2 && m_pManager->GameClear) return (new SceneSelect);

		if (!isFading() && isOut &&
			m_pManager->GetPushPause() == 1 && !m_pManager->GameClear)	return (new SceneSelect);
	}*/
	

	

	//m_pManager->updateNoShot();

	// BGM�Đ�
	if (!m_playSound)
	{
		PlaySoundMem(m_backGroundSound, DX_PLAYTYPE_BACK, true);
		m_playSound = true;
	}
	// BGM����Ȃ��Ȃ����烋�[�v����悤�ɂ���
	if (CheckSoundMem(m_backGroundSound) == 0)
	{
		m_playSound = false;
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
		if (m_pManager->GetPushPause() == 1 && !m_pManager->GameClear)	startFadeOut();// �|�[�Y��ʂ̍��ڇ@, ���̏����t��
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

SceneBase* SceneStageBase::updateBefore()
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
			m_pManager->GetPushPause() == 2 && m_pManager->GameClear) return (new SceneSelect);
		if (!isFading() && isOut &&
			m_pManager->GetPushPause() == 3 && m_pManager->GameClear) return CreateRetryStage();

		if (!isFading() && isOut &&
			(m_pManager->GetPushPause() == 1 && !m_pManager->GameClear))	return (new SceneSelect);
		if (!isFading() && isOut &&
			(m_pManager->GetPushPause() == 2 || m_pManager->GameOver))	return CreateRetryStage();
	}

	return this;
}