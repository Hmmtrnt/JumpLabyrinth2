// �Z���N�g���
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

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
	// �X�e�[�W�I�����̐�
	int m_stageSelect;
	// �e�L�X�g�n���h��
	int m_textHandle;
	int m_textHandle2;

	// ��������X�e�[�W��
	int m_createStage;

	// �^�C�g����ʂɖ߂邩�ǂ���
	bool m_pushTitle;

	Back* m_pBack;
};