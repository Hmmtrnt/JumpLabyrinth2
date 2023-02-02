#include "GameManager.h"
#include "../Object/Player.h"
#include "../Object/Shot.h"
#include "../Object/Stage.h"
#include "../Object/Back.h"
#include "DrawFunctions.h"

GameManager::GameManager() :
	m_gimmickFrame(0),
	m_shrink(0),
	m_inflate(0),
	m_GameOverCount(0),
	GameOver(0),
	GameClear(0),
	m_frameCountGameOver(0),
	m_handleNeedle(-1),
	m_rota(0.0f),
	colNextFlag(0),
	colFlagL(0),
	colFlagR(0),
	colFlagUp(0),
	colFlagBottom(0),
	colL(0),
	colR(0),
	colUp(0),
	colBottom(0),
	colNL(0),
	colNR(0),
	colNUp(0),
	colNBottom(0)

{
	m_pPlayer = new Player;
	m_pShot = new Shot;
	m_pStage = new Stage;
	m_pBack = new Back;
}

GameManager::~GameManager()
{
	delete m_pPlayer;
	delete m_pShot;
	delete m_pStage;
	delete m_pBack;
}

void GameManager::initCommon()
{
	m_gimmickFrame = 0;
	m_shrink = 60;
	m_inflate = 60;
	m_GameOverCount = 30;
	GameOver = false;
	GameClear = false;
	m_frameCountGameOver = 30;
	m_handleNeedle = draw::MyLoadGraph("data/needle2.png");
	colFlagL = false;
	colFlagR = false;
	colFlagUp = false;
	colFlagBottom = false;
	colL = false;
	colR = false;
	colUp = false;
	colBottom = false;
	colNL = false;
	colNR = false;
	colNUp = false;
	colNBottom = false;
}

void GameManager::initP()
{
	initCommon();
	m_pPlayer->initP();
	m_pShot->init();
	m_pStage->initP();
	m_pBack->init();
}

void GameManager::init1()
{
	initCommon();
	m_pPlayer->init1();
	m_pStage->init1();
	m_pBack->init();
}

void GameManager::init2()
{
	initCommon();
	m_pPlayer->init2();
	m_pStage->init2();
	m_pBack->init();
}

void GameManager::end()
{
	m_pPlayer->end();
	m_pShot->end();
	m_pStage->end();
	m_pBack->end();
}

void GameManager::update()
{
	collision();
	colEnemy();
	
	if (colFlagL || colFlagR || colFlagUp || colFlagBottom)
	{
		m_GameOverCount--;
		if (m_GameOverCount <= 0)
		{
			m_GameOverCount = 0;
			if (m_GameOverCount == 0)
			{
				GameOver = true;
			}
		}
	}
	if (!colFlagL && !colFlagR && !colFlagUp && !colFlagBottom)
	{
		m_GameOverCount = 30;
	}

	if (!GameOver)
	{
		m_pPlayer->operation(colL, colR, colUp, colBottom);
	}
	else if (GameOver)
	{
		GameOverMotion();
		m_pPlayer->m_speedX = 0;
		m_pPlayer->m_speedY = 0;
	}

	if (GameClear)
	{
		m_pPlayer->m_speedX = 0;
		m_pPlayer->m_speedY = 0;
	}
	
	m_pPlayer->update();
	m_pShot->update();
	m_pShot->moveWidth(colNL, colNR);
	//m_pShot->moveHeight(colNUp, colNBottom);
	m_pStage->update();
}

void GameManager::updateNoShot()
{
	collisionNoShot();
	colEnemy();

	if (colFlagL || colFlagR || colFlagUp || colFlagBottom)
	{
		m_GameOverCount--;
		if (m_GameOverCount <= 0)
		{
			m_GameOverCount = 0;
			if (m_GameOverCount == 0)
			{
				GameOver = true;
			}
		}
	}
	if (!colFlagL && !colFlagR && !colFlagUp && !colFlagBottom)
	{
		m_GameOverCount = 30;
	}

	if (!GameOver)
	{
		m_pPlayer->operation(colL, colR, colUp, colBottom);
	}
	else if (GameOver)
	{
		GameOverMotion();
		m_pPlayer->m_speedX = 0;
		m_pPlayer->m_speedY = 0;
	}

	if (GameClear)
	{
		m_pPlayer->m_speedX = 0;
		m_pPlayer->m_speedY = 0;
	}

	m_pPlayer->update();
	m_pStage->update();
}

