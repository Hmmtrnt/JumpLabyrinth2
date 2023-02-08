// �X�e�[�W
#pragma once
#include "../Util/common.h"
class Stage
{
public:
	Stage();
	virtual ~Stage();

	void initCommon();	// ���ʂ̏�����

	void initStage(const int stage[][kVariable::StageWidth], int stageHeight, int stageWidth);	// �����p������

	void initP();		// �v���g�^�C�v�p������

	void end();			// �I��
	void update();		// �X�V
	void draw();		// �`��

	int m_stage[kVariable::StageWidth][kVariable::StageWidth];

	int* m_pStage[kVariable::StageWidth][kVariable::StageWidth];

private:
	// �X�e�[�W�̕`��
	void stageDraw(int x, int y);
	// �j�̕`��
	void needleDraw(int x, int y);

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
	int m_handleGoal;

	// �؂��鍶��̒��_
	int m_verX;
	int m_verY;

	// �S�[���̍��㒸�_
	int m_idxGoalX;
	int m_idxGoalY;

	int m_GoalFrame;
	int m_drawGoalFirst;
	int m_drawGoalSecond;
};