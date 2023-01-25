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
};

