// �G�l�~�[
#pragma once
#include "../Util/common.h"

class Shot
{
public:
	Shot();
	virtual ~Shot();

	void init();		// ������(������)
	void end();			// �I��
	void update();		// �X�V
	void draw();		// �`��

private:
	// �摜�n���h��
	int m_handle;

	// �e�̈ʒu
	int m_posX;
	int m_posY;

	// �e�̑���
	int m_speedX;
	int m_speedY;
};