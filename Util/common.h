#pragma once
#include "DxLib.h"

// �v���C���[�̕�
#define PLAYER_HEIGHT 3		// �c
#define PLAYER_WIDTH 3		// ��

// �X�e�[�W�̕�
#define STAGE_HEIGHT 15		// �c
#define STAGE_WIDTH 15		// ��

// �X�e�[�W�̕`�悷�镝
#define DRAW_WIDTH 40

// �`�悷��ʒu�ύX
#define DRAW_POSITION_X 60
#define DRAW_POSITION_Y 50

namespace kStage
{
	// �X�e�[�W�̔z��
	// 0:��
	// 6:��������
	// 7:���t���[����ɐj���o�ăQ�[���I�[�o�[�ɂȂ锻��
	// 8:�S�[��
	// 9:��
	constexpr int stage1[STAGE_HEIGHT][STAGE_WIDTH] = {
		// 1�s       6�s         11�s     
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},// 1�s
		{9,0,0,8,9,  0,0,0,7,9,  0,0,0,0,9},
		{9,0,9,9,9,  0,7,0,9,9,  0,9,9,0,9},
		{9,0,0,7,9,  0,9,0,9,9,  0,9,9,0,9},
		{9,0,0,0,9,  0,9,0,9,9,  0,9,9,0,9},

		{9,9,9,0,9,  0,9,0,0,0,  0,9,9,0,9},// 6�s
		{9,6,0,0,9,  0,9,6,9,9,  9,9,9,0,9},
		{9,6,0,9,9,  0,9,9,9,9,  9,9,0,0,9},
		{9,6,0,9,9,  0,9,9,9,9,  9,9,0,0,9},
		{9,6,0,0,0,  0,9,9,9,9,  9,9,0,9,9},

		{9,9,0,0,0,  0,0,0,0,0,  7,9,0,9,9},// 11�s
		{9,6,0,0,0,  0,9,9,0,0,  9,9,0,0,9},
		{9,6,0,9,9,  0,9,9,0,0,  9,0,0,0,9},
		{9,6,0,0,0,  0,0,0,0,0,  9,0,0,0,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},
	};
}

namespace kPlayer
{
	// �v���C���[�̔z��
	// 0:��
	// 1:�v���C���[
	constexpr int playr[PLAYER_HEIGHT][PLAYER_WIDTH] = {
		{0,0,0},
		{0,1,0},
		{0,0,0},
	};
}

// �F
namespace kColor
{
	const int Black = GetColor(0, 0, 0);			// ��
	const int Red = GetColor(255, 0, 0);			// ��
	const int Blue = GetColor(0, 0, 255);			// ��
	const int White = GetColor(255, 255, 255);		// ��
}