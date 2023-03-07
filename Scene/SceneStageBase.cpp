#include "SceneStageBase.h"
#include "SceneSelect.h"
#include "../Util/GameManager.h"
#include "../Object/Back.h"
#include "../Object/Shot.h"
#include "../Util/common.h"
#include <cassert>

namespace
{
	// 音量
	constexpr int kVolumeBgm = 100;		// bgm
	constexpr int kVolumeDeath = 150;	// 死亡音

	constexpr float kQuakeFrame = 20.0f;// ブレるフレーム
	constexpr int kQuakeTime = 60;	// ブレ続ける時間
}

SceneStageBase::SceneStageBase() :
	m_posX(0),
	m_posY(0),
	m_frameX(0),
	m_frameY(0),
	m_shotPosX(0), m_shotPosY(0),
	m_shotPosX2(0), m_shotPosY2(0),
	m_shotPosX3(0), m_shotPosY3(0),
	m_shotPosX4(0), m_shotPosY4(0),
	m_shotPosX5(0), m_shotPosY5(0),
	m_shotPosX6(0), m_shotPosY6(0),
	m_colShotX(0), m_colShotY(0),
	m_colShotX2(0), m_colShotY2(0),
	m_colShotX3(0), m_colShotY3(0),
	m_colShotX4(0), m_colShotY4(0),
	m_colShotX5(0), m_colShotY5(0),
	m_colShotX6(0), m_colShotY6(0),
	m_size(0),
	m_frameCountShot(0),
	m_screenHandle(0),
	m_quakeX(0.0f),
	m_quakeTime(0),
	m_backGroundSound(0),
	m_burnSound(0),
	m_needleSound(0),
	m_inflateSound(0),
	m_arrowSound(0),
	m_volumeBgm(0),
	m_arrowTrap(false),
	m_isAllocation(false),
	m_pushHelp(false),
	m_inShot(false),
	m_playSound(false),
	m_deathSound(false)
{
	m_pManager = new GameManager;
	m_pBack = new Back;
	m_pShot = new Shot;
}

SceneStageBase::~SceneStageBase()
{
	delete m_pManager;
	delete m_pBack;
	delete m_pShot;
}

void SceneStageBase::init()
{
	playerInit();
	stageInit();

	/*m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
		m_stage, kVariable::StageWidth, kVariable::StageWidth);*/

	bool isEnableShot = m_stageSelectNumTest == 16 || 
		m_stageSelectNumTest == 17 || m_stageSelectNumTest == 18 ||
		m_stageSelectNumTest == 19 || m_stageSelectNumTest == 20;

	if (isEnableShot)
	{
		m_inShot = true;
	}
	else if (!isEnableShot)
	{
		m_inShot = false;
	}

	if (m_inShot)
	{
		shotInit();
		
	}
	m_size = kVariable::DrawWidth;
	m_pBack->init();
	m_pShot->init();

	// スクリーン
	int ScreenW;	// 幅
	int ScreenH;	// 高さ
	int ScreenBit;	// ビット数
	GetScreenState(&ScreenW, &ScreenH, &ScreenBit);// 幅、高さ取得

	m_screenHandle = MakeScreen(ScreenW, ScreenH);// 加工用画面
	assert(m_screenHandle >= 0);// 作れているか確認
	m_backGroundSound = LoadSoundMem("sound/stageBgm.mp3");
	m_burnSound = LoadSoundMem("sound/burnSound.mp3");
	m_needleSound = LoadSoundMem("sound/damegeSound.mp3");
	m_inflateSound = LoadSoundMem("sound/inflate.mp3");
	m_arrowSound = LoadSoundMem("sound/arrowSound.mp3");
	m_volumeBgm = 100;
	
	m_frameCountShot = 60;
	m_isAllocation = false;
	m_pushHelp = false;
	m_playSound = false;
	m_deathSound = false;
}

void SceneStageBase::end()
{
	m_pManager->end();
	m_pBack->end();
	m_pShot->end();
	DeleteGraph(m_screenHandle);
	DeleteSoundMem(m_backGroundSound);
}

