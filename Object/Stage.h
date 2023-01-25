// ステージ
#pragma once
#include "../Util/common.h"
class Stage
{
public:
	Stage();
	virtual ~Stage();

	void init();
	void end();
	void update();
	void draw();

	int m_stage[STAGE_HEIGHT][STAGE_WIDTH];

private:
	// ギミックの描画が変わる時間
	int m_gimmickFrame;
	// しぼんでいる時間
	int m_shrink;
	// 膨らんている時間
	int m_inflate;
};

