#include "Stage.h"
#include "ParticleBase.h"

namespace
{
	// �j�̕`��T�C�Y
	constexpr float kNeedleSize = 1.8f;
	// �X�e�[�W�̕`��T�C�Y
	constexpr float kStageSize = 2.2f;
}

Stage::Stage() :
	m_gimmickFrame(0),
	m_shrink(0),
	m_inflate(0),
	m_handleWall(0),
	m_handleTrap(0),
	m_handleSmallNeedle(0),
	m_handleGoal(0),
	m_verX(0),
	m_verY(0),
	m_sizeGimmick(0),
	m_idxGoalX(0),
	m_idxGoalY(0),
	m_GoalFrame(0),
	m_drawGoalFirst(0),
	m_drawGoalSecond(0),
	m_showerFrame(0),
	m_particleFrame(0),
	m_auraFrame(0)
{
	for (int y = 0; y < kVariable::StageWidth; y++)
	{
		for (int x = 0; x < kVariable::StageWidth; x++)
		{
			m_stage[y][x] = 0;
		}
	}
}

Stage::~Stage()
{
}

void Stage::initCommon()
{
	m_gimmickFrame = 0;
	m_shrink = 50;
	m_inflate = 50;
	// �X�e�[�W�n���h��
	m_handleWall = draw::MyLoadGraph("data/tileset/stage.png");
	m_handleTrap = draw::MyLoadGraph("data/Trap.png");
	m_handleSmallNeedle = draw::MyLoadGraph("data/smallneedle.png");
	m_handleGoal = draw::MyLoadGraph("data/goal1.png");

	// �X�e�[�W�؂���
	m_verX = 0;
	m_verY = 0;

	m_sizeGimmick = kStageSize;

	m_idxGoalX = 0;
	m_idxGoalY = 0;

	m_GoalFrame = 0;
	m_drawGoalFirst = 30;
	m_drawGoalSecond = 30;
	for (auto& pParticle : m_particle)
	{
		pParticle = std::make_shared<ParticleBase>();
	}
	m_showerFrame = kParticle::ShowerInterval;
	m_particleFrame = 0;
	m_auraFrame = kParticle::AuraInterval;
}

void Stage::initStage(const int stage[][kVariable::StageWidth], int stageHeight, int stageWidth)
{
	initCommon();
	for (int y = 0; y < stageHeight; y++)
	{
		for (int x = 0; x < stageWidth; x++)
		{
			m_stage[y][x] = stage[y][x];
		}
	}
}

void Stage::end()
{
	DeleteGraph(m_handleWall);
}

void Stage::update()
{
	// �M�~�b�N�̕`��ύX����
	m_gimmickFrame++;
	if (m_gimmickFrame >= m_shrink + m_inflate)
	{
		m_gimmickFrame = 0;
	}

	// �S�[���̕`��ύX����
	m_GoalFrame++;
	if (m_GoalFrame >= m_drawGoalFirst + m_drawGoalSecond)
	{
		m_GoalFrame = 0;
	}
}

void Stage::draw()
{
	// �X�e�[�W�`��
	for (int y = 0; y < kVariable::StageWidth; y++)
	{
		for (int x = 0; x < kVariable::StageWidth; x++)
		{
			stageDraw(x, y);
		}
	}

	// �p�[�e�B�N���`��
	drawParticle();
}

