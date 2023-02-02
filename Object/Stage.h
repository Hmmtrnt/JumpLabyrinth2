// ステージ
#pragma once
#include "../Util/common.h"
class Stage
{
public:
	Stage();
	virtual ~Stage();

	void initCommon();	// 共通の初期化
	void initP();		// プロトタイプ用初期化
	void init1();		// ステージ1の初期化
	void init2();		// ステージ2の初期化
	void init3();		// ステージ3の初期化
	void init4();		// ステージ4の初期化
	void init5();		// ステージ5の初期化
	void end();			// 終了
	void update();		// 更新
	void draw();		// 描画

	int m_stage[STAGE_HEIGHT][STAGE_WIDTH];

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

	// 切り取る左上の頂点
	int m_verX;
	int m_verY;
};