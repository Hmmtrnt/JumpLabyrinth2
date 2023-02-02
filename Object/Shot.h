// �G�l�~�[
#pragma once
#include "../Util/common.h"

class Shot
{
public:
	Shot();
	virtual ~Shot();

	void init();
	void end();
	void update();
	void draw();

	void moveWidth(bool colL, bool colR);
	void moveHeight(bool colUp, bool colDown);

	// �e�X�g�֐�
	void operation(bool colL, bool colR, bool colUp, bool colDown);


	// �G�l�~�[�̔z��̈ʒu
	int m_posX;			// X���W
	int m_posY;			// Y���W
	// �G�l�~�[�̈ړ��t���[��
	int m_frameX;		// X���W
	int m_frameY;		// Y���W
	// �G�l�~�[�̈ړ����x
	int m_speedX;		// X���W
	int m_speedY;		// Y���W

	int m_stopFrame;	// �ǂɂ����Ƃ��Ɏ~�܂��Ă��鎞��

	// �G�l�~�[�̔z��̎󂯓n��
	int m_enemy[SHOT_HEIGHT][SHOT_WIDTH];

private:
	
	int m_handleArrow;

};

