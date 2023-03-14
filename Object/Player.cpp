#include "Player.h"
#include "../Util/Pad.h"
#include "ParticleBase.h"

namespace
{
	// ���[�V�����t���[��
	constexpr int motionCount = 40;
	// ����
	constexpr int speed = 68;
	// BGM�̉���
	constexpr int kVolumeBgm = 255;
}

Player::Player() :
	m_posX(0),
	m_posY(0),
	m_frameX(0),
	m_frameY(0),
	m_speedX(0),
	m_speedY(0),
	m_verXPlayer(0),
	m_verYPlayer(0),
	m_handle(-1),
	m_handle2(-1),
	m_handleEffect(-1),
	m_handlenumX(-1),
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

// ���ʂ̏�����
void Player::initCommon()
{
	m_verXPlayer = 0;
	m_verYPlayer = 0;
	m_frameCount = motionCount;
	m_rota = 0.0f;
	// �v���C���[�`��
	m_handle = draw::MyLoadGraph("data/AnimationSheet_Character.png");// �����[�V����
	m_handle2 = draw::MyLoadGraph("data/moveChar2.png");// �ړ���
	m_jumpSound = LoadSoundMem("sound/jumpSound.mp3");// �W�����v������
	m_landingSound = LoadSoundMem("sound/landingSound.mp3");// ���n������
	m_sound = true;

	ChangeVolumeSoundMem(kVolumeBgm, m_landingSound);
	ChangeVolumeSoundMem(kVolumeBgm, m_jumpSound);

	// �v���C���[�̔z��
	for (int y = 0; y < kVariable::PlayerWidth; y++)
	{
		for (int x = 0; x < kVariable::PlayerWidth; x++)
		{
			m_player[y][x] = kPlayer::playr[y][x];
		}
	}
	// �p�[�e�B�N��
	for (auto& pParticle : m_particle)
	{
		pParticle = std::make_shared<ParticleBase>();
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

// �I��
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

void Player::update()
{
	// �ړ�
	m_frameX += m_speedX;
	m_posX = m_frameX / kVariable::DrawWidth;
	m_frameY += m_speedY;
	m_posY = m_frameY / kVariable::DrawWidth;
}

void Player::updateInCollision(int& frameX, int& frameY)
{
	// �ړ�
	m_frameX += m_speedX;
	m_posX = m_frameX / kVariable::DrawWidth;
	m_frameY += m_speedY;
	m_posY = m_frameY / kVariable::DrawWidth;

	// �����蔻��
	frameX = m_frameX + (kVariable::DrawPosition + kVariable::DrawWidth);
	frameY = m_frameY;
}

void Player::DrawGamePlay()
{
	for (int y = 0; y < kVariable::PlayerWidth; y++)
	{
		for (int x = 0; x < kVariable::PlayerWidth; x++)
		{
			if (m_player[y][x] == 1)
			{
				playerDraw(x, y);// �v���C���[
				motion(x, y);// ���[�V����
			}
		}
	}
}

void Player::DrawTitle(int posX, int posY)
{
	// �^�C�g����ʑҋ@���[�V����
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

// �v���C���[�̑��쏈��
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
		// ���K�p
		if (Pad::isPress(PAD_INPUT_DOWN) == 0 &&
			Pad::isPress(PAD_INPUT_RIGHT) == 0 &&
			Pad::isPress(PAD_INPUT_LEFT) == 0)
		{
			// ��
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
			// ��
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
			// �E
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
			// ��
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

// �v���C���[�̕`��
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
	
	// �p�[�e�B�N���\���^�C�}�[
	particleTime();

	particle(kVariable::DrawPosition + (m_frameX + (x * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
		(m_frameY + (y * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2), m_rota);
	drawParticle();
}

// �v���C���[�̃��[�V����
void Player::motion(int x, int y)
{
	m_frameCount--;

	// �ړ����̃L�����̌�����
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

	// �ҋ@���[�V����
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

	bool upLanding = m_rota == PI / 1 && Pad::isTrigger(PAD_INPUT_UP);// ��
	bool downLanding = m_rota == 0 && Pad::isTrigger(PAD_INPUT_DOWN);// ��
	bool rightLanding = m_rota == PI / -2 && Pad::isTrigger(PAD_INPUT_RIGHT);// �E
	bool leftLanding = m_rota == PI / 2 && Pad::isTrigger(PAD_INPUT_LEFT);// ��
	// �p�[�e�B�N���\������^�C�}�[
	if (m_speedX == 0 && m_speedY == 0)	m_landing = true;
	if (m_speedX != 0 || m_speedY != 0)
	{
		m_landing = false;
	}
	
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
			// ��
			if (rota == PI / 1)
			{
				pos.x = static_cast<float>(x);
				pos.y = static_cast<float>(y - 30);
				vec.x = static_cast<float>(GetRand(8)) - 4.0f;
				vec.y = static_cast<float>(GetRand(10));
			}
			// ��
			if (rota == 0)
			{
				pos.x = static_cast<float>(x);
				pos.y = static_cast<float>(y + 30);
				vec.x = static_cast<float>(GetRand(8)) - 4.0f;
				vec.y = -static_cast<float>(GetRand(10));
			}
			// �E
			if (rota == PI / -2)
			{
				pos.x = static_cast<float>(x + 30);
				pos.y = static_cast<float>(y);
				vec.x = -static_cast<float>(GetRand(10));
				vec.y = static_cast<float>(GetRand(8)) - 4.0f;
			}
			// ��
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