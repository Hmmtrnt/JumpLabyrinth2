#pragma once
#include "SceneBase.h"
class ScenePause : public SceneBase
{
public:
	ScenePause();
	virtual ~ScenePause();

	virtual void init();
	virtual void end();
	virtual SceneBase* update();
	virtual void draw();
private:

};

