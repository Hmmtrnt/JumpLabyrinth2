#pragma once
#include "../Util/common.h"

class StageTimer
{
public:
	StageTimer();
	virtual ~StageTimer();

	void timerUpdate();// タイマー更新
	void timeAssignment();// ステージごとに開発者のタイムを代入

	/// <summary>
	/// プレイ中のタイマー描画
	/// </summary>
	/// <param name="font">フォント</param>
	void drawTime(int font);

	/// <summary>
	/// タイムの結果
	/// </summary>
	/// <param name="font">フォント</param>
	void drawResult(int font);
private:
	// クリア時間
	int m_clearTime;// 全体フレーム
	int m_timeMsec;// ミリ秒
	int m_timeSecond;// 秒
	int m_timeMinute;// 分
	// 以下開発者のタイム
	int m_developerMsec;// ミリ秒
	int m_developerSecond;// 秒
	int m_developerMinute;// 分
};