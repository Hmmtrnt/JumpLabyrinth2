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

	int GetPushNum(){ return m_pushNum; }

private:
	// テキストハンドル
	int m_textHandle;
	// 矢印の位置
	int m_posArrow;
	// 押した回数
	int m_pushNum;
};