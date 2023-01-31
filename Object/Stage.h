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
	int m_handleWall;		// 触れる判定のハンドル
	int m_handleTrap;		// 敵判定のハンドル

	// 切り取る左上の頂点
	int m_verXWall;
	int m_verYWall;
	int m_verXTrap;
	int m_verYTrap;
	int m_verXLagTrap;
	int m_verYLagTrap;
	int m_verXFire;
	int m_verYFire;
	int m_verXInflate;
	int m_verYInflate;
	int m_verXInflate2;
	int m_verYInflate2;
	int m_verXGoal;
	int m_verYGoal;
};

