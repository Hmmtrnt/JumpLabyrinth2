#include "SceneTitle.h"
#include "SceneSelect.h"
#include "SceneMain.h"
#include "../Util/Pad.h"

SceneTitle::SceneTitle() :
	m_textHandle(-1),
	m_textFlash(0),
	m_textShow(0),
	m_textHide(0)
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::init()
{
	m_textHandle = CreateFontToHandle(NULL, 50, 4);
	m_textFlash = 0;
	m_textShow = 40;
	m_textHide = 20;
}

void SceneTitle::end()
{
	DeleteFontToHandle(m_textHandle);
}

SceneBase* SceneTitle::update()
{
	// テキストの点滅
	m_textFlash++;
	if (m_textFlash >= m_textShow + m_textHide)
	{
		m_textFlash = 0;
	}

	// 仮のシーン遷移
	if (Pad::isTrigger(PAD_INPUT_2) == 1)
	{
		return(new SceneSelect);
	}
	return this;
}

void SceneTitle::draw()
{
	DrawStringToHandle(50, 200, "Tomb of the Maskっぽいナニカ", kColor::White, m_textHandle);

	// 点滅テキスト
	if (m_textFlash < m_textShow)
	{
		DrawString(270, 500, "Ｂボタンを押してセレクト画面へ", kColor::White, true);
	}

}