#include "SceneStage19.h"
#include "SceneSelect.h"
#include "../Object/Back.h"
#include "../Object/Shot.h"
#include "../Util/GameManager.h"

SceneStage19::SceneStage19() :
	m_frameCount(0),
	m_posX(0), m_posY(0),
	m_frameX(0), m_frameY(0),
	m_shotPosX(0), m_shotPosY(0),
	m_shotPosX2(0), m_shotPosY2(0),
	m_shotPosX3(0), m_shotPosY3(0),
	m_colShotY(0),
	m_colShotX2(0),
	m_colShotY3(0),
	m_size(0),
	m_frameCountShot(0)
{
	m_pManager = new GameManager;
	m_pShot = new Shot;
	m_pBack = new Back;
}

SceneStage19::~SceneStage19()
{
	delete m_pManager;
	delete m_pShot;
	delete m_pBack;
}

void SceneStage19::init()
{
	m_frameCount = 90;

	m_posX = 6;
	m_posY = 2;

	m_frameX = 408;
	m_frameY = 136;

	initShot();

	m_size = kVariable::DrawWidth;

	m_frameCountShot = 60;

	m_pManager->initManagerInShot(m_posX, m_posY, m_frameX, m_frameY,
		kStage::stage19, kVariable::StageWidth, kVariable::StageWidth);

	m_pBack->init();
}

void SceneStage19::initShot()
{
	// íeç¿ïWÇÃèâä˙âª
	m_shotPosX = kVariable::DrawPosition + 748;
	m_shotPosY = 476;
	m_shotPosX2 = kVariable::DrawPosition + 68;
	m_shotPosY2 = 204;
	m_shotPosX3 = kVariable::DrawPosition + 884;
	m_shotPosY3 = 884;

	// íeÇ™è¡Ç¶ÇÈîªíË
	m_colShotY = 884;
	m_colShotX2 = kVariable::DrawPosition + 204;
	m_colShotY3 = 476;
}

void SceneStage19::end()
{
	m_pManager->end();
	m_pBack->end();
}

SceneBase* SceneStage19::update()
{
	m_pManager->updateTest(m_frameX, m_frameY);

	m_frameCountShot--;
	if (m_frameCountShot <= 0)
	{
		initShot();
		m_frameCountShot = 60;
	}

	m_pShot->shotBottom(m_shotPosY, m_colShotY);
	m_pShot->shotRight(m_shotPosX2, m_colShotX2);
	m_pShot->shotUp(m_shotPosY3, m_colShotY3);

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
		return(new SceneStage19);
	}

	if (m_pManager->GameOver)
	{
		m_frameCount--;

		if (m_frameCount <= 0)
		{
			return(new SceneStage19);
		}
	}
	if (m_pManager->GameClear)
	{
		return(new SceneSelect);
	}

	return this;
}

void SceneStage19::draw()
{
	m_pBack->draw();

	m_pShot->drawB(m_shotPosX, m_shotPosY);
	m_pShot->drawR(m_shotPosX2, m_shotPosY2);
	m_pShot->drawU(m_shotPosX3, m_shotPosY3);

	m_pManager->drawInShot();
}

void SceneStage19::collisionShot()
{
	// íeÇÃìñÇΩÇËîªíËÇÃê^ãU
	bool col1 = m_shotPosX == m_frameX && m_shotPosY == m_frameY + m_size;
	bool col2 = m_shotPosX2 == m_frameX && m_shotPosY2 == m_frameY + m_size;
	bool col3 = m_shotPosX3 == m_frameX && m_shotPosY3 == m_frameY + m_size;

	if (col1 || col2 || col3)
	{
		m_pManager->GameOver = true;
		//printfDx("ìñÇΩÇ¡ÇΩÅ[!?\n");
		return;
	}
}
