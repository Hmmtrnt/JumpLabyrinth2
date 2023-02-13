#pragma once
#include "../Util/common.h"


class ScenePause
{
public:
	ScenePause();
	virtual ~ScenePause();

	void init();
	void end();
	void update();
	void pauseDraw();

	void GameOverDraw();

	int GetPushNum(){ return m_pushNum; }

private:
	// �e�L�X�g�n���h��
	int m_textHandle;
	// ���̈ʒu
	int m_posArrow;
	// ��������
	int m_pushNum;
};