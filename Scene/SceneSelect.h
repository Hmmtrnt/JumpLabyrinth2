// �Z���N�g���
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

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
};