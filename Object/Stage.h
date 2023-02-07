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
	void init1();		// �X�e�[�W1�̏�����
	void init2();		// �X�e�[�W2�̏�����
	void init3();		// �X�e�[�W3�̏�����
	void init4();		// �X�e�[�W4�̏�����
	void init5();		// �X�e�[�W5�̏�����
	void init6();		// �X�e�[�W6�̏�����
	void init7();		// �X�e�[�W7�̏�����
	void init8();		// �X�e�[�W8�̏�����
	void init9();		// �X�e�[�W9�̏�����
	void init10();		// �X�e�[�W10�̏�����
	void init11();		// �X�e�[�W11�̏�����
	void init12();		// �X�e�[�W12�̏�����
	void init13();		// �X�e�[�W13�̏�����

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

	// �؂��鍶��̒��_
	int m_verX;
	int m_verY;
};