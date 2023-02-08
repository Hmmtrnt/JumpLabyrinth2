// ステージ
#pragma once
#include "../Util/common.h"
class Stage
{
public:
	Stage();
	virtual ~Stage();

	void initCommon();	// 共通の初期化

	void initStage(const int stage[][kVariable::StageWidth], int stageHeight, int stageWidth);	// 実験用初期化

	void initP();		// プロトタイプ用初期化

	void end();			// 終了
	void update();		// 更新
	void draw();		// 描画

	int m_stage[kVariable::StageWidth][kVariable::StageWidth];

	int* m_pStage[kVariable::StageWidth][kVariable::StageWidth];

private:
	// ステージの描画
	void stageDraw(int x, int y);
	// 針の描画
	void needleDraw(int x, int y);

	// ギミックの描画が変わる時間
	int m_gimmickFrame;
	// しぼんでいる時間
	int m_shrink;
	// 膨らんている時間
	int m_inflate;

	// ステージハンドル
	int m_handleWall;		// 触れる判定のハンドル
	int m_handleTrap;		// 敵判定のハンドル
	int m_handleSmallNeedle;// 少し出てる針
	int m_handleGoal;

	// 切り取る左上の頂点
	int m_verX;
	int m_verY;

	// ゴールの左上頂点
	int m_idxGoalX;
	int m_idxGoalY;

	int m_GoalFrame;
	int m_drawGoalFirst;
	int m_drawGoalSecond;
};