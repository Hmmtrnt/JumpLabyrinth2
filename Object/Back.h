#pragma once
#include "../Util/common.h"

class Back
{
public:
	Back();
	virtual ~Back();

	void init();
	void draw();

private:
	// �w�i�T�C�Y�擾
	int m_back[BACK_HEIGHT][BACK_WIDTH];
	// �w�i�n���h��
	int m_handle;
	// �؂��鍶��̒��_
	int m_verX;
	int m_verY;
};

