// �X�e�[�W18
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class GameManager;
class Shot;
class Back;

class SceneStage18 : public SceneBase
{
public:
	SceneStage18();
	virtual ~SceneStage18();

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
	int m_shotPosX5;		// X���W
	int m_shotPosY5;		// Y���W
	int m_shotPosX6;		// X���W
	int m_shotPosY6;		// Y���W

	// �e���ǂɓ�������W
	int m_colShotX;			// X���W
	int m_colShotY2;		// Y���W
	int m_colShotY3;		// Y���W
	int m_colShotX4;		// X���W
	int m_colShotY5;		// Y���W
	int m_colShotX6;		// Y���W

	// �T�C�Y
	int m_size;

	// �t���[���J�E���g
	int m_frameCountShot;
};