SceneBase* SceneStageBase::update()
{
	//ChangeVolumeSoundMem(m_volume, m_backGroundSound);

	SceneBase* pScene = updateBefore();

	updateGame();

	// BGM再生
	if (!m_playSound)
	{
		PlaySoundMem(m_backGroundSound, DX_PLAYTYPE_BACK, true);
		m_playSound = true;
	}
	// BGM流れなくなったらループするようにする
	if (CheckSoundMem(m_backGroundSound) == 0)
	{
		m_playSound = false;
	}
	if (m_pManager->GameClear)
	{
		StopSoundMem(m_backGroundSound);
		m_playSound = true;
	}

	if (m_inShot)
	{
		m_frameCountShot--;
		if (m_frameCountShot <= 0)
		{
			shotInit();
			m_frameCountShot = 60;
		}
		updateShot();
		collisionShot();
	}

	if (m_pManager->GameOver && !m_isAllocation)
	{
		m_quakeX = kQuakeFrame;
		m_quakeTime = kQuakeTime;
		m_isAllocation = true;
	}

	if (m_quakeTime > 0 && m_isAllocation)
	{
		m_quakeX = -m_quakeX;
		m_quakeX *= 0.95f;
		--m_quakeTime;
	}
	else
	{
		m_quakeX = 0;
	}

	deathSound();

	if (!isFading())
	{
		// フェードアウト開始
		//if (m_pManager->GameClear)				startFadeOut();
		// クリアポーズ画面の項目処理
		if (m_pManager->GameClear && m_pManager->GetPushPause() == 1)				startFadeOut();// ポーズ画面の項目①
		if (m_pManager->GameClear && m_pManager->GetPushPause() == 2)				startFadeOut();// ポーズ画面の項目②
		if (m_pManager->GameClear && m_pManager->GetPushPause() == 3)				startFadeOut();// ポーズ画面の項目③

		if (m_pManager->GameOver && m_quakeTime == 0)				startFadeOut();// ゲームオーバー
		if (m_pManager->GetPushPause() == 1 && !m_pManager->GameClear)	startFadeOut();// ポーズ画面の項目①, 仮の条件付き
		if (m_pManager->GetPushPause() == 2)	startFadeOut();// ポーズ画面の項目②
	}

	return pScene;
}

void SceneStageBase::draw()
{
	// 加工用スクリーンセット
	SetDrawScreen(m_screenHandle);

	m_pBack->draw();

	if (m_inShot)
	{
		drawShot();
	}

	m_pManager->draw();
	drawGuide();

	SetDrawScreen(DX_SCREEN_BACK);
	DrawGraph(static_cast<int>(m_quakeX), 0, m_screenHandle, false);


	//printfDx("m_quakeTime%d\n", m_quakeTime);

	SceneBase::drawFade();
}

SceneBase* SceneStageBase::updateBefore()
{
	// フェード処理
	if (isFading())
	{
		bool isOut = isFadingOut();
		SceneBase::updateFade(m_backGroundSound);
		// フェードアウト終了時にシーン切り替え
		// ステージ20の処理
		// セレクト画面へ
		if (!isFading() && isOut &&
			m_pManager->GetPushPause() == 1 && m_pManager->GameClear &&
			m_stageSelectNumTest == 20)		return (new SceneSelect);

		// リトライ
		if (!isFading() && isOut &&
			m_pManager->GetPushPause() == 2 && m_pManager->GameClear &&
			m_stageSelectNumTest == 20)		return(new SceneStageBase);

		// 次のステージ
		if (!isFading() && isOut &&
			m_pManager->GetPushPause() == 1 && m_pManager->GameClear)
		{
			m_stageSelectNumTest++;
			if (m_stageSelectNumTest > 20)
			{
				m_stageSelectNumTest = 20;
			}
			return(new SceneStageBase);
		}
		// セレクト画面へ
		if (!isFading() && isOut &&
			m_pManager->GetPushPause() == 2 && m_pManager->GameClear)		return (new SceneSelect);
		// リトライ
		if (!isFading() && isOut &&
			m_pManager->GetPushPause() == 3 && m_pManager->GameClear)		return(new SceneStageBase);

		// リタイア
		if (!isFading() && isOut &&
			(m_pManager->GetPushPause() == 1 && !m_pManager->GameClear))	return (new SceneSelect);
		// リスタート
		if (!isFading() && isOut &&
			(m_pManager->GetPushPause() == 2 || m_pManager->GameOver))		return(new SceneStageBase);
	}

	return this;
}

