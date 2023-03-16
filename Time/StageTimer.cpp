#include "StageTimer.h"

namespace
{
	// �J���҂̃^�C��
	// �X�e�[�W1
	constexpr int kStage1Msec = 46;// �~���b
	constexpr int kStage1Second = 1;// �b
	constexpr int kStage1Minute = 0;// ��
	// �X�e�[�W2
	constexpr int kStage2Msec = 18;// �~���b
	constexpr int kStage2Second = 3;// �b
	constexpr int kStage2Minute = 0;// ��
	// �X�e�[�W3
	constexpr int kStage3Msec = 34;// �~���b
	constexpr int kStage3Second = 3;// �b
	constexpr int kStage3Minute = 0;// ��
	// �X�e�[�W4
	constexpr int kStage4Msec = 40;// �~���b
	constexpr int kStage4Second = 2;// �b
	constexpr int kStage4Minute = 0;// ��
	// �X�e�[�W5
	constexpr int kStage5Msec = 26;// �~���b
	constexpr int kStage5Second = 2;// �b
	constexpr int kStage5Minute = 0;// ��
	// �X�e�[�W6
	constexpr int kStage6Msec = 33;// �~���b
	constexpr int kStage6Second = 3;// �b
	constexpr int kStage6Minute = 0;// ��
	// �X�e�[�W7
	constexpr int kStage7Msec = 25;// �~���b
	constexpr int kStage7Second = 3;// �b
	constexpr int kStage7Minute = 0;// ��
	// �X�e�[�W8
	constexpr int kStage8Msec = 0;// �~���b
	constexpr int kStage8Second = 4;// �b
	constexpr int kStage8Minute = 0;// ��
	// �X�e�[�W9
	constexpr int kStage9Msec = 8;// �~���b
	constexpr int kStage9Second = 2;// �b
	constexpr int kStage9Minute = 0;// ��
	// �X�e�[�W10
	constexpr int kStage10Msec = 23;// �~���b
	constexpr int kStage10Second = 3;// �b
	constexpr int kStage10Minute = 0;// ��
	// �X�e�[�W11
	constexpr int kStage11Msec = 53;// �~���b
	constexpr int kStage11Second = 3;// �b
	constexpr int kStage11Minute = 0;// ��
	// �X�e�[�W12
	constexpr int kStage12Msec = 12;// �~���b
	constexpr int kStage12Second = 7;// �b
	constexpr int kStage12Minute = 0;// ��
	// �X�e�[�W13
	constexpr int kStage13Msec = 40;// �~���b
	constexpr int kStage13Second = 7;// �b
	constexpr int kStage13Minute = 0;// ��
	// �X�e�[�W14
	constexpr int kStage14Msec = 10;// �~���b
	constexpr int kStage14Second = 6;// �b
	constexpr int kStage14Minute = 0;// ��
	// �X�e�[�W15
	constexpr int kStage15Msec = 58;// �~���b
	constexpr int kStage15Second = 3;// �b
	constexpr int kStage15Minute = 0;// ��
	// �X�e�[�W16
	constexpr int kStage16Msec = 55;// �~���b
	constexpr int kStage16Second = 3;// �b
	constexpr int kStage16Minute = 0;// ��
	// �X�e�[�W17
	constexpr int kStage17Msec = 34;// �~���b
	constexpr int kStage17Second = 5;// �b
	constexpr int kStage17Minute = 0;// ��
	// �X�e�[�W18
	constexpr int kStage18Msec = 55;// �~���b
	constexpr int kStage18Second = 10;// �b
	constexpr int kStage18Minute = 0;// ��
	// �X�e�[�W19
	constexpr int kStage19Msec = 52;// �~���b
	constexpr int kStage19Second = 8;// �b
	constexpr int kStage19Minute = 0;// ��
	// �X�e�[�W20
	constexpr int kStage20Msec = 24;// �~���b
	constexpr int kStage20Second = 10;// �b
	constexpr int kStage20Minute = 0;// ��
}

StageTimer::StageTimer() :
	m_clearTime(0),
	m_timeMsec(0),
	m_timeSecond(0),
	m_timeMinute(0),
	m_developerMsec(0),
	m_developerSecond(0),
	m_developerMinute(0)
{
}

StageTimer::~StageTimer()
{
}

void StageTimer::timerUpdate()
{
	// ���ԑ���
	m_clearTime = GetNowCount();
	if (GetNowCount() - m_clearTime < 1000)
	{
		m_timeMsec++;
		if (m_timeMsec == 60)
		{
			m_timeSecond++;
			m_timeMsec = 0;
			if (m_timeSecond == 60)
			{
				m_timeMinute++;
				m_timeSecond = 0;
			}

		}
	}
}

