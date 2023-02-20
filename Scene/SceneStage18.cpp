#include "SceneStage18.h"
#include "SceneSelect.h"
#include "../Object/Back.h"
#include "../Object/Shot.h"
#include "../Util/GameManager.h"

SceneStage18::SceneStage18() :
	m_frameCount(0),
	m_posX(0), m_posY(0),
	m_frameX(0), m_frameY(0),
	m_shotPosX(0), m_shotPosY(0),
	m_shotPosX2(0), m_shotPosY2(0),
	m_shotPosX3(0), m_shotPosY3(0),
	m_shotPosX4(0), m_shotPosY4(0),
	m_shotPosX5(0), m_shotPosY5(0),
	m_shotPosX6(0), m_shotPosY6(0),
	m_colShotX(0),
	m_colShotY2(0),
	m_colShotY3(0),
	m_colShotX4(0),
	m_colShotY5(0),
	m_colShotX6(0),
	m_size(0),
	m_frameCountShot(0),
	m_pushHelp(false)
{
	m_pManager = new GameManager;
	m_pShot = new Shot;
	m_pBack = new Back;
}

SceneStage18::~SceneStage18()
{
	delete m_pManager;
	delete m_pShot;
	delete m_pBack;
}

void SceneStage18::init()
{
	m_frameCount = 90;
	m_posX = 11;
	m_posY = 7;

	m_frameX = 748;
	m_frameY = 476;

	initShot();

	m_size = kVariable::DrawWidth;

	m_frameCountShot = 60;

	m_pManager->initManagerInShot(m_posX, m_posY, m_frameX, m_frameY,
		kStage::stage18, kVariable::StageWidth, kVariable::StageWidth);

	m_pBack->init();
}

void SceneStage18::initShot()
{
	// 弾座標の初期化
	m_shotPosX = kVariable::DrawPosition + 544;
	m_shotPosY = 272;
	m_shotPosX2 = kVariable::DrawPosition + 884;
	m_shotPosY2 = 340;
	m_shotPosX3 = kVariable::DrawPosition + 272;
	m_shotPosY3 = 68;
	m_shotPosX4 = kVariable::DrawPosition + 204;
	m_shotPosY4 = 272;
	m_shotPosX5 = kVariable::DrawPosition + 272;
	m_shotPosY5 = 544;
	m_shotPosX6 = kVariable::DrawPosition + 544;
	m_shotPosY6 = 884;

	// 弾が消える判定
	m_colShotX = kVariable::DrawPosition + 952;
	m_colShotY2 = 0;
	m_colShotY3 = 272;
	m_colShotX4 = kVariable::DrawPosition + 0;
	m_colShotY5 = 680;
	m_colShotX6 = kVariable::DrawPosition + 204;
}

void SceneStage18::end()
{
	m_pManager->end();
	m_pBack->end();
}

SceneBase* SceneStage18::update()
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
			(m_pManager->GetPushPause() == 3 || m_pManager->GameOver))	return (new SceneStage18);
	}

	m_pManager->updateTest(m_frameX, m_frameY);

	m_frameCountShot--;
	if (m_frameCountShot <= 0)
	{
		initShot();
		m_frameCountShot = 60;
	}

	m_pShot->shotRight(m_shotPosX, m_colShotX);
	m_pShot->shotUp(m_shotPosY2, m_colShotY2);
	m_pShot->shotBottom(m_shotPosY3, m_colShotY3);
	m_pShot->shotLeft(m_shotPosX4, m_colShotX4);
	m_pShot->shotBottom2(m_shotPosY5, m_colShotY5);
	m_pShot->shotLeft2(m_shotPosX6, m_colShotX6);


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

void SceneStage18::draw()
{
	m_pBack->draw();

	m_pShot->drawR(m_shotPosX, m_shotPosY);
	m_pShot->drawU(m_shotPosX2, m_shotPosY2);
	m_pShot->drawB(m_shotPosX3, m_shotPosY3);
	m_pShot->drawL(m_shotPosX4, m_shotPosY4);
	m_pShot->drawB2(m_shotPosX5, m_shotPosY5);
	m_pShot->drawL2(m_shotPosX6, m_shotPosY6);

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

void SceneStage18::collisionShot()
{
	// 弾の当たり判定の真偽
	bool col1 = m_shotPosX == m_frameX && m_shotPosY == m_frameY + m_size;
	bool col2 = m_shotPosX2 == m_frameX && m_shotPosY2 == m_frameY + m_size;
	bool col3 = m_shotPosX3 == m_frameX && m_shotPosY3 == m_frameY + m_size;
	bool col4 = m_shotPosX4 == m_frameX && m_shotPosY4 == m_frameY + m_size;
	bool col5 = m_shotPosX5 == m_frameX && m_shotPosY5 == m_frameY + m_size;
	bool col6 = m_shotPosX6 == m_frameX && m_shotPosY6 == m_frameY + m_size;

	if (col1 || col2 || col3 || col4 || col5 || col6)
	{
		m_pManager->GameOver = true;
		//printfDx("当たったー!?\n");
		return;
	}
}
