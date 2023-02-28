#include "SceneStage20.h"
#include "SceneSelect.h"
#include "../Object/Back.h"
#include "../Object/Shot.h"
#include "../Util/GameManager.h"

SceneStage20::SceneStage20() :
	m_shotPosX(0), m_shotPosY(0),
	m_shotPosX2(0), m_shotPosY2(0),
	m_shotPosX3(0), m_shotPosY3(0),
	m_shotPosX4(0), m_shotPosY4(0),
	m_colShotY(0),
	m_colShotX2(0),
	m_colShotX3(0),
	m_colShotY4(0),
	m_size(0),
	m_frameCountShot(0),
	m_pushHelp(false)
{
	m_pShot = new Shot;
}

SceneStage20::~SceneStage20()
{
	delete m_pShot;
}

void SceneStage20::init()
{
	m_frameCount = 90;

	m_posX = 6;
	m_posY = 12;

	m_frameX = 408;
	m_frameY = 816;

	initShot();

	m_size = kVariable::DrawWidth;

	m_frameCountShot = 60;

	m_pShot->init();

	m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
		kStage::stage20, kVariable::StageWidth, kVariable::StageWidth);

	SceneStageBase::init();
}

void SceneStage20::initShot()
{
	// ’eÀ•W‚Ì‰Šú‰»
	m_shotPosX = kVariable::DrawPosition + 340;
	m_shotPosY = 340;
	m_shotPosX2 = kVariable::DrawPosition + 612;
	m_shotPosY2 = 476;
	m_shotPosX3 = kVariable::DrawPosition + 748;
	m_shotPosY3 = 544;
	m_shotPosX4 = kVariable::DrawPosition + 68;
	m_shotPosY4 = 340;

	// ’e‚ªÁ‚¦‚é”»’è
	m_colShotY = 748;
	m_colShotX2 = kVariable::DrawPosition + 408;
	m_colShotX3 = kVariable::DrawPosition + 952;
	m_colShotY4 = 0;
}

SceneBase* SceneStage20::CreateRetryStage() 
{
	return new SceneStage20; 
}

SceneBase* SceneStage20::update()
{
	SceneBase* pScene = updateBefore();

	//SceneStageBase::updateBefore();

	m_pManager->updateInShot(m_frameX, m_frameY);

	m_frameCountShot--;
	if (m_frameCountShot <= 0)
	{
		initShot();
		m_frameCountShot = 60;
	}

	m_pShot->shotBottom(m_shotPosY, m_colShotY);
	m_pShot->shotLeft(m_shotPosX2, m_colShotX2);
	m_pShot->shotRight(m_shotPosX3, m_colShotX3);
	m_pShot->shotUp(m_shotPosY4, m_colShotY4);

	collisionShot();

	if (Pad::isTrigger(PAD_INPUT_4))
	{
		if (m_pushHelp == false)
		{
			m_pushHelp = true;
		}
		else if (m_pushHelp == true)
		{
			m_pushHelp = false;
		}
	}

	SceneStageBase::update();

	return pScene;
}

void SceneStage20::draw()
{
	SceneStageBase::draw();

	if (!m_pManager->GetPushPauseOpen())
	{
		m_pShot->drawB(m_shotPosX, m_shotPosY);
		m_pShot->drawL(m_shotPosX2, m_shotPosY2);
		m_pShot->drawR(m_shotPosX3, m_shotPosY3);
		m_pShot->drawU(m_shotPosX4, m_shotPosY4);
	}

	if (m_pushHelp == false)
	{
		m_pBack->drawHelp();
	}

	if (m_pushHelp == true)
	{
		m_pBack->drawExplan17_20();
	}
}

void SceneStage20::collisionShot()
{
	// ’e‚Ì“–‚½‚è”»’è‚Ì^‹U
	bool col1 = m_shotPosX == m_frameX && m_shotPosY == m_frameY + m_size;
	bool col2 = m_shotPosX2 == m_frameX && m_shotPosY2 == m_frameY + m_size;
	bool col3 = m_shotPosX3 == m_frameX && m_shotPosY3 == m_frameY + m_size;
	bool col4 = m_shotPosX4 == m_frameX && m_shotPosY4 == m_frameY + m_size;

	if (col1 || col2 || col3 || col4)
	{
		m_pManager->GameOver = true;
		return;
	}
}
