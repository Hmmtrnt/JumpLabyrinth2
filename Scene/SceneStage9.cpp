#include "SceneStage9.h"
#include "SceneSelect.h"
#include "../Util/GameManager.h"
#include"../Object/Back.h"

SceneStage9::SceneStage9() :
	m_frameCount(0),
	m_posX(0),
	m_posY(0),
	m_frameX(0),
	m_frameY(0),
	m_pushHelp(false)
{
	m_pManager = new GameManager;
	m_pBack = new Back;
}

SceneStage9::~SceneStage9()
{
	delete m_pManager;
	delete m_pBack;
}

void SceneStage9::init()
{
	m_frameCount = 90; 
	m_posX = 1;
	m_posY = 1;
	
	m_frameX = 68;
	m_frameY = 68;

	m_pushHelp = false;

	m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
		kStage::stage9, kVariable::StageWidth, kVariable::StageWidth);
	m_pBack->init();
}

void SceneStage9::end()
{
	m_pManager->end();
	m_pBack->end();
}

SceneBase* SceneStage9::update()
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
			(m_pManager->GetPushPause() == 3 || m_pManager->GameOver))	return (new SceneStage9);
	}

	m_pManager->updateNoShot();

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

void SceneStage9::draw()
{
	m_pManager->draw();

	if (m_pushHelp == false)
	{
		m_pBack->drawHelp();
	}

	if (m_pushHelp == true)
	{
		m_pBack->drawExplan7_9();
	}

	SceneBase::drawFade();
}