void Stage::stageDraw(int x, int y)
{
	// 0:��
	if (m_stage[y][x] == 0)
	{
	}
	// 4:�e���ˊJ�n�ʒu
	else if (m_stage[y][x] == 4)
	{
		m_verX = 1;
		m_verY = 0;
		draw::MyDrawRectRotaGraph(kVariable::DrawPosition + (x * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			(y * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			m_verX * 32, m_verY * 32,
			32, 32,
			kStageSize, 0.0f,
			m_handleWall, true, false);

	}
	// 5:�c��񂾂瑦������
	else if (m_stage[y][x] == 5)
	{
		if (m_gimmickFrame < m_shrink)
		{
			m_verX = 3;
			m_verY = 0;
			m_sizeGimmick = kStageSize;
		}
		if (m_gimmickFrame > m_inflate)
		{
			m_verX = 2;
			m_verY = 0;
			m_sizeGimmick = kStageSize + 4.0f;
		}
		draw::MyDrawRectRotaGraph(kVariable::DrawPosition + (x * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			(y * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			m_verX * 32, m_verY * 32,
			32, 32,
			m_sizeGimmick, 0.0f,
			m_handleWall, true, false);
	}
	// 6:��������
	else if (m_stage[y][x] == 6)
	{
		m_verX = 13;
		m_verY = 13;
		draw::MyDrawRectRotaGraph(kVariable::DrawPosition + (x * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			(y * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			m_verX * 16, m_verY * 16,
			16, 16,
			4.2f, 0.0f,
			m_handleTrap, true, false);
	}
	// 7:���t���[����ɐj���o�ăQ�[���I�[�o�[�ɂȂ锻��
	else if (m_stage[y][x] == 7)
	{
		m_verX = 0;
		m_verY = 0;
		draw::MyDrawRectRotaGraph(kVariable::DrawPosition + (x * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			(y * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			m_verX * 32, m_verY * 32,
			32, 32,
			kStageSize, 0.0f,
			m_handleWall, true, false);
		needleDraw(x, y);
	}
	// 8:�S�[��
	else if (m_stage[y][x] == 8)
	{
		// �`�惂�[�V�����t���[��
		if (m_GoalFrame < m_drawGoalFirst)
		{
			m_idxGoalX = 0;
			m_idxGoalY = 0;
		}
		if (m_GoalFrame > m_drawGoalSecond)
		{
			m_idxGoalX = 1;
			m_idxGoalY = 0;
		}
		draw::MyDrawRectRotaGraph(kVariable::DrawPosition + (x * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			(y * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			m_idxGoalX * 40, m_idxGoalY * 40,
			40, 40,
			1.7f, 0.0f,
			m_handleGoal, true, false);
		// �p�[�e�B�N��
		particle(kVariable::DrawPosition + (x * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			(y * kVariable::DrawWidth) + (kVariable::DrawWidth / 2));
		
	}
	// 9:��
	else if (m_stage[y][x] == 9)
	{
		m_verX = 4;
		m_verY = 0;
		draw::MyDrawRectRotaGraph(kVariable::DrawPosition + (x * kVariable::DrawWidth) + (kVariable::DrawWidth / 2), 
			(y * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			m_verX * 32, m_verY * 32,
			32, 32,
			kStageSize, 0.0f,
			m_handleWall, true, false);

	}
}

void Stage::needleDraw(int x, int y)
{
	// �E
	if (m_stage[y][x + 1] == 0)
	{
		draw::MyDrawRectRotaGraph(kVariable::DrawPosition + ((x + 1) * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			(y * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			0, 0,
			40, 40,
			kNeedleSize, PI / 2,
			m_handleSmallNeedle, true, false);
	}
	// ��
	if (m_stage[y][x - 1] == 0)
	{
		draw::MyDrawRectRotaGraph(kVariable::DrawPosition + ((x - 1) * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			(y * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			0, 0,
			40, 40,
			kNeedleSize, PI / -2,
			m_handleSmallNeedle, true, false);
	}
	// ��
	if (m_stage[y - 1][x] == 0)
	{
		draw::MyDrawRectRotaGraph(kVariable::DrawPosition + (x * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			((y - 1) * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			0, 0,
			40, 40,
			kNeedleSize, 0.0f,
			m_handleSmallNeedle, true, false);
	}
	// ��
	if (m_stage[y + 1][x] == 0)
	{
		draw::MyDrawRectRotaGraph(kVariable::DrawPosition + (x * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			((y + 1) * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			0, 0,
			40, 40,
			kNeedleSize, PI / 1,
			m_handleSmallNeedle, true, false);
	}
}

void Stage::particle(int x, int y)
{
	for (auto& pParticle : m_particle)
	{
		if (!pParticle->isExist())	continue;
		pParticle->update();
	}
	m_auraFrame--;
	if (m_auraFrame <= 0)
	{
		int count = 0;
		// �~�󂩂璆�S��
		for (auto& pParticle : m_particle)
		{
			if (pParticle->isExist())  continue;

			float randSin = static_cast<float>(GetRand(360)) / 360.0f;// �p�x
			randSin *= DX_TWO_PI_F;
			float randSpeed = static_cast<float>(GetRand(60)) / 10.0f + 1.0f;// �X�s�[�h

			Vec2 pos;// ���W
			float dist = static_cast<float>(50 + GetRand(32));// �p�x
			pos.x = x + cosf(randSin) * dist;
			pos.y = y + sinf(randSin) * dist;

			Vec2 vec;// �ړ�
			vec.x = -cosf(randSin) * randSpeed;
			vec.y = -sinf(randSin) * randSpeed;

			pParticle->start(pos);
			pParticle->setVec(vec);
			pParticle->setRadius(2.0f);
			pParticle->setColor(kColor::Yellow);
			pParticle->setGravity(0.0f);
			pParticle->setAlphaDec(16);
			pParticle->setRadiusAcc(-0.05f);

			count++;
			if (count >= 10)
			{
				break;
			}
		}
		m_auraFrame = kParticle::AuraInterval;
	}
	
}

void Stage::drawParticle()
{
	for (auto& pParticle : m_particle)
	{
		if (!pParticle->isExist())  continue;
		pParticle->draw();
	}
}