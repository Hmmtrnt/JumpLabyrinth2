#include "SceneSelect.h"
#include "SceneTitle.h"
#include "SceneStage1.h"
#include "SceneStage2.h"
#include "SceneStage3.h"
#include "SceneStage4.h"
#include "SceneStage5.h"
#include "SceneStage6.h"
#include "SceneStage7.h"
#include "SceneStage8.h"
#include "SceneStage9.h"
#include "SceneStage10.h"
#include "SceneStage11.h"
#include "SceneStage12.h"
#include "SceneStage13.h"
#include "SceneStage14.h"
#include "SceneStage15.h"
#include "SceneStage16.h"
#include "SceneStage17.h"
#include "SceneStage18.h"
#include "SceneStage19.h"
#include "SceneStage20.h"
#include "../Object/Back.h"
#include "../Util/Pad.h"

SceneSelect::SceneSelect() :
	m_stageSelect(0),
	m_textHandle(-1),
	m_textHandle2(-1),
	m_createStage(0),
	m_pushTitle(false)
{
	m_pBack = new Back;
}

SceneSelect::~SceneSelect()
{
	delete m_pBack;
}

void SceneSelect::init()
{
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
	m_stageSelect = 1;
	m_textHandle = CreateFontToHandle("Silver", 100, -1, -1);
	m_textHandle2 = CreateFontToHandle("Silver", 50, -1, -1);
	m_createStage = 20;
	m_textHandle = 
	m_pushTitle = false;
	m_pBack->init();
}

void SceneSelect::end()
{
	DeleteFontToHandle(m_textHandle);
	DeleteFontToHandle(m_textHandle2);
	m_pBack->end();
}

SceneBase* SceneSelect::update()
{
	//�t�F�[�h����
	if (isFading())
	{
		bool isOut = isFadingOut();
		SceneBase::updateFade();
		// �t�F�[�h�A�E�g�I�����ɃV�[���؂�ւ�
		if (!isFading() && isOut && m_pushTitle)			return (new SceneTitle);
		if (!isFading() && isOut && m_stageSelect == 1)		return (new SceneStage1);
		if (!isFading() && isOut && m_stageSelect == 2)		return (new SceneStage2);
		if (!isFading() && isOut && m_stageSelect == 3)		return (new SceneStage3);
		if (!isFading() && isOut && m_stageSelect == 4)		return (new SceneStage4);
		if (!isFading() && isOut && m_stageSelect == 5)		return (new SceneStage5);
		if (!isFading() && isOut && m_stageSelect == 6)		return (new SceneStage6);
		if (!isFading() && isOut && m_stageSelect == 7)		return (new SceneStage7);
		if (!isFading() && isOut && m_stageSelect == 8)		return (new SceneStage8);
		if (!isFading() && isOut && m_stageSelect == 9)		return (new SceneStage9);
		if (!isFading() && isOut && m_stageSelect == 10)	return (new SceneStage10);
		if (!isFading() && isOut && m_stageSelect == 11)	return (new SceneStage11);
		if (!isFading() && isOut && m_stageSelect == 12)	return (new SceneStage12);
		if (!isFading() && isOut && m_stageSelect == 13)	return (new SceneStage13);
		if (!isFading() && isOut && m_stageSelect == 14)	return (new SceneStage14);
		if (!isFading() && isOut && m_stageSelect == 15)	return (new SceneStage15);
		if (!isFading() && isOut && m_stageSelect == 16)	return (new SceneStage16);
		if (!isFading() && isOut && m_stageSelect == 17)	return (new SceneStage17);
		if (!isFading() && isOut && m_stageSelect == 18)	return (new SceneStage18);
		if (!isFading() && isOut && m_stageSelect == 19)	return (new SceneStage19);
		if (!isFading() && isOut && m_stageSelect == 20)	return (new SceneStage20);
	}

	// �X�e�[�W�I��
	if (Pad::isTrigger(PAD_INPUT_RIGHT) == 1)
	{
		m_stageSelect++;
	}
	else if (Pad::isTrigger(PAD_INPUT_LEFT) == 1)
	{
		m_stageSelect--;
	}
	else if (Pad::isTrigger(PAD_INPUT_Y) == 1)
	{
		m_stageSelect -= 5;
	}
	else if (Pad::isTrigger(PAD_INPUT_Z) == 1)
	{
		m_stageSelect += 5;
	}
	if (m_stageSelect <= 1)
	{
		m_stageSelect = 1;
	}
	else if (m_stageSelect >= m_createStage)
	{
		m_stageSelect = m_createStage;
	}

	if (Pad::isTrigger(PAD_INPUT_1))	m_pushTitle = true;

	if (!isFading())
	{
		if (Pad::isTrigger(PAD_INPUT_2) || Pad::isTrigger(PAD_INPUT_1))
		{
			// �t�F�[�h�A�E�g�J�n
			startFadeOut();
		}
	}
	return this;
}

void SceneSelect::draw()
{
	m_pBack->draw();
	DrawStringToHandle(300, 180, "�X�e�[�W", kColor::White,m_textHandle2 );
	if (m_stageSelect <= 9)
	{
		DrawFormatStringToHandle(380, 240, kColor::White, m_textHandle, "%d", m_stageSelect);
	}
	else
	{
		DrawFormatStringToHandle(360, 240, kColor::White, m_textHandle, "%d", m_stageSelect);
	}
	DrawStringToHandle(300, 500, "B�{�^���ŃX�e�[�W��I��", kColor::White, m_textHandle2);
	DrawFormatStringToHandle(300, 550, kColor::White, m_textHandle2, "%d�X�e�[�W�܂ŏo���Ă��܂�\n", m_createStage);
	DrawStringToHandle(600, 200, "RB�{�^���{5", kColor::White, m_textHandle2);
	DrawFormatStringToHandle(600, 240, kColor::White, m_textHandle, "��");
	if (m_stageSelect != 1)
	{
		DrawStringToHandle(100, 200, "LB�{�^���[5", kColor::White, m_textHandle2);
		DrawFormatStringToHandle(100, 240, kColor::White, m_textHandle, "��");
	}
	SceneBase::drawFade();
}
