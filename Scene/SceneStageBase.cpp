#include "SceneStageBase.h"
#include "SceneSelect.h"
#include "../Util/GameManager.h"
#include "../Object/Back.h"

SceneStageBase::SceneStageBase() :
	m_frameCount(0),
	m_posX(0),
	m_posY(0),
	m_frameX(0),
	m_frameY(0),
	m_backGroundSound(-1),
	m_playSound(false)
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
	m_backGroundSound = LoadSoundMem("sound/stageBgm.mp3");
	ChangeVolumeSoundMem(100, m_backGroundSound);
	m_playSound = false;
}

void SceneStageBase::end()
{
	m_pManager->end();
	m_pBack->end();
	DeleteSoundMem(m_backGroundSound);
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

	// BGM再生
	if (!m_playSound)
	{
		PlaySoundMem(m_backGroundSound, DX_PLAYTYPE_BACK, true);
		m_playSound = true;
	}
	

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
		if (m_pManager->GetPushPause() == 1 && !m_pManager->GameClear)	startFadeOut();// ポーズ画面の項目①, 仮の条件付き
		if (m_pManager->GetPushPause() == 2)	startFadeOut();// ポーズ画面の項目②
	}
	/*if (CheckSoundMem(m_backGroundSound) == 1)
	{
		PlaySoundMem(m_backGroundSound, DX_PLAYTYPE_BACK, true);
	}*/
	
	
	/*if (CheckSoundMem(m_backGroundSound) == 1)
	{
		printfDx("なっているよ\n");

	}
	else
	{
		printfDx("なってないよ\n");
	}*/

	return this;
}

void SceneStageBase::draw()
{
	m_pBack->draw();
	m_pManager->draw();

	SceneBase::drawFade();
}
