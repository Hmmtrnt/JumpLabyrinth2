#include "SceneSelect.h"
#include "SceneMain.h"
#include "../Util/Pad.h"

SceneSelect::SceneSelect() :
	m_stageSelect(0),
	m_textHandle(-1),
	m_textHandle2(-1)
{
}

SceneSelect::~SceneSelect()
{
}

void SceneSelect::init()
{
	m_stageSelect = 0;
	m_textHandle = CreateFontToHandle(NULL, 100, 3);
	m_textHandle2 = CreateFontToHandle(NULL, 50, 3);
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

	if (m_stageSelect <= 0)
	{
		m_stageSelect = 0;
	}

	// 仮のシーン遷移
	if (Pad::isTrigger(PAD_INPUT_2) == 1)
	{
		return(new SceneMain);
	}
	return this;
}

void SceneSelect::draw()
{
	DrawStringToHandle(300, 180, "ステージ", kColor::White,m_textHandle2 );
	DrawFormatStringToHandle(380, 240, kColor::White, m_textHandle ,"%d", m_stageSelect);
	DrawString(300, 500, "Bボタンでステージを選択", kColor::White);
}
