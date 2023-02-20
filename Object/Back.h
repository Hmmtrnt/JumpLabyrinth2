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

	// �w���v�`��
	void drawHelp();
	void drawExplan2_5();
	void drawExplan6();
	void drawExplan7_10();
	void drawExplan11();
	void drawExplan12_15();
	void drawExplan16();
	void drawExplan17_20();

private:
	// �w�i�z��̃T�C�Y�擾
	int m_back[kVariable::BackHeight][kVariable::BackWidth];
	// �w�i�n���h��
	int m_handle;
	// �؂��鍶��̒��_
	int m_verX;			// ��
	int m_verY;			// �c

	// �e�L�X�g�n���h��
	int m_textHandle;

	// �M�~�b�N�`��̃n���h��
	int m_gimmickHandle;
	int m_gimmickHandle2;
};