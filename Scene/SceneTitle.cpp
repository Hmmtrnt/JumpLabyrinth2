#include "SceneTitle.h"
#include "SceneSelect.h"
#include "../Object/Back.h"
#include "../Object/Player.h"
#include "../Util/Pad.h"

SceneTitle::SceneTitle() :
	m_textHandle(-1),
	m_textFlash(0),
	m_textShow(0),
	m_textHide(0),
	m_fontTitle(0),
	m_fontOthers(0)
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
	m_textFlash = 0;
	m_textShow = 40;
	m_textHide = 20;

	// ���\�[�X�̓ǂݍ���
	LPCSTR font_path = "Font/marukiya.ttf";// �ǂݍ��ރt�H���g�t�@�C���̃p�X
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0)
	{

	}
	else
	{
		// �t�H���g�ǂݍ��݃G���[����
		MessageBox(NULL, "�t�H���g�ǂݍ��ݎ��s", "", MB_OK);
	}

	m_fontTitle = CreateFontToHandle("marukiya", 100, -1, -1);
	m_fontOthers = CreateFontToHandle("marukiya", 64, -1, -1);
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
	// �e�L�X�g�̓_��
	m_textFlash++;
	if (m_textFlash >= m_textShow + m_textHide)
	{
		m_textFlash = 0;
	}

	// ���̃V�[���J��
	if (Pad::isTrigger(PAD_INPUT_2) == 1)
	{
		return(new SceneSelect);
	}
	return this;
}

void SceneTitle::draw()
{
	m_pBack->draw();

	DrawStringToHandle(450, 200, "jump Labyrinth", kColor::White, m_fontTitle);

	// �_�Ńe�L�X�g
	if (m_textFlash < m_textShow)
	{
		DrawStringToHandle(500, 600, "B�{�^�����I���ăZ���N�g�K������", kColor::White, m_fontOthers);
	}
	DrawStringToHandle(500, 700, "�W���C�p�b�h�Ƀ^�C�I�E���Ă��܂�", kColor::White, m_fontOthers);

	m_pPlayer->DrawOthers(100, 100);
}