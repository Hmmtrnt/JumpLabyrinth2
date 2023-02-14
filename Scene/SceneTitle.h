// �^�C�g�����
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class Back;
class Player;

class SceneTitle : public SceneBase
{
public:
	SceneTitle();
	virtual ~SceneTitle();

	virtual void init();			// ������
	virtual void end();				// �I������
	virtual SceneBase* update();	// �X�V����
	virtual void draw();			// �`��

private:
	// �e�L�X�g�n���h��
	int m_textHandle;
	// �e�L�X�g�̓_��
	int m_textFlash;		// �t���[��
	int m_textShow;			// �\��
	int m_textHide;			// ��\��

	// �t�H���g�̃f�[�^
	int m_fontTitle;			// �^�C�g��
	int m_fontOthers;			// �^�C�g���ȊO

	Back* m_pBack;
	Player* m_pPlayer;
};

