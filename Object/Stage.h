// �X�e�[�W
#pragma once
#include "../Util/common.h"
#include "../Util/Vec2.h"
#include <array>
#include <memory>

class CharParticle;

class Stage
{
public:
	Stage();
	virtual ~Stage();

	void initCommon();	// ���ʂ̏�����
	void initStage(const int stage[][kVariable::StageWidth], int stageHeight, int stageWidth);	// �����p������
	void end();			// �I��
	void update();		// �X�V
	void draw();		// �`��

	int m_stage[kVariable::StageWidth][kVariable::StageWidth];// �X�e�[�W

private:
	// �X�e�[�W�̕`��
	void stageDraw(int x, int y);
	// �j�̕`��
	void needleDraw(int x, int y);
	// �S�[���̃p�[�e�B�N��
	void particle(int x, int y);	// ����
	void drawParticle();			// �`��

	// �M�~�b�N�̕`�悪�ς�鎞��
	int m_gimmickFrame;
	// ���ڂ�ł��鎞��
	int m_shrink;
	// �c���Ă��鎞��
	int m_inflate;

	// �X�e�[�W�n���h��
	int m_handleWall;// �G��锻��̃n���h��
	int m_handleTrap;// �G����̃n���h��
	int m_handleSmallNeedle;// �����o�Ă�j
	int m_handleGoal;// �S�[��

	// �؂��鍶��̒��_
	int m_verX;
	int m_verY;

	// �S�[���̍��㒸�_
	int m_idxGoalX;
	int m_idxGoalY;

	// �S�[���̃��[�V��������
	int m_GoalFrame;// �S��
	int m_drawGoalFirst;// �ꖇ��
	int m_drawGoalSecond;// �񖇖�

	// �p�[�e�B�N��
	std::array<std::shared_ptr<CharParticle>, kParticle::ParticleNum> m_particle;
	int m_showerFrame;		// �`�悷��t���[��
	int m_particleFrame;	// �\�����鎞��
	int m_auraFrame;		// �G���A
};