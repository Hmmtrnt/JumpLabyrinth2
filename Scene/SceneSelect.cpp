#include "SceneSelect.h"
#include "SceneMain.h"
#include "SceneStage1.h"
#include "../Util/Pad.h"

SceneSelect::SceneSelect() :
	m_stageSelect(0),
	m_textHandle(-1),
	m_textHandle2(-1)
{
}

SceneSelect::~SceneSelect()
{
}

void SceneSelect::init()
{
	m_stageSelect = 0;
	m_textHandle = CreateFontToHandle(NULL, 100, 3);
	m_textHandle2 = CreateFontToHandle(NULL, 50, 3);
}

void SceneSelect::end()
{
	DeleteFontToHandle(m_textHandle);
	DeleteFontToHandle(m_textHandle2);
}

SceneBase* SceneSelect::update()
{
	if (Pad::isTrigger(PAD_INPUT_RIGHT) == 1)
	{
		m_stageSelect++;
	}
	else if (Pad::isTrigger(PAD_INPUT_LEFT) == 1)
	{
		m_stageSelect--;
	}

	if (m_stageSelect <= 0)
	{
		m_stageSelect = 0;
	}

	// �v���g�^�C�v�p�X�e�[�W�ւ̃V�[���J��
	if (Pad::isTrigger(PAD_INPUT_2) == 1 && m_stageSelect == 0)
	{
		return(new SceneMain);
	}
	// ��������X�e�[�W�I��
	if (Pad::isTrigger(PAD_INPUT_2) == 1 && m_stageSelect == 1)
	{
		return (new SceneStage1);
	}

	return this;
}

void SceneSelect::draw()
{
	DrawStringToHandle(300, 180, "�X�e�[�W", kColor::White,m_textHandle2 );
	DrawFormatStringToHandle(380, 240, kColor::White, m_textHandle ,"%d", m_stageSelect);
	DrawString(300, 500, "B�{�^���ŃX�e�[�W��I��", kColor::White);
	DrawString(300, 550, "1�X�e�[�W�܂łł��Ă��܂�\n", kColor::White);
	DrawString(300, 600, "0�X�e�[�W�͎����p�X�e�[�W�ł�\n", kColor::White);
	DrawFormatStringToHandle(600, 240, kColor::White, m_textHandle, "��");
	if (m_stageSelect != 0)
	{
		DrawFormatStringToHandle(100, 240, kColor::White, m_textHandle, "��");
	}
}
