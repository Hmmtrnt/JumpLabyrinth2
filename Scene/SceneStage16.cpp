#include "SceneStage16.h"
#include "SceneSelect.h"
#include "ScenePause.h"
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
	m_pushPause(false),
	m_pushHelp(false)
{
	m_pManager = new GameManager;
	m_pShot = new Shot;
	m_pBack = new Back;
	m_pPause = new ScenePause;
}

SceneStage16::~SceneStage16()
{
	delete m_pManager;
	delete m_pShot;
	delete m_pBack;
	delete m_pPause;
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
	m_pPause->init();
}

void SceneStage16::initShot()
{
	// 弾座標の初期化
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

	// 弾の消える当たり判定
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
	m_pPause->end();
}

SceneBase* SceneStage16::update()
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
			(m_pManager->GetPushPause() == 3 || m_pManager->GameOver))	return (new SceneStage16);
	}

	m_pManager->updateInShot(m_frameX, m_frameY);

	m_frameCountShot--;
	if (m_frameCountShot <= 0)
	{
		initShot();
		m_frameCountShot = 60;
	}

	m_pShot->shotUp(m_shotPosY, m_colShotY);
	m_pShot->shotRight(m_shotPosX2, m_colShotX2);
	m_pShot->shotBottom(m_shotPosY3, m_colShotY3);
	m_pShot->shotLeft(m_shotPosX4, m_colShotX4);
	m_pShot->shotRight2(m_shotPosX5, m_colShotX5);
	
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

void SceneStage16::draw()
{
	m_pBack->draw();
	if (!m_pManager->GetPushPauseOpen())
	{
		m_pShot->drawU(m_shotPosX, m_shotPosY);
		m_pShot->drawR(m_shotPosX2, m_shotPosY2);
		m_pShot->drawB(m_shotPosX3, m_shotPosY3);
		m_pShot->drawL(m_shotPosX4, m_shotPosY4);
		m_pShot->drawR2(m_shotPosX5, m_shotPosY5);
	}
	
	m_pManager->drawInShot();

	if (!m_pushHelp)
	{
		m_pBack->drawHelp();
	}

	if (m_pushHelp)
	{
		m_pBack->drawExplan16();
	}

	SceneBase::drawFade();
}

void SceneStage16::collisionShot()
{
	// 弾の当たり判定の真偽
	bool col1 = m_shotPosX == m_frameX && m_shotPosY == m_frameY + m_size;
	bool col2 = m_shotPosX2 == m_frameX && m_shotPosY2 == m_frameY + m_size;
	bool col3 = m_shotPosX3 == m_frameX && m_shotPosY3 == m_frameY + m_size;
	bool col4 = m_shotPosX4 == m_frameX && m_shotPosY4 == m_frameY + m_size;
	bool col5 = m_shotPosX5 == m_frameX && m_shotPosY5 == m_frameY + m_size;

	// 全体の当たり判定
	if (col1 || col2 || col3 || col4 || col5)
	{
		m_pManager->GameOver = true;
		return;
	}
}