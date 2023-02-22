#include "SceneStage17.h"
#include "SceneSelect.h"
#include "../Object/Back.h"
#include "../Object/Shot.h"
#include "../Util/GameManager.h"

SceneStage17::SceneStage17() :
	m_frameCount(0),
	m_posX(0), m_posY(0),
	m_frameX(0), m_frameY(0),
	m_shotPosX(0), m_shotPosY(0),
	m_shotPosX2(0), m_shotPosY2(0),
	m_shotPosX3(0), m_shotPosY3(0),
	m_shotPosX4(0), m_shotPosY4(0),
	m_colShotX(0),
	m_colShotX2(0),
	m_colShotX3(0),
	m_colShotY4(0),
	m_size(0),
	m_frameCountShot(0),
	m_pushHelp(false)
{
	m_pManager = new GameManager;
	m_pShot = new Shot;
	m_pBack = new Back;
}

SceneStage17::~SceneStage17()
{
	delete m_pManager;
	delete m_pShot;
	delete m_pBack;
}

void SceneStage17::init()
{
	m_frameCount = 90;
	m_posX = 10;
	m_posY = 1;

	m_frameX = 680;
	m_frameY = 68;

	initShot();

	m_size = kVariable::DrawWidth;

	m_frameCountShot = 60;

	m_pManager->initManagerInShot(m_posX, m_posY, m_frameX, m_frameY,
		kStage::stage17, kVariable::StageWidth, kVariable::StageWidth);

	m_pBack->init();
}

void SceneStage17::initShot()
{
	// 弾座標の初期化
	m_shotPosX = kVariable::DrawPosition + 476;
	m_shotPosY = 68;
	m_shotPosX2 = kVariable::DrawPosition + 340;
	m_shotPosY2 = 476;
	m_shotPosX3 = kVariable::DrawPosition + 544;
	m_shotPosY3 = 680;
	m_shotPosX4 = kVariable::DrawPosition + 136;
	m_shotPosY4 = 612;

	// 弾の消える当たり判定
	m_colShotX = kVariable::DrawPosition + 68;
	m_colShotX2 = kVariable::DrawPosition + 0;
	m_colShotX3 = kVariable::DrawPosition + 816;
	m_colShotY4 = 952;
}

void SceneStage17::end()
{
	m_pManager->end();
	m_pBack->end();
}

SceneBase* SceneStage17::update()
{
	// フェード処理
	if (isFading())
	{
		bool isOut = isFadingOut();
		SceneBase::updateFade();
		// フェードアウト終了時にシーン切り替え
		if (!isFading() && isOut &&
			(m_pManager->GameClear || m_pManager->GetPushPause() == 2))	return (new SceneSelect);
		if (!isFading() && isOut &&
			(m_pManager->GetPushPause() == 3 || m_pManager->GameOver))	return (new SceneStage17);
	}

	m_pManager->updateInShot(m_frameX, m_frameY);

	m_frameCountShot--;
	if (m_frameCountShot <= 0)
	{
		initShot();
		m_frameCountShot = 60;
	}

	m_pShot->shotLeft(m_shotPosX, m_colShotX);
	m_pShot->shotLeft2(m_shotPosX2, m_colShotX2);
	m_pShot->shotRight(m_shotPosX3, m_colShotX3);
	m_pShot->shotBottom(m_shotPosY4, m_colShotY4);

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

	if (m_pManager->GetPushPause() == 1)
	{
	}

	if (!isFading())
	{
		// フェードアウト開始
		if (m_pManager->GameClear)				startFadeOut();
		if (m_pManager->GameOver)				startFadeOut();
		if (m_pManager->GetPushPause() == 2)	startFadeOut();
		if (m_pManager->GetPushPause() == 3)	startFadeOut();
	}

	return this;
}

void SceneStage17::draw()
{
	m_pBack->draw();
	if (!m_pManager->GetPushPauseOpen())
	{
		m_pShot->drawL(m_shotPosX, m_shotPosY);
		m_pShot->drawL2(m_shotPosX2, m_shotPosY2);
		m_pShot->drawR(m_shotPosX3, m_shotPosY3);
		m_pShot->drawB(m_shotPosX4, m_shotPosY4);
	}

	m_pManager->drawInShot();

	if (m_pushHelp == false)
	{
		m_pBack->drawHelp();
	}

	if (m_pushHelp == true)
	{
		m_pBack->drawExplan17_20();
	}

	SceneBase::drawFade();
}

void SceneStage17::collisionShot()
{
	// 弾の当たり判定の真偽
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
