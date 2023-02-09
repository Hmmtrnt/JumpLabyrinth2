#include "SceneStage16.h"
#include "SceneSelect.h"
#include "../Object/Back.h"
#include "../Object/Shot.h"
#include "../Util/GameManager.h"

SceneStage16::SceneStage16() :
	m_frameCount(0),
	m_posX(0),
	m_posY(0),
	m_frameX(0),
	m_frameY(0),
	m_shotPosX(0),
	m_shotPosY(0),
	m_shotPosX2(0),
	m_shotPosY2(0),
	m_colShotX(0),
	m_colShotY(0),
	m_colShotX2(0),
	m_colShotY2(0),
	m_frameCountShot(0)
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

	/*m_shotPosX = kVariable::DrawPositionX + 544;
	m_shotPosY = 884;

	m_colShotX = kVariable::DrawPositionX + 544;
	m_colShotY = 544;*/

	initShot();

	m_frameCountShot = 60;

	/*m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
		kStage::stage16, kVariable::StageWidth, kVariable::StageWidth);*/
	//m_pShot->init();
	m_pManager->initManagerInShot(m_posX, m_posY, m_frameX, m_frameY,
		kStage::stage16, kVariable::StageWidth, kVariable::StageWidth,
		m_shotPosX, m_shotPosY);
	m_pBack->init();
}

void SceneStage16::initShot()
{
	// ’e‚Ì‰Šú‰»
	m_shotPosX = kVariable::DrawPositionX + 544;
	m_shotPosY = 884;

	m_shotPosX2 = kVariable::DrawPositionX + 476;
	m_shotPosY2 = 68;

	// ’e‚Ì“–‚½‚è”»’è
	m_colShotX = kVariable::DrawPositionX + 544;
	m_colShotY = 544;

	m_colShotX2 = kVariable::DrawPositionX + 884;
	m_colShotY2 = 68;

	//m_colShotY = 486;
}

void SceneStage16::end()
{
	m_pManager->end();
	m_pBack->end();
}

SceneBase* SceneStage16::update()
{
	m_pManager->update();

	m_frameCountShot--;
	if (m_frameCountShot <= 0)
	{
		initShot();
		m_frameCountShot = 60;
	}

	m_pManager->updateShotUp(m_shotPosX, m_shotPosY, m_colShotY);

	//m_pManager->updateShotRight(m_shotPosX2, m_shotPosY2, 0/*kVariable::DrawWidth*/, m_colShotX2);

	collisionShot();

	//m_pShot->shotUp(m_shotPosY, m_colShotY);

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
	m_pManager->drawInShot(m_shotPosX, m_shotPosY);

	m_pManager->drawInShot(m_shotPosX2, m_shotPosY2);
	/*DrawFormatString(0, 0, kColor::White, "%d", m_frameX);
	DrawFormatString(0, 30, kColor::White, "%d", m_frameY);
	DrawFormatString(0, 90, kColor::White, "%d", m_shotPosX);
	DrawFormatString(0, 120, kColor::White, "%d", m_shotPosY);*/
}

void SceneStage16::collisionShot()
{
	if (m_shotPosX == m_frameX && m_shotPosY == m_frameY)
	{
		m_pManager->GameOver = true;
	}
}
