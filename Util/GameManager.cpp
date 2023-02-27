#include "GameManager.h"
#include "../Object/Player.h"
#include "../Object/Stage.h"
#include "../Object/Back.h"
#include "../Scene/ScenePause.h"
#include "DrawFunctions.h"
#include "../Util/Pad.h"
#include "../Object/Shot.h"

GameManager::GameManager() :
	GameOver(false),
	GameClear(false),
	m_pushPause(0),
	m_gimmickFrame(0),
	m_shrink(0),
	m_inflate(0),
	m_GameOverCount(0),
	m_frameCountGameOver(0),
	m_handleNeedle(-1),
	m_goalSound(0),
	m_deathSound(0),
	m_decideSound(0),
	m_rota(0.0f),
	colNextFlag(false),
	colFlagL(false),
	colFlagR(false),
	colFlagUp(false),
	colFlagBottom(false),
	colL(false),
	colR(false),
	colUp(false),
	colBottom(false),
	m_pushFlag(false),
	m_playSound(false)
{
	m_pPlayer = new Player;
	m_pStage = new Stage;
	m_pBack = new Back;
	m_pPause = new ScenePause;
	m_pShot = new Shot;
}

GameManager::~GameManager()
{
	delete m_pPlayer;
	delete m_pStage;
	delete m_pBack;
	delete m_pPause;
	delete m_pShot;
}

void GameManager::initCommon()
{
	GameOver = false;
	GameClear = false;
	m_pushPause = 0;
	m_gimmickFrame = 0;
	m_shrink = 50;
	m_inflate = 50;
	m_GameOverCount = 30;
	m_frameCountGameOver = 30;
	m_handleNeedle = draw::MyLoadGraph("data/needle2.png");
	m_goalSound = LoadSoundMem("sound/goalSound.mp3");
	m_deathSound = LoadSoundMem("sound/damegeSound.mp3");
	m_decideSound = LoadSoundMem("sound/decideSound.mp3");
	colFlagL = false;
	colFlagR = false;
	colFlagUp = false;
	colFlagBottom = false;
	colL = false;
	colR = false;
	colUp = false;
	colBottom = false;
	m_playSound = false;

	ChangeVolumeSoundMem(100, m_goalSound);
	ChangeVolumeSoundMem(100, m_deathSound);
	m_pPause->init();
	
}

void GameManager::initManager(int posX, int posY, int frameX, int frameY, 
	const int stage[][kVariable::StageWidth], int stageHeight, int stageWidth)
{
	initCommon();
	m_pPlayer->initPlayer(posX, posY,frameX,frameY);
	m_pStage->initStage(stage, stageHeight, stageWidth);
	m_pBack->init();
}

void GameManager::initManagerInShot(int posX, int posY, int frameX, int frameY, 
	const int stage[][kVariable::StageWidth], int stageHeight, int stageWidth)
{
	initCommon();
	m_pShot->init();
	m_pPlayer->initPlayer(posX, posY, frameX, frameY);
	m_pStage->initStage(stage, stageHeight, stageWidth);
	m_pBack->init();
}

void GameManager::end()
{
	DeleteGraph(m_handleNeedle);
	DeleteSoundMem(m_goalSound);
	DeleteSoundMem(m_deathSound);
	DeleteSoundMem(m_decideSound);
	m_pPlayer->end();
	m_pStage->end();
	m_pBack->end();
	m_pPause->end();
	m_pShot->end();
}

void GameManager::updateInShot(int& frameX, int& frameY)
{
	// ポーズボタンを押したときの処理
	if (Pad::isTrigger(PAD_INPUT_R) == 1)
	{
		if (!GameOver)
		{
			// 開く
			if (m_pushFlag == false)
			{
				m_pushFlag = true;
			}
			// 閉じる
			else if (m_pushFlag == true)
			{
				m_pushFlag = false;
			}
		}
	}
	// ポーズボタンを閉じるときの処理
	if (Pad::isTrigger(PAD_INPUT_1))
	{
		if (!GameOver)
		{
			if (m_pushFlag == true)
			{
				m_pushFlag = false;
			}
		}
	}

	if (!m_pushFlag)
	{
		collision();

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
			if (!m_playSound)
			{
				PlaySoundMem(m_deathSound, DX_PLAYTYPE_BACK, true);
			}
			m_playSound = true;
		}

		if (GameClear)
		{
			m_pPlayer->m_speedX = 0;
			m_pPlayer->m_speedY = 0;
			if (!m_playSound)
			{
				PlaySoundMem(m_goalSound, DX_PLAYTYPE_BACK, true);
			}
			m_playSound = true;
		}
		// 弾との当たり判定を得るための更新処理
		m_pPlayer->updateInCollision(frameX, frameY);
		m_pStage->update();
	}
	if (m_pushFlag)
	{
		m_pPause->updatePause();
		updatePause();
	}
	if (GameClear)
	{
		m_pPause->updateClearPause();
		updatePause();
		GameOver = false;
	}
}

