#pragma once
#include "../Util/common.h"

class Back
{
public:
	Back();
	virtual ~Back();

	void init();		// ������
	void end();			// �I��
	void draw();		// �`��

private:
	// �w�i�z��̃T�C�Y�擾
	int m_back[kVariable::BackHeight][kVariable::BackWidth];
	// �w�i�n���h��
	int m_handle;
	// �؂��鍶��̒��_
	int m_verX;			// ��
	int m_verY;			// �c
};