void StageTimer::timeAssignment()
{
	// �X�e�[�W����
	if (stageSelectNum == 1)
	{
		m_developerMsec = kStage1Msec;// �~���b
		m_developerSecond = kStage1Second;// �b
		m_developerMinute = kStage1Minute;// ��
	}
	if (stageSelectNum == 2)
	{
		m_developerMsec = kStage2Msec;// �~���b
		m_developerSecond = kStage2Second;// �b
		m_developerMinute = kStage2Minute;// ��
	}
	if (stageSelectNum == 3)
	{
		m_developerMsec = kStage3Msec;// �~���b
		m_developerSecond = kStage3Second;// �b
		m_developerMinute = kStage3Minute;// ��
	}
	if (stageSelectNum == 4)
	{
		m_developerMsec = kStage4Msec;// �~���b
		m_developerSecond = kStage4Second;// �b
		m_developerMinute = kStage4Minute;// ��
	}
	if (stageSelectNum == 5)
	{
		m_developerMsec = kStage5Msec;// �~���b
		m_developerSecond = kStage5Second;// �b
		m_developerMinute = kStage5Minute;// ��
	}
	if (stageSelectNum == 6)
	{
		m_developerMsec = kStage6Msec;// �~���b
		m_developerSecond = kStage6Second;// �b
		m_developerMinute = kStage6Minute;// ��
	}
	if (stageSelectNum == 7)
	{
		m_developerMsec = kStage7Msec;// �~���b
		m_developerSecond = kStage7Second;// �b
		m_developerMinute = kStage7Minute;// ��
	}
	if (stageSelectNum == 8)
	{
		m_developerMsec = kStage8Msec;// �~���b
		m_developerSecond = kStage8Second;// �b
		m_developerMinute = kStage8Minute;// ��
	}
	if (stageSelectNum == 9)
	{
		m_developerMsec = kStage9Msec;// �~���b
		m_developerSecond = kStage9Second;// �b
		m_developerMinute = kStage9Minute;// ��
	}
	if (stageSelectNum == 10)
	{
		m_developerMsec = kStage10Msec;// �~���b
		m_developerSecond = kStage10Second;// �b
		m_developerMinute = kStage10Minute;// ��
	}
	if (stageSelectNum == 11)
	{
		m_developerMsec = kStage11Msec;// �~���b
		m_developerSecond = kStage11Second;// �b
		m_developerMinute = kStage11Minute;// ��
	}
	if (stageSelectNum == 12)
	{
		m_developerMsec = kStage12Msec;// �~���b
		m_developerSecond = kStage12Second;// �b
		m_developerMinute = kStage12Minute;// ��
	}
	if (stageSelectNum == 13)
	{
		m_developerMsec = kStage13Msec;// �~���b
		m_developerSecond = kStage13Second;// �b
		m_developerMinute = kStage13Minute;// ��
	}
	if (stageSelectNum == 14)
	{
		m_developerMsec = kStage14Msec;// �~���b
		m_developerSecond = kStage14Second;// �b
		m_developerMinute = kStage14Minute;// ��
	}
	if (stageSelectNum == 15)
	{
		m_developerMsec = kStage15Msec;// �~���b
		m_developerSecond = kStage15Second;// �b
		m_developerMinute = kStage15Minute;// ��
	}
	if (stageSelectNum == 16)
	{
		m_developerMsec = kStage16Msec;// �~���b
		m_developerSecond = kStage16Second;// �b
		m_developerMinute = kStage16Minute;// ��
	}
	if (stageSelectNum == 17)
	{
		m_developerMsec = kStage17Msec;// �~���b
		m_developerSecond = kStage17Second;// �b
		m_developerMinute = kStage17Minute;// ��
	}
	if (stageSelectNum == 18)
	{
		m_developerMsec = kStage18Msec;// �~���b
		m_developerSecond = kStage18Second;// �b
		m_developerMinute = kStage18Minute;// ��
	}
	if (stageSelectNum == 19)
	{
		m_developerMsec = kStage19Msec;// �~���b
		m_developerSecond = kStage19Second;// �b
		m_developerMinute = kStage19Minute;// ��
	}
	if (stageSelectNum == 20)
	{
		m_developerMsec = kStage20Msec;// �~���b
		m_developerSecond = kStage20Second;// �b
		m_developerMinute = kStage20Minute;// ��
	}
}

void StageTimer::drawTime(int font)
{
	DrawFormatStringToHandle(100, 900, kColor::White, font, "%d:%d.%d", m_timeMinute, m_timeSecond, m_timeMsec);
}

void StageTimer::drawResult(int font)
{
	DrawFormatStringToHandle(1030, 700, kColor::White, font, "Timer");
	DrawFormatStringToHandle(700, 800, kColor::White, font, "Player");
	DrawFormatStringToHandle(1020, 800, kColor::White, font, "%d:%d.%d", m_timeMinute, m_timeSecond, m_timeMsec);
	DrawFormatStringToHandle(700, 900, kColor::White, font, "Developer");
	DrawFormatStringToHandle(1020, 900, kColor::White, font, "%d:%d.%d", m_developerMinute, m_developerSecond, m_developerMsec);
}
