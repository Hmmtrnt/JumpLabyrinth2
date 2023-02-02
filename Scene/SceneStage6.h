#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class GameManager;

class SceneStage6 : public SceneBase
{
public:
	SceneStage6();
	virtual ~SceneStage6();

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

