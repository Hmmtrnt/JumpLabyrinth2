#include "DrawFunctions.h"
#include "DxLib.h"
#include <cassert>

namespace draw
{
	/// <summary>
	/// �O���t�B�b�N�����[�h����
	/// </summary>
	/// <param name="path">�摜�t�@�C���̃p�X</param>
	/// <returns>�摜�̃n���h��</returns>
	int MyLoadGraph(const TCHAR* path)
	{
		int handle = LoadGraph(path);
		assert(handle >= 0);
		return handle;
	}
	int MyDrawRectRotaGraph(int x, int y, int left, int top, int width, int height, float scale, float angle, int handle, bool transFlg)
	{
		return DrawRectRotaGraph(x, y,					// �\�����W
								 left, top,				// �؂��荶��
								 width, height,			// ���A����
								 scale, angle,			// �g�嗦�A��]�p�x
								 handle, transFlg);
	}
	int MyDrawRotaGraph(int x, int y, float ExtRate, float Angle, int GrHandle, int TransFlag, int TurnFlag)
	{
		return DrawRotaGraph(x, y, ExtRate, Angle, GrHandle, TransFlag, TurnFlag);
	}
}