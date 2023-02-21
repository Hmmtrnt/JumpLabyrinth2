#include "SceneStage1.h"
#include "SceneSelect.h"
#include "../Util/GameManager.h"
#include"../Object/Back.h"

SceneStage1::SceneStage1() :
	m_frameCount(0),
	m_posX(0),
	m_posY(0),
	m_frameX(0),
	m_frameY(0)
{
	m_pManager = new GameManager;
	m_pBack = new Back;
}

SceneStage1::~SceneStage1()
{
	delete m_pManager;
	delete m_pBack;
}

void SceneStage1::init()
{
	m_frameCount = 90;
	m_posX = 1;
	m_posY = 12;

	m_frameX = 68;
	m_frameY = 816;

	m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY, 
						 kStage::stage1, kVariable::StageWidth, kVariable::StageWidth);
	m_pBack->init();
}

void SceneStage1::end()
{
	m_pManager->end();
	m_pBack->end();
}

SceneBase* SceneStage1::update()
{
	// フェード処理
	if (isFading())
	{
		bool isOut = isFadingOut();
		SceneBase::updateFade();
		// フェードアウト終了時にシーン切り替え
		if (!isFading() && isOut && 
			(m_pManager->GetPushPause() == 2 || m_pManager->GameClear))	return (new SceneSelect);
		if (!isFading() && isOut && 
			(m_pManager->GetPushPause() == 3 || m_pManager->GameOver))	return (new SceneStage1);
	}

	m_pManager->updateNoShot();

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

void SceneStage1::draw()
{
	m_pManager->draw();

	m_pBack->drawMenuGuide();

	SceneBase::drawFade();
}
