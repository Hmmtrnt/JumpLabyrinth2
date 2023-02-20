#pragma once
#include "DxLib.h"
#include "game.h"
#include "DrawFunctions.h"
#include "Pad.h"

// 円周率(仮)
#define PI    3.1415926535897932384626433832795f

namespace kVariable
{
	// プレイヤーの配列の幅
	constexpr int PlayerWidth = 3;		// 横

	// ショットの配列の幅
	constexpr int ShotWidth = 3;		// 横

	// ステージの幅
	constexpr int StageWidth = 15;

	// 背景の幅
	constexpr int BackHeight = 22;		// 縦
	constexpr int BackWidth = 25;		// 横

	// ステージの描画する幅
	constexpr int DrawWidth = 68;

	// 背景を描画する幅
	constexpr int DrawBackWidth = 100;

	// 描画する位置変更
	constexpr int DrawPosition = 450;
}

// 背景
namespace kBack
{
	constexpr int backs[kVariable::BackHeight][kVariable::BackWidth] = {
		// 1行	    6行        11行       16行       21行     
		{0,0,0,0,0, 1,0,0,0,0, 0,0,0,0,1, 0,1,1,0,0, 1,1,0,0,0},// 1行
		{0,0,0,0,0, 0,1,0,0,0, 0,1,0,1,0, 1,0,0,0,0, 0,0,1,0,0},
		{0,0,1,0,0, 0,0,1,0,1, 0,0,0,0,0, 0,0,0,0,1, 0,0,1,1,1},
		{0,0,0,0,0, 0,0,0,0,0, 1,0,1,0,0, 0,1,0,1,0, 1,0,0,0,0},
		{1,0,0,0,0, 1,0,1,0,0, 0,1,0,0,0, 0,0,1,0,0, 0,1,0,0,0},

		{0,0,0,1,1, 0,0,0,0,0, 1,0,0,0,1, 0,0,0,0,0, 0,0,1,0,0},// 6行
		{0,0,0,1,0, 1,0,0,0,1, 0,0,0,0,1, 0,0,0,1,0, 1,0,0,0,0},
		{0,0,0,0,0, 0,0,1,0,0, 0,0,0,1,0, 1,0,0,0,0, 0,1,0,0,1},
		{0,0,0,1,0, 0,1,0,1,0, 0,0,1,0,0, 0,1,1,0,1, 0,0,0,1,0},
		{0,0,0,0,0, 0,0,0,0,1, 1,0,0,0,0, 0,0,0,0,0, 1,1,1,0,0},

		{0,1,0,0,0, 0,0,0,1,0, 0,1,1,0,1, 0,0,0,1,1, 0,0,0,0,0},// 11行
		{0,0,0,0,0, 0,0,1,1,0, 0,0,0,0,0, 1,1,0,0,0, 0,1,1,1,1},
		{0,0,0,0,0, 1,1,0,1,0, 1,0,0,0,0, 0,1,1,0,0, 0,0,0,1,0},
		{0,1,0,1,0, 0,0,0,0,1, 0,0,0,0,0, 0,0,0,0,0, 1,0,1,0,0},
		{0,0,0,0,0, 0,1,0,0,0, 0,0,0,1,1, 1,0,0,1,0, 1,0,0,0,0},

		{1,0,0,0,0, 0,0,0,0,0, 1,0,0,0,0, 0,1,0,0,0, 0,0,0,0,0},// 16行
		{0,0,0,0,0, 1,0,0,0,0, 0,0,0,1,1, 1,0,1,0,1, 0,0,0,0,0},
		{0,0,0,1,0, 0,1,1,0,1, 0,0,1,0,0, 0,0,0,0,0, 1,1,1,0,0},
		{0,0,0,0,0, 1,0,0,0,0, 0,0,0,0,0, 0,0,0,1,0, 1,0,1,0,1},
		{1,0,0,1,0, 0,1,0,0,0, 0,0,1,0,0, 0,1,0,0,0, 0,0,0,1,0},

		{0,0,0,0,0, 0,0,1,1,0, 1,0,0,0,0, 1,0,0,0,1, 0,0,1,0,0},// 21行
		{0,0,0,0,0, 1,0,0,0,0, 0,0,1,0,1, 0,0,0,1,0, 0,0,0,0,1},
		
	};
}

