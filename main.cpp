#include "DxLib.h"
#include "Scene/SceneManager.h"
#include "Util/game.h"
#include "Util/Pad.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
	// window���[�h�ݒ�
	ChangeWindowMode(Game::kWindowModo);
	// �E�C���h�E���ݒ�
	SetMainWindowText(Game::kTitleText);
	// ��ʃT�C�Y�̐ݒ�
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);


	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	// �_�u���o�b�t�@���[�h
	SetDrawScreen(DX_SCREEN_BACK);

	SceneManager scene;
	scene.init();

	while (ProcessMessage() == 0)
	{
		LONGLONG time = GetNowHiPerformanceCount();
		// ��ʂ̃N���A
		ClearDrawScreen();

		scene.update();
		scene.draw();

		//auto drawcall = GetDrawCallCount();// �`�施�ߐ�
		//DrawFormatString(10, 30, 0xffffff, "DC=%d", drawcall);

		// ����ʂ�\��ʂ����ւ���
		ScreenFlip();

		// �Z���N�g�{�^���ŏI���V
		if (Pad::isTrigger(PAD_INPUT_L)) break;


		// esc���[����������I������
		if (CheckHitKey(KEY_INPUT_ESCAPE))	break;
		// fps��60�ɌŒ�
		while (GetNowHiPerformanceCount() - time < 16667)
		{
		}
	}

	scene.end();

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}