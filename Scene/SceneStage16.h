// �X�e�[�W16
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"
#include <memory>

class GameManager;
class Shot;
class Back;
class ScenePause;

class SceneStage16 : public SceneBase
{
public:
	SceneStage16();
	virtual ~SceneStage16();

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
	ScenePause* m_pPause;		// �|�[�Y���

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
	int m_shotPosX5;		// X���W
	int m_shotPosY5;		// Y���W

	// �e���ǂɓ�������W
	int m_colShotY;			// Y���W
	int m_colShotX2;		// X���W
	int m_colShotY3;		// Y���W
	int m_colShotX4;		// X���W
	int m_colShotX5;		// X���W

	// �T�C�Y
	int m_size;

	// �t���[���J�E���g
	int m_frameCountShot;

	// �|�[�Y��ʂ��Ђ炢�����ǂ���
	bool m_pushPause;
};

