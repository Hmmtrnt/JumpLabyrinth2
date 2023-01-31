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

	int MyDrawGraph(int x, int y,							// �`�悷�鍶����W
					int handle, bool TransFlag);			// �O���t�B�b�N�n���h���A�摜�̓����x

	int MyDrawRotaGraph(int x, int y,						// �`�悷�钆�S���W
						float scale, float angle,			// �g�嗦�A��]�p�x
						int handle,							// �O���t�B�b�N�n���h��
						bool transFlag, bool turnFlag);		// �摜�̓����x�A�摜�̍��E���]

	int MyDrawRectRotaGraph(int x, int y,					// �\�����W
							int left, int top,				// �؂��荶��
							int width, int height,			// ���A����
							float scale, float angle,		// �g�嗦�A��]�p�x
							int handle, bool transFlg, bool turnFlag);		

	int MyDerivationGraph(int x, int y,						// ��`�̍�����W
						  int width, int height,			// �����o���O���t�B�b�N�̃T�C�Y
						  int handle);					// �O���t�B�b�N�n���h��
	
	int MyDrawExtendGraph(int x1, int y1,					// ���㒸�_�̍��W
						  int x2, int y2,					// �E��̒��_���W
						  int handle,						// �O���t�B�b�N�n���h��
						  int TransFlag);					// ��ʂ̓����x

}

