// �X�e�[�W14
#pragma once
//#include "SceneBase.h"
#include "SceneStageBase.h"

class SceneStage15 : public SceneStageBase
{
public:
	SceneStage15();
	virtual ~SceneStage15(){}

	virtual void init();			// ������
	virtual SceneBase* update();	// �X�V
	virtual void draw();			// �`��

private:
	// �w���v�����������̐^�U
	bool m_pushHelp;
};