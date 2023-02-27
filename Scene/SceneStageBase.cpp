#include "SceneStageBase.h"
#include "SceneSelect.h"
#include "../Util/GameManager.h"
#include "../Object/Back.h"

SceneStageBase::SceneStageBase() :
	m_frameCount(0),
	m_posX(0),
	m_posY(0),
	m_frameX(0),
	m_frameY(0)
{
	m_pManager = new GameManager;
	m_pBack = new Back;
}

SceneStageBase::~SceneStageBase()
{
	delete m_pManager;
	delete m_pBack;
}

void SceneStageBase::init()
{
	m_pBack->init();
}

void SceneStageBase::end()
{
	m_pManager->end();
	m_pBack->end();
}

SceneBase* SceneStageBase::update()
{
	// フェード処理
	//if (isFading())
	//{
	//	bool isOut = isFadingOut();
	//	SceneBase::updateFade();
	//	// フェードアウト終了時にシーン切り替え
	//	if (!isFading() && isOut &&
	//		(m_pManager->GetPushPause() == 2 || m_pManager->GameClear))	return (new SceneSelect);
	//	if (!isFading() && isOut &&
	//		(m_pManager->GetPushPause() == 3 || m_pManager->GameOver))	return (new SceneStage1);
	//}

	//m_pManager->updateNoShot();

	if (m_pManager->GetPushPause() == 1)
	{
	}

	if (!isFading())
	{
		// フェードアウト開始
		//if (m_pManager->GameClear)				startFadeOut();
		// クリアポーズ画面の項目処理
		if (m_pManager->GameClear && m_pManager->GetPushPause() == 1)				startFadeOut();// ポーズ画面の項目①
		if (m_pManager->GameClear && m_pManager->GetPushPause() == 2)				startFadeOut();// ポーズ画面の項目②
		if (m_pManager->GameClear && m_pManager->GetPushPause() == 3)				startFadeOut();// ポーズ画面の項目③

		if (m_pManager->GameOver)				startFadeOut();// ゲームオーバー
		if (m_pManager->GetPushPause() == 1)	startFadeOut();// ポーズ画面の項目①
		if (m_pManager->GetPushPause() == 2)	startFadeOut();// ポーズ画面の項目②
	}

	return this;
}

void SceneStageBase::draw()
{
	m_pBack->draw();
	m_pManager->draw();

	SceneBase::drawFade();
}
