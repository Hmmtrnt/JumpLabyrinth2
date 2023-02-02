#include "Back.h"

Back::Back() :
	m_handle(-1),
	m_verX(0),
	m_verY(0)
{
	for (int y = 0; y < BACK_HEIGHT; y++)
	{
		for (int x = 0; x < BACK_WIDTH; x++)
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

	// �w�i�z��̃T�C�Y�擾
	for (int y = 0; y < BACK_HEIGHT; y++)
	{
		for (int x = 0; x < BACK_WIDTH; x++)
		{
			m_back[y][x] = kBack::backs[y][x];
		}
	}
}

// �I��
void Back::end()
{
	DeleteGraph(m_handle);
}

// �`��
void Back::draw()
{
	for (int y = 0; y < BACK_HEIGHT; y++)
	{
		for (int x = 0; x < BACK_WIDTH; x++)
		{
			if (m_back[y][x] == 0)
			{
				m_verX = 4;
				m_verY = 1;
				draw::MyDrawRectRotaGraph((x * DRAW_BACK_WIDTH) + (DRAW_BACK_WIDTH / 2), (y * DRAW_BACK_WIDTH) + (DRAW_BACK_WIDTH / 2),
										  m_verX * 32, m_verY * 32,
										  32, 32,
										  1.0f, 0.0f,
										  m_handle, true, false);
			}
			if (m_back[y][x] == 1)
			{
				m_verX = 0;
				m_verY = 1;
				draw::MyDrawRectRotaGraph((x * DRAW_BACK_WIDTH) + (DRAW_BACK_WIDTH / 2), (y * DRAW_BACK_WIDTH) + (DRAW_BACK_WIDTH / 2),
					m_verX * 32, m_verY * 32,
					32, 32,
					1.0f, 0.0f,
					m_handle, true, false);
			}
		}
	}

}
