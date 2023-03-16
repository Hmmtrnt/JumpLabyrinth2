#pragma once
#include "../Util/common.h"

class Back
{
public:
	Back();
	virtual ~Back();

	void init();// ������
	void end();// �I��
	void update();// �X�V
	void draw();// �`��

	void drawMenuGuide();// ���j���[�\�����@�`��
	void drawCloseGuide();// �M�~�b�N�����\�����@�`��

	// �w���v�`��
	void drawOpenGuide();// �w���v�{�^���U���`��
	void drawExplan2_5();// 2����5�X�e�[�W�̃M�~�b�N�����`��
	void drawExplan6And10();// 6��10�X�e�[�W�̃M�~�b�N�����`��
	void drawExplan7_9();// 7����9�X�e�[�W�̃M�~�b�N�����`��
	void drawExplan11();// 11�X�e�[�W�̃M�~�b�N�����`��
	void drawExplan12_15();// 12����15�X�e�[�W�̃M�~�b�N�����`��
	void drawExplan16();// 16�X�e�[�W�̃M�~�b�N�����`��
	void drawExplan17_20();// 17����20�X�e�[�W�̃M�~�b�N�����`��

	void drawTutorial();// �`���[�g���A���`��
	void drawTutorialText();// �`���[�g���A�������邩�ǂ����̕`��

private:
	// �M�~�b�N�����̕`��
	
	/// <summary>
	/// �����g���b�v�̐����`��
	/// </summary>
	/// <param name="posXHandle">�摜��X���W</param>
	/// <param name="posYHandle">�摜��Y���W</param>
	/// <param name="posXText">�e�L�X�g��X���W</param>
	/// <param name="posYText">�e�L�X�g��Y���W</param>
	void drawExplanDeath(int posXHandle, int posYHandle,
		int posXText, int posYText);
	/// <summary>
	/// ���ԍ��g���b�v�̐����`��
	/// </summary>
	/// <param name="posXHandle">�摜��X���W</param>
	/// <param name="posYHandle">�摜��Y���W</param>
	/// <param name="posXText">�e�L�X�g��X���W</param>
	/// <param name="posYText">�e�L�X�g��Y���W</param>
	void drawExplanLagTrap(int posXHandle, int posYHandle,
		int posXText, int posYText);
	/// <summary>
	/// �c��ރg���b�v�̐����`��
	/// </summary>
	/// <param name="posXHandle">�f�X����摜��X���W</param>
	/// <param name="posYHandle">�f�X����摜��Y���W</param>
	/// <param name="posXHandle2">�摜��X���W</param>
	/// <param name="posYHandle2">�摜��Y���W</param>
	/// <param name="posXText">�e�L�X�g��X���W</param>
	/// <param name="posYText">�e�L�X�g��Y���W</param>
	void drawExplanInflateTrap(int posXHandle, int posYHandle,
		int posXHandle2, int posYHandle2,
		int posXText, int posYText);
	/// <summary>
	/// �V���b�g�g���b�v�̐����`��
	/// </summary>
	/// <param name="posXHandle">�摜��X���W</param>
	/// <param name="posYHandle">�摜��Y���W</param>
	/// <param name="posXText">�e�L�X�g��X���W</param>
	/// <param name="posYText">�e�L�X�g��Y���W</param>
	void drawExplanShotTrap(int posXHandle, int posYHandle,
		int posXText, int posYText);

	/// <summary>
	/// �{�^���`��
	/// </summary>
	/// <param name="x">X���W</param>
	/// <param name="y">Y���W</param>
	void drawButton(int x, int y);
	/// <summary>
	/// �����ׂ��{�^���̕`��
	/// </summary>
	/// <param name="handleNum">�`�悷��摜�̔ԍ�</param>
	void drawPushButton(int handleNum);

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
	int m_buttonPauseLeftNum;// ������W��X��
	int m_buttonPauseTopNum;// ������W��Y��
	// �{�^��
	int m_buttonHandleLeftNum;// ������W��X��
	int m_buttonHandleTopNum;// ������W��Y��
	int m_buttonHandleX;// X���W
	int m_buttonHandleY;// Y���W
	int m_buttohHandleDisplayTime;// �\������
	int m_buttonHandleTime;// �S�̎���
};