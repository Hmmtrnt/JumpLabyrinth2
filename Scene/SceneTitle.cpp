#include "SceneTitle.h"
#include "SceneSelect.h"
#include "SceneDemo.h"
#include "../Object/Back.h"
#include "../Object/Player.h"
#include "../Util/Pad.h"

namespace
{
	const char* const kTitleText = "Jump Labyrinth";
	const char* const kGuideText = "Press Any Button";
	// BGM�̉���
	constexpr int kVolumeBgm = 100;
}

SceneTitle::SceneTitle() :
	m_textHandle(-1),
	m_textFlashCount(0),
	m_textShow(0),
	m_textHide(0),
	m_fontTitle(0),
	m_fontGuide(0),
	m_posX(0),	m_posY(0),
	m_pushSound(0),
	m_backGroundSound(0),
	m_waitingTime(0)
{
	m_pBack = new Back;
	m_pPlayer = new Player;
}

SceneTitle::~SceneTitle()
{
	delete m_pBack;
	delete m_pPlayer;
}

void SceneTitle::init()
{
	m_textHandle = CreateFontToHandle(NULL, 50, 4);
	m_textFlashCount = 0;
	m_textShow = 40;
	m_textHide = 20;

	m_posX = 650;
	m_posY = 205;

	// ���\�[�X�̓ǂݍ���
	LPCSTR font_path = "Font/Silver.ttf";// �ǂݍ��ރt�H���g�t�@�C���̃p�X
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0)
	{
	}
	else
	{
		// �t�H���g�ǂݍ��݃G���[����
		MessageBox(NULL, "�t�H���g�ǂݍ��ݎ��s", "", MB_OK);
	}

	m_fontTitle = CreateFontToHandle("Silver", 200, -1, 3);
	m_fontGuide = CreateFontToHandle("Silver", 100, -1, -1);
	m_pushSound = LoadSoundMem("sound/titlePushSound.mp3");
	m_backGroundSound = LoadSoundMem("sound/titleSound.mp3");
	m_pBack->init();
	m_pPlayer->initTitle();
	PlaySoundMem(m_backGroundSound, DX_PLAYTYPE_LOOP, true);
	stageSelectNum = 1;
#ifdef _DEBUG
	m_waitingTime = 60 * 5;// ��b�Ԃ̃t���[��*�b��
#else
	m_waitingTime = 60 * 15;// ��b�Ԃ̃t���[��*�b��
#endif
}

void SceneTitle::end()
{
	DeleteFontToHandle(m_textHandle);
	DeleteFontToHandle(m_fontTitle);
	DeleteFontToHandle(m_fontGuide);
	DeleteSoundMem(m_pushSound);
	DeleteSoundMem(m_backGroundSound);
	m_pBack->end();
	m_pPlayer->endTitle();
}

SceneBase* SceneTitle::update()
{
	// ���삵�Ă��Ȃ�����
	m_waitingTime--;
	// �t�F�[�h����
	if (isFading())
	{
		bool isOut = isFadingOut();
		SceneBase::updateFade(m_backGroundSound);
		// �t�F�[�h�A�E�g�I�����ɃV�[���؂�ւ�
		if (!isFading() && isOut && m_waitingTime <= 0)
		{
			return (new SceneDemo);
		}
		if (!isFading() && isOut)
		{
			return (new SceneSelect);
		}
	}

	// �e�L�X�g�̓_��
	m_textFlashCount++;
	if (m_textFlashCount >= m_textShow + m_textHide)
	{
		m_textFlashCount = 0;
	}


	if (!isFading())
	{
		if (Pad::isTrigger(PAD_INPUT_1) || Pad::isTrigger(PAD_INPUT_2) || Pad::isTrigger(PAD_INPUT_3) || 
			Pad::isTrigger(PAD_INPUT_4) || Pad::isTrigger(PAD_INPUT_UP) || Pad::isTrigger(PAD_INPUT_DOWN) || 
			Pad::isTrigger(PAD_INPUT_RIGHT) || Pad::isTrigger(PAD_INPUT_LEFT) || Pad::isTrigger(PAD_INPUT_5) ||
			Pad::isTrigger(PAD_INPUT_6) || Pad::isTrigger(PAD_INPUT_7) || Pad::isTrigger(PAD_INPUT_8))
		{
			m_textShow = 5;
			m_textHide = 5;
			PlaySoundMem(m_pushSound, DX_PLAYTYPE_BACK, true);
			// �t�F�[�h�A�E�g�J�n
			startFadeOut();
		}
		if (m_waitingTime <= 0)
		{
			// �t�F�[�h�A�E�g�J�n
			startFadeOut();
		}
	}
	return this;
}

void SceneTitle::draw()
{
	// �w�i
	m_pBack->draw();

	// �^�C�g��
	DrawStringToHandle(505, 205, kTitleText, kColor::RedBlack, m_fontTitle);
	DrawStringToHandle(500, 200, kTitleText, kColor::White, m_fontTitle);

	// �_�Ńe�L�X�g
	if (m_textFlashCount < m_textShow)
	{
		DrawStringToHandle(702, 702, kGuideText, kColor::RedBlack, m_fontGuide);
		DrawStringToHandle(700, 700, kGuideText, kColor::White, m_fontGuide);
	}
	// �^�C�g����ʂ̃v���C���[�`��
	m_pPlayer->DrawTitle(m_posX, m_posY);

	SceneBase::drawFade();
}