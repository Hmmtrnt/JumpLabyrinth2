#include "GameManager.h"
#include "../Object/Player.h"
#include "../Object/Stage.h"

GameManager::GameManager() :
	m_GameOverCount(0),
	GameOver(0),
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
	/*if (colNextFlag)
	{
		m_GameOverCount = 30;
	}

	if (colNextFlag)
	{
		m_GameOverCount--;
		if (m_GameOverCount <= 0)
		{
			m_GameOverCount = 0;
			GameOver = true;
			printfDx("ゲームオーバー\n");
		}
	}*/

	collision();
	/*if (!colL)
	{
		colFlagL = false;
	}
	if (!colR)
	{
		colFlagR = false;
	}
	if (!colUp)
	{
		colFlagUp = false;
	}
	if (!colDown)
	{
		colFlagDown = false;
	}*/

	if (!GameOver)
	{
		m_pPlayer->operation(colL, colR, colUp, colDown);
		
	}
	else if (GameOver)
	{
		m_pPlayer->m_speedX = 0;
		m_pPlayer->m_speedY = 0;
	}
	m_pPlayer->update();
	m_pStage->update();

	
}

void GameManager::draw()
{
	m_pStage->draw();
	m_pPlayer->draw();
	//printfDx("%d\n", m_GameOverCount);
}

void GameManager::collision()
{
	collisionR();
	collisionL();
	collisionUP();
	collisionBottom();
	collisionGameOver();
}

// ----------------------------------------------
// 当たり判定
// ----------------------------------------------

// 右
void GameManager::collisionR()
{
	//colR = false;
	//colNextFlag = false;
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
				/*else if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x + 1)] == 7)
				{
					colR = true;
					colFlagR = true;
				}*/
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
	//colL = false;
	//colNextFlag = false;
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
				/*else if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x - 1)] == 7)
				{
					colL = true;
					colFlagL = true;
				}*/
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
	//colUp = false;
	//colNextFlag = false;
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
				/*else if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + x] == 7)
				{
					colUp = true;
					colFlagUp = true;
				}*/
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
	//colDown = false;
	//colNextFlag = false;
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
				/*else if (m_pStage->m_stage[m_pPlayer->m_posY + (y + 1)][m_pPlayer->m_posX + x] == 7)
				{
					colDown = true;
					colFlagDown = true;
				}*/
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
					printfDx("ゲームオーバー(即死)\n");
					GameOver = true;
				}
			}
		}
	}
}
