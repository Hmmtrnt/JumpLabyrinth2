#include "GameManager.h"
#include "../Object/Player.h"
#include "../Object/Enemy.h"
#include "../Object/Stage.h"

GameManager::GameManager() :
	m_gimmickFrame(0),
	m_shrink(0),
	m_inflate(0),
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
	m_pEnemy = new Enemy;
	m_pStage = new Stage;
}

GameManager::~GameManager()
{
	delete m_pPlayer;
	delete m_pEnemy;
	delete m_pStage;
}

void GameManager::init()
{
	m_gimmickFrame = 0;
	m_shrink = 60;
	m_inflate = 60;
	m_GameOverCount = 30;
	GameOver = false;
	GameClear = false;
	colFlagL = false;
	colFlagR = false;
	colFlagUp = false;
	colFlagDown = false;

	m_pPlayer->init();
	m_pEnemy->init();
	m_pStage->init();
}

void GameManager::end()
{
	m_pPlayer->end();
	m_pEnemy->end();
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
	m_pEnemy->update();
	m_pEnemy->moveWidth(colL, colR);
	m_pStage->update();

	
}

void GameManager::draw()
{
	m_pStage->draw();
	m_pEnemy->draw();
	m_pPlayer->draw();
	//printfDx("%d\n", m_GameOverCount);
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

// ----------------------------------------------
// �����蔻��
// ----------------------------------------------

// �E
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

// ��
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

// ��
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

// ��
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
					colDown = false;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + (y + 1)][m_pPlayer->m_posX + x] == 6)
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

// �M�~�b�N5:�c��񂾂瑦������
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
					// �E
					if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x + 1)] == 5)
					{
						GameOver = true;
					}
					// ��
					if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x - 1)] == 5)
					{
						GameOver = true;
					}
					// ��
					if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + x] == 5)
					{
						GameOver = true;
					}
					// ��
					if (m_pStage->m_stage[m_pPlayer->m_posY + (y + 1)][m_pPlayer->m_posX + (x - 1)] == 5)
					{
						GameOver = true;
					}
					// �E��
					if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + (x + 1)] == 5)
					{
						GameOver = true;
					}
					// ����
					if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + (x - 1)] == 5)
					{
						GameOver = true;
					}
					// �E��
					if (m_pStage->m_stage[m_pPlayer->m_posY + (y + 1)][m_pPlayer->m_posX + (x + 1)] == 5)
					{
						GameOver = true;
					}
					// ����
					if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + (x - 1)] == 5)
					{
						GameOver = true;
					}
				}
			}
		}
		//printfDx("�����蔻��L��\n");
	}
}

// �M�~�b�N7:���t���[����ɐj���o�ăQ�[���I�[�o�[�ɂȂ锻��
void GameManager::collisionTimeLag()
{
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_pPlayer->m_player[y][x] != 0)
			{
				// �E
				if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x + 1)] == 7)
				{
					colFlagR = true;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x + 1)] != 7)
				{
					colFlagR = false;
				}
				// ��
				if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x - 1)] == 7)
				{
					colFlagL = true;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x - 1)] != 7)
				{
					colFlagL = false;
				}
				// ��
				if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + x] == 7)
				{
					colFlagUp = true;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + x] != 7)
				{
					colFlagUp = false;
				}
				// ��
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

// �G
void GameManager::collisionEnemy()
{
	if (m_pPlayer->m_posX == m_pEnemy->m_posX && m_pPlayer->m_posY == m_pEnemy->m_posY)
	{
		GameOver = true;
	}

}

// �Q�[���I�[�o�[
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
				// �M�~�b�N6:��������
				if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + x] == 6)
				{
					GameOver = true;
				}
			}
		}
	}
}

// �Q�[���N���A
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

void GameManager::EnemyElasticity()
{
	// �M�~�b�N�̓����蔻��ύX����
	m_gimmickFrame++;
	if (m_gimmickFrame >= m_shrink + m_inflate)
	{
		m_gimmickFrame = 0;
	}
}
