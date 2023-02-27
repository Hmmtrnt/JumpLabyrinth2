// �X�e�[�W20
#pragma once
//#include "SceneBase.h"
#include "SceneStageBase.h"

class Shot;

class SceneStage20 : public SceneStageBase
{
public:
	SceneStage20();
	virtual ~SceneStage20();

	virtual void init();			// ������
	void initShot();				// �e�̏�����
	virtual void end();				// �I��
	virtual SceneBase* update();	// �X�V
	virtual void draw();			// �`��

	void collisionShot();			// �e�̓����蔻��

private:
	// �|�C���^
	Shot* m_pShot;				// �V���b�g

	// �e�̍��W
	int m_shotPosX;			// X���W
	int m_shotPosY;			// Y���W
	int m_shotPosX2;		// X���W
	int m_shotPosY2;		// Y���W
	int m_shotPosX3;		// X���W
	int m_shotPosY3;		// Y���W
	int m_shotPosX4;		// X���W
	int m_shotPosY4;		// Y���W

	// �e���ǂɓ�������W
	int m_colShotY;			// Y���W
	int m_colShotX2;		// X���W
	int m_colShotX3;		// X���W
	int m_colShotY4;		// X���W

	// �T�C�Y
	int m_size;
	// �V���b�g�̃t���[���J�E���g
	int m_frameCountShot;

	// �w���v�����������̐^�U
	bool m_pushHelp;
};