void SceneStageBase::playerInit()
{
	if (m_stageSelectNumTest == 1 || m_stageSelectNumTest == 3 ||
		m_stageSelectNumTest == 10 || m_stageSelectNumTest == 12)
	{
		m_posX = 1;
		m_posY = 12;

		m_frameX = 68;
		m_frameY = 816;
	}
	if (m_stageSelectNumTest == 2)
	{
		m_posX = 1;
		m_posY = 2;

		m_frameX = 68;
		m_frameY = 136;
	}
	if (m_stageSelectNumTest == 4)
	{
		m_posX = 6;
		m_posY = 6;

		m_frameX = 408;
		m_frameY = 408;
	}
	if (m_stageSelectNumTest == 5 || m_stageSelectNumTest == 9 ||
		m_stageSelectNumTest == 15)
	{
		m_posX = 1;
		m_posY = 1;

		m_frameX = 68;
		m_frameY = 68;
	}
	if (m_stageSelectNumTest == 6 || m_stageSelectNumTest == 16)
	{
		m_posX = 11;
		m_posY = 12;

		m_frameX = 748;
		m_frameY = 816;
	}
	if (m_stageSelectNumTest == 7)
	{
		m_posX = 10;
		m_posY = 12;

		m_frameX = 680;
		m_frameY = 816;
	}
	if (m_stageSelectNumTest == 8 || m_stageSelectNumTest == 11)
	{
		m_posX = 11;
		m_posY = 1;

		m_frameX = 748;
		m_frameY = 68;
	}
	if (m_stageSelectNumTest == 13)
	{
		m_posX = 1;
		m_posY = 6;

		m_frameX = 68;
		m_frameY = 408;
	}
	if (m_stageSelectNumTest == 14)
	{
		m_posX = 6;
		m_posY = 7;

		m_frameX = 408;
		m_frameY = 476;
	}
	if (m_stageSelectNumTest == 17)
	{
		m_posX = 10;
		m_posY = 1;

		m_frameX = 680;
		m_frameY = 68;
	}
	if (m_stageSelectNumTest == 18)
	{
		m_posX = 11;
		m_posY = 7;

		m_frameX = 748;
		m_frameY = 476;
	}
	if (m_stageSelectNumTest == 19)
	{
		m_posX = 6;
		m_posY = 2;

		m_frameX = 408;
		m_frameY = 136;
	}
	if (m_stageSelectNumTest == 20)
	{
		m_posX = 6;
		m_posY = 12;

		m_frameX = 408;
		m_frameY = 816;
	}
}

void SceneStageBase::stageInit()
{
	// ステージ選択
	if (m_stageSelectNumTest == 1) 
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage1, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (m_stageSelectNumTest == 2)
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage2, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (m_stageSelectNumTest == 3)
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage3, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (m_stageSelectNumTest == 4)
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage4, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (m_stageSelectNumTest == 5)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage5, kVariable::StageWidth, kVariable::StageWidth);
	}

	if (m_stageSelectNumTest == 6)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage6, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (m_stageSelectNumTest == 7)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage7, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (m_stageSelectNumTest == 8)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage8, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (m_stageSelectNumTest == 9)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage9, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (m_stageSelectNumTest == 10)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage10, kVariable::StageWidth, kVariable::StageWidth);
	}

	if (m_stageSelectNumTest == 11)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage11, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (m_stageSelectNumTest == 12)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage12, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (m_stageSelectNumTest == 13)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage13, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (m_stageSelectNumTest == 14)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage14, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (m_stageSelectNumTest == 15)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage15, kVariable::StageWidth, kVariable::StageWidth);
	}

	if (m_stageSelectNumTest == 16)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage16, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (m_stageSelectNumTest == 17)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage17, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (m_stageSelectNumTest == 18)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage18, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (m_stageSelectNumTest == 19)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage19, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (m_stageSelectNumTest == 20)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage20, kVariable::StageWidth, kVariable::StageWidth);
	}
}

