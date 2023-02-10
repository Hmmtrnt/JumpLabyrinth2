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
	void draw(int &posX, int &posY);		// �`��

	// �ː�
	void shotRight(int &posX, int &stagePosX);			// �E
	void shotLeft(int &posX, int &stagePosX);			// ��
	void shotUp(int &posY, int &stagePosY);				// ��
	void shotBottom(int &posY, int &stagePosY);			// ��

	// �ː��A
	void shotRight2(int& posX, int& stagePosX);			// �E

	// �e�̈ʒu
	int m_posX;
	int m_posY;

	int getSpeedX() { return m_speedX; }
	int getSpeedY() { return m_speedY; }

	// �e�̑���
	int m_speedX;
	int m_speedY;
	int m_speedX2;
	int m_speedY2;
	int m_speedX3;

private:
	// �摜�n���h��
	int m_handle;

	// ��]��
	float m_rota;

	

	int m_frameCount;
};