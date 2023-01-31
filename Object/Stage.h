// �X�e�[�W
#pragma once
#include "../Util/common.h"
class Stage
{
public:
	Stage();
	virtual ~Stage();

	void init();
	void end();
	void update();
	void draw();

	int m_stage[STAGE_HEIGHT][STAGE_WIDTH];

private:
	// �M�~�b�N�̕`�悪�ς�鎞��
	int m_gimmickFrame;
	// ���ڂ�ł��鎞��
	int m_shrink;
	// �c���Ă��鎞��
	int m_inflate;

	// �X�e�[�W�n���h��
	int m_handleWall;		// �G��锻��̃n���h��
	int m_handleTrap;		// �G����̃n���h��

	// �؂��鍶��̒��_
	int m_verXWall;
	int m_verYWall;
	int m_verXTrap;
	int m_verYTrap;
	int m_verXLagTrap;
	int m_verYLagTrap;
	int m_verXFire;
	int m_verYFire;
	int m_verXInflate;
	int m_verYInflate;
	int m_verXInflate2;
	int m_verYInflate2;
	int m_verXGoal;
	int m_verYGoal;
};