// ステージ
namespace kStage
{
	// ステージの配列
	// 0:無
	// 4:弾発射開始位置
	// 5:膨らんだら即死判定
	// 6:即死判定
	// 7:数フレーム後に針が出てゲームオーバーになる判定
	// 8:ゴール
	// 9:壁
	// プロトタイプ用ステージ
	constexpr int stageP[kVariable::StageWidth][kVariable::StageWidth] = {
		// 1行       6行         11行     
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},// 1行
		{9,0,0,8,9,  0,0,0,7,9,  0,0,0,0,9},
		{9,0,9,9,9,  0,9,0,9,9,  0,9,9,0,9},
		{9,0,0,7,9,  0,9,0,9,9,  0,9,9,0,9},
		{9,0,0,0,9,  0,9,0,9,9,  0,9,9,0,9},

		{9,9,0,0,9,  0,9,0,0,0,  0,9,9,0,9},// 6行
		{9,9,0,0,9,  0,9,6,9,9,  9,9,9,0,9},
		{9,9,0,0,9,  0,9,9,9,9,  9,7,0,0,9},
		{9,9,0,0,9,  0,9,9,9,9,  9,9,0,0,9},
		{9,9,0,0,0,  0,9,9,9,9,  9,9,0,9,9},

		{9,9,0,5,0,  0,0,0,0,0,  9,9,0,9,9},// 11行
		{9,9,0,0,0,  0,7,0,0,0,  9,9,0,0,9},
		{9,9,0,0,0,  0,0,0,0,0,  9,0,0,0,9},
		{9,4,0,0,0,  0,0,0,0,0,  9,0,0,0,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},
	};

	// ステージ１
	// 8:ゴール
	// 9:壁
	constexpr int stage1[kVariable::StageWidth][kVariable::StageWidth] = {
		// 1行		 6行		 11行
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},// 1行
		{9,9,9,9,9,  9,0,0,0,0,  0,0,0,9,9},
		{9,9,9,9,9,  9,0,9,9,9,  9,9,0,9,9},
		{9,9,9,9,9,  9,0,9,9,9,  9,9,0,9,9},
		{9,9,9,9,9,  9,0,9,9,9,  9,9,0,9,9},

		{9,9,9,9,9,  9,0,9,9,9,  9,9,0,9,9},// 6行
		{9,9,0,0,0,  0,0,0,0,0,  0,9,0,9,9},
		{9,9,0,9,9,  9,0,0,0,0,  0,9,0,9,9},
		{9,9,0,9,9,  9,0,9,9,0,  0,9,0,9,9},
		{9,9,8,9,9,  9,0,0,0,0,  0,9,0,9,9},

		{9,9,9,9,9,  9,9,9,9,9,  9,9,0,9,9},// 11行
		{9,9,9,9,9,  9,9,9,9,9,  9,9,0,9,9},
		{9,0,0,0,0,  0,0,0,0,0,  0,0,0,9,9},
		{9,0,0,0,9,  9,9,9,9,9,  9,9,9,9,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},
	};
	// ステージ２
	// 6:即死判定
	// 8:ゴール
	// 9:壁
	constexpr int stage2[kVariable::StageWidth][kVariable::StageWidth] = {
		// 1行		 6行		 11行
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},// 1行
		{9,0,0,0,0,  0,0,0,0,0,  0,0,0,0,9},
		{9,0,0,0,6,  6,6,6,6,6,  6,6,6,0,9},
		{9,0,0,0,9,  9,9,9,9,9,  9,9,9,0,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,0,9},

		{9,9,9,9,9,  9,9,9,9,9,  6,6,6,0,9},// 6行
		{9,8,0,0,0,  0,0,9,9,9,  0,0,0,0,9},
		{9,9,9,9,9,  9,0,9,9,9,  0,0,0,0,9},
		{9,9,6,0,0,  0,0,9,9,9,  0,9,9,9,9},
		{9,9,9,0,0,  0,0,9,9,0,  0,9,9,9,9},

		{9,9,9,0,9,  9,0,9,9,0,  9,9,9,6,9},// 11行
		{9,9,9,0,0,  0,0,0,9,0,  0,0,0,0,9},
		{9,9,9,9,9,  9,9,0,9,9,  9,9,6,0,9},
		{9,9,9,9,9,  9,9,0,0,0,  0,0,0,0,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},
	};
	// ステージ3
	// 6:即死判定
	// 8:ゴール
	// 9:壁
	constexpr int stage3[kVariable::StageWidth][kVariable::StageWidth] = {
		// 1行		 6行		 11行
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},// 1行
		{9,9,9,9,9,  9,9,9,9,9,  9,6,6,6,9},
		{9,9,8,0,0,  0,0,0,0,0,  0,0,0,6,9},
		{9,9,9,9,9,  9,0,0,0,0,  0,0,0,6,9},
		{9,9,9,9,9,  0,0,0,0,0,  0,9,0,6,9},

		{9,0,0,0,0,  0,9,9,9,6,  6,6,6,6,9},// 6行
		{9,0,9,9,9,  9,9,9,9,6,  6,6,9,6,9},
		{9,0,0,0,9,  0,0,0,0,0,  0,0,0,6,9},
		{9,9,9,0,9,  0,9,9,9,0,  9,9,0,9,9},
		{9,9,9,0,0,  0,9,0,0,0,  9,9,0,9,9},

		{9,9,9,9,9,  9,9,0,9,0,  0,0,0,9,9},// 11行
		{9,0,0,9,9,  9,9,0,0,0,  9,9,0,9,9},
		{9,0,0,0,0,  0,0,0,9,0,  0,0,0,9,9},
		{9,0,0,0,9,  9,9,9,9,9,  9,9,9,9,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},
	};
	// ステージ4
	// 6:即死判定
	// 8:ゴール
	// 9:壁
	constexpr int stage4[kVariable::StageWidth][kVariable::StageWidth] = {
		// 1行		 6行		 11行
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},// 1行
		{9,6,9,6,6,  6,6,6,6,6,  6,9,6,6,9},
		{9,6,0,0,0,  0,0,0,0,0,  0,0,0,0,9},
		{9,6,0,0,9,  6,6,6,6,9,  6,6,6,0,9},
		{9,9,0,6,0,  0,9,0,0,0,  6,6,6,0,9},

		{9,0,0,9,0,  0,9,8,9,0,  9,6,6,0,9},// 6行
		{9,0,6,6,0,  0,9,9,9,0,  0,0,0,0,9},
		{9,0,6,6,0,  0,0,0,0,0,  0,0,0,9,9},
		{9,0,6,6,0,  6,6,9,6,6,  6,6,0,6,9},
		{9,0,6,6,0,  6,9,9,9,9,  9,6,0,6,9},

		{9,0,6,6,0,  6,9,9,9,9,  9,6,0,6,9},// 11行
		{9,0,6,6,0,  6,6,6,6,6,  6,6,0,6,9},
		{9,0,6,9,0,  0,0,0,0,0,  0,0,0,6,9},
		{9,0,0,0,0,  9,6,6,6,6,  6,6,9,6,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},
	};
	// ステージ5
	// 6:即死判定
	// 8:ゴール
	// 9:壁
	constexpr int stage5[kVariable::StageWidth][kVariable::StageWidth] = {
		// 1行		 6行		 11行
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},// 1行
		{9,0,0,0,0,  0,0,0,0,0,  0,0,0,0,9},
		{9,0,0,0,0,  0,0,0,0,0,  0,0,0,6,9},
		{9,0,9,0,0,  0,0,0,0,0,  0,0,0,0,9},
		{9,0,0,8,6,  0,0,0,0,0,  0,0,0,0,9},

		{9,0,0,0,0,  0,0,0,0,6,  9,0,0,0,9},// 6行
		{9,0,9,0,0,  0,0,0,0,0,  0,0,0,0,9},
		{9,0,0,0,0,  0,0,0,0,0,  0,0,0,0,9},
		{9,0,0,0,0,  0,0,0,0,0,  0,0,0,9,9},
		{9,0,0,9,0,  0,0,0,0,0,  0,0,0,0,9},

		{9,0,0,0,0,  0,0,0,0,0,  0,9,0,0,9},// 11行
		{9,0,0,0,9,  0,0,0,0,0,  0,0,0,0,9},
		{9,0,0,0,0,  0,0,0,0,0,  9,0,0,0,9},
		{9,9,0,0,0,  0,0,0,0,0,  0,0,0,0,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},
	};
	// ステージ6
	// 7:数フレーム後に針が出てゲームオーバーになる判定
	// 8:ゴール
	// 9:壁
	constexpr int stage6[kVariable::StageWidth][kVariable::StageWidth] = {
		// 1行		 6行		 11行
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},// 1行
		{9,9,9,9,9,  9,7,7,9,0,  0,0,0,7,9},
		{9,0,0,0,0,  9,7,7,9,0,  9,0,0,9,9},
		{9,0,9,9,0,  9,9,9,9,0,  9,0,0,9,9},
		{9,0,0,9,0,  0,0,0,0,0,  7,0,0,9,9},

		{9,9,0,9,9,  9,9,9,9,9,  9,0,0,9,9},// 6行
		{9,9,0,0,9,  9,9,9,0,0,  0,0,0,9,9},
		{9,0,0,0,9,  9,9,9,0,0,  0,0,0,9,9},
		{9,0,7,0,9,  9,9,8,0,0,  0,0,0,9,9},
		{9,0,0,0,9,  9,9,9,9,9,  9,9,9,9,9},

		{9,9,0,9,9,  9,9,9,9,9,  9,9,9,9,9},// 11行
		{9,9,0,9,0,  0,0,9,9,9,  9,9,9,9,9},
		{9,9,0,9,0,  0,0,9,9,9,  9,0,0,0,9},
		{9,9,0,0,0,  9,0,0,0,0,  0,0,0,0,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},
	};
	// ステージ7
	// 6:即死判定
	// 7:数フレーム後に針が出てゲームオーバーになる判定
	// 8:ゴール
	// 9:壁
	constexpr int stage7[kVariable::StageWidth][kVariable::StageWidth] = {
		// 1行		 6行		 11行
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},// 1行
		{9,9,7,9,7,  6,9,0,0,0,  0,0,0,0,9},
		{9,9,0,0,0,  6,0,0,0,9,  9,9,9,0,9},
		{9,9,0,9,0,  6,0,9,0,9,  7,9,9,0,9},
		{9,9,0,9,0,  6,6,6,0,9,  0,0,0,0,9},

		{9,9,0,9,0,  9,9,9,0,9,  0,9,9,9,9},// 6行
		{9,9,0,9,0,  9,0,0,0,9,  0,9,6,9,9},
		{9,9,0,9,0,  9,0,9,7,9,  0,0,0,9,9},
		{9,9,0,9,0,  9,0,9,0,0,  0,9,0,9,9},
		{9,9,0,9,0,  9,0,9,0,9,  0,9,0,9,9},

		{9,9,0,9,0,  9,0,9,0,9,  0,0,0,7,9},// 11行
		{9,9,0,9,0,  9,0,9,0,9,  9,9,9,9,9},
		{9,9,0,9,0,  9,0,9,0,9,  0,0,0,9,9},
		{9,9,8,7,0,  0,0,9,0,0,  0,0,0,9,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},
	};
	// ステージ8
	// 6:即死判定
	// 7:数フレーム後に針が出てゲームオーバーになる判定
	// 8:ゴール
	// 9:壁
	constexpr int stage8[kVariable::StageWidth][kVariable::StageWidth] = {
		// 1行		 6行		 11行
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},// 1行
		{9,9,9,9,7,  0,0,0,9,0,  0,0,0,0,9},
		{9,9,7,9,9,  0,9,0,9,0,  9,0,0,0,9},
		{9,9,0,0,0,  0,0,0,9,0,  9,9,9,9,9},
		{9,9,0,9,9,  0,9,7,9,0,  0,0,0,7,9},

		{9,7,0,0,0,  0,0,0,9,9,  9,9,0,9,9},// 6行
		{9,9,9,9,9,  0,9,0,9,0,  0,0,0,6,9},
		{9,9,9,9,9,  0,9,0,9,0,  9,9,7,9,9},
		{9,9,0,0,0,  0,0,0,9,0,  0,0,0,9,9},
		{9,9,0,9,9,  0,9,9,9,7,  9,9,0,9,9},

		{9,9,0,9,9,  0,9,9,9,9,  9,9,0,9,9},// 11行
		{9,7,0,0,0,  0,0,0,6,9,  9,9,0,9,9},
		{9,9,9,9,9,  0,9,0,9,9,  9,9,0,9,9},
		{9,9,8,0,0,  0,9,0,0,0,  0,0,0,9,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},
	};
	// ステージ9
	// 6:即死判定
	// 7:数フレーム後に針が出てゲームオーバーになる判定
	// 8:ゴール
	// 9:壁
	constexpr int stage9[kVariable::StageWidth][kVariable::StageWidth] = {
		// 1行		 6行		 11行
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},// 1行
		{9,0,0,0,0,  0,0,0,0,0,  0,0,6,9,9},
		{9,0,0,0,0,  0,0,0,0,0,  0,0,0,7,9},
		{9,9,9,9,9,  0,0,0,0,0,  0,0,0,0,9},
		{9,9,7,0,0,  0,0,0,0,0,  6,0,0,0,9},

		{9,6,0,0,0,  0,0,0,0,0,  0,7,0,0,9},// 6行
		{9,0,0,0,7,  0,0,0,6,0,  0,0,0,0,9},
		{9,0,0,6,0,  0,0,0,0,7,  0,0,0,0,9},
		{9,0,0,0,0,  0,8,0,0,6,  0,0,0,0,9},
		{9,0,0,0,0,  0,0,0,7,0,  0,0,0,0,9},

		{9,0,0,7,0,  0,0,0,0,0,  0,6,0,0,9},// 11行
		{9,0,0,0,6,  0,0,0,0,0,  7,0,0,0,9},
		{9,7,0,0,0,  0,0,0,0,0,  0,0,0,6,9},
		{9,9,6,0,0,  0,0,0,0,0,  0,0,7,9,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},
	};
	// ステージ10
	// 6:即死判定
	// 7:数フレーム後に針が出てゲームオーバーになる判定
	// 8:ゴール
	// 9:壁
	constexpr int stage10[kVariable::StageWidth][kVariable::StageWidth] = {
		// 1行		 6行		 11行
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},// 1行
		{9,9,9,7,7,  9,9,9,9,9,  9,9,9,9,9},
		{9,9,9,0,0,  7,7,9,9,9,  9,9,9,9,9},
		{9,9,9,0,0,  0,0,7,7,9,  9,9,9,9,9},
		{9,9,9,0,0,  0,0,0,0,7,  7,9,9,9,9},

		{9,9,9,0,0,  0,0,0,0,0,  0,9,9,9,9},// 6行
		{9,9,9,0,0,  0,0,0,0,0,  0,0,0,8,9},
		{9,9,9,0,0,  0,0,0,0,0,  0,0,9,9,9},
		{9,9,9,0,0,  0,0,0,0,0,  7,7,9,9,9},
		{9,9,9,0,0,  0,0,0,7,7,  9,9,9,9,9},

		{9,9,9,0,0,  0,7,7,9,9,  9,9,9,9,9},// 11行
		{9,9,9,0,7,  7,9,9,9,9,  9,9,9,9,9},
		{9,0,0,0,9,  9,9,9,9,9,  9,9,9,9,9},
		{9,0,0,0,9,  9,9,9,9,9,  9,9,9,9,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},
	};
	// ステージ11
	// 5:膨らんだら即死判定
	// 8:ゴール
	// 9:壁
	constexpr int stage11[kVariable::StageWidth][kVariable::StageWidth] = {
		// 1行		 6行		 11行
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},// 1行
		{9,9,9,9,0,  0,0,9,9,9,  9,0,0,0,9},
		{9,9,9,9,0,  9,0,9,9,0,  0,0,0,0,9},
		{9,9,9,9,0,  9,0,9,9,0,  9,9,9,9,9},
		{9,9,0,0,0,  9,0,9,0,0,  0,0,0,9,9},

		{9,9,0,5,0,  9,0,9,0,5,  0,9,0,9,9},// 6行
		{9,9,0,0,0,  9,0,9,0,0,  0,9,0,9,9},
		{9,9,0,0,0,  9,0,9,9,9,  9,9,0,9,9},
		{9,9,0,5,0,  9,0,9,9,9,  0,0,0,9,9},
		{9,9,0,0,0,  9,0,9,9,9,  0,5,0,9,9},

		{9,9,0,0,0,  9,0,0,0,0,  0,0,0,9,9},// 11行
		{9,9,0,5,0,  9,9,9,9,9,  9,9,9,9,9},
		{9,9,0,0,0,  0,0,0,0,0,  0,0,0,8,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},
	};
	// ステージ12
	// 5:膨らんだら即死判定
	// 6:即死判定
	// 7:数フレーム後に針が出てゲームオーバーになる判定
	// 8:ゴール
	// 9:壁
	constexpr int stage12[kVariable::StageWidth][kVariable::StageWidth] = {
		// 1行		 6行		 11行
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},// 1行
		{9,9,9,9,9,  9,0,0,0,0,  0,0,7,9,9},
		{9,9,9,9,9,  9,0,0,0,5,  0,0,0,0,9},
		{9,7,9,0,0,  0,0,0,0,0,  0,0,5,0,9},
		{9,0,0,0,5,  0,9,0,0,0,  0,0,0,0,9},

		{9,0,9,0,0,  0,0,0,0,0,  9,9,9,0,9},// 6行
		{9,0,9,0,0,  0,0,0,9,7,  7,7,9,0,9},
		{9,0,9,0,0,  0,5,0,9,0,  0,0,9,8,9},
		{9,0,9,9,9,  0,0,0,9,0,  0,0,9,9,9},
		{9,0,0,0,9,  9,9,9,9,0,  5,0,0,0,9},

		{9,6,7,0,0,  0,0,0,0,0,  0,0,9,0,9},// 11行
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,0,9},
		{9,0,0,0,9,  9,9,0,0,0,  9,9,0,0,9},
		{9,0,0,0,0,  0,0,0,7,0,  0,0,0,7,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},
	};
	// ステージ13
	// 5:膨らんだら即死判定
	// 6:即死判定
	// 7:数フレーム後に針が出てゲームオーバーになる判定
	// 8:ゴール
	// 9:壁
	constexpr int stage13[kVariable::StageWidth][kVariable::StageWidth] = {
		// 1行		 6行		 11行
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},// 1行
		{9,9,0,0,0,  0,9,6,0,0,  0,0,0,7,9},
		{9,6,0,5,0,  0,0,0,0,0,  0,0,0,9,9},
		{9,6,0,0,0,  0,0,5,0,0,  0,5,0,9,9},
		{9,6,0,0,0,  0,0,0,0,9,  0,0,0,6,9},

		{9,9,9,9,9,  0,9,9,9,9,  0,0,9,9,9},// 6行
		{9,0,0,0,9,  0,9,0,0,0,  0,0,9,6,9},
		{9,0,0,0,9,  0,9,0,9,9,  9,9,9,0,9},
		{9,0,9,9,9,  0,9,0,9,0,  0,0,0,0,9},
		{9,0,9,9,9,  0,9,0,9,0,  9,0,5,0,9},

		{9,0,9,9,9,  0,0,0,9,0,  9,0,0,0,9},// 11行
		{9,0,0,0,9,  0,5,0,9,0,  9,0,9,9,9},
		{9,0,5,0,9,  0,0,0,9,0,  9,0,9,9,9},
		{9,0,0,0,0,  0,7,0,0,0,  7,0,8,9,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},
	};
	// ステージ14
	// 5:膨らんだら即死判定
	// 6:即死判定
	// 7:数フレーム後に針が出てゲームオーバーになる判定
	// 8:ゴール
	// 9:壁
	constexpr int stage14[kVariable::StageWidth][kVariable::StageWidth] = {
		// 1行		 6行		 11行
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},// 1行
		{9,9,0,0,0,  0,0,0,0,0,  7,6,6,6,9},
		{9,9,0,5,0,  9,9,9,9,9,  0,0,0,0,9},
		{9,6,0,0,0,  0,0,0,0,0,  0,7,0,0,9},
		{9,9,9,9,9,  9,0,5,0,9,  9,0,0,0,9},

		{9,6,0,0,0,  9,0,0,0,9,  9,0,5,0,9},// 6行
		{9,6,0,5,0,  9,9,0,9,9,  7,0,0,0,9},
		{9,0,0,0,0,  0,0,0,0,0,  0,0,0,0,9},
		{9,0,0,9,9,  9,9,0,9,9,  0,0,5,0,9},
		{9,9,0,9,9,  9,9,9,9,9,  0,0,0,0,9},

		{9,0,0,0,9,  9,9,8,9,9,  0,0,0,0,9},// 11行
		{9,0,5,0,9,  0,0,0,0,7,  0,5,0,0,9},
		{9,0,0,0,0,  0,0,0,0,7,  0,0,0,0,9},
		{9,9,9,6,9,  9,9,0,0,9,  0,9,9,7,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},
	};
	// ステージ15
	// 5:膨らんだら即死判定
	// 6:即死判定
	// 7:数フレーム後に針が出てゲームオーバーになる判定
	// 8:ゴール
	// 9:壁
	constexpr int stage15[kVariable::StageWidth][kVariable::StageWidth] = {
		// 1行		 6行		 11行
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},// 1行
		{9,6,6,6,6,  6,6,6,6,7,  0,0,0,0,9},
		{9,0,0,0,0,  7,0,0,0,0,  0,0,5,0,9},
		{9,9,9,9,0,  0,0,0,5,0,  0,0,0,0,9},
		{9,9,9,9,0,  0,0,0,0,0,  0,0,0,0,9},

		{9,0,0,0,9,  7,0,0,0,0,  0,0,0,0,9},// 6行
		{9,0,5,0,0,  0,0,0,0,0,  0,0,0,0,9},
		{9,0,0,0,0,  0,0,0,0,0,  5,0,0,7,9},
		{9,0,0,0,0,  0,0,0,0,0,  0,0,0,0,9},
		{9,0,0,0,0,  0,0,0,0,0,  0,0,7,0,9},

		{9,0,0,0,0,  0,0,0,5,0,  0,0,0,0,9},// 11行
		{9,7,0,0,0,  0,0,0,0,0,  0,0,5,0,9},
		{9,7,0,0,0,  0,0,0,0,7,  8,0,0,0,9},
		{9,9,6,9,6,  6,6,6,6,6,  7,7,7,6,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},
	};
	// ステージ16
	// 0:無
	// 4:弾発射開始位置
	// 8:ゴール
	// 9:壁
	constexpr int stage16[kVariable::StageWidth][kVariable::StageWidth] = {
		// 1行		 6行		 11行
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},// 1行
		{9,4,0,0,0,  0,0,4,0,0,  0,0,0,9,9},
		{9,0,0,9,9,  9,0,0,0,9,  9,9,0,9,9},
		{9,0,9,9,9,  9,9,9,9,9,  9,9,0,9,9},
		{9,0,9,9,9,  9,9,9,9,9,  9,9,0,9,9},

		{9,0,9,9,9,  9,9,9,9,9,  9,9,0,9,9},// 6行
		{9,0,0,0,0,  0,0,9,9,9,  9,9,0,9,9},
		{9,9,9,9,9,  9,0,9,9,9,  9,9,0,9,9},
		{9,9,9,9,9,  9,0,9,9,9,  9,9,0,9,9},
		{9,9,9,9,9,  0,0,9,0,0,  0,0,0,9,9},

		{9,9,0,0,0,  0,4,9,0,9,  9,9,9,9,9},// 11行
		{9,9,0,9,9,  9,9,9,0,9,  9,9,9,9,9},
		{9,9,0,9,9,  9,9,9,0,0,  0,0,0,0,9},
		{9,4,0,0,0,  8,9,9,4,9,  9,0,0,0,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},
	};
	// ステージ17
	// 4:弾発射開始位置
	// 5:膨らんだら即死判定
	// 6:即死判定
	// 7:数フレーム後に針が出てゲームオーバーになる判定
	// 8:ゴール
	// 9:壁
	constexpr int stage17[kVariable::StageWidth][kVariable::StageWidth] = {
		// 1行		 6行		 11行
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},// 1行
		{9,9,0,0,0,  0,0,4,7,9,  0,0,0,0,9},
		{9,7,0,9,9,  9,0,0,0,9,  0,0,0,0,9},
		{9,0,0,0,0,  0,9,9,0,9,  9,9,9,0,9},
		{9,0,7,0,5,  0,9,7,0,0,  0,0,0,0,9},

		{9,0,9,0,0,  0,9,9,9,9,  0,5,0,7,9},// 6行
		{9,0,9,0,9,  0,0,0,0,0,  0,0,0,0,9},
		{9,0,0,0,4,  6,9,9,9,9,  9,9,9,0,9},
		{9,9,9,0,0,  0,0,0,0,0,  0,0,0,0,9},
		{9,9,4,9,9,  9,9,9,9,9,  9,9,9,0,9},

		{9,9,0,0,0,  0,0,7,4,0,  0,0,9,0,9},// 11行
		{9,9,0,0,0,  9,0,9,9,0,  9,0,9,0,9},
		{9,9,0,5,0,  9,0,0,0,0,  9,0,9,0,9},
		{9,8,0,0,0,  9,9,9,9,7,  9,0,0,0,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},
	};
	// ステージ18
	// 4:弾発射開始位置
	// 5:膨らんだら即死判定
	// 6:即死判定
	// 7:数フレーム後に針が出てゲームオーバーになる判定
	// 8:ゴール
	// 9:壁
	constexpr int stage18[kVariable::StageWidth][kVariable::StageWidth] = {
		// 1行		 6行		 11行
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},// 1行
		{9,0,0,0,4,  7,0,0,0,6,  7,0,0,0,9},
		{9,0,5,0,0,  0,0,9,0,0,  0,0,9,0,9},
		{9,0,0,0,0,  0,0,9,9,9,  9,9,9,0,9},
		{9,0,0,4,7,  0,0,9,4,0,  0,0,0,0,9},

		{9,0,0,9,9,  6,7,9,9,0,  0,0,0,4,9},// 6行
		{9,7,0,9,9,  9,9,0,0,0,  9,9,9,9,9},
		{9,0,0,0,6,  9,9,0,5,0,  0,0,0,0,9},
		{9,0,5,0,4,  9,9,0,0,0,  9,0,0,0,9},
		{9,0,0,0,0,  0,9,9,9,9,  9,9,9,9,9},

		{9,9,9,9,9,  0,0,0,0,0,  0,0,0,7,9},// 11行
		{9,9,9,9,7,  9,0,5,0,9,  9,9,0,9,9},
		{9,7,0,0,0,  9,0,0,0,0,  9,9,0,9,9},
		{9,9,8,9,0,  0,0,0,4,0,  0,0,0,9,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},
	};
	// ステージ19
	// 4:弾発射開始位置
	// 5:膨らんだら即死判定
	// 6:即死判定
	// 7:数フレーム後に針が出てゲームオーバーになる判定
	// 8:ゴール
	// 9:壁
	constexpr int stage19[kVariable::StageWidth][kVariable::StageWidth] = {
		// 1行		 6行		 11行
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},// 1行
		{9,7,0,0,0,  6,6,6,6,6,  0,7,9,9,9},
		{9,9,0,7,0,  0,0,0,0,0,  0,0,0,6,9},
		{9,4,0,9,9,  9,0,0,0,9,  0,7,0,0,9},
		{9,0,0,6,9,  9,0,9,9,9,  4,7,0,0,9},

		{9,0,9,9,0,  0,0,0,0,7,  9,9,0,0,9},// 6行
		{9,0,9,9,0,  5,0,9,0,0,  0,0,0,7,9},
		{9,0,9,9,0,  0,0,9,7,0,  0,4,9,7,9},
		{9,0,9,9,9,  9,9,6,7,0,  0,0,8,0,9},
		{9,0,0,7,0,  0,0,0,0,0,  5,0,0,0,9},

		{9,9,0,0,0,  9,0,5,0,0,  0,0,0,0,9},// 11行
		{9,0,0,0,6,  0,0,0,0,0,  0,0,7,0,9},
		{9,0,5,0,7,  0,0,0,0,0,  7,0,0,0,9},
		{9,0,0,0,9,  9,0,0,0,9,  9,9,0,4,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},
	};
	// ステージ20
	// 4:弾発射開始位置
	// 5:膨らんだら即死判定
	// 6:即死判定
	// 7:数フレーム後に針が出てゲームオーバーになる判定
	// 8:ゴール
	// 9:壁
	constexpr int stage20[kVariable::StageWidth][kVariable::StageWidth] = {
		// 1行		 6行		 11行
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},// 1行
		{9,0,0,7,0,  0,0,8,7,7,  0,0,0,0,9},
		{9,0,0,0,0,  5,0,6,0,0,  0,0,0,0,9},
		{9,0,0,0,0,  0,0,0,0,0,  0,0,5,0,9},
		{9,0,0,0,7,  0,0,0,0,0,  9,0,0,0,9},

		{9,4,9,0,0,  4,0,9,0,0,  0,0,0,0,9},// 6行
		{9,9,0,0,0,  0,0,0,9,0,  0,0,5,0,9},
		{9,0,0,0,0,  0,7,0,0,4,  0,0,0,0,9},
		{9,0,6,7,0,  0,0,9,0,0,  9,4,0,0,9},
		{9,0,0,0,0,  0,0,0,7,0,  0,0,0,9,9},

		{9,7,0,0,0,  0,0,0,0,9,  0,5,0,0,9},// 11行
		{9,0,0,0,6,  9,9,9,0,9,  0,0,0,0,9},
		{9,0,5,0,9,  9,0,0,0,9,  0,0,0,0,9},
		{9,0,0,0,9,  9,0,0,0,9,  9,0,7,0,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},
	};
}

// プレイヤー
namespace kPlayer
{
	// プレイヤーの配列
	// 0:無
	// 1:プレイヤー
	constexpr int playr[kVariable::PlayerWidth][kVariable::PlayerWidth] = {
		{0,0,0},
		{0,1,0},
		{0,0,0},
	};
}

// ショットの配列


// 色
namespace kColor
{
	const int Black = GetColor(0, 0, 0);			// 黒
	const int Red = GetColor(255, 0, 0);			// 赤
	const int Peach = GetColor(255, 0, 255);		// 桃
	const int Green = GetColor(0, 255, 0);			// 緑
	const int Blue = GetColor(0, 0, 255);			// 青
	const int LightBlue = GetColor(0, 255, 255);	// 水
	const int Yellow = GetColor(255, 255, 0);		// 黄
	const int YellowGreen = GetColor(154, 205, 50);	// 黄緑
	const int White = GetColor(255, 255, 255);		// 白
}