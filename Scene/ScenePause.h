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
private:
	// �e�L�X�g�n���h��
	int m_textHandle;
};