void GameManager::updateNoShot()
{
	// ポーズボタンを押したときの処理
	if (Pad::isTrigger(PAD_INPUT_R) == 1)
	{
		if (!GameOver && !GameClear)
		{
			// 開く
			if (m_pushFlag == false)
			{
				m_pushFlag = true;
			}
			// 閉じる
			else if (m_pushFlag == true)
			{
				m_pushFlag = false;
			}
		}
	}
	// ポーズボタンを閉じるときの処理
	if (Pad::isTrigger(PAD_INPUT_1))
	{
		if (!GameOver && !GameClear)
		{
			if (m_pushFlag == true)
			{
				m_pushFlag = false;
			}
		}
	}

	if (!m_pushFlag)
	{
		collision();

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
			if (!m_playSound)
			{
				PlaySoundMem(m_deathSound, DX_PLAYTYPE_BACK, true);
			}
			m_playSound = true;
		}

		if (GameClear)
		{
			m_pPlayer->m_speedX = 0;
			m_pPlayer->m_speedY = 0;
			if (!m_playSound)
			{
				PlaySoundMem(m_goalSound, DX_PLAYTYPE_BACK, true);
			}
			m_playSound = true;
		}

		m_pPlayer->update();
		m_pStage->update();
	}
	
	if (m_pushFlag)
	{
		m_pPause->updatePause();
		updatePause();
	}
	if (GameClear)
	{
		m_pPause->updateClearPause();
		updatePause();
		GameOver = false;
	}
}

void GameManager::updatePause()
{
	if (Pad::isTrigger(PAD_INPUT_2) == 1)
	{
		PlaySoundMem(m_decideSound, DX_PLAYTYPE_BACK, true);
		if (m_pPause->GetPushNum() == 0)
		{
			m_pushPause = 1;
		}
		else if (m_pPause->GetPushNum() == 1)
		{
			m_pushPause = 2;
		}
		if (GameClear)
		{
			if (m_pPause->GetPushNum() == 2)
			{
				m_pushPause = 3;
			}
		}
		
	}
}

void GameManager::draw()
{
	m_pStage->draw();
	if (!GameClear)
	{
		drawNeedle();
		m_pPlayer->DrawGamePlay();
	}
	if (GameClear)
	{
		m_pPause->drawClearPause();
	}
	if (m_pushFlag)
	{
		m_pPause->drawPause();
	}
}

void GameManager::collision()
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
	for (int y = 0; y < kVariable::PlayerWidth; y++)
	{
		for (int x = 0; x < kVariable::PlayerWidth; x++)
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
	for (int y = 0; y < kVariable::PlayerWidth; y++)
	{
		for (int x = 0; x < kVariable::PlayerWidth; x++)
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
	for (int y = 0; y < kVariable::PlayerWidth; y++)
	{
		for (int x = 0; x < kVariable::PlayerWidth; x++)
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
	for (int y = 0; y < kVariable::PlayerWidth; y++)
	{
		for (int x = 0; x < kVariable::PlayerWidth; x++)
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
		for (int y = 0; y < kVariable::PlayerWidth; y++)
		{
			for (int x = 0; x < kVariable::PlayerWidth; x++)
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
	for (int y = 0; y < kVariable::PlayerWidth; y++)
	{
		for (int x = 0; x < kVariable::PlayerWidth; x++)
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

// ギミック6:即死判定
void GameManager::collisionGameOver()
{
	collisionBulge();
	collisionTimeLag();
	for (int y = 0; y < kVariable::PlayerWidth; y++)
	{
		for (int x = 0; x < kVariable::PlayerWidth; x++)
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
	for (int y = 0; y < kVariable::PlayerWidth; y++)
	{
		for (int x = 0; x < kVariable::PlayerWidth; x++)
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

// 針の描画
void GameManager::drawNeedle()
{
	float needleSize = 1.8f;

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
		for (int y = 0; y < kVariable::PlayerWidth; y++)
		{
			for (int x = 0; x < kVariable::PlayerWidth; x++)
			{
				if (m_pPlayer->m_player[y][x] == 1)
				{
					draw::MyDrawRectRotaGraph(kVariable::DrawPosition + (m_pPlayer->m_frameX + (x * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
						(m_pPlayer->m_frameY + (y * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
						0, 0,
						40, 40,
						needleSize, m_rota,
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
