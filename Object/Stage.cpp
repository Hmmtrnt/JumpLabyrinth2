#include "Stage.h"

Stage::Stage() :
	m_gimmickFrame(0),
	m_shrink(0),
	m_inflate(0),
	m_handleWall(-1),
	m_handleTrap(-1),
	m_verXWall(0),
	m_verYWall(0),
	m_verXTrap(0),
	m_verYTrap(0),
	m_verXLagTrap(0),
	m_verYLagTrap(0),
	m_verXFire(0),
	m_verYFire(0),
	m_verXInflate(0),
	m_verYInflate(0),
	m_verXInflate2(0),
	m_verYInflate2(0),
	m_verXGoal(0),
	m_verYGoal(0)
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

	// ステージハンドル
	m_verXWall = 4;
	m_verYWall = 0;
	m_verXTrap = 13;
	m_verYTrap = 13;
	m_verXLagTrap = 0;
	m_verYLagTrap = 0;
	m_verXFire = 1;
	m_verYFire = 0;
	m_verXInflate = 3;
	m_verYInflate = 0;
	m_verXInflate2 = 2;
	m_verYInflate2 = 0;
	m_verXGoal = 1;
	m_verYGoal = 1;

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
				/*DrawBox(x * DRAW_WIDTH, y * DRAW_WIDTH,
						(x * DRAW_WIDTH) + DRAW_WIDTH, 
						(y * DRAW_WIDTH) + DRAW_WIDTH,
						kColor::White, false);*/
				//draw::MyDrawRectRotaGraph()
			}
			if (m_stage[y][x] == 4)
			{
				/*DrawBox(x * DRAW_WIDTH, y * DRAW_WIDTH,
					(x * DRAW_WIDTH) + DRAW_WIDTH,
					(y * DRAW_WIDTH) + DRAW_WIDTH,
					kColor::YellowGreen, true);*/

				draw::MyDrawRectRotaGraph((x * DRAW_WIDTH) + (DRAW_WIDTH / 2), (y * DRAW_WIDTH) + (DRAW_WIDTH / 2),
					m_verXFire * 32, m_verYFire * 32,
					32, 32,
					1.3f, 0.0f,
					m_handleWall, true, false);

			}
			if (m_stage[y][x] == 5)
			{
				if (m_gimmickFrame < m_shrink)
				{
					/*DrawBox(x * DRAW_WIDTH, y * DRAW_WIDTH,
						(x * DRAW_WIDTH) + DRAW_WIDTH,
						(y * DRAW_WIDTH) + DRAW_WIDTH,
						kColor::Yellow, true);*/

					draw::MyDrawRectRotaGraph((x * DRAW_WIDTH) + (DRAW_WIDTH / 2), (y * DRAW_WIDTH) + (DRAW_WIDTH / 2),
											   m_verXInflate * 32, m_verYInflate * 32,
											   32, 32,
											   1.3f, 0.0f,
											   m_handleWall, true, false);

				}
				if (m_gimmickFrame > m_inflate)
				{
					/*DrawBox(x * DRAW_WIDTH - 40, y * DRAW_WIDTH - 40,
						(x * DRAW_WIDTH) + DRAW_WIDTH + 40,
						(y * DRAW_WIDTH) + DRAW_WIDTH + 40,
						kColor::Yellow, true);*/

					draw::MyDrawRectRotaGraph((x * DRAW_WIDTH) + (DRAW_WIDTH / 2), (y * DRAW_WIDTH) + (DRAW_WIDTH / 2),
											  m_verXInflate2 * 32, m_verYInflate2 * 32,
											  32, 32,
											  3.7f, 0.0f,
											  m_handleWall, true, false);

				}
			}
			if (m_stage[y][x] == 6)
			{
				/*DrawBox(x * DRAW_WIDTH, y * DRAW_WIDTH,
					(x * DRAW_WIDTH) + DRAW_WIDTH,
					(y * DRAW_WIDTH) + DRAW_WIDTH,
					kColor::Red, true);*/

				draw::MyDrawRectRotaGraph((x * DRAW_WIDTH) + (DRAW_WIDTH / 2), (y * DRAW_WIDTH) + (DRAW_WIDTH / 2),
					m_verXTrap * 16, m_verYTrap * 16,
					16, 16,
					2.5f, 0.0f,
					m_handleTrap, true, false);


			}
			if (m_stage[y][x] == 7)
			{
				/*DrawBox(x * DRAW_WIDTH, y * DRAW_WIDTH,
					(x * DRAW_WIDTH) + DRAW_WIDTH,
					(y * DRAW_WIDTH) + DRAW_WIDTH,
					kColor::Blue, true);*/

				draw::MyDrawRectRotaGraph((x * DRAW_WIDTH) + (DRAW_WIDTH / 2), (y * DRAW_WIDTH) + (DRAW_WIDTH / 2),
					m_verXLagTrap * 32, m_verYLagTrap * 32,
					32, 32,
					1.3f, 0.0f,
					m_handleWall, true, false);
			}
			if (m_stage[y][x] == 8)
			{
				/*DrawBox(x * DRAW_WIDTH, y * DRAW_WIDTH,
					(x * DRAW_WIDTH) + DRAW_WIDTH,
					(y * DRAW_WIDTH) + DRAW_WIDTH,
					kColor::LightBlue, true);*/

				draw::MyDrawRectRotaGraph((x * DRAW_WIDTH) + (DRAW_WIDTH / 2), (y * DRAW_WIDTH) + (DRAW_WIDTH / 2),
										  m_verXGoal * 32, m_verYGoal * 32,
										  32, 32,
										  1.3f, 0.0f,
										  m_handleWall, true, false);

			}
			if (m_stage[y][x] == 9)
			{
				/*DrawBox(x * DRAW_WIDTH, y * DRAW_WIDTH, 
						(x * DRAW_WIDTH) + DRAW_WIDTH, 
						(y * DRAW_WIDTH) + DRAW_WIDTH, 
						kColor::White, true);*/

				draw::MyDrawRectRotaGraph((x * DRAW_WIDTH) + (DRAW_WIDTH / 2), (y * DRAW_WIDTH) + (DRAW_WIDTH / 2),
					m_verXWall * 32, m_verYWall * 32,
					32, 32,
					1.3f, 0.0f,
					m_handleWall, true, false);

			}
		}
	}
	// 変数確認用描画
	DrawFormatString(600, 200, kColor::Red, "m_gimmickFrame:%d", m_gimmickFrame);
	//DrawFormatString(600, 250, kColor::Red, "m_inflate:%d", m_inflate);

}
