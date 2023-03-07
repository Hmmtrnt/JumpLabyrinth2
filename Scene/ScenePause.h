#pragma once
#include "../Util/common.h"


class ScenePause
{
public:
	ScenePause();
	virtual ~ScenePause();

	void init();			// ������
	void end();				// �I��
	void updatePause();		// �|�[�Y�X�V
	void drawPause();		// �|�[�Y�\��

	void updateClearPause();// �N���A�|�[�Y�X�V
	void drawClearPause();	// �N���A�|�[�Y�\��

	// �������񐔂̏��擾
	int GetPushNum(){ return m_pushNum; }

private:
	// �e�L�X�g�n���h��
	int m_textHandle;
	// ���̈ʒu
	int m_posCursor;		// �|�[�Y���
	int m_posClearCursorY;	// �N���A���
	// ��������
	int m_pushNum;
	// �N���A���̃|�[�Y�ʒu
	int m_posClearPauseX;		// ������W
	int m_posClearPauseY;
	int m_sizeClearPauseX;		// �T�C�Y���W
	int m_sizeClearPauseY;
	int m_posClearTextX;		// �N���A�|�[�Y��ʂ̃e�L�X�g���W
	int m_posClearCursorX;		// �N���A�|�[�Y��ʂ̃J�[�\���ʒu
	int m_posClearTextY1;		// ����1
	int m_posClearTextY2;		// 2
	int m_posClearTextY3;		// 3
	int m_itemNum;

	// ���n���h��
	int m_cursorSound;		// �J�[�\���ړ���
	int m_cursorNotSound;	// �J�[�\���ړ��ł��Ȃ���

	bool isInit = false;
};