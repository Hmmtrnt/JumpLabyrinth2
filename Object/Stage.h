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
	int m_handleSmallNeedle;// �����o�Ă�j

	// �؂��鍶��̒��_
	int m_verX;
	int m_verY;
};