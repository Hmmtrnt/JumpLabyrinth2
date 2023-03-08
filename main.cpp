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


	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	// ダブルバッファモード
	SetDrawScreen(DX_SCREEN_BACK);

	SceneManager scene;
	scene.init();

	while (ProcessMessage() == 0)
	{
		LONGLONG time = GetNowHiPerformanceCount();
		// 画面のクリア
		ClearDrawScreen();

		scene.update();
		scene.draw();

		//auto drawcall = GetDrawCallCount();// 描画命令数
		//DrawFormatString(10, 30, 0xffffff, "DC=%d", drawcall);

		// 裏画面を表画面を入れ替える
		ScreenFlip();

		// セレクトボタンで終了７
		if (Pad::isTrigger(PAD_INPUT_L)) break;


		// escきーを押したら終了する
		if (CheckHitKey(KEY_INPUT_ESCAPE))	break;
		// fpsを60に固定
		while (GetNowHiPerformanceCount() - time < 16667)
		{
		}
	}

	scene.end();

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}