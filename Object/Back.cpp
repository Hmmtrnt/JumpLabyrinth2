#include "Back.h"

namespace
{
	constexpr float kSize = 3.3f;
	const char* const kGuideOpenText = "Y�{�^��:�M�~�b�N����";
	const char* const kGuideCloseText = "Y�{�^��:����";
	const char* const kExplanText = "�M�~�b�N����";
	const char* const kExplanGimmickDeath = "���̃u���b�N�ɓ������\n����ł��܂��܂�";
	const char* const kExplanGimmickTimeRug = "���̃u���b�N�̍��E�㉺��\n��莞�Ԃ����\n����ł��܂��܂�";
	const char* const kExplanGimmickInflate = "���̃u���b�N�����̂悤��\n�k��ł����\n���n�ł��܂�\n�������A�E�̂悤��\n�c���ł����\n����ł��܂��܂�";
	const char* const kExplanGimmickArrow = "���̃u���b�N����\n���E�㉺�����ꂩ��\n�����ɔ��˂���A\n������Ǝ���ł��܂��܂�";
}

Back::Back() :
	m_handle(-1),
	m_verX(0),
	m_verY(0),
	m_textHandle(0),
	m_gimmickHandle(0),
	m_gimmickHandle2(0)
{
	for (int y = 0; y < kVariable::BackHeight; y++)
	{
		for (int x = 0; x < kVariable::BackWidth; x++)
		{
			m_back[y][x] = 0;
		}
	}
}

Back::~Back()
{
}

// ������
void Back::init()
{
	// �w�i�n���h��
	m_handle = draw::MyLoadGraph("data/tileset/inca_back2.png");
	// �؂��鍶��̒��_
	m_verX = 0;
	m_verY = 0;

	m_textHandle = CreateFontToHandle("Silver", 50, -1, -1);

	m_gimmickHandle = draw::MyLoadGraph("data/tileset/inca_front.png");
	m_gimmickHandle2 = draw::MyLoadGraph("data/Textures-16.png");

	// �w�i�z��̃T�C�Y�擾
	for (int y = 0; y < kVariable::BackHeight; y++)
	{
		for (int x = 0; x < kVariable::BackWidth; x++)
		{
			m_back[y][x] = kBack::backs[y][x];
		}
	}
}

// �I��
void Back::end()
{
	DeleteGraph(m_handle);
	DeleteFontToHandle(m_textHandle);
	DeleteGraph(m_gimmickHandle);
	DeleteGraph(m_gimmickHandle2);
}

// �`��
void Back::draw()
{
	for (int y = 0; y < kVariable::BackHeight; y++)
	{
		for (int x = 0; x < kVariable::BackWidth; x++)
		{
			if (m_back[y][x] == 0)
			{
				m_verX = 4;
				m_verY = 1;
				draw::MyDrawRectRotaGraph((x * kVariable::DrawBackWidth) + (kVariable::DrawBackWidth / 2),
					(y * kVariable::DrawBackWidth) + (kVariable::DrawBackWidth / 2),
					m_verX * 32, m_verY * 32,
					32, 32,
					kSize, 0.0f,
					m_handle, true, false);
			}
			if (m_back[y][x] == 1)
			{
				m_verX = 0;
				m_verY = 1;
				draw::MyDrawRectRotaGraph((x * kVariable::DrawBackWidth) + (kVariable::DrawBackWidth / 2),
					(y * kVariable::DrawBackWidth) + (kVariable::DrawBackWidth / 2),
					m_verX * 32, m_verY * 32,
					32, 32,
					kSize, 0.0f,
					m_handle, true, false);
			}
		}
	}

	DrawFormatStringToHandle(1500, 50, kColor::White, m_textHandle, "START:���j���[���");

}

void Back::drawHelp()
{
	DrawFormatStringToHandle(50, 50, kColor::White, m_textHandle, kGuideOpenText);
}

void Back::drawExplan2_5()
{
	DrawFormatStringToHandle(50,50, kColor::White, m_textHandle, kGuideCloseText);
	DrawFormatStringToHandle(50, 100, kColor::White, m_textHandle, kExplanText);
	draw::MyDrawRectRotaGraph(200, 200, 
		13 * 16, 13 * 16,
		16, 16,
		4.2f, 0.0f, 
		m_gimmickHandle2, true, false);

	DrawFormatStringToHandle(50, 300, 
		kColor::White, m_textHandle, 
		kExplanGimmickDeath);

}

void Back::drawExplan6()
{
	DrawFormatStringToHandle(50, 50, kColor::White, m_textHandle, kGuideCloseText);
	DrawFormatStringToHandle(50, 100, kColor::White, m_textHandle, kExplanText);

	draw::MyDrawRectRotaGraph(200, 200,
		0, 0,
		32, 32,
		2.0f, 0.0f,
		m_gimmickHandle, true, false);

	DrawFormatStringToHandle(50, 300, 
		kColor::White, m_textHandle, 
		kExplanGimmickTimeRug);
}

