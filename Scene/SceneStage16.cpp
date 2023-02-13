#include "SceneStage16.h"
#include "SceneSelect.h"
#include "../Object/Back.h"
#include "../Object/Shot.h"
#include "../Util/GameManager.h"
#include "../Util/Pad.h"

SceneStage16::SceneStage16() :
	m_frameCount(0),
	m_posX(0), m_posY(0),
	m_frameX(0), m_frameY(0),
	m_shotPosX(0), m_shotPosY(0),
	m_shotPosX2(0), m_shotPosY2(0),
	m_shotPosX3(0), m_shotPosY3(0),
	m_shotPosX4(0), m_shotPosY4(0),
	m_shotPosX5(0), m_shotPosY5(0),
	m_colShotY(0),
	m_colShotX2(0),
	m_colShotY3(0),
	m_colShotX4(0),
	m_colShotX5(0),
	m_size(0),
	m_frameCountShot(0),
	m_pushPause(false)
{
	m_pManager = new GameManager;
	m_pShot = new Shot;
	m_pBack = new Back;
}

SceneStage16::~SceneStage16()
{
	delete m_pManager;
	delete m_pShot;
	delete m_pBack;
}

void SceneStage16::init()
{
	m_frameCount = 90;
	m_posX = 11;
	m_posY = 12;

	m_frameX = 748;
	m_frameY = 816;

	initShot();

	m_size = kVariable::DrawWidth;

	m_frameCountShot = 60;

	m_pushPause = false;

	m_pManager->initManagerInShot(m_posX, m_posY, m_frameX, m_frameY,
		kStage::stage16, kVariable::StageWidth, kVariable::StageWidth);

	m_pBack->init();
}

void SceneStage16::initShot()
{
	// ’eÀ•W‚Ì‰Šú‰»
	m_shotPosX = kVariable::DrawPosition + 544;
	m_shotPosY = 952;

	m_shotPosX2 = kVariable::DrawPosition + 476;
	m_shotPosY2 = 68;

	m_shotPosX3 = kVariable::DrawPosition + 68;
	m_shotPosY3 = 68;

	m_shotPosX4 = kVariable::DrawPosition + 408;
	m_shotPosY4 = 680;

	m_shotPosX5 = kVariable::DrawPosition + 68;
	m_shotPosY5 = 884;

	// ’e‚ÌÁ‚¦‚é“–‚½‚è”»’è
	m_colShotY = 544;

	m_colShotX2 = kVariable::DrawPosition + 884;

	m_colShotY3 = 476;

	m_colShotX4 = kVariable::DrawPosition + 68;

	m_colShotX5 = kVariable::DrawPosition + 408;
}

void SceneStage16::end()
{
	m_pManager->end();
	m_pBack->end();
}

SceneBase* SceneStage16::update()
{
	if (Pad::isTrigger(PAD_INPUT_R) == 1)
	{
		if (!m_pManager->GameOver)
		{
			if (m_pushPause == false)
			{
				m_pushPause = true;
				initShot();
			}
			else if (m_pushPause == true)
			{
				m_pushPause = false;
			}
		}
	}

	m_pManager->updateTest(m_frameX, m_frameY);

	m_frameCountShot--;
	if (m_frameCountShot <= 0)
	{
		initShot();
		m_frameCountShot = 60;
	}
	/*if (!m_pushPause)
	{*/
		m_pShot->shotUp(m_shotPosY, m_colShotY);
		m_pShot->shotRight(m_shotPosX2, m_colShotX2);
		m_pShot->shotBottom(m_shotPosY3, m_colShotY3);
		m_pShot->shotLeft(m_shotPosX4, m_colShotX4);
		m_pShot->shotRight2(m_shotPosX5, m_colShotX5);
	//}

	collisionShot();

	if (m_pManager->GetPushPause() == 1)
	{
	}
	else if (m_pManager->GetPushPause() == 2)
	{
		return(new SceneSelect);
	}
	else if (m_pManager->GetPushPause() == 3)
	{
		return(new SceneStage16);
	}

	if (m_pManager->GameOver)
	{
		m_frameCount--;

		if (m_frameCount <= 0)
		{
			return(new SceneSelect);
		}
	}
	if (m_pManager->GameClear)
	{
		return(new SceneSelect);
	}

	return this;
}

void SceneStage16::draw()
{
	m_pBack->draw();
	m_pShot->drawU(m_shotPosX, m_shotPosY);
	m_pShot->drawR(m_shotPosX2, m_shotPosY2);
	m_pShot->drawB(m_shotPosX3, m_shotPosY3);
	m_pShot->drawL(m_shotPosX4, m_shotPosY4);
	m_pShot->drawR2(m_shotPosX5, m_shotPosY5);
	m_pManager->drawInShot();
	m_pShot->drawTest();
}

void SceneStage16::collisionShot()
{
	// ’e‚Ì“–‚½‚è”»’è‚Ì^‹U
	bool col1 = m_shotPosX == m_frameX && m_shotPosY == m_frameY + m_size;
	bool col2 = m_shotPosX2 == m_frameX && m_shotPosY2 == m_frameY + m_size;
	bool col3 = m_shotPosX3 == m_frameX && m_shotPosY3 == m_frameY + m_size;
	bool col4 = m_shotPosX4 == m_frameX && m_shotPosY4 == m_frameY + m_size;
	bool col5 = m_shotPosX5 == m_frameX && m_shotPosY5 == m_frameY + m_size;

	// ‘S‘Ì‚Ì“–‚½‚è”»’è
	if (col1 || col2 || col3 || col4 || col5)
	{
		m_pManager->GameOver = true;
		return;
	}
}