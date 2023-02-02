#pragma once
#include "../Util/common.h"


class ScenePause
{
public:
	ScenePause();
	virtual ~ScenePause();

	virtual void init();
	virtual void end();
	virtual void update();
	virtual void draw();
private:
	// テキストハンドル
	int m_textHandle;
};