// �X�e�[�W20
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class GameManager;
class Shot;
class Back;

class SceneStage20 : public SceneBase
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
	GameManager* m_pManager;	// �Q�[���}�l�[�W���[
	Shot* m_pShot;				// �e
	Back* m_pBack;				// �w�i

	// �t���[���J�E���g
	int m_frameCount;
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

	// �e���ǂɓ�������W
	int m_colShotY;			// Y���W
	int m_colShotX2;		// X���W
	int m_colShotX3;		// X���W
	int m_colShotY4;		// X���W

	// �T�C�Y
	int m_size;
	// �t���[���J�E���g
	int m_frameCountShot;

	// �w���v�����������̐^�U
	bool m_pushHelp;
};