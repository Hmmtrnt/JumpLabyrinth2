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

	void moveWidth(bool colL, bool colR);
	void moveHeight(bool colUp, bool colDown);

	// �e�X�g�֐�
	void operation(bool colL, bool colR, bool colUp, bool colDown);


	// �e�̔z��̈ʒu
	int m_posX;			// X���W
	int m_posY;			// Y���W
	// �e�̈ړ��t���[��
	int m_frameX;		// X���W
	int m_frameY;		// Y���W
	// �e�̈ړ����x
	int m_speedX;		// X���W
	int m_speedY;		// Y���W

	int m_stopFrame;	// �ǂɂ����Ƃ��Ɏ~�܂��Ă��鎞��

	// �e�̔z��̎󂯓n��
	int m_enemy[kVariable::ShotHeight][kVariable::ShotWidth];

private:
	// �e�̕`��
	void shotDraw(int x, int y);

	int m_handleArrow;

};

