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

	int MyDerivationGraph(int x, int y,						// ��`�̍�����W
						  int width, int height,			// �����o���O���t�B�b�N�̃T�C�Y
						  int Grhandle);					// �O���t�B�b�N�n���h��
	
	int MyDrawExtendGraph(int x1, int y1,					// ���㒸�_�̍��W
						  int x2, int y2,					// �E��̒��_���W
						  int GrHandle,						// �O���t�B�b�N�n���h��
						  int TransFlag);					// ��ʂ̓����x

}

