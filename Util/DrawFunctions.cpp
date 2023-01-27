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
	int MyDrawRectRotaGraph(int x, int y, int left, int top, int width, int height, float scale, float angle, int handle, bool transFlg)
	{
		return DrawRectRotaGraph(x, y,					// 表示座標
								 left, top,				// 切り取り左上
								 width, height,			// 幅、高さ
								 scale, angle,			// 拡大率、回転角度
								 handle, transFlg);
	}
	int MyDrawRotaGraph(int x, int y, float ExtRate, float Angle, int GrHandle, int TransFlag, int TurnFlag)
	{
		return DrawRotaGraph(x, y, ExtRate, Angle, GrHandle, TransFlag, TurnFlag);
	}
}