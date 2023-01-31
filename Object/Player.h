// �v���C���[
#pragma once
#include "../Util/common.h"

class Player
{
public:
	Player();
	virtual ~Player();

	void init();		// ������
	void end();			// �I��
	void update();		// �X�V
	void draw();		// �`��

	// �v���C���[����
	void operation(bool colL,bool colR, bool colUp, bool colDown);

	// ���[�V����
	void motion();
	// �������[�V����
	void standMotion();
	// �W�����v���[�V����
	void jumpMotion();

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

private:
	// �v���C���[�n���h��
	int m_handle;
	int m_handle2;
	// �v���C���[�摜�̔ԍ�
	int m_handlenumX;
	// �v���C���[�̐؂��鍶��̒��_
	int m_verXPlayer;
	int m_verYPlayer;
	// �t���[���J�E���g
	int m_frameCount;

	// �v���C���[�̉�]
	float m_rota;
};