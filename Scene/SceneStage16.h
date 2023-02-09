// �X�e�[�W16
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class GameManager;
class Shot;
class Back;

class SceneStage16 : public SceneBase
{
public:
	SceneStage16();
	virtual ~SceneStage16();

	virtual void init();			// ������
	void initShot();				// �e�������ʒu�ɖ߂�
	virtual void end();				// �I��
	virtual SceneBase* update();	// �X�V
	virtual void draw();			// �`��

	void collisionShot();			// �e�̓����蔻��

private:
	// �Q�[���}�l�[�W���[�|�C���^
	GameManager* m_pManager;
	Shot* m_pShot;
	Back* m_pBack;

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

	// �e���ǂɓ�������W
	int m_colShotX;			// X���W
	int m_colShotY;			// Y���W
	int m_colShotX2;		// X���W
	int m_colShotY2;		// Y���W

	// �t���[���J�E���g
	int m_frameCountShot;
};

