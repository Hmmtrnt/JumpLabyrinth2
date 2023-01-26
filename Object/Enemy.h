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

	void moveWidth(bool colL, bool colR);
	void moveHeight(bool colUp, bool colDown);

	// �G�l�~�[�̔z��̈ʒu
	int m_posX;			// X���W
	int m_posY;			// Y���W
	// �G�l�~�[�̈ړ��t���[��
	int m_frameX;		// X���W
	int m_frameY;		// Y���W
	// �G�l�~�[�̈ړ����x
	int m_speedX;		// X���W
	int m_speedY;		// Y���W

	// �G�l�~�[�̔z��̎󂯓n��
	int m_enemy[ENEMY_HEIGHT][ENEMY_WIDTH];

private:

};

