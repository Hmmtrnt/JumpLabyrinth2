#pragma once
#include "../Util/common.h"


class ScenePause
{
public:
	ScenePause();
	virtual ~ScenePause();

	void init();
	void end();
	void update();
	void pauseDraw();

	int GetPushNum(){ return m_pushNum; }

private:
	// テキストハンドル
	int m_textHandle;
	// 矢印の位置
	int m_posArrow;
	// 押した回数
	int m_pushNum;
	// 音ハンドル
	int m_cursorSound;		// カーソル移動音
	int m_cursorNotSound;	// カーソル移動できない音
};