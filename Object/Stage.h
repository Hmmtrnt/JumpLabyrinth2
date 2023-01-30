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

	// ステージハンドル
	int m_handle;
	int m_handle2;

	// 切り取る左上の頂点
	int m_vertexX;
	int m_vertexY;
	int m_vertexX2;
	int m_vertexY2;

	int m_verX;
	int m_verY;
	int m_verX2;
	int m_verY2;
};

