// �X�e�[�W5
#pragma once
//#include "SceneBase.h"
#include "SceneStageBase.h"

class SceneStage5 : public SceneStageBase
{
public:
	SceneStage5();
	virtual ~SceneStage5(){}

	virtual void init();			// ������
	virtual void end();				// �I��
	virtual SceneBase* update();	// �X�V
	virtual void draw();			// �`��

private:
	// �w���v�����������̐^�U
	bool m_pushHelp;
};

