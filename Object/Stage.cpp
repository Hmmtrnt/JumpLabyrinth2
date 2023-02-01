#include "Stage.h"

Stage::Stage() :
	m_gimmickFrame(0),
	m_shrink(0),
	m_inflate(0),
	m_handleWall(-1),
	m_handleTrap(-1),
	m_handleSmallNeedle(-1),
	m_verX(0),
	m_verY(0)
{
	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			m_stage[y][x] = 0;
		}
	}
}

Stage::~Stage()
{
}

void Stage::init()
{
	m_gimmickFrame = 0;
	m_shrink = 60;
	m_inflate = 60;
	m_handleWall = draw::MyLoadGraph("data/tileset/inca_front.png");
	m_handleTrap = draw::MyLoadGraph("data/Textures-16.png");
	m_handleSmallNeedle = draw::MyLoadGraph("data/smallneedle.png");

	// ステージハンドル
	m_verX = 0;
	m_verY = 0;

	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			m_stage[y][x] = kStage::stageP[y][x];
		}
	}
}

void Stage::end()
{
	DeleteGraph(m_handleWall);
}

void Stage::update()
{
	// ギミックの描画変更処理
	m_gimmickFrame++;
	if (m_gimmickFrame >= m_shrink + m_inflate)
	{
		m_gimmickFrame = 0;
	}
}

void Stage::draw()
{
	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			if (m_stage[y][x] == 0)
			{
			}
			if (m_stage[y][x] == 4)
			{
				m_verX = 1;
				m_verY = 0;
				draw::MyDrawRectRotaGraph((x * DRAW_WIDTH) + (DRAW_WIDTH / 2), (y * DRAW_WIDTH) + (DRAW_WIDTH / 2),
										  m_verX * 32, m_verY * 32,
										  32, 32,
										  1.3f, 0.0f,
										  m_handleWall, true, false);

			}
			if (m_stage[y][x] == 5)
			{
				if (m_gimmickFrame < m_shrink)
				{
					m_verX = 3;
					m_verY = 0;
					draw::MyDrawRectRotaGraph((x * DRAW_WIDTH) + (DRAW_WIDTH / 2), (y * DRAW_WIDTH) + (DRAW_WIDTH / 2),
											  m_verX * 32, m_verY * 32,
											  32, 32,
											  1.3f, 0.0f,
											  m_handleWall, true, false);

				}
				if (m_gimmickFrame > m_inflate)
				{
					m_verX = 2;
					m_verY = 0;
					draw::MyDrawRectRotaGraph((x * DRAW_WIDTH) + (DRAW_WIDTH / 2), (y * DRAW_WIDTH) + (DRAW_WIDTH / 2),
											  m_verX * 32, m_verY * 32,
											  32, 32,
											  3.6f, 0.0f,
											  m_handleWall, true, false);

				}
			}
			if (m_stage[y][x] == 6)
			{
				m_verX = 13;
				m_verY = 13;
				draw::MyDrawRectRotaGraph((x * DRAW_WIDTH) + (DRAW_WIDTH / 2), (y * DRAW_WIDTH) + (DRAW_WIDTH / 2),
										  m_verX * 16, m_verY * 16,
										  16, 16,
										  2.5f, 0.0f,
										  m_handleTrap, true, false);


			}
			if (m_stage[y][x] == 7)
			{
				m_verX = 0;
				m_verY = 0;
				draw::MyDrawRectRotaGraph((x * DRAW_WIDTH) + (DRAW_WIDTH / 2), (y * DRAW_WIDTH) + (DRAW_WIDTH / 2),
										  m_verX * 32, m_verY * 32,
										  32, 32,
										  1.3f, 0.0f,
										  m_handleWall, true, false);
				// 右
				if (m_stage[y][x + 1] != 7)
				{
					draw::MyDrawRectRotaGraph(((x + 1) * DRAW_WIDTH) + (DRAW_WIDTH / 2), (y * DRAW_WIDTH) + (DRAW_WIDTH / 2),
						0, 0,
						40, 40,
						1.0f, PI/-2,
						m_handleSmallNeedle, true, false);
				}
				// 左
				if (m_stage[y][x - 1] != 7)
				{
					draw::MyDrawRectRotaGraph(((x - 1) * DRAW_WIDTH) + (DRAW_WIDTH / 2), (y * DRAW_WIDTH) + (DRAW_WIDTH / 2),
						0, 0,
						40, 40,
						1.0f, PI/2,
						m_handleSmallNeedle, true, false);
				}
				// 上
				if (m_stage[y + 1][x] != 7)
				{
					draw::MyDrawRectRotaGraph((x * DRAW_WIDTH) + (DRAW_WIDTH / 2), (y * DRAW_WIDTH) + (DRAW_WIDTH / 2),
						0, 0,
						40, 40,
						1.0f, PI/1,
						m_handleSmallNeedle, true, false);
				}
				// 下
				draw::MyDrawRectRotaGraph((x * DRAW_WIDTH) + (DRAW_WIDTH / 2), (y * DRAW_WIDTH) + (DRAW_WIDTH / 2),
					0, 0,
					40, 40,
					1.0f, 0.0f,
					m_handleSmallNeedle, true, false);
			}
			if (m_stage[y][x] == 8)
			{
				m_verX = 1;
				m_verY = 1;
				draw::MyDrawRectRotaGraph((x * DRAW_WIDTH) + (DRAW_WIDTH / 2), (y * DRAW_WIDTH) + (DRAW_WIDTH / 2),
										  m_verX * 32, m_verY * 32,
										  32, 32,
										  1.3f, 0.0f,
										  m_handleWall, true, false);

			}
			if (m_stage[y][x] == 9)
			{
				m_verX = 4;
				m_verY = 0;
				draw::MyDrawRectRotaGraph((x * DRAW_WIDTH) + (DRAW_WIDTH / 2), (y * DRAW_WIDTH) + (DRAW_WIDTH / 2),
					m_verX * 32, m_verY * 32,
					32, 32,
					1.3f, 0.0f,
					m_handleWall, true, false);

			}
		}
	}
	// 変数確認用描画
	//DrawFormatString(600, 200, kColor::Red, "m_gimmickFrame:%d", m_gimmickFrame);
	//DrawFormatString(600, 250, kColor::Red, "m_inflate:%d", m_inflate);
}
