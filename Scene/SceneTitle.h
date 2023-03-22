// �^�C�g�����
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class Back;
class Player;
class Stage;

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
	int m_textFlashCount;		// �t���[��
	int m_textShow;				// �\��
	int m_textHide;				// ��\��

	// �t�H���g�̃f�[�^
	int m_fontTitle;			// �^�C�g��
	int m_fontGuide;			// �^�C�g���ȊO

	// �v���C���[���W
	int m_posX;			// X���W
	int m_posY;			// Y���W

	// ���̃n���h��
	int m_pushSound;		// �������Ƃ�
	int m_backGroundSound;	// bgm

	// �����쎞��
	int m_waitingTime;

	Back* m_pBack;
	Player* m_pPlayer;
	Stage* m_pStage;
};

