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

	// クリアタイムの情報取得
	// プレイヤー
	int GetTimeMsec() { return m_timeMsec; }
	int GetTimeSecond() { return m_timeSecond; }
	int GetTimeMinute() { return m_timeMinute; }
	// 開発者
	int GetDeveloperTimeMsec() { return m_developerMsec; }
	int GetDeveloperTimeSecond() { return m_developerSecond; }
	int GetDeveloperTimeMinute() { return m_developerMinute; }

	int m_timeMsec;// ミリ秒
	int m_timeSecond;// 秒
	int m_timeMinute;// 分
	// 以下開発者のタイム
	int m_developerMsec;// ミリ秒
	int m_developerSecond;// 秒
	int m_developerMinute;// 分

private:
	// クリア時間
	int m_clearTime;// 全体フレーム
	
};