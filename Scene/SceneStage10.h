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
};

