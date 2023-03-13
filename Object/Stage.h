// ステージ
#pragma once
#include "../Util/common.h"
#include "../Util/Vec2.h"
#include <array>
#include <memory>

class CharParticle;

class Stage
{
public:
	Stage();
	virtual ~Stage();

	void initCommon();	// 共通の初期化
	void initStage(const int stage[][kVariable::StageWidth], int stageHeight, int stageWidth);	// 実験用初期化
	void end();			// 終了
	void update();		// 更新
	void draw();		// 描画

	int m_stage[kVariable::StageWidth][kVariable::StageWidth];// ステージ

private:
	// ステージの描画
	void stageDraw(int x, int y);
	// 針の描画
	void needleDraw(int x, int y);
	// ゴールのパーティクル
	void particle(int x, int y);	// 動き
	void drawParticle();			// 描画

	// ギミックの描画が変わる時間
	int m_gimmickFrame;
	// しぼんでいる時間
	int m_shrink;
	// 膨らんている時間
	int m_inflate;

	// ステージハンドル
	int m_handleWall;// 触れる判定のハンドル
	int m_handleTrap;// 敵判定のハンドル
	int m_handleSmallNeedle;// 少し出てる針
	int m_handleGoal;// ゴール

	// 切り取る左上の頂点
	int m_verX;
	int m_verY;

	// ゴールの左上頂点
	int m_idxGoalX;
	int m_idxGoalY;

	// ゴールのモーション引数
	int m_GoalFrame;// 全体
	int m_drawGoalFirst;// 一枚目
	int m_drawGoalSecond;// 二枚目

	// パーティクル
	std::array<std::shared_ptr<CharParticle>, kParticle::ParticleNum> m_particle;
	int m_showerFrame;		// 描画するフレーム
	int m_particleFrame;	// 表示する時間
	int m_auraFrame;		// エリア
};