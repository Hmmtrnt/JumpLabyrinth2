#include "Player.h"
#include "../Util/Pad.h"

namespace
{
	constexpr int motionCount = 40;
	constexpr int speed = 68;
}

Player::Player() :
	m_posX(0),
	m_posY(0),
	m_frameX(0),
	m_frameY(0),
	m_speedX(0),
	m_speedY(0),
	m_handle(-1),
	m_handle2(-1),
	m_handleEffect(-1),
	m_handlenumX(-1),
	m_verXPlayer(0),
	m_verYPlayer(0),
	m_frameCount(0),
	m_rota(0.0f)
{
	for (int y = 0; y < kVariable::PlayerWidth; y++)
	{
		for (int x = 0; x < kVariable::PlayerWidth; x++)
		{
			m_player[y][x] = 0;
		}
	}
}

Player::~Player()
{
}

// 共通の初期化
void Player::initCommon()
{
	m_verXPlayer = 0;
	m_verYPlayer = 0;
	m_frameCount = motionCount;
	m_rota = 0.0f;
	m_handle = draw::MyLoadGraph("data/AnimationSheet_Character.png");
	m_handle2 = draw::MyLoadGraph("data/moveChar2.png");
	m_handleEffect = draw::MyLoadGraph("data/charEffect2.png");

	for (int y = 0; y < kVariable::PlayerWidth; y++)
	{
		for (int x = 0; x < kVariable::PlayerWidth; x++)
		{
			m_player[y][x] = kPlayer::playr[y][x];
		}
	}
}

void Player::initPlayer(int posX, int posY, int frameX, int frameY)
{
	m_posX = posX;
	m_posY = posY;
	m_frameX = frameX;
	m_frameY = frameY;
	initCommon();
}

// プロトタイプ用初期化
void Player::initP()
{
	m_posX = 11;
	m_posY = 12;
	m_frameX = 440;
	m_frameY = 480;
	initCommon();
}

// 終了
void Player::end()
{
	DeleteGraph(m_handle);
	DeleteGraph(m_handle2);
	DeleteGraph(m_handleEffect);
}

// 更新
void Player::update()
{
	m_frameX += m_speedX;
	m_posX = m_frameX / kVariable::DrawWidth;
	m_frameY += m_speedY;
	m_posY = m_frameY / kVariable::DrawWidth;
	
	//motion();
	//standMotion();
	//jumpMotion();
}

// 描画
void Player::draw()
{
	for (int y = 0; y < kVariable::PlayerWidth; y++)
	{
		for (int x = 0; x < kVariable::PlayerWidth; x++)
		{
			if (m_player[y][x] == 1)
			{
				playerDraw(x, y);
				motion(x, y);
			}
		}
	}
	/*DrawFormatString(600, 0, GetColor(255, 0, 0), "m_frameCount:%d", m_frameCount);
	DrawFormatString(600, 50, GetColor(255, 0, 0), "m_verXPlayer:%d", m_verXPlayer);
	DrawFormatString(600, 100, GetColor(255, 0, 0), "m_verYPlayer:%d", m_verYPlayer);
	DrawFormatString(600, 150, GetColor(255, 0, 0), "m_flameY:%d", m_frameY);*/
}

