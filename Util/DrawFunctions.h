// 画像を読み込む
#pragma once
#include <tchar.h>

// 自分用ライブラリ用名前空間
namespace draw
{
	/// <summary>
	/// 画像をロードする
	/// </summary>
	/// <param name="path">パス文字列</param>
	/// <returns>画像のハンドル</returns>
	int MyLoadGraph(const TCHAR* path);

	int MyDrawGraph(int x, int y,							// 描画する左上座標
					int handle, bool TransFlag);			// グラフィックハンドル、画像の透明度

	int MyDrawRotaGraph(int x, int y,						// 描画する中心座標
						float scale, float angle,			// 拡大率、回転角度
						int handle,							// グラフィックハンドル
						bool transFlag, bool turnFlag);		// 画像の透明度、画像の左右反転

	int MyDrawRectRotaGraph(int x, int y,					// 表示座標
							int left, int top,				// 切り取り左上
							int width, int height,			// 幅、高さ
							float scale, float angle,		// 拡大率、回転角度
							int handle, bool transFlg, bool turnFlag);		

	int MyDerivationGraph(int x, int y,						// 矩形の左上座標
						  int width, int height,			// 抜き出すグラフィックのサイズ
						  int handle);					// グラフィックハンドル
	
	int MyDrawExtendGraph(int x1, int y1,					// 左上頂点の座標
						  int x2, int y2,					// 右上の頂点座標
						  int handle,						// グラフィックハンドル
						  int TransFlag);					// 画面の透明度

}

