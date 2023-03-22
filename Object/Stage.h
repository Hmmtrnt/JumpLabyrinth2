// �X�e�[�W
#pragma once
#include "../Util/common.h"
#include "../Util/Vec2.h"
#include <array>
#include <memory>

class ParticleBase;

class Stage
{
public:
	Stage();
	virtual ~Stage();

	void initCommon();// ���ʂ̏�����
	void initStage(const int stage[][kVariable::StageWidth], int stageHeight, int stageWidth);// ������

	void initTitle();

	void end();// �I��
	void update();// �X�V
	void draw();// �`��

	void drawTitle();// �^�C�g����ʂ̕`��

	int m_stage[kVariable::StageWidth][kVariable::StageWidth];// �X�e�[�W

private:
	// �X�e�[�W�̕`��
	void stageDraw(int x, int y);
	// �j�̕`��
	void needleDraw(int x, int y);
	// �S�[���̃p�[�e�B�N��
	void particle(int x, int y);// ����
	void drawParticle();// �`��

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

	// �^�C�g���`��̕ϐ�
	int m_TposX;// X���W
	int m_TposY;// Y���W
	int m_TverX;// ����X���W
	int m_TverY;// ����Y���W
	// �S�[��
	int m_TverGoalX;// ����X���W
	int m_TverGoalY;// ����Y���W

	// �c��񂾂瑦������̑傫��
	float m_sizeGimmick;

	// �S�[���̍��㒸�_
	int m_idxGoalX;
	int m_idxGoalY;

	// �S�[���̃��[�V��������
	int m_GoalFrame;// �S��
	int m_drawGoalFirst;// �ꖇ��
	int m_drawGoalSecond;// �񖇖�

	// �p�[�e�B�N��
	std::array<std::shared_ptr<ParticleBase>, kParticle::ParticleNum> m_particle;
	int m_showerFrame;// �`�悷��t���[��
	int m_particleFrame;// �\�����鎞��
	int m_auraFrame;// �G���A
};