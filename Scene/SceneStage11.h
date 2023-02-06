// �X�e�[�W11
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class GameManager;

class SceneStage11 : public SceneBase
{
public:
	SceneStage11();
	virtual ~SceneStage11();

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

