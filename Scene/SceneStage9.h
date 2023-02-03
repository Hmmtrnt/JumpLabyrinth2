// �X�e�[�W9
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class GameManager;

class SceneStage9 : public SceneBase
{
public:
	SceneStage9();
	virtual ~SceneStage9();

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