void GameManager::draw()
{
	m_pBack->draw();
	m_pShot->draw();
	m_pStage->draw();
	drawNeedle();
	m_pPlayer->draw();
}

void GameManager::collision()
{
	collisionR();
	collisionL();
	collisionUP();
	collisionBottom();
	collisionEnemy();
	collisionGameOver();
	collisionGameClear();
}

void GameManager::collisionNoShot()
{
	collisionR();
	collisionL();
	collisionUP();
	collisionBottom();
	collisionGameOver();
	collisionGameClear();
}

// ----------------------------------------------
// 当たり判定
// ----------------------------------------------

// **********************************************
// プレイヤー
// **********************************************

// 右
void GameManager::collisionR()
{
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_pPlayer->m_player[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x + 1)] == 8)
				{
					colR = false;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x + 1)] == 6)
				{
					colR = false;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x + 1)] != 0)
				{
					colR = true;
				}
				else
				{
					colR = false;
				}
			}
		}
	}
}

// 左
void GameManager::collisionL()
{
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_pPlayer->m_player[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x - 1)] == 8)
				{
					colL = false;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x - 1)] == 6)
				{
					colL = false;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x - 1)] != 0)
				{
					colL = true; 
				}
				else
				{
					colL = false;
				}
			}
		}
	}
}

// 上
void GameManager::collisionUP()
{
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_pPlayer->m_player[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + x] == 8)
				{
					colUp = false;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + x] == 6)
				{
					colUp = false;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + x] != 0)
				{
					colUp = true; 
				}
				else
				{
					colUp = false;
				}
			}
		}
	}
}

// 下
void GameManager::collisionBottom()
{
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_pPlayer->m_player[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pPlayer->m_posY + (y + 1)][m_pPlayer->m_posX + x] == 8)
				{
					colBottom = false;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + (y + 1)][m_pPlayer->m_posX + x] == 6)
				{
					colBottom = false;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + (y + 1)][m_pPlayer->m_posX + x] != 0)
				{
					colBottom = true;
				}
				else
				{
					colBottom = false;
				}
			}
		}
	}
}

// ギミック5:膨らんだら即死判定
void GameManager::collisionBulge()
{
	EnemyElasticity();
	if (m_gimmickFrame > m_inflate)
	{
		for (int y = 0; y < PLAYER_HEIGHT; y++)
		{
			for (int x = 0; x < PLAYER_WIDTH; x++)
			{
				if (m_pPlayer->m_player[y][x] != 0)
				{
					// 右
					if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x + 1)] == 5)
					{
						GameOver = true;
					}
					// 左
					if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x - 1)] == 5)
					{
						GameOver = true;
					}
					// 上
					if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + x] == 5)
					{
						GameOver = true;
					}
					// 下
					if (m_pStage->m_stage[m_pPlayer->m_posY + (y + 1)][m_pPlayer->m_posX + x] == 5)
					{
						GameOver = true;
					}
					// 右上
					if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + (x + 1)] == 5)
					{
						GameOver = true;
					}
					// 左上
					if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + (x - 1)] == 5)
					{
						GameOver = true;
					}
					// 右下
					if (m_pStage->m_stage[m_pPlayer->m_posY + (y + 1)][m_pPlayer->m_posX + (x + 1)] == 5)
					{
						GameOver = true;
					}
					// 左下
					if (m_pStage->m_stage[m_pPlayer->m_posY + (y + 1)][m_pPlayer->m_posX + (x - 1)] == 5)
					{
						GameOver = true;
					}
				}
			}
		}
		//printfDx("当たり判定有り\n");
	}
}

// ギミック7:数フレーム後に針が出てゲームオーバーになる判定
void GameManager::collisionTimeLag()
{
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_pPlayer->m_player[y][x] != 0)
			{
				// 右
				if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x + 1)] == 7)
				{
					colFlagR = true;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x + 1)] != 7)
				{
					colFlagR = false;
				}
				// 左
				if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x - 1)] == 7)
				{
					colFlagL = true;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x - 1)] != 7)
				{
					colFlagL = false;
				}
				// 上
				if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + x] == 7)
				{
					colFlagUp = true;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + x] != 7)
				{
					colFlagUp = false;
				}
				// 下
				if (m_pStage->m_stage[m_pPlayer->m_posY + (y + 1)][m_pPlayer->m_posX + x] == 7)
				{
					colFlagBottom = true;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + (y + 1)][m_pPlayer->m_posX + x] != 7)
				{
					colFlagBottom = false;
				}
			}
		}
	}
}

