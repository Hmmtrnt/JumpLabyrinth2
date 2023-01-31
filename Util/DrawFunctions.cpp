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
	int MyDrawRectRotaGraph(int x, int y, int left, int top, int width, int height, float scale, float angle, int handle, bool transFlg, bool turnFlag)
	{
		return DrawRectRotaGraph(x, y,					// �\�����W
								 left, top,				// �؂��荶��
								 width, height,			// ���A����
								 scale, angle,			// �g�嗦�A��]�p�x
								 handle, transFlg, turnFlag);
	}

	int MyDerivationGraph(int x, int y, int width, int height, int Grhandle)
	{
		return DerivationGraph(x, y,					// ��`�̍�����W
							   width, height,			// �����o���O���t�B�b�N�̃T�C�Y
							   Grhandle);				// �O���t�B�b�N�n���h��
	}

	int MyDrawExtendGraph(int x1, int y1, int x2, int y2, int GrHandle, int TransFlag)
	{
		return DrawExtendGraph(x1, y1,					// ���㒸�_�̍��W
							   x2, y2,					// �E��̒��_���W
							   GrHandle,				// �O���t�B�b�N�n���h��
							   TransFlag);				// ��ʂ̓����x
	}
}