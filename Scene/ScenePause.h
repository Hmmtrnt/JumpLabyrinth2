#pragma once
#include "../Util/common.h"
#include <array>
#include <memory>
#include <vector>

class ParticleBase;
class Back;

class ScenePause
{
public:
	ScenePause();
	virtual ~ScenePause();

	void init();			// ������
	void end();				// �I��
	void updatePause();		// �|�[�Y�X�V
	void drawPause();		// �|�[�Y�\��

	void updateClearPause();// �N���A�|�[�Y�X�V
	void drawClearPause();	// �N���A�|�[�Y�\��

	void movePause();		// �|�[�Y��ʈړ�

	// �������񐔂̏��擾
	int GetPushNum(){ return m_pushNum; }

private:
	void particle(int count);
	void drawParticle();

	// �|�C���^
	Back* m_pBack;

	// �e�L�X�g�n���h��
	int m_textHandle;
	// ���̈ʒu
	int m_posCursorX;		// �|�[�Y��ʂ̃J�[�\���ʒu
	int m_posCursorY;

	int m_posClearCursorX;	// �N���A�|�[�Y��ʂ̃J�[�\���ʒu
	int m_posClearCursorY;	
	// ��������
	int m_pushNum;
	// �N���A���̃|�[�Y�ʒu
	int m_posClearPauseX;		// ������W
	int m_posClearPauseY;
	int m_sizeClearPauseX;		// �T�C�Y���W
	int m_sizeClearPauseY;
	int m_posClearTextX;		// �N���A�|�[�Y��ʂ̃e�L�X�g���W
	int m_pauseCursorNum;		// �|�[�Y��ʂ̃J�[�\���ʒu
	int m_clearCursorNum;		// �N���A��ʂ̃J�[�\���ʒu
	int m_posClearTextY1;		// ����1
	int m_posClearTextY2;		// 2
	int m_posClearTextY3;		// 3
	int m_itemNum;				// �I���ł���͈�
	int m_CursorPosX;			// �J�[�\�����W	X���W
	int m_CursorPosY;			// �J�[�\�����W	Y���W
	int m_movePosX;				// �������W
	int m_vecPauseX;			// �|�[�Y��ʂ̓�������

	// ���n���h��
	int m_cursorSound;		// �J�[�\���ړ���
	int m_cursorNotSound;	// �J�[�\���ړ��ł��Ȃ���

	// �J�[�\�����������������ǂ���
	bool m_isCursorInit;
	// �����Ԃ���Ă��邩�ǂ���
	bool m_FillBox;
	// �X�e�[�W20�ł��邩�ǂ���
	bool m_isStage20;

	// �p�[�e�B�N��
	std::array<std::shared_ptr<ParticleBase>, kParticle::ParticleNum> m_particle;
	int m_flowerFrame;// �ԉ΂̂悤�ȃp�[�e�B�N��
	int m_particleCount;// �p�[�e�B�N�����������鐔
	// �p�[�e�B�N���������W
	int m_particlePosX;// X���W
	int m_particlePosY;// Y���W
	bool first = true;// �ꔭ��
	bool second = false;// �񔭖�
	bool third = false;// �O����
};