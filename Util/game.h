#pragma once

namespace Game
{
#ifdef _DEBUG
	// ウインドウモード設定
	constexpr bool kWindowModo = true;
#else
	constexpr bool kWindowModo = false;
#endif
	// ウインドウ名
	const char* const kTitleText = "Jump Labyrinth";
	// ウインドウサイズ
	constexpr int kScreenWidth = 1920;
	constexpr int kScreenHeight = 1080;

	// カラーモード
	constexpr int kColorDepth = 32;		// 32 or 16
};