// �X�e�[�W1�t�@�C��
#pragma once
//#include "SceneBase.h"
#include "SceneStageBase.h"

class SceneStage1 : public SceneStageBase
{
public:
	SceneStage1(){}
	virtual ~SceneStage1(){}

	virtual void init();			// ������
	virtual SceneBase* CreateRetryStage();	// �V�[�����g���C
	virtual SceneBase* update();	// �X�V
	virtual void draw();			// �`��
};