void SceneStageBase::shotInit()
{
	if (m_stageSelectNumTest == 16)
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
	if (m_stageSelectNumTest == 17)
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
	if (m_stageSelectNumTest == 18)
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
		m_colShotX6 = kVariable::DrawPosition + 340;
	}
	if (m_stageSelectNumTest == 19)
	{
		// 弾座標の初期化
		m_shotPosX = kVariable::DrawPosition + 748;
		m_shotPosY = 476;
		m_shotPosX2 = kVariable::DrawPosition + 68;
		m_shotPosY2 = 204;
		m_shotPosX3 = kVariable::DrawPosition + 884;
		m_shotPosY3 = 884;

		// 弾が消える判定
		m_colShotY = 884;
		m_colShotX2 = kVariable::DrawPosition + 204;
		m_colShotY3 = 476;
	}
	if (m_stageSelectNumTest == 20)
	{
		// 弾座標の初期化
		m_shotPosX = kVariable::DrawPosition + 340;
		m_shotPosY = 340;
		m_shotPosX2 = kVariable::DrawPosition + 612;
		m_shotPosY2 = 476;
		m_shotPosX3 = kVariable::DrawPosition + 748;
		m_shotPosY3 = 544;
		m_shotPosX4 = kVariable::DrawPosition + 68;
		m_shotPosY4 = 340;

		// 弾が消える判定
		m_colShotY = 748;
		m_colShotX2 = kVariable::DrawPosition + 408;
		m_colShotX3 = kVariable::DrawPosition + 952;
		m_colShotY4 = 0;
	}
}

void SceneStageBase::updateGame()
{
	if (m_quakeTime == 0)
	{
		if (m_inShot)
		{
			m_pManager->updateInShot(m_frameX, m_frameY);
		}
		else
		{
			m_pManager->updateNoShot();

		}
	}
	else
	{
		m_pManager->GameOverMotion();
	}
	if (m_stageSelectNumTest != 1)
	{
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
	}
}

void SceneStageBase::updateShot()
{
	if (m_quakeTime == 0)
	{
		if (m_stageSelectNumTest == 16)
		{
			m_pShot->shotUp(m_shotPosY, m_colShotY);
			m_pShot->shotRight(m_shotPosX2, m_colShotX2);
			m_pShot->shotBottom(m_shotPosY3, m_colShotY3);
			m_pShot->shotLeft(m_shotPosX4, m_colShotX4);
			m_pShot->shotRight2(m_shotPosX5, m_colShotX5);
		}
		if (m_stageSelectNumTest == 17)
		{
			m_pShot->shotLeft(m_shotPosX, m_colShotX);
			m_pShot->shotLeft2(m_shotPosX2, m_colShotX2);
			m_pShot->shotRight(m_shotPosX3, m_colShotX3);
			m_pShot->shotBottom(m_shotPosY4, m_colShotY4);
		}
		if (m_stageSelectNumTest == 18)
		{
			m_pShot->shotRight(m_shotPosX, m_colShotX);
			m_pShot->shotUp(m_shotPosY2, m_colShotY2);
			m_pShot->shotBottom(m_shotPosY3, m_colShotY3);
			m_pShot->shotLeft(m_shotPosX4, m_colShotX4);
			m_pShot->shotBottom2(m_shotPosY5, m_colShotY5);
			m_pShot->shotLeft2(m_shotPosX6, m_colShotX6);
		}
		if (m_stageSelectNumTest == 19)
		{
			m_pShot->shotBottom(m_shotPosY, m_colShotY);
			m_pShot->shotRight(m_shotPosX2, m_colShotX2);
			m_pShot->shotUp(m_shotPosY3, m_colShotY3);
		}
		if (m_stageSelectNumTest == 20)
		{
			m_pShot->shotBottom(m_shotPosY, m_colShotY);
			m_pShot->shotLeft(m_shotPosX2, m_colShotX2);
			m_pShot->shotRight(m_shotPosX3, m_colShotX3);
			m_pShot->shotUp(m_shotPosY4, m_colShotY4);
		}
	}
}

void SceneStageBase::drawGuide()
{
	bool isStage2_5 = m_stageSelectNumTest == 2 ||
		m_stageSelectNumTest == 3 ||
		m_stageSelectNumTest == 4 ||
		m_stageSelectNumTest == 5;

	bool isStage6And10 = m_stageSelectNumTest == 6 ||
		m_stageSelectNumTest == 10;

	bool isStage7_9 = m_stageSelectNumTest == 7 ||
		m_stageSelectNumTest == 8 ||
		m_stageSelectNumTest == 9;

	bool isStage11 = m_stageSelectNumTest == 11;

	bool isStage12_15 = m_stageSelectNumTest == 12 ||
		m_stageSelectNumTest == 13 ||
		m_stageSelectNumTest == 14 ||
		m_stageSelectNumTest == 15;

	bool isStage16 = m_stageSelectNumTest == 16;

	bool isStage17_20 = m_stageSelectNumTest == 17 ||
		m_stageSelectNumTest == 18 ||
		m_stageSelectNumTest == 19 ||
		m_stageSelectNumTest == 20;


	if (m_stageSelectNumTest == 1)
	{
		m_pBack->drawMenuGuide();
	}
	if (m_stageSelectNumTest != 1)
	{
		if (!m_pushHelp)  m_pBack->drawHelp();
	}
	if (m_pushHelp)
	{
		if (isStage2_5)
		{
			if (m_pushHelp)		m_pBack->drawExplan2_5();
		}
		if (isStage6And10)
		{
			if (m_pushHelp)		m_pBack->drawExplan6And10();
		}
		if (isStage7_9)
		{
			if (m_pushHelp)		m_pBack->drawExplan7_9();
		}
		if (isStage11)
		{
			if (m_pushHelp)		m_pBack->drawExplan11();
		}
		if (isStage12_15)
		{
			if (m_pushHelp)		m_pBack->drawExplan12_15();
		}
		if (isStage16)
		{
			if (m_pushHelp)		m_pBack->drawExplan16();
		}
		if (isStage17_20)
		{
			if (m_pushHelp)		m_pBack->drawExplan17_20();
		}
	}
}

