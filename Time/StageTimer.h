#pragma once
#include "../Util/common.h"

class StageTimer
{
public:
	StageTimer();
	virtual ~StageTimer();

	void timerUpdate();// �^�C�}�[�X�V
	void timeAssignment();// �X�e�[�W���ƂɊJ���҂̃^�C������

	/// <summary>
	/// �v���C���̃^�C�}�[�`��
	/// </summary>
	/// <param name="font">�t�H���g</param>
	void drawTime(int font);

	/// <summary>
	/// �^�C���̌���
	/// </summary>
	/// <param name="font">�t�H���g</param>
	void drawResult(int font);
private:
	// �N���A����
	int m_clearTime;// �S�̃t���[��
	int m_timeMsec;// �~���b
	int m_timeSecond;// �b
	int m_timeMinute;// ��
	// �ȉ��J���҂̃^�C��
	int m_developerMsec;// �~���b
	int m_developerSecond;// �b
	int m_developerMinute;// ��
};