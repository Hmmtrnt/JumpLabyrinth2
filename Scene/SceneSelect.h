// �Z���N�g���
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class SceneSelect : public SceneBase
{
public:
	SceneSelect();
	virtual ~SceneSelect();

	virtual void init();			// ������
	virtual void end();				// �I������
	virtual SceneBase* update();	// �X�V����
	virtual void draw();			// �`��

private:

};