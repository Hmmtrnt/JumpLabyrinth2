#pragma once

namespace Game
{
#ifdef _DEBUG
	// �E�C���h�E���[�h�ݒ�
	constexpr bool kWindowModo = true;
#else
	constexpr bool kWindowModo = false;
#endif
	// �E�C���h�E��
	const char* const kTitleText = "Jump Labyrinth";
	// �E�C���h�E�T�C�Y
	constexpr int kScreenWidth = 1920;
	constexpr int kScreenHeight = 1080;

	// �J���[���[�h
	constexpr int kColorDepth = 32;		// 32 or 16
};