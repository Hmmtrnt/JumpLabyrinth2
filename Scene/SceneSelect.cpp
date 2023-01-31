#include "SceneSelect.h"
#include "SceneMain.h"
#include "../Util/Pad.h"

SceneSelect::SceneSelect()
{
}

SceneSelect::~SceneSelect()
{
}

void SceneSelect::init()
{
}

void SceneSelect::end()
{
}

SceneBase* SceneSelect::update()
{
	// ‰¼‚ÌƒV[ƒ“‘JˆÚ
	if (Pad::isTrigger(PAD_INPUT_2) == 1)
	{
		return(new SceneMain);
	}
	return this;
}

void SceneSelect::draw()
{
	DrawString(0, 0, "SceneSelect", kColor::White);
}
