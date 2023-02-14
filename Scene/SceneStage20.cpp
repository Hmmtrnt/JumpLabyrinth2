#include "SceneStage20.h"
#include "SceneSelect.h"
#include "../Object/Back.h"
#include "../Object/Shot.h"
#include "../Util/GameManager.h"

SceneStage20::SceneStage20() :
	m_frameCount(0),
	m_posX(0), m_posY(0),
	m_frameX(0), m_frameY(0),
	m_size(0),
	m_frameCountShot(0)
{
	m_pManager = new GameManager;
	m_pShot = new Shot;
	m_pBack = new Back;
}

SceneStage20::~SceneStage20()
{
	delete m_pManager;
	delete m_pShot;
	delete m_pBack;
}

void SceneStage20::init()
{
	m_frameCount = 90;

	/*m_posX = 6;
	m_posY = 12;*/

	// デバッグ用座標
	m_posX = 0;
	m_posY = 6;

	/*m_frameX = 408;
	m_frameY = 816;*/

	// デバッグ用座標
	m_frameX = 0;
	m_frameY = 408;

	initShot();

	m_size = kVariable::DrawWidth;

	m_frameCountShot = 60;

	m_pManager->initManagerInShot(m_posX, m_posY, m_frameX, m_frameY,
		kStage::stage20, kVariable::StageWidth, kVariable::StageWidth);

	m_pBack->init();
}

void SceneStage20::initShot()
{
}

void SceneStage20::end()
{
	m_pManager->end();
	m_pBack->end();
}

SceneBase* SceneStage20::update()
{
	m_pManager->updateTest(m_frameX, m_frameY);

	m_frameCountShot--;
	if (m_frameCountShot <= 0)
	{
		initShot();
		m_frameCountShot = 60;
	}

	/*m_pShot->shotBottom(m_shotPosY, m_colShotY);
	m_pShot->shotRight(m_shotPosX2, m_colShotX2);
	m_pShot->shotUp(m_shotPosY3, m_colShotY3);*/

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
		return(new SceneStage20);
	}

	if (m_pManager->GameOver)
	{
		m_frameCount--;

		if (m_frameCount <= 0)
		{
			return(new SceneStage20);
		}
	}
	if (m_pManager->GameClear)
	{
		return(new SceneSelect);
	}

	return this;
}

void SceneStage20::draw()
{
	m_pBack->draw();

	/*m_pShot->drawB(m_shotPosX, m_shotPosY);
	m_pShot->drawR(m_shotPosX2, m_shotPosY2);
	m_pShot->drawU(m_shotPosX3, m_shotPosY3);*/

	m_pManager->drawInShot();
}

void SceneStage20::collisionShot()
{
}
