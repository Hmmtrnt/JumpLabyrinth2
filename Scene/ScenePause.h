#pragma once
#include "../Util/common.h"


class ScenePause
{
public:
	ScenePause();
	virtual ~ScenePause();

	virtual void init();
	virtual void end();
	virtual void update();
	virtual void draw();

	int GetPushNum(){ return m_pushNum; }

private:
	// �e�L�X�g�n���h��
	int m_textHandle;
	// ���̈ʒu
	int m_posArrow;
	// ��������
	int m_pushNum;
};