#include "Player.h"
#include "../Util/Pad.h"
#include "CharParticle.h"

namespace
{
	constexpr int motionCount = 40;
	constexpr int speed = 68;
	// BGMの音量
	constexpr int kVolumeBgm = 255;
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
	m_jumpSound(0),
	m_landingSound(0),
	m_rota(0.0f),
	m_sound(false),
	m_showerFrame(0),
	m_particleFrame(0),
	m_landing(false)
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
	m_jumpSound = LoadSoundMem("sound/jumpSound.mp3");
	m_landingSound = LoadSoundMem("sound/landingSound.mp3");
	m_sound = true;

	ChangeVolumeSoundMem(kVolumeBgm, m_landingSound);
	ChangeVolumeSoundMem(kVolumeBgm, m_jumpSound);

	for (int y = 0; y < kVariable::PlayerWidth; y++)
	{
		for (int x = 0; x < kVariable::PlayerWidth; x++)
		{
			m_player[y][x] = kPlayer::playr[y][x];
		}
	}
	for (auto& pParticle : m_particle)
	{
		pParticle = std::make_shared<CharParticle>();
	}
	m_showerFrame = kParticle::ShowerInterval;
	m_particleFrame = 0;
	m_landing = true;
}

void Player::initPlayer(int posX, int posY, int frameX, int frameY)
{
	m_posX = posX;
	m_posY = posY;
	m_frameX = frameX;
	m_frameY = frameY;
	initCommon();
}

void Player::initTitle()
{
	m_handle = draw::MyLoadGraph("data/AnimationSheet_Character.png");
}

// 終了
void Player::end()
{
	DeleteGraph(m_handle);
	DeleteGraph(m_handle2);
	DeleteGraph(m_handleEffect);
	DeleteSoundMem(m_jumpSound);
	DeleteSoundMem(m_landingSound);
}

void Player::endTitle()
{
	DeleteGraph(m_handle);
}

// 更新
void Player::update()
{
	m_frameX += m_speedX;
	m_posX = m_frameX / kVariable::DrawWidth;
	m_frameY += m_speedY;
	m_posY = m_frameY / kVariable::DrawWidth;
}

void Player::updateInCollision(int& frameX, int& frameY)
{
	m_frameX += m_speedX;
	m_posX = m_frameX / kVariable::DrawWidth;
	m_frameY += m_speedY;
	m_posY = m_frameY / kVariable::DrawWidth;

	frameX = m_frameX + (kVariable::DrawPosition + kVariable::DrawWidth);
	frameY = m_frameY;
}

// 描画
void Player::DrawGamePlay()
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

void Player::DrawTitle(int posX, int posY)
{
	// タイトル画面待機モーション
	m_frameCount--;
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

	draw::MyDrawRectRotaGraph(posX,
		posY,
		m_verXPlayer * 32, m_verYPlayer * 32,
		32, 32,
		3.0f, m_rota,
		m_handle, true, false);
}