// 敵
void GameManager::collisionEnemy()
{
	if (m_pPlayer->m_posX == m_pShot->m_posX && m_pPlayer->m_posY == m_pShot->m_posY)
	{
		GameOver = true;
	}

}

// ギミック6:即死判定
void GameManager::collisionGameOver()
{
	collisionBulge();
	collisionTimeLag();
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_pPlayer->m_player[y][x] != 0)
			{
				// ギミック6:即死判定
				if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + x] == 6)
				{
					GameOver = true;
				}
			}
		}
	}
}

// ゲームクリア
void GameManager::collisionGameClear()
{
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_pPlayer->m_player[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + x] == 8)
				{
					GameClear = true;
				}
			}
		}
	}
}

// **********************************************
// エネミー
// **********************************************
// 全体
void GameManager::colEnemy()
{
	colEnemyR();
	colEnemyL();
	//colEnemyUP();
	//colEnemyBottom();
}

// 右
void GameManager::colEnemyR()
{
	for (int y = 0; y < SHOT_HEIGHT; y++)
	{
		for (int x = 0; x < SHOT_WIDTH; x++)
		{
			if (m_pShot->m_enemy[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pShot->m_posY + y][m_pShot->m_posX + (x + 1)] != 0)
				{
					m_pShot->m_frameX = -40;
					colNR = true;
				}
				else
				{
					colNR = false;
				}
			}
		}
	}
}

// 左
void GameManager::colEnemyL()
{
	for (int y = 0; y < SHOT_HEIGHT; y++)
	{
		for (int x = 0; x < SHOT_WIDTH; x++)
		{
			if (m_pShot->m_enemy[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pShot->m_posY + y][m_pShot->m_posX + (x - 1)] != 0)
				{
					colNL = true;
				}
				else
				{
					colNL = false;
				}
			}
		}
	}
}

// 上
void GameManager::colEnemyUP()
{
	for (int y = 0; y < SHOT_HEIGHT; y++)
	{
		for (int x = 0; x < SHOT_WIDTH; x++)
		{
			if (m_pShot->m_enemy[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pShot->m_posY + (y - 1)][m_pShot->m_posX + x] != 0)
				{
					m_pShot->m_frameY = 560;
					colNUp = true;
				}
				else
				{
					colNUp = false;
				}
			}
		}
	}
}

// 下
void GameManager::colEnemyBottom()
{
	for (int y = 0; y < SHOT_HEIGHT; y++)
	{
		for (int x = 0; x < SHOT_WIDTH; x++)
		{
			if (m_pShot->m_enemy[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pShot->m_posY + (y + 1)][m_pShot->m_posX + x] != 0)
				{
					colNBottom = true;
				}
				else
				{
					colNBottom = false;
				}
			}
		}
	}
}

// 針の描画
void GameManager::drawNeedle()
{
	if (colFlagR)
	{
		m_rota = PI / -2;
	}
	else if (colFlagL)
	{
		m_rota = PI / 2;
	}
	else if (colFlagUp)
	{
		m_rota = PI / 1;
	}
	else if (colFlagBottom)
	{
		m_rota = 0.0f;
	}

	if (m_GameOverCount == 0)
	{
		for (int y = 0; y < PLAYER_HEIGHT; y++)
		{
			for (int x = 0; x < PLAYER_WIDTH; x++)
			{
				if (m_pPlayer->m_player[y][x] == 1)
				{
					draw::MyDrawRectRotaGraph((m_pPlayer->m_frameX + (x * DRAW_WIDTH)) + (DRAW_WIDTH / 2), (m_pPlayer->m_frameY + (y * DRAW_WIDTH)) + (DRAW_WIDTH / 2),
											  0, 0,
											  40, 40,
											  1.0f, m_rota,
											  m_handleNeedle, true, false);
				}
			}
		}
	}
}

void GameManager::GameOverMotion()
{
	m_frameCountGameOver--;
	m_pPlayer->m_verXPlayer = 1;
	m_pPlayer->m_verYPlayer = 6;
	
	if (m_frameCountGameOver <= 0)
	{
		m_frameCountGameOver = 0;
		m_pPlayer->m_verXPlayer = 2;
		m_pPlayer->m_verYPlayer = 6;
	}
}

void GameManager::EnemyElasticity()
{
	// ギミックの当たり判定変更処理
	m_gimmickFrame++;
	if (m_gimmickFrame >= m_shrink + m_inflate)
	{
		m_gimmickFrame = 0;
	}
}
