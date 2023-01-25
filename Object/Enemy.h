// �G�l�~�[
#pragma once
#include "../Util/common.h"

class Enemy
{
public:
	Enemy();
	virtual ~Enemy();

	void init();
	void end();
	void update();
	void draw();

	// �G�l�~�[�̔z��̈ʒu
	int m_posX;			// X���W
	int m_posY;			// Y���W
	// �G�l�~�[�̈ړ��t���[��
	int m_flameX;		// X���W
	int m_flameY;		// Y���W
	// �G�l�~�[�̈ړ����x
	int m_speedX;		// X���W
	int m_speedY;		// Y���W

	// �v���C���[�̔z��̎󂯓n��
	int m_enemy[ENEMY_HEIGHT][ENEMY_WIDTH];

private:

};

