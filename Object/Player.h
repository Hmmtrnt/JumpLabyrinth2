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

	// �v���C���[�̔z��̈ʒu
	int m_posX;			// X���W
	int m_posY;			// Y���W
	// �v���C���[�̈ړ��t���[��
	int m_flameX;		// X���W
	int m_flameY;		// Y���W
	
	int m_speedX;
	int m_speedY;

	// �v���C���[�̔z��̎󂯓n��
	int m_player[PLAYER_HEIGHT][PLAYER_WIDTH];

private:

};