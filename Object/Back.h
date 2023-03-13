#pragma once
#include "../Util/common.h"

class Back
{
public:
	Back();
	virtual ~Back();

	void init();		// ������
	void end();			// �I��
	void update();
	void draw();		// �`��

	void drawMenuGuide();		// ���j���[�\�����@�`��
	void drawCloseGuide();		// �M�~�b�N�����\�����@�`��

	// �w���v�`��
	void drawOpenGuide();				// �w���v�{�^���U���`��
	void drawExplan2_5();			// 2����5�X�e�[�W�̃M�~�b�N�����`��
	void drawExplan6And10();		// 6��10�X�e�[�W�̃M�~�b�N�����`��
	void drawExplan7_9();			// 7����9�X�e�[�W�̃M�~�b�N�����`��
	void drawExplan11();			// 11�X�e�[�W�̃M�~�b�N�����`��
	void drawExplan12_15();			// 12����15�X�e�[�W�̃M�~�b�N�����`��
	void drawExplan16();			// 16�X�e�[�W�̃M�~�b�N�����`��
	void drawExplan17_20();			// 17����20�X�e�[�W�̃M�~�b�N�����`��

private:
	// �M�~�b�N�����̕`��
	void drawExplanDeath(int posXHandle, int posYHandle,
		int posXText, int posYText);		// ����
	void drawExplanLagTrap(int posXHandle, int posYHandle,
		int posXText, int posYText);		// ���ԍ��
	void drawExplanInflateTrap(int posXHandle, int posYHandle,
		int posXHandle2, int posYHandle2,
		int posXText, int posYText);	// �c����
	void drawExplanShotTrap(int posXHandle, int posYHandle,
		int posXText, int posYText);	// �V���b�g���
	void drawButton();

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

	// �{�^���n���h��
	int m_buttonHandle;
	// �|�[�Y
	int m_buttonPauseLeftNum;		// ������W��X��
	int m_buttonPauseTopNum;		// ������W��Y��
	// �{�^��
	int m_buttonHandleLeftNum;		// ������W��X��
	int m_buttonHandleTopNum;		// ������W��Y��
	int m_buttonHandleX;			// X���W
	int m_buttonHandleY;			// Y���W
	int m_buttohHandleDisplayTime;	// �\������
	int m_buttonHandleTime;			// �S�̎���
};