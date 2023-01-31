#include "DrawFunctions.h"
#include "DxLib.h"
#include <cassert>

namespace draw
{
	/// <summary>
	/// グラフィックをロードする
	/// </summary>
	/// <param name="path">画像ファイルのパス</param>
	/// <returns>画像のハンドル</returns>
	int MyLoadGraph(const TCHAR* path)
	{
		int handle = LoadGraph(path);
		assert(handle >= 0);
		return handle;
	}
	int MyDrawRectRotaGraph(int x, int y, int left, int top, int width, int height, float scale, float angle, int handle, bool transFlg, bool turnFlag)
	{
		return DrawRectRotaGraph(x, y,					// 表示座標
								 left, top,				// 切り取り左上
								 width, height,			// 幅、高さ
								 scale, angle,			// 拡大率、回転角度
								 handle, transFlg, turnFlag);
	}

	int MyDerivationGraph(int x, int y, int width, int height, int Grhandle)
	{
		return DerivationGraph(x, y,					// 矩形の左上座標
							   width, height,			// 抜き出すグラフィックのサイズ
							   Grhandle);				// グラフィックハンドル
	}

	int MyDrawExtendGraph(int x1, int y1, int x2, int y2, int GrHandle, int TransFlag)
	{
		return DrawExtendGraph(x1, y1,					// 左上頂点の座標
							   x2, y2,					// 右上の頂点座標
							   GrHandle,				// グラフィックハンドル
							   TransFlag);				// 画面の透明度
	}
}