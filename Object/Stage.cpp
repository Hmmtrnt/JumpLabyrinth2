#include "Stage.h"

Stage::Stage() :
	m_gimmickFrame(0),
	m_shrink(0),
	m_inflate(0),
	m_handle(0)
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
	m_handle = draw::MyLoadGraph("data/industrial.v2.png");
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
	DeleteGraph(m_handle);
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
				DrawBox(x * DRAW_WIDTH, y * DRAW_WIDTH,
						(x * DRAW_WIDTH) + DRAW_WIDTH, 
						(y * DRAW_WIDTH) + DRAW_WIDTH,
						kColor::White, false);
				draw::MyDrawRectRotaGraph()
			}
			if (m_stage[y][x] == 4)
			{
				DrawBox(x * DRAW_WIDTH, y * DRAW_WIDTH,
					(x * DRAW_WIDTH) + DRAW_WIDTH,
					(y * DRAW_WIDTH) + DRAW_WIDTH,
					kColor::YellowGreen, true);
			}
			if (m_stage[y][x] == 5)
			{
				if (m_gimmickFrame < m_shrink)
				{
					DrawBox(x * DRAW_WIDTH, y * DRAW_WIDTH,
						(x * DRAW_WIDTH) + DRAW_WIDTH,
						(y * DRAW_WIDTH) + DRAW_WIDTH,
						kColor::Yellow, true);
				}
				if (m_gimmickFrame > m_inflate)
				{
					DrawBox(x * DRAW_WIDTH - 40, y * DRAW_WIDTH - 40,
						(x * DRAW_WIDTH) + DRAW_WIDTH + 40,
						(y * DRAW_WIDTH) + DRAW_WIDTH + 40,
						kColor::Yellow, true);
				}
			}
			if (m_stage[y][x] == 6)
			{
				DrawBox(x * DRAW_WIDTH, y * DRAW_WIDTH,
					(x * DRAW_WIDTH) + DRAW_WIDTH,
					(y * DRAW_WIDTH) + DRAW_WIDTH,
					kColor::Red, true);
			}
			if (m_stage[y][x] == 7)
			{
				DrawBox(x * DRAW_WIDTH, y * DRAW_WIDTH,
					(x * DRAW_WIDTH) + DRAW_WIDTH,
					(y * DRAW_WIDTH) + DRAW_WIDTH,
					kColor::Blue, true);
			}
			if (m_stage[y][x] == 8)
			{
				DrawBox(x * DRAW_WIDTH, y * DRAW_WIDTH,
					(x * DRAW_WIDTH) + DRAW_WIDTH,
					(y * DRAW_WIDTH) + DRAW_WIDTH,
					kColor::LightBlue, true);
			}
			if (m_stage[y][x] == 9)
			{
				DrawBox(x * DRAW_WIDTH, y * DRAW_WIDTH, 
						(x * DRAW_WIDTH) + DRAW_WIDTH, 
						(y * DRAW_WIDTH) + DRAW_WIDTH, 
						kColor::White, true);
			}
		}
	}
	// 変数確認用描画
	DrawFormatString(600, 200, kColor::Red, "m_gimmickFrame:%d", m_gimmickFrame);
	//DrawFormatString(600, 250, kColor::Red, "m_inflate:%d", m_inflate);

}