void Back::drawExplan7_10()
{
	DrawFormatStringToHandle(50, 50, kColor::White, m_textHandle, kGuideCloseText);
	DrawFormatStringToHandle(50, 100, kColor::White, m_textHandle, kExplanText);
	draw::MyDrawRectRotaGraph(200, 200,
		13 * 16, 13 * 16,
		16, 16,
		4.2f, 0.0f,
		m_gimmickHandle2, true, false);

	DrawFormatStringToHandle(50, 300,
		kColor::White, m_textHandle,
		kExplanGimmickDeath);

	draw::MyDrawRectRotaGraph(200, 650,
		0, 0,
		32, 32,
		2.0f, 0.0f,
		m_gimmickHandle, true, false);

	DrawFormatStringToHandle(50, 750,
		kColor::White, m_textHandle,
		kExplanGimmickTimeRug);
}

void Back::drawExplan11()
{
	DrawFormatStringToHandle(50, 50, kColor::White, m_textHandle, kGuideCloseText);
	DrawFormatStringToHandle(50, 100, kColor::White, m_textHandle, kExplanText);
	draw::MyDrawRectRotaGraph(300, 200,
		64, 0,
		32, 32,
		4.0f, 0.0f,
		m_gimmickHandle, true, false);
	draw::MyDrawRectRotaGraph(150, 200,
		96, 0,
		32, 32,
		2.0f, 0.0f,
		m_gimmickHandle, true, false);
	DrawFormatStringToHandle(50, 300,
		kColor::White, m_textHandle,
		kExplanGimmickInflate);
}

void Back::drawExplan12_15()
{
	DrawFormatStringToHandle(50, 50, kColor::White, m_textHandle, kGuideCloseText);
	DrawFormatStringToHandle(50, 100, kColor::White, m_textHandle, kExplanText);
	draw::MyDrawRectRotaGraph(200, 200,
		13 * 16, 13 * 16,
		16, 16,
		4.2f, 0.0f,
		m_gimmickHandle2, true, false);

	DrawFormatStringToHandle(50, 300,
		kColor::White, m_textHandle,
		kExplanGimmickDeath);

	draw::MyDrawRectRotaGraph(200, 650,
		0, 0,
		32, 32,
		2.0f, 0.0f,
		m_gimmickHandle, true, false);

	DrawFormatStringToHandle(50, 750,
		kColor::White, m_textHandle,
		kExplanGimmickTimeRug);

	draw::MyDrawRectRotaGraph(1750, 200,
		64, 0,
		32, 32,
		4.0f, 0.0f,
		m_gimmickHandle, true, false);
	draw::MyDrawRectRotaGraph(1600, 200,
		96, 0,
		32, 32,
		2.0f, 0.0f,
		m_gimmickHandle, true, false);
	DrawFormatStringToHandle(1500, 300,
		kColor::White, m_textHandle,
		kExplanGimmickInflate);
}

void Back::drawExplan16()
{
	DrawFormatStringToHandle(50, 50, kColor::White, m_textHandle, kGuideCloseText);
	DrawFormatStringToHandle(50, 100, kColor::White, m_textHandle, kExplanText);
	draw::MyDrawRectRotaGraph(200, 200,
		32, 0,
		32, 32,
		2.0f, 0.0f,
		m_gimmickHandle, true, false);

	DrawFormatStringToHandle(50, 300,
		kColor::White, m_textHandle,
		kExplanGimmickArrow);
}

void Back::drawExplan17_20()
{
	DrawFormatStringToHandle(50, 50, kColor::White, m_textHandle, kGuideCloseText);
	DrawFormatStringToHandle(50, 100, kColor::White, m_textHandle, kExplanText);
	draw::MyDrawRectRotaGraph(200, 200,
		13 * 16, 13 * 16,
		16, 16,
		4.2f, 0.0f,
		m_gimmickHandle2, true, false);

	DrawFormatStringToHandle(50, 300,
		kColor::White, m_textHandle,
		kExplanGimmickDeath);

	draw::MyDrawRectRotaGraph(200, 650,
		0, 0,
		32, 32,
		2.0f, 0.0f,
		m_gimmickHandle, true, false);

	DrawFormatStringToHandle(50, 750,
		kColor::White, m_textHandle,
		kExplanGimmickTimeRug);

	draw::MyDrawRectRotaGraph(1750, 200,
		64, 0,
		32, 32,
		4.0f, 0.0f,
		m_gimmickHandle, true, false);
	draw::MyDrawRectRotaGraph(1600, 200,
		96, 0,
		32, 32,
		2.0f, 0.0f,
		m_gimmickHandle, true, false);
	DrawFormatStringToHandle(1500, 300,
		kColor::White, m_textHandle,
		kExplanGimmickInflate);

	draw::MyDrawRectRotaGraph(1700, 650,
		32, 0,
		32, 32,
		2.0f, 0.0f,
		m_gimmickHandle, true, false);

	DrawFormatStringToHandle(1500, 750,
		kColor::White, m_textHandle,
		kExplanGimmickArrow);
}
