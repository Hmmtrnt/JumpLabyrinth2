// �摜��ǂݍ���
#pragma once
#include <tchar.h>

// �����p���C�u�����p���O���
namespace draw
{
	/// <summary>
	/// �摜�����[�h����
	/// </summary>
	/// <param name="path">�p�X������</param>
	/// <returns>�摜�̃n���h��</returns>
	int MyLoadGraph(const TCHAR* path);

	int MyDrawRectRotaGraph(int x, int y,					// �\�����W
							int left, int top,				// �؂��荶��
							int width, int height,			// ���A����
							float scale, float angle,		// �g�嗦�A��]�p�x
							int handle, bool transFlg, bool turnFlag);		

	int MyDrawRotaGraph(int x, int y,						// �\�����W
						float ExtRate, float Angle,		// �g�嗦�A��]�p�x
						int GrHandle,						// �O���t�B�b�N�n���h��
						int TransFlag, int TurnFlag);		// �摜�̓����x�A�摜�̍��E���]
}

