#include "ScenePause.h"
#include "../Util/Pad.h"

ScenePause::ScenePause() :
	m_textHandle(-1)
{
}

ScenePause::~ScenePause()
{
}

void ScenePause::init()
{
	m_textHandle = CreateFontToHandle(NULL, 50, 4);
}

void ScenePause::end()
{
	DeleteFontToHandle(m_textHandle);
}

void ScenePause::update()
{
}

void ScenePause::draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(100, 100, 700, 600, kColor::LightBlue, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawBox(100, 100, 700, 600, kColor::Black, false);
	//DrawStringToHandle(200, 250, "リタイア", kColor::Black, m_textHandle);
	//DrawFormatStringToHandle(200, 250, kColor::Black, m_textHandle, "リタイア");
	DrawString(200, 250, "リタイア", kColor::Black);
}
