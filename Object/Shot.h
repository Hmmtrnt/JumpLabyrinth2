// �G�l�~�[
#pragma once
#include "../Util/common.h"

class Shot
{
public:
	Shot();
	virtual ~Shot();

	void init(int posX, int posY);		// ������(������)
	void end();			// �I��
	void update();		// �X�V
	void draw(int &posX, int &posY);		// �`��

	void shotRight(int posX, int posY, int sizeX ,int stagePosX);			// �E
	void shotLeft(int &posX, int &stagePosX);					// ��
	void shotUp(int posX, int posY, int stagePosY);				// ��
	void shotBottom(int &posY, int &sizeY, int &stagePosY);		// ��

	// �e�̈ʒu
	int m_posX;
	int m_posY;

private:
	// �摜�n���h��
	int m_handle;

	// ��]��
	float m_rota;

	// �e�̑���
	int m_speedX;
	int m_speedY;

	int m_frameCount;
};