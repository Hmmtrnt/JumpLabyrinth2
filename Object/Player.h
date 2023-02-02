// �v���C���[
#pragma once
#include "../Util/common.h"

class Player
{
public:
	Player();
	virtual ~Player();

	void initCommon();	// ���ʂ̏�����
	void initP();		// �v���g�^�C�v�p������
	void init1();		// �X�e�[�W1�̏�����
	void end();			// �I��
	void update();		// �X�V
	void draw();		// �`��

	// �v���C���[����
	void operation(bool colL,bool colR, bool colUp, bool colDown);

	// �v���C���[�̔z��̈ʒu
	int m_posX;			// X���W
	int m_posY;			// Y���W
	// �v���C���[�̈ړ��t���[��
	int m_frameX;		// X���W
	int m_frameY;		// Y���W
	// �v���C���[�̈ړ����x
	int m_speedX;		// X���W
	int m_speedY;		// Y���W

	// �v���C���[�̔z��̎󂯓n��
	int m_player[PLAYER_HEIGHT][PLAYER_WIDTH];

	// �v���C���[�̐؂��鍶��̒��_
	int m_verXPlayer;
	int m_verYPlayer;

private:
	// �v���C���[�̕`��
	void playerDraw(int x, int y);
	// ���[�V����
	void motion(int x, int y);

	// �v���C���[�n���h��
	int m_handle;		// �Î~
	int m_handle2;		// �����Ă�
	int m_handleEffect;	// �G�t�F�N�g

	// �v���C���[�摜�̔ԍ�
	int m_handlenumX;
	
	// �t���[���J�E���g
	int m_frameCount;

	// �v���C���[�̉�]
	float m_rota;
};