// プレイヤーの操作処理
void Player::operation(bool colL, bool colR, bool colUp, bool colDown)
{

	if (m_speedX != 0 || m_speedY != 0)
	{
		m_sound = false;
	}

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
		if (!m_sound)
		{
			PlaySoundMem(m_landingSound, DX_PLAYTYPE_BACK, true);
		}
		m_sound = true;
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
					//PlaySoundMem(m_jumpSound, DX_PLAYTYPE_BACK, true);
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
					//PlaySoundMem(m_jumpSound, DX_PLAYTYPE_BACK, true);
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
					//PlaySoundMem(m_jumpSound, DX_PLAYTYPE_BACK, true);
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
					//PlaySoundMem(m_jumpSound, DX_PLAYTYPE_BACK, true);
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
		draw::MyDrawRectRotaGraph(kVariable::DrawPosition + (m_frameX + (x * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
								  (m_frameY + (y * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
								  m_verXPlayer * 32, m_verYPlayer * 32,
								  32, 32,
								  2.2f, m_rota,
								  m_handle, true, true);

	}
	else if (m_speedX == 0 && m_speedY == 0)
	{
		draw::MyDrawRectRotaGraph(kVariable::DrawPosition + (m_frameX + (x * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
								  (m_frameY + (y * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
								  m_verXPlayer * 32, m_verYPlayer * 32,
								  32, 32,
								  2.2f, m_rota,
								  m_handle, true, false);
	}
	
	// パーティクル表示タイマー
	particleTime();

	particle(kVariable::DrawPosition + (m_frameX + (x * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
		(m_frameY + (y * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2), m_rota);
	drawParticle();
}

// プレイヤーのモーション
void Player::motion(int x, int y)
{
	m_frameCount--;

	// 移動中のキャラの見た目
	if (m_speedX != 0 || m_speedY != 0)
	{
		draw::MyDrawRectRotaGraph(kVariable::DrawPosition + (m_frameX + (x * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
			(m_frameY + (y * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
			0, 0,
			40, 40,
			2.0f, m_rota,
			m_handle2, true, false);
		m_frameCount = motionCount;
	}

	// 待機モーション
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

void Player::particleTime()
{
	// パーティクル表示するタイマー
	if (m_speedX == 0 && m_speedY == 0)	m_landing = true;
	if (Pad::isTrigger(PAD_INPUT_UP) || Pad::isTrigger(PAD_INPUT_DOWN) ||
		Pad::isTrigger(PAD_INPUT_RIGHT) || Pad::isTrigger(PAD_INPUT_LEFT)) m_landing = false;

	//if (m_speedX != 0 || m_speedY != 0)	m_landing = false;

	if (m_landing)
	{

		m_particleFrame--;
		if (m_particleFrame <= 0)	m_particleFrame = 0;
	}
	if (!m_landing)
	{
		m_particleFrame = 10;
		for (auto& pParticle : m_particle)
		{
			if (!pParticle->isExist())	continue;
			pParticle->init();
		}
	}
}

void Player::particle(int x, int y, float rota)
{
	for (auto& pParticle : m_particle)
	{
		if (!pParticle->isExist())	continue;
		pParticle->update();
	}
	m_showerFrame--;
	if (m_showerFrame <= 0)
	{
		int count = 0;
		for (auto& pParticle : m_particle)
		{
			if (pParticle->isExist())	continue;

			Vec2 pos;
			Vec2 vec;
			// 上
			if (rota == PI / 1)
			{
				pos.x = static_cast<float>(x);
				pos.y = static_cast<float>(y - 30);
				vec.x = static_cast<float>(GetRand(8)) - 4.0f;
				vec.y = static_cast<float>(GetRand(10));
			}
			// 下
			if (rota == 0)
			{
				pos.x = static_cast<float>(x);
				pos.y = static_cast<float>(y + 30);
				vec.x = static_cast<float>(GetRand(8)) - 4.0f;
				vec.y = -static_cast<float>(GetRand(10));
			}
			// 右
			if (rota == PI / -2)
			{
				pos.x = static_cast<float>(x + 30);
				pos.y = static_cast<float>(y);
				vec.x = -static_cast<float>(GetRand(10));
				vec.y = static_cast<float>(GetRand(8)) - 4.0f;
			}
			// 左
			if (rota == PI / 2)
			{
				pos.x = static_cast<float>(x - 30);
				pos.y = static_cast<float>(y);
				vec.x = static_cast<float>(GetRand(10));
				vec.y = static_cast<float>(GetRand(8)) - 4.0f;
			}
			if (m_particleFrame > 1 && m_landing) pParticle->start(pos);
			pParticle->setVec(vec);
			pParticle->setColor(kColor::Brown);
			count++;
			if (count >= 4)
			{
				break;
			}
		}
		m_showerFrame = kParticle::ShowerInterval;
	}
	
}

void Player::drawParticle()
{
	for (auto& pParticle : m_particle)
	{
		if (!pParticle->isExist())	continue;
		pParticle->draw();
	}
}
