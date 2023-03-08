// �V�[���X�e�[�W�̊��N���X
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class GameManager;
class Shot;
class Back;

class SceneStageBase : public SceneBase
{
public:
	SceneStageBase();
	virtual ~SceneStageBase();

	virtual void init();				// ������
	virtual void end();					// �I��
	virtual SceneBase* update();		// �X�V
	virtual void draw();				// �`��

	//virtual SceneBase* CreateRetryStage() = 0;	// �V�[���J�ڂ̏ꏊ
	virtual SceneBase* updateBefore();// �V�[���J��

	void playerInit();			// �v���C���[�̏�����
	void stageInit();			// �X�e�[�W�̏�����
	void shotInit();			// �V���b�g�̏�����
	void updateGame();			// �Q�[���̍X�V����
	void updateShot();			// �V���b�g�̏���
	void drawGuide();			// �e�X�e�[�W�̃K�C�h�`��
	void drawShot();			// �V���b�g�̕`��
	void collisionShot();		// �V���b�g�ƃv���C���[�̓����蔻��
	void deathSound();			// ���S���̉�

protected:
	// �|�C���^
	GameManager* m_pManager;	// �Q�[���}�l�[�W���[
	Back* m_pBack;				// �w�i
	Shot* m_pShot;				// �V���b�g

	// �X�e�[�W��ۑ�����
	//int m_stage[kVariable::StageWidth][kVariable::StageWidth];

	// �L�����̍��W
	int m_posX;				// X���W
	int m_posY;				// Y���W
	// �L�����̈ړ��t���[��
	int m_frameX;			// X���W
	int m_frameY;			// Y���W

	// �e�̍��W
	int m_shotPosX;			// X���W
	int m_shotPosY;			// Y���W
	int m_shotPosX2;		// X���W
	int m_shotPosY2;		// Y���W
	int m_shotPosX3;		// X���W
	int m_shotPosY3;		// Y���W
	int m_shotPosX4;		// X���W
	int m_shotPosY4;		// Y���W
	int m_shotPosX5;		// X���W
	int m_shotPosY5;		// Y���W
	int m_shotPosX6;		// X���W
	int m_shotPosY6;		// Y���W

	// �e���ǂɓ�������W
	int m_colShotX;			// X���W
	int m_colShotY;			// Y���W
	int m_colShotX2;		// X���W
	int m_colShotY2;		// Y���W
	int m_colShotX3;		// X���W
	int m_colShotY3;		// Y���W
	int m_colShotX4;		// X���W
	int m_colShotY4;		// Y���W
	int m_colShotX5;		// X���W
	int m_colShotY5;		// Y���W
	int m_colShotX6;		// X���W
	int m_colShotY6;		// Y���W

	// �T�C�Y
	int m_size;
	// �V���b�g�̃t���[���J�E���g
	int m_frameCountShot;

	// ��ʌ��ʗp�X�N���[���n���h��
	int m_screenHandle;
	float m_quakeX;	// ���u��
	int m_quakeTime;

	// ���̃n���h��
	int m_backGroundSound;// bgm
	int m_burnSound;	// �������艹
	int m_needleSound;	// �j���艹
	int m_inflateSound;	// �c��ޔ��艹
	int m_arrowSound;	// ��艹
	// ����
	int m_volumeBgm;	// BGM

	// ��ɓ����������ǂ���
	bool m_arrowTrap;
	// �u���̕ϐ��ɑ���������ǂ���
	bool m_isAllocation;
	// �w���v�����������̐^�U
	bool m_pushHelp;
	// �X�e�[�W�ɃV���b�g�����������Ă��邩�ǂ���
	bool m_inShot;
	// ���Ă��邩�ǂ���
	bool m_deathSound;	// ���S��

	
};