void SceneStageBase::drawShot()
{
	if (m_stageSelectNumTest == 16)
	{
		if (!m_pManager->GetPushPauseOpen())
		{
			m_pShot->drawU(m_shotPosX, m_shotPosY);
			m_pShot->drawR(m_shotPosX2, m_shotPosY2);
			m_pShot->drawB(m_shotPosX3, m_shotPosY3);
			m_pShot->drawL(m_shotPosX4, m_shotPosY4);
			m_pShot->drawR2(m_shotPosX5, m_shotPosY5);
		}
	}
	if (m_stageSelectNumTest == 17)
	{
		if (!m_pManager->GetPushPauseOpen())
		{
			m_pShot->drawL(m_shotPosX, m_shotPosY);
			m_pShot->drawL2(m_shotPosX2, m_shotPosY2);
			m_pShot->drawR(m_shotPosX3, m_shotPosY3);
			m_pShot->drawB(m_shotPosX4, m_shotPosY4);
		}
	}
	if (m_stageSelectNumTest == 18)
	{
		if (!m_pManager->GetPushPauseOpen())
		{
			m_pShot->drawR(m_shotPosX, m_shotPosY);
			m_pShot->drawU(m_shotPosX2, m_shotPosY2);
			m_pShot->drawB(m_shotPosX3, m_shotPosY3);
			m_pShot->drawL(m_shotPosX4, m_shotPosY4);
			m_pShot->drawB2(m_shotPosX5, m_shotPosY5);
			m_pShot->drawL2(m_shotPosX6, m_shotPosY6);
		}
	}
	if (m_stageSelectNumTest == 19)
	{
		if (!m_pManager->GetPushPauseOpen())
		{
			m_pShot->drawB(m_shotPosX, m_shotPosY);
			m_pShot->drawR(m_shotPosX2, m_shotPosY2);
			m_pShot->drawU(m_shotPosX3, m_shotPosY3);
		}
	}
	if (m_stageSelectNumTest == 20)
	{
		if (!m_pManager->GetPushPauseOpen())
		{
			m_pShot->drawB(m_shotPosX, m_shotPosY);
			m_pShot->drawL(m_shotPosX2, m_shotPosY2);
			m_pShot->drawR(m_shotPosX3, m_shotPosY3);
			m_pShot->drawU(m_shotPosX4, m_shotPosY4);
		}
	}
}

void SceneStageBase::collisionShot()
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
		m_arrowTrap = true;
	}
}

void SceneStageBase::deathSound()
{
	if (!m_pManager->GameClear)
	{
		if (m_pManager->m_burnTrap)
		{
			if (!m_deathSound)
			{
				PlaySoundMem(m_burnSound, DX_PLAYTYPE_BACK, true);
			}
			m_deathSound = true;
		}
		if (m_pManager->m_needleTrap)
		{
			if (!m_deathSound)
			{
				PlaySoundMem(m_needleSound, DX_PLAYTYPE_BACK, true);
			}
			m_deathSound = true;
		}
		if (m_pManager->m_inflateTrap)
		{
			if (!m_deathSound)
			{
				PlaySoundMem(m_inflateSound, DX_PLAYTYPE_BACK, true);
			}
			m_deathSound = true;
		}
		if (m_arrowTrap)
		{
			if (!m_deathSound)
			{
				PlaySoundMem(m_arrowSound, DX_PLAYTYPE_BACK, true);
			}
			m_deathSound = true;
		}
	}
}
