// �X�e�[�W10
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class GameManager;

class SceneStage10 : public SceneBase
{
public:
	SceneStage10();
	virtual ~SceneStage10();

	virtual void init();			// ������
	virtual void end();				// �I��
	virtual SceneBase* update();	// �X�V
	virtual void draw();			// �`��

private:
	// �Q�[���}�l�[�W���[�|�C���^
	GameManager* m_pManager;

	// �t���[���J�E���g
	int m_frameCount;
	// �L�����̍��W
	int m_posX;				// X���W
	int m_posY;				// Y���W
	// �L�����̈ړ��t���[��
	int m_frameX;			// X���W
	int m_frameY;			// Y���W
};

