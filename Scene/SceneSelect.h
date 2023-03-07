// �Z���N�g���
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"
#include <vector>

class Back;

class SceneSelect : public SceneBase
{
public:
	SceneSelect();
	virtual ~SceneSelect();

	virtual void init();			// ������
	virtual void end();				// �I������
	virtual SceneBase* update();	// �X�V����
	virtual void draw();			// �`��

private:

	void difficultyDraw();	// ��Փx�\��
	void difficulty1Draw();	// ��Փx1
	void difficulty2Draw();	// ��Փx2
	void difficulty3Draw();	// ��Փx3
	void difficulty4Draw();	// ��Փx4
	void difficulty5Draw();	// ��Փx5
	void difficulty6Draw();	// ��Փx6

	// �e�L�X�g�n���h��
	int m_textHandle;
	int m_textHandle2;

	// ��������X�e�[�W��
	int m_createStage;

	// �X�e�[�W��
	int m_stageNum;
	int m_stageNumText;

	// �Z���N�g���ڂ̈ʒu
	int m_selectPos;

	// �J�[�\���̎������W
	int m_cursorX;		// X���W
	int m_cursorY;		// Y���W

	// �J�[�\���̕\���ʒu
	int m_cursorPosX;	// X���W
	int m_cursorPosY;	// Y���W
	int m_cursorPosW;	// ����
	int m_cursorPosH;	// �c��

	// �X�e�[�W�n���h��
	int m_stageH1;
	int m_stageH2;
	int m_stageH3;
	int m_stageH4;
	int m_stageH5;
	int m_stageH6;
	int m_stageH7;
	int m_stageH8;
	int m_stageH9;
	int m_stageH10;
	int m_stageH11;
	int m_stageH12;
	int m_stageH13;
	int m_stageH14;
	int m_stageH15;
	int m_stageH16;
	int m_stageH17;
	int m_stageH18;
	int m_stageH19;
	int m_stageH20;

	// �I������Ă���X�e�[�W�n���h��
	int m_centerStageH;

	// ��Փx��\�����鐯�n���h��
	int m_starTest;

	// �{�^���̕`��n���h��
	int m_buttonHandle;

	// ���n���h��
	int m_cursorSound;		// �J�[�\���ړ���
	int m_decideSound;		// ���艹
	int m_backGroundSound;	// bgm

	// bgm�����Ă��邩�^�U
	bool m_playSound;
	// �^�C�g����ʂɖ߂邩�^�U
	bool m_pushTitle;

	Back* m_pBack;
};