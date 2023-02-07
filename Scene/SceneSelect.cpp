#include "SceneSelect.h"
#include "SceneMain.h"
#include "SceneStage1.h"
#include "SceneStage2.h"
#include "SceneStage3.h"
#include "SceneStage4.h"
#include "SceneStage5.h"
#include "SceneStage6.h"
#include "SceneStage7.h"
#include "SceneStage8.h"
#include "SceneStage9.h"
#include "SceneStage10.h"
#include "SceneStage11.h"
#include "SceneStage12.h"
#include "SceneStage13.h"
#include "../Util/Pad.h"

SceneSelect::SceneSelect() :
	m_stageSelect(0),
	m_textHandle(-1),
	m_textHandle2(-1),
	m_createStage(0)
{
}

SceneSelect::~SceneSelect()
{
}

void SceneSelect::init()
{
	m_stageSelect = 1;
	m_textHandle = CreateFontToHandle(NULL, 100, 3);
	m_textHandle2 = CreateFontToHandle(NULL, 50, 3);
	m_createStage = 13;
}

void SceneSelect::end()
{
	DeleteFontToHandle(m_textHandle);
	DeleteFontToHandle(m_textHandle2);
}

SceneBase* SceneSelect::update()
{
	if (Pad::isTrigger(PAD_INPUT_RIGHT) == 1)
	{
		m_stageSelect++;
	}
	else if (Pad::isTrigger(PAD_INPUT_LEFT) == 1)
	{
		m_stageSelect--;
	}
	else if (Pad::isTrigger(PAD_INPUT_Y) == 1)
	{
		m_stageSelect -= 5;
	}
	else if (Pad::isTrigger(PAD_INPUT_Z) == 1)
	{
		m_stageSelect += 5;
	}
	if (m_stageSelect <= 0)
	{
		m_stageSelect = 0;
	}
	else if (m_stageSelect >= m_createStage)
	{
		m_stageSelect = m_createStage;
	}

	// プロトタイプ用ステージへのシーン遷移
	if (Pad::isTrigger(PAD_INPUT_2) == 1 && m_stageSelect == 0)
	{
		return(new SceneMain);
	}
	// ここからステージ選択
	// ステージ1
	if (Pad::isTrigger(PAD_INPUT_2) == 1 && m_stageSelect == 1)
	{
		return (new SceneStage1);
	}
	// ステージ2
	if (Pad::isTrigger(PAD_INPUT_2) == 1 && m_stageSelect == 2)
	{
		return (new SceneStage2);
	}
	// ステージ3
	if (Pad::isTrigger(PAD_INPUT_2) == 1 && m_stageSelect == 3)
	{
		return (new SceneStage3);
	}
	// ステージ4
	if (Pad::isTrigger(PAD_INPUT_2) == 1 && m_stageSelect == 4)
	{
		return (new SceneStage4);
	}
	// ステージ5
	if (Pad::isTrigger(PAD_INPUT_2) == 1 && m_stageSelect == 5)
	{
		return (new SceneStage5);
	}
	// ステージ6
	if (Pad::isTrigger(PAD_INPUT_2) == 1 && m_stageSelect == 6)
	{
		return (new SceneStage6);
	}
	// ステージ7
	if (Pad::isTrigger(PAD_INPUT_2) == 1 && m_stageSelect == 7)
	{
		return (new SceneStage7);
	}
	// ステージ8
	if (Pad::isTrigger(PAD_INPUT_2) == 1 && m_stageSelect == 8)
	{
		return (new SceneStage8);
	}
	// ステージ9
	if (Pad::isTrigger(PAD_INPUT_2) == 1 && m_stageSelect == 9)
	{
		return (new SceneStage9);
	}
	// ステージ10
	if (Pad::isTrigger(PAD_INPUT_2) == 1 && m_stageSelect == 10)
	{
		return (new SceneStage10);
	}
	// ステージ11
	if (Pad::isTrigger(PAD_INPUT_2) == 1 && m_stageSelect == 11)
	{
		return (new SceneStage11);
	}
	// ステージ12
	if (Pad::isTrigger(PAD_INPUT_2) == 1 && m_stageSelect == 12)
	{
		return (new SceneStage12);
	}
	// ステージ13
	if (Pad::isTrigger(PAD_INPUT_2) == 1 && m_stageSelect == 13)
	{
		return (new SceneStage13);
	}

	return this;
}

void SceneSelect::draw()
{
	DrawStringToHandle(300, 180, "ステージ", kColor::White,m_textHandle2 );
	if (m_stageSelect <= 9)
	{
		DrawFormatStringToHandle(380, 240, kColor::White, m_textHandle, "%d", m_stageSelect);
	}
	else
	{
		DrawFormatStringToHandle(360, 240, kColor::White, m_textHandle, "%d", m_stageSelect);
	}
	DrawString(300, 500, "Bボタンでステージを選択", kColor::White);
	DrawFormatString(300, 550, kColor::White, "%dステージまで出来ています\n", m_createStage);
	DrawString(300, 600, "0ステージは実験用ステージです\n", kColor::White);
	DrawString(600, 200, "RBボタン＋5", kColor::White);
	DrawFormatStringToHandle(600, 240, kColor::White, m_textHandle, "→");
	if (m_stageSelect != 0)
	{
		DrawString(100, 200, "LBボタンー5", kColor::White);
		DrawFormatStringToHandle(100, 240, kColor::White, m_textHandle, "←");
	}
}
