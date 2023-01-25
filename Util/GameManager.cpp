#include "GameManager.h"
#include "../Object/Player.h"
#include "../Object/Stage.h"

GameManager::GameManager() :
	m_GameOverCount(0),
	GameOver(0),
	GameClear(0),
	colNextFlag(0),
	colFlagL(0),
	colFlagR(0),
	colFlagUp(0),
	colFlagDown(0),
	colL(0),
	colR(0),
	colUp(0),
	colDown(0)
{
	m_pPlayer = new Player;
	m_pStage = new Stage;
}

GameManager::~GameManager()
{
	delete m_pPlayer;
	delete m_pStage;
}

void GameManager::init()
{
	m_GameOverCount = 30;
	GameOver = false;
	GameClear = false;
	colFlagL = false;
	colFlagR = false;
	colFlagUp = false;
	colFlagDown = false;
	m_pPlayer->init();
	m_pStage->init();
}

void GameManager::end()
{
	m_pPlayer->end();
	m_pStage->end();
}

void GameManager::update()
{
	collision();
	
	if (colFlagL || colFlagR || colFlagUp || colFlagDown)
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
	if (!colFlagL && !colFlagR && !colFlagUp && !colFlagDown)
	{
		m_GameOverCount = 30;
	}

	if (!GameOver)
	{
		m_pPlayer->operation(colL, colR, colUp, colDown);
	}
	else if (GameOver)
	{
		m_pPlayer->m_speedX = 0;
		m_pPlayer->m_speedY = 0;
		printfDx("GameOver\n");
	}

	if (GameClear)
	{
		m_pPlayer->m_speedX = 0;
		m_pPlayer->m_speedY = 0;
		printfDx("GameClear\n");
	}
	
	
	m_pPlayer->update();
	m_pStage->update();

	
}

void GameManager::draw()
{
	m_pStage->draw();
	m_pPlayer->draw();
	printfDx("%d\n", m_GameOverCount);
}

void GameManager::collision()
{
	collisionR();
	collisionL();
	collisionUP();
	collisionBottom();
	collisionTimeLag();
	collisionGameOver();
	collisionGameClear();
}

// ----------------------------------------------
// ìñÇΩÇËîªíË
// ----------------------------------------------

// âE
void GameManager::collisionR()
{
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_pPlayer->m_player[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x + 1)] == 6)
				{
					colR = false;
				}
				if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x + 1)] == 8)
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

// ç∂
void GameManager::collisionL()
{
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_pPlayer->m_player[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x - 1)] == 6)
				{
					colL = false;
				}
				if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x - 1)] == 8)
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

// è„
void GameManager::collisionUP()
{
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_pPlayer->m_player[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + x] == 6)
				{
					colUp = false;
				}
				if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + x] == 8)
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

// â∫
void GameManager::collisionBottom()
{
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_pPlayer->m_player[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pPlayer->m_posY + (y + 1)][m_pPlayer->m_posX + x] == 6)
				{
					colDown = false;
				}
				if (m_pStage->m_stage[m_pPlayer->m_posY + (y + 1)][m_pPlayer->m_posX + x] == 8)
				{
					colDown = false;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + (y + 1)][m_pPlayer->m_posX + x] != 0)
				{
					colDown = true;
				}
				else
				{
					colDown = false;
				}
			}
		}
	}
}

void GameManager::collisionTimeLag()
{
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_pPlayer->m_player[y][x] != 0)
			{
				// âE
				if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x + 1)] == 7)
				{
					colFlagR = true;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x + 1)] != 7)
				{
					colFlagR = false;
				}
				// ç∂
				if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x - 1)] == 7)
				{
					colFlagL = true;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x - 1)] != 7)
				{
					colFlagL = false;
				}
				// è„
				if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + x] == 7)
				{
					colFlagUp = true;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + x] != 7)
				{
					colFlagUp = false;
				}
				// â∫
				if (m_pStage->m_stage[m_pPlayer->m_posY + (y + 1)][m_pPlayer->m_posX + x] == 7)
				{
					colFlagDown = true;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + (y + 1)][m_pPlayer->m_posX + x] != 7)
				{
					colFlagDown = false;
				}
			}
		}
	}
}

void GameManager::collisionGameOver()
{
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_pPlayer->m_player[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + x] == 6)
				{
					GameOver = true;
				}
			}
		}
	}
}

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