// プレイヤーの操作処理
void Player::operation(bool colL, bool colR, bool colUp, bool colDown)
{

	if (colL || colR)
	{
		m_speedX = 0;
	}
	if (colUp || colDown)
	{
		m_speedY = 0;
	}

	if (m_speedX == 0 && m_speedY == 0)
	{
		// 正規用
		if (Pad::isPress(PAD_INPUT_DOWN) == 0 &&
			Pad::isPress(PAD_INPUT_RIGHT) == 0 &&
			Pad::isPress(PAD_INPUT_LEFT) == 0)
		{
			// 上
			if (Pad::isTrigger(PAD_INPUT_UP) == 1)
			{
				m_rota = PI / 1;
				if (!colUp)
				{
					m_speedY = -speed;
				}
			}
		}
		if (Pad::isPress(PAD_INPUT_UP) == 0 &&
			Pad::isPress(PAD_INPUT_RIGHT) == 0 &&
			Pad::isPress(PAD_INPUT_LEFT) == 0)
		{
			// 下
			if (Pad::isTrigger(PAD_INPUT_DOWN) == 1)
			{
				m_rota = 0;
				if (!colDown)
				{
					m_speedY = speed;
				}
			}
		}
		if (Pad::isPress(PAD_INPUT_DOWN) == 0 &&
			Pad::isPress(PAD_INPUT_UP) == 0 &&
			Pad::isPress(PAD_INPUT_LEFT) == 0)
		{
			// 右
			if (Pad::isTrigger(PAD_INPUT_RIGHT) == 1)
			{
				m_rota = PI / -2;
				if (!colR)
				{
					m_speedX = speed;
				}
			}
		}
		if (Pad::isPress(PAD_INPUT_DOWN) == 0 &&
			Pad::isPress(PAD_INPUT_UP) == 0 &&
			Pad::isPress(PAD_INPUT_RIGHT) == 0)
		{
			// 左
			if (Pad::isTrigger(PAD_INPUT_LEFT) == 1)
			{
				m_rota = PI / 2;
				if (!colL)
				{
					m_speedX = -speed;
				}
			}
		}
	}
}

// プレイヤーの描画
void Player::playerDraw(int x, int y)
{
	if (m_rota == PI / 2 && m_speedX == 0 && m_speedY == 0)
	{
		draw::MyDrawRectRotaGraph(kVariable::DrawPositionX + (m_frameX + (x * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
								  (m_frameY + (y * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
								  m_verXPlayer * 32, m_verYPlayer * 32,
								  32, 32,
								  2.2f, m_rota,
								  m_handle, true, true);

	}
	else if (m_speedX == 0 && m_speedY == 0)
	{
		draw::MyDrawRectRotaGraph(kVariable::DrawPositionX + (m_frameX + (x * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
								  (m_frameY + (y * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
								  m_verXPlayer * 32, m_verYPlayer * 32,
								  32, 32,
								  2.2f, m_rota,
								  m_handle, true, false);
	}
}

// プレイヤーのモーション
void Player::motion(int x, int y)
{
	m_frameCount--;

	// 移動中のキャラエフェクト
	if (m_speedY == -40)
	{
		draw::MyDrawRectRotaGraph(kVariable::DrawPositionX + (m_frameX + (x * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
			(m_frameY + (y * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
			0, 0,
			40, 40,
			1.0f, m_rota,
			m_handleEffect, true, false);
	}
	if (m_speedY == 40)
	{
		draw::MyDrawRectRotaGraph(kVariable::DrawPositionX + (m_frameX + (x * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
			(m_frameY + (y * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
			0, 0,
			40, 40,
			1.0f, m_rota,
			m_handleEffect, true, false);
	}
	if (m_speedX == -40)
	{
		draw::MyDrawRectRotaGraph(kVariable::DrawPositionX + (m_frameX + (x * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
			(m_frameY + (y * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
			0, 0,
			40, 40,
			1.0f, m_rota,
			m_handleEffect, true, false);
	}
	if (m_speedX == 40)
	{
		draw::MyDrawRectRotaGraph(kVariable::DrawPositionX + (m_frameX + (x * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
			(m_frameY + (y * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
			0, 0,
			40, 40,
			1.0f, m_rota,
			m_handleEffect, true, false);
	}

	// 移動中のキャラの見た目
	if (m_speedX != 0 || m_speedY != 0)
	{
		draw::MyDrawRectRotaGraph(kVariable::DrawPositionX + (m_frameX + (x * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
			(m_frameY + (y * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
			0, 0,
			40, 40,
			2.0f, m_rota,
			m_handle2, true, false);
		m_frameCount = motionCount;
	}

	if (m_speedX == 0 && m_speedY == 0)
	{
		if (m_frameCount <= 0 && m_verXPlayer != 1)
		{
			m_verXPlayer = 1;
			m_verYPlayer = 0;
			m_frameCount = motionCount;
		}
		else if (m_frameCount <= 0 && m_verXPlayer != 0)
		{
			m_verXPlayer = 0;
			m_verYPlayer = 0;
			m_frameCount = motionCount;
		}
	}
}