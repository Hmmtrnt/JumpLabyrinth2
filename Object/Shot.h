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
	void drawR(int &posX, int &posY);		// �E�����`��
	void drawL(int& posX, int& posY);		// �������`��
	void drawU(int& posX, int& posY);		// ������`��
	void drawB(int& posX, int& posY);		// �������`��
	void drawR2(int& posX, int& posY);		// �E�����`��A
	void drawL2(int& posX, int& posY);		// �������`��A

	// �ϐ��̊m�F
	void drawTest();

	// �ː�
	void shotRight(int &posX, int &stagePosX);			// �E
	void shotLeft(int &posX, int &stagePosX);			// ��
	void shotUp(int &posY, int &stagePosY);				// ��
	void shotBottom(int &posY, int &stagePosY);			// ��

	// �ː��A
	void shotRight2(int& posX, int& stagePosX);			// �E
	void shotLeft2(int& posX, int& stagePosX);			// ��

private:
	// �e�̑���
	int m_speedX;
	int m_speedY;
	int m_speedX2;
	int m_speedY2;
	int m_speedX3;
	int m_speedX4;

	// �摜�n���h��
	int m_handle;

	// ��]��
	float m_rota;

	// ���˂���t���[����
	int m_frameCount;

	// �|�[�Y��ʂ��J�������ǂ���
	bool m_pushPause;
};