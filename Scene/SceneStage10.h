// �X�e�[�W10
#pragma once
//#include "SceneBase.h"
#include "SceneStageBase.h"

class SceneStage10 : public SceneStageBase
{
public:
	SceneStage10();
	virtual ~SceneStage10(){}

	virtual void init();			// ������
	virtual SceneBase* CreateRetryStage();	// �V�[�����g���C
	virtual SceneBase* update();	// �X�V
	virtual void draw();			// �`��

private:
	// �w���v�����������̐^�U
	bool m_pushHelp;
};

