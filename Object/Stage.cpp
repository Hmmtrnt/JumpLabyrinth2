#include "Stage.h"

Stage::Stage()
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
	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			m_stage[y][x] = kStage::stage[y][x];
		}
	}
}

void Stage::end()
{
}

void Stage::update()
{
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
						GetColor(255, 255, 255), false);
			}
			if (m_stage[y][x] == 8)
			{
				DrawBox(x * DRAW_WIDTH, y * DRAW_WIDTH,
					(x * DRAW_WIDTH) + DRAW_WIDTH,
					(y * DRAW_WIDTH) + DRAW_WIDTH,
					GetColor(0, 255, 255), true);
			}
			if (m_stage[y][x] == 9)
			{
				DrawBox(x * DRAW_WIDTH, y * DRAW_WIDTH, 
						(x * DRAW_WIDTH) + DRAW_WIDTH, 
						(y * DRAW_WIDTH) + DRAW_WIDTH, 
						GetColor(255, 255, 255), true);
			}
		}
	}
}
