#include "DxLib.h"
#include "Scene/SceneManager.h"
#include "Util/game.h"
#include "Util/Pad.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
	// windowモード設定
	ChangeWindowMode(Game::kWindowModo);
	// ウインドウ名設定
	SetMainWindowText(Game::kTitleText);
	// 画面サイズの設定
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);
	// ウインドウモード時大きさ変更可能
	SetWindowSizeChangeEnableFlag(true);


	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	// ダブルバッファモード
	SetDrawScreen(DX_SCREEN_BACK);

	// シーンのポインタ
	SceneManager scene;
	scene.init();// 初期化

	while (ProcessMessage() == 0)
	{
		LONGLONG time = GetNowHiPerformanceCount();
		// 画面のクリア
		ClearDrawScreen();

		scene.update();// 更新
		scene.draw();// 描画

		// 裏画面を表画面を入れ替える
		ScreenFlip();

		// escきーを押したら終了する
		if (CheckHitKey(KEY_INPUT_ESCAPE))	break;
		// fpsを60に固定
		while (GetNowHiPerformanceCount() - time < 16667)
		{
		}
	}

	scene.end();// 終了

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}