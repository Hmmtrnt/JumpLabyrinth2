#include "SceneTitle.h"
#include "SceneSelect.h"
#include "SceneMain.h"
#include "../Util/Pad.h"

SceneTitle::SceneTitle()
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::init()
{
}

void SceneTitle::end()
{
}

SceneBase* SceneTitle::update()
{

	// ‰¼‚ÌƒV[ƒ“‘JˆÚ
	if (Pad::isTrigger(PAD_INPUT_2) == 1)
	{
		return(new SceneSelect);
	}
	return this;
}

void SceneTitle::draw()
{
	DrawString(0, 0, "SceneTitle", GetColor(255, 255, 255), true);
}