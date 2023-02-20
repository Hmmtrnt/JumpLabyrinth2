#include "SceneTitle.h"
#include "SceneSelect.h"
#include "../Object/Back.h"
#include "../Object/Player.h"
#include "../Util/Pad.h"

namespace
{
	const char* const kTitleText = "Jump Labyrinth";
	const char* const kGuideText = "B�{�^���������ăZ���N�g��ʂ�";
	const char* const kGuideText2 = "�W���C�p�b�h������I�X�X�����܂�";
	const char* const kGuideText3 = "BACK�{�^���ł��ł��I���ł��܂�";
}

SceneTitle::SceneTitle() :
	m_textHandle(-1),
	m_textFlashCount(0),
	m_textShow(0),
	m_textHide(0),
	m_fontTitle(0),
	m_fontOthers(0),
	m_posX(0),	m_posY(0)
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

	m_posX = 600;
	m_posY = 730;

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

	m_fontTitle = CreateFontToHandle("Silver", 200, -1, -1);
	m_fontOthers = CreateFontToHandle("Silver", 64, -1, -1);
	m_pBack->init();
	m_pPlayer->initTitle();
}

void SceneTitle::end()
{
	DeleteFontToHandle(m_textHandle);
	DeleteFontToHandle(m_fontTitle);
	DeleteFontToHandle(m_fontOthers);
	m_pBack->end();
	m_pPlayer->endTitle();
}

SceneBase* SceneTitle::update()
{
	// �t�F�[�h����
	if (isFading())
	{
		bool isOut = isFadingOut();
		SceneBase::updateFade();
		// �t�F�[�h�A�E�g�I�����ɃV�[���؂�ւ�
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
		if (Pad::isTrigger(PAD_INPUT_2))
		{
			// �t�F�[�h�A�E�g�J�n
			startFadeOut();
		}
	}
	return this;
}

void SceneTitle::draw()
{
	m_pBack->draw();

	DrawStringToHandle(500, 200, kTitleText, kColor::White, m_fontTitle);

	// �_�Ńe�L�X�g
	if (m_textFlashCount < m_textShow)
	{
		DrawStringToHandle(650, 700, kGuideText, kColor::White, m_fontOthers);
	}
	DrawStringToHandle(625, 800, kGuideText2, kColor::White, m_fontOthers);

	DrawStringToHandle(625, 900, kGuideText3, kColor::White, m_fontOthers);

	m_pPlayer->DrawOthers(m_posX, m_posY);

	SceneBase::drawFade();
}