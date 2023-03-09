#include "Player.h"
#include "../Util/Pad.h"

namespace
{
	constexpr int motionCount = 40;
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
	m_sound(false)
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

// �X�V
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

void Player::updateInCollision(int& frameX, int& frameY)
{
	m_frameX += m_speedX;
	m_posX = m_frameX / kVariable::DrawWidth;
	m_frameY += m_speedY;
	m_posY = m_frameY / kVariable::DrawWidth;

	frameX = m_frameX + (kVariable::DrawPosition + kVariable::DrawWidth);
	frameY = m_frameY;
	
	
	
}

// �`��
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
				//moveParticle();
				
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
					//PlaySoundMem(m_jumpSound, DX_PLAYTYPE_BACK, true);
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
					//PlaySoundMem(m_jumpSound, DX_PLAYTYPE_BACK, true);
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
					//PlaySoundMem(m_jumpSound, DX_PLAYTYPE_BACK, true);
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
					//PlaySoundMem(m_jumpSound, DX_PLAYTYPE_BACK, true);
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

	

	//int a = GetRand(60);

	//for (int i = 0; i < a; i++)
	//{
	//	CreateParticle(kVariable::DrawPosition + (m_frameX + (x * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2),
	//		(m_frameY + (y * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2));
	//}

	//// �p�[�e�B�N���`��
	//for (int i = 0; i < kMaxSpark; i++)
	//{
	//	if (Particle[i].UsingFlag)
	//	{
	//		DrawPixel(kVariable::DrawPosition + (m_frameX + (x * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2), 
	//			(m_frameY + (y * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2), 
	//			GetColor(Particle[i].Bright, Particle[i].Bright, Particle[i].Bright));
	//	}
	//}

	//printfDx("%d\n", a);

	/*BrightTest-=2;

	if (BrightTest <= 0)
	{
		BrightTest = 255;
		testX = GetRand(100);
		testY = -GetRand(100);
	}
	int posx = kVariable::DrawPosition + (m_frameX + (x * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2);
	int posy = (m_frameY + (y * kVariable::DrawWidth)) + (kVariable::DrawWidth / 2);
	
	posx += testX;
	posy += testY;

	DrawPixel(posx, posy, GetColor(BrightTest, BrightTest, BrightTest));*/
	
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