#include "StageTimer.h"

namespace
{
	// 開発者のタイム
	// ステージ1
	constexpr int kStage1Msec = 46;// ミリ秒
	constexpr int kStage1Second = 1;// 秒
	constexpr int kStage1Minute = 0;// 分
	// ステージ2
	constexpr int kStage2Msec = 18;// ミリ秒
	constexpr int kStage2Second = 3;// 秒
	constexpr int kStage2Minute = 0;// 分
	// ステージ3
	constexpr int kStage3Msec = 34;// ミリ秒
	constexpr int kStage3Second = 3;// 秒
	constexpr int kStage3Minute = 0;// 分
	// ステージ4
	constexpr int kStage4Msec = 40;// ミリ秒
	constexpr int kStage4Second = 2;// 秒
	constexpr int kStage4Minute = 0;// 分
	// ステージ5
	constexpr int kStage5Msec = 26;// ミリ秒
	constexpr int kStage5Second = 2;// 秒
	constexpr int kStage5Minute = 0;// 分
	// ステージ6
	constexpr int kStage6Msec = 33;// ミリ秒
	constexpr int kStage6Second = 3;// 秒
	constexpr int kStage6Minute = 0;// 分
	// ステージ7
	constexpr int kStage7Msec = 25;// ミリ秒
	constexpr int kStage7Second = 3;// 秒
	constexpr int kStage7Minute = 0;// 分
	// ステージ8
	constexpr int kStage8Msec = 0;// ミリ秒
	constexpr int kStage8Second = 4;// 秒
	constexpr int kStage8Minute = 0;// 分
	// ステージ9
	constexpr int kStage9Msec = 8;// ミリ秒
	constexpr int kStage9Second = 2;// 秒
	constexpr int kStage9Minute = 0;// 分
	// ステージ10
	constexpr int kStage10Msec = 23;// ミリ秒
	constexpr int kStage10Second = 3;// 秒
	constexpr int kStage10Minute = 0;// 分
	// ステージ11
	constexpr int kStage11Msec = 53;// ミリ秒
	constexpr int kStage11Second = 3;// 秒
	constexpr int kStage11Minute = 0;// 分
	// ステージ12
	constexpr int kStage12Msec = 12;// ミリ秒
	constexpr int kStage12Second = 7;// 秒
	constexpr int kStage12Minute = 0;// 分
	// ステージ13
	constexpr int kStage13Msec = 40;// ミリ秒
	constexpr int kStage13Second = 7;// 秒
	constexpr int kStage13Minute = 0;// 分
	// ステージ14
	constexpr int kStage14Msec = 10;// ミリ秒
	constexpr int kStage14Second = 6;// 秒
	constexpr int kStage14Minute = 0;// 分
	// ステージ15
	constexpr int kStage15Msec = 58;// ミリ秒
	constexpr int kStage15Second = 3;// 秒
	constexpr int kStage15Minute = 0;// 分
	// ステージ16
	constexpr int kStage16Msec = 55;// ミリ秒
	constexpr int kStage16Second = 3;// 秒
	constexpr int kStage16Minute = 0;// 分
	// ステージ17
	constexpr int kStage17Msec = 34;// ミリ秒
	constexpr int kStage17Second = 5;// 秒
	constexpr int kStage17Minute = 0;// 分
	// ステージ18
	constexpr int kStage18Msec = 55;// ミリ秒
	constexpr int kStage18Second = 10;// 秒
	constexpr int kStage18Minute = 0;// 分
	// ステージ19
	constexpr int kStage19Msec = 52;// ミリ秒
	constexpr int kStage19Second = 8;// 秒
	constexpr int kStage19Minute = 0;// 分
	// ステージ20
	constexpr int kStage20Msec = 24;// ミリ秒
	constexpr int kStage20Second = 10;// 秒
	constexpr int kStage20Minute = 0;// 分
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
	// 時間測定
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
	// ステージごと
	if (stageSelectNum == 1)
	{
		m_developerMsec = kStage1Msec;// ミリ秒
		m_developerSecond = kStage1Second;// 秒
		m_developerMinute = kStage1Minute;// 分
	}
	if (stageSelectNum == 2)
	{
		m_developerMsec = kStage2Msec;// ミリ秒
		m_developerSecond = kStage2Second;// 秒
		m_developerMinute = kStage2Minute;// 分
	}
	if (stageSelectNum == 3)
	{
		m_developerMsec = kStage3Msec;// ミリ秒
		m_developerSecond = kStage3Second;// 秒
		m_developerMinute = kStage3Minute;// 分
	}
	if (stageSelectNum == 4)
	{
		m_developerMsec = kStage4Msec;// ミリ秒
		m_developerSecond = kStage4Second;// 秒
		m_developerMinute = kStage4Minute;// 分
	}
	if (stageSelectNum == 5)
	{
		m_developerMsec = kStage5Msec;// ミリ秒
		m_developerSecond = kStage5Second;// 秒
		m_developerMinute = kStage5Minute;// 分
	}
	if (stageSelectNum == 6)
	{
		m_developerMsec = kStage6Msec;// ミリ秒
		m_developerSecond = kStage6Second;// 秒
		m_developerMinute = kStage6Minute;// 分
	}
	if (stageSelectNum == 7)
	{
		m_developerMsec = kStage7Msec;// ミリ秒
		m_developerSecond = kStage7Second;// 秒
		m_developerMinute = kStage7Minute;// 分
	}
	if (stageSelectNum == 8)
	{
		m_developerMsec = kStage8Msec;// ミリ秒
		m_developerSecond = kStage8Second;// 秒
		m_developerMinute = kStage8Minute;// 分
	}
	if (stageSelectNum == 9)
	{
		m_developerMsec = kStage9Msec;// ミリ秒
		m_developerSecond = kStage9Second;// 秒
		m_developerMinute = kStage9Minute;// 分
	}
	if (stageSelectNum == 10)
	{
		m_developerMsec = kStage10Msec;// ミリ秒
		m_developerSecond = kStage10Second;// 秒
		m_developerMinute = kStage10Minute;// 分
	}
	if (stageSelectNum == 11)
	{
		m_developerMsec = kStage11Msec;// ミリ秒
		m_developerSecond = kStage11Second;// 秒
		m_developerMinute = kStage11Minute;// 分
	}
	if (stageSelectNum == 12)
	{
		m_developerMsec = kStage12Msec;// ミリ秒
		m_developerSecond = kStage12Second;// 秒
		m_developerMinute = kStage12Minute;// 分
	}
	if (stageSelectNum == 13)
	{
		m_developerMsec = kStage13Msec;// ミリ秒
		m_developerSecond = kStage13Second;// 秒
		m_developerMinute = kStage13Minute;// 分
	}
	if (stageSelectNum == 14)
	{
		m_developerMsec = kStage14Msec;// ミリ秒
		m_developerSecond = kStage14Second;// 秒
		m_developerMinute = kStage14Minute;// 分
	}
	if (stageSelectNum == 15)
	{
		m_developerMsec = kStage15Msec;// ミリ秒
		m_developerSecond = kStage15Second;// 秒
		m_developerMinute = kStage15Minute;// 分
	}
	if (stageSelectNum == 16)
	{
		m_developerMsec = kStage16Msec;// ミリ秒
		m_developerSecond = kStage16Second;// 秒
		m_developerMinute = kStage16Minute;// 分
	}
	if (stageSelectNum == 17)
	{
		m_developerMsec = kStage17Msec;// ミリ秒
		m_developerSecond = kStage17Second;// 秒
		m_developerMinute = kStage17Minute;// 分
	}
	if (stageSelectNum == 18)
	{
		m_developerMsec = kStage18Msec;// ミリ秒
		m_developerSecond = kStage18Second;// 秒
		m_developerMinute = kStage18Minute;// 分
	}
	if (stageSelectNum == 19)
	{
		m_developerMsec = kStage19Msec;// ミリ秒
		m_developerSecond = kStage19Second;// 秒
		m_developerMinute = kStage19Minute;// 分
	}
	if (stageSelectNum == 20)
	{
		m_developerMsec = kStage20Msec;// ミリ秒
		m_developerSecond = kStage20Second;// 秒
		m_developerMinute = kStage20Minute;// 分
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
