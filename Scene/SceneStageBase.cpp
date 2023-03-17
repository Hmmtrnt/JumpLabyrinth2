#include "SceneStageBase.h"
#include "SceneSelect.h"
#include "../Util/GameManager.h"
#include "../Object/Back.h"
#include "../Object/Shot.h"
#include "../Time/StageTimer.h"
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
	m_fontHandle(0),
	m_arrowTrap(false),
	m_isAllocation(false),
	m_pushHelp(false),
	m_inShot(false),
	m_deathSound(false)
{
	m_pManager = new GameManager;
	m_pBack = new Back;
	m_pShot = new Shot;
	m_pTimer = new StageTimer;
}

SceneStageBase::~SceneStageBase()
{
	delete m_pManager;
	delete m_pBack;
	delete m_pShot;
	delete m_pTimer;
}

void SceneStageBase::init()
{
	playerInit();
	stageInit();

	// ショットのあるステージかどうか
	bool isEnableShot = stageSelectNum == 16 || stageSelectNum == 17 || stageSelectNum == 18 ||
		stageSelectNum == 19 || stageSelectNum == 20;

	// 選択したステージにショットがあるかどうか
	if (isEnableShot)
	{
		m_inShot = true;
	}
	else if (!isEnableShot)
	{
		m_inShot = false;
	}

	// ショットが存在するなら初期化
	if (m_inShot)  shotInit();

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

	m_fontHandle = CreateFontToHandle("Silver", 100, -1, 3);
	
	m_frameCountShot = 60;

	m_isAllocation = false;
	m_pushHelp = false;
	m_deathSound = false;
	PlaySoundMem(m_backGroundSound, DX_PLAYTYPE_LOOP, true);

	m_pTimer->timeAssignment();
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
	// デバッグ用強制クリア
#ifdef _DEBUG
	if (Pad::isTrigger(PAD_INPUT_3))
	{
		m_pManager->GameClear = true;
	}
#else
#endif
	// シーン遷移
	SceneBase* pScene = updateBefore();
	// ゲームの全体処理
	updateGame();
	// ボタン表示時間
	m_pBack->update();

	// BGMストップ
	if (m_pManager->GameClear)	StopSoundMem(m_backGroundSound);

	// 一定時間たったら次の弾を打つ
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
	// ゲームオーバーの画面揺れ
	if (m_pManager->GameOver && !m_isAllocation)
	{
		m_quakeX = kQuakeFrame;
		m_quakeTime = kQuakeTime;
		m_isAllocation = true;
	}
	// 揺れている時間と揺れ方
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

	// ステージ内タイマー
	if (!m_pManager->GameClear && !m_pManager->GetPushPauseOpen())
	{
		m_pTimer->timerUpdate();
	}
	
	// 死亡音
	deathSound();

	if (!isFading())
	{
		// フェードアウト開始
		// クリアポーズ画面の項目処理
		if (m_pManager->GameClear && m_pManager->GetPushPause() == 1) startFadeOut();// ポーズ画面の項目①
		if (m_pManager->GameClear && m_pManager->GetPushPause() == 2) startFadeOut();// ポーズ画面の項目②
		if (m_pManager->GameClear && m_pManager->GetPushPause() == 3) startFadeOut();// ポーズ画面の項目③

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
	// ショット
	if (m_inShot)
	{
		drawShot();
	}

	m_pManager->draw();
	drawGuide();// ステージギミック説明

	SetDrawScreen(DX_SCREEN_BACK);
	DrawGraph(static_cast<int>(m_quakeX), 0, m_screenHandle, false);

	// 現在のステージ数
	DrawFormatStringToHandle(1500, 900, kColor::White, m_fontHandle, "%d/20 stage", stageSelectNum);

	printfDx("stageSelectNum = %d\n", stageSelectNum);

	// クリアにかかる時間
	if (!m_pManager->GameClear)
	{
		m_pTimer->drawTime(m_fontHandle);
	}
	else
	{
		m_pTimer->drawResult(m_fontHandle);
	}

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
			stageSelectNum == 20)		return (new SceneSelect);

		// リトライ
		if (!isFading() && isOut &&
			m_pManager->GetPushPause() == 2 && m_pManager->GameClear &&
			stageSelectNum == 20)		return(new SceneStageBase);

		// 次のステージ
		if (!isFading() && isOut &&
			m_pManager->GetPushPause() == 1 && m_pManager->GameClear)
		{
			stageSelectNum++;
			if (stageSelectNum > 20)
			{
				stageSelectNum = 20;
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
	// プレイヤーの各ステージの初期位置
	if (stageSelectNum == 1 || stageSelectNum == 3 ||
		stageSelectNum == 10 || stageSelectNum == 12)
	{
		m_posX = 1;
		m_posY = 12;

		m_frameX = 68;
		m_frameY = 816;
	}
	if (stageSelectNum == 2)
	{
		m_posX = 1;
		m_posY = 2;

		m_frameX = 68;
		m_frameY = 136;
	}
	if (stageSelectNum == 4)
	{
		m_posX = 6;
		m_posY = 6;

		m_frameX = 408;
		m_frameY = 408;
	}
	if (stageSelectNum == 5 || stageSelectNum == 9 ||
		stageSelectNum == 15)
	{
		m_posX = 1;
		m_posY = 1;

		m_frameX = 68;
		m_frameY = 68;
	}
	if (stageSelectNum == 6 || stageSelectNum == 16)
	{
		m_posX = 11;
		m_posY = 12;

		m_frameX = 748;
		m_frameY = 816;
	}
	if (stageSelectNum == 7)
	{
		m_posX = 10;
		m_posY = 12;

		m_frameX = 680;
		m_frameY = 816;
	}
	if (stageSelectNum == 8 || stageSelectNum == 11)
	{
		m_posX = 11;
		m_posY = 1;

		m_frameX = 748;
		m_frameY = 68;
	}
	if (stageSelectNum == 13)
	{
		m_posX = 1;
		m_posY = 6;

		m_frameX = 68;
		m_frameY = 408;
	}
	if (stageSelectNum == 14)
	{
		m_posX = 6;
		m_posY = 7;

		m_frameX = 408;
		m_frameY = 476;
	}
	if (stageSelectNum == 17)
	{
		m_posX = 10;
		m_posY = 1;

		m_frameX = 680;
		m_frameY = 68;
	}
	if (stageSelectNum == 18)
	{
		m_posX = 11;
		m_posY = 7;

		m_frameX = 748;
		m_frameY = 476;
	}
	if (stageSelectNum == 19)
	{
		m_posX = 6;
		m_posY = 2;

		m_frameX = 408;
		m_frameY = 136;
	}
	if (stageSelectNum == 20)
	{
		m_posX = 6;
		m_posY = 12;

		m_frameX = 408;
		m_frameY = 816;
	}
}

void SceneStageBase::stageInit()
{
	// 各ステージの初期化
	if (stageSelectNum == 1) 
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage1, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (stageSelectNum == 2)
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage2, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (stageSelectNum == 3)
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage3, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (stageSelectNum == 4)
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage4, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (stageSelectNum == 5)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage5, kVariable::StageWidth, kVariable::StageWidth);
	}

	if (stageSelectNum == 6)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage6, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (stageSelectNum == 7)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage7, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (stageSelectNum == 8)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage8, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (stageSelectNum == 9)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage9, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (stageSelectNum == 10)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage10, kVariable::StageWidth, kVariable::StageWidth);
	}

	if (stageSelectNum == 11)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage11, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (stageSelectNum == 12)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage12, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (stageSelectNum == 13)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage13, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (stageSelectNum == 14)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage14, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (stageSelectNum == 15)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage15, kVariable::StageWidth, kVariable::StageWidth);
	}

	if (stageSelectNum == 16)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage16, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (stageSelectNum == 17)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage17, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (stageSelectNum == 18)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage18, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (stageSelectNum == 19)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage19, kVariable::StageWidth, kVariable::StageWidth);
	}
	if (stageSelectNum == 20)  	
	{
		m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
			kStage::stage20, kVariable::StageWidth, kVariable::StageWidth);
	}
}

void SceneStageBase::shotInit()
{
	// 各ステージのショットの初期化
	if (stageSelectNum == 16)
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
	if (stageSelectNum == 17)
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
	if (stageSelectNum == 18)
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
	if (stageSelectNum == 19)
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
	if (stageSelectNum == 20)
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
	// 画面揺れていなければ処理する
	if (m_quakeTime == 0)
	{
		m_pManager->update(m_frameX, m_frameY);
	}
	else
	{
		m_pManager->GameOverMotion();
	}
	// ステージ1以外, ギミック説明をするかどうか
	if (stageSelectNum != 1)
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
	// 各ステージのショットの更新
	if (m_quakeTime == 0)
	{
		if (stageSelectNum == 16)
		{
			m_pShot->shotUp(m_shotPosY, m_colShotY);
			m_pShot->shotRight(m_shotPosX2, m_colShotX2);
			m_pShot->shotBottom(m_shotPosY3, m_colShotY3);
			m_pShot->shotLeft(m_shotPosX4, m_colShotX4);
			m_pShot->shotRight2(m_shotPosX5, m_colShotX5);
		}
		if (stageSelectNum == 17)
		{
			m_pShot->shotLeft(m_shotPosX, m_colShotX);
			m_pShot->shotLeft2(m_shotPosX2, m_colShotX2);
			m_pShot->shotRight(m_shotPosX3, m_colShotX3);
			m_pShot->shotBottom(m_shotPosY4, m_colShotY4);
		}
		if (stageSelectNum == 18)
		{
			m_pShot->shotRight(m_shotPosX, m_colShotX);
			m_pShot->shotUp(m_shotPosY2, m_colShotY2);
			m_pShot->shotBottom(m_shotPosY3, m_colShotY3);
			m_pShot->shotLeft(m_shotPosX4, m_colShotX4);
			m_pShot->shotBottom2(m_shotPosY5, m_colShotY5);
			m_pShot->shotLeft2(m_shotPosX6, m_colShotX6);
		}
		if (stageSelectNum == 19)
		{
			m_pShot->shotBottom(m_shotPosY, m_colShotY);
			m_pShot->shotRight(m_shotPosX2, m_colShotX2);
			m_pShot->shotUp(m_shotPosY3, m_colShotY3);
		}
		if (stageSelectNum == 20)
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
	bool isStage2_5 = stageSelectNum == 2 ||
		stageSelectNum == 3 ||
		stageSelectNum == 4 ||
		stageSelectNum == 5;

	bool isStage6And10 = stageSelectNum == 6 ||
		stageSelectNum == 10;

	bool isStage7_9 = stageSelectNum == 7 ||
		stageSelectNum == 8 ||
		stageSelectNum == 9;

	bool isStage11 = stageSelectNum == 11;

	bool isStage12_15 = stageSelectNum == 12 ||
		stageSelectNum == 13 ||
		stageSelectNum == 14 ||
		stageSelectNum == 15;

	bool isStage16 = stageSelectNum == 16;

	bool isStage17_20 = stageSelectNum == 17 ||
		stageSelectNum == 18 ||
		stageSelectNum == 19 ||
		stageSelectNum == 20;

	// ステージギミックの説明描画
	if (stageSelectNum == 1)
	{
		m_pBack->drawTutorial();
		m_pBack->drawMenuGuide();
	}
	if (stageSelectNum != 1)
	{
		if (!m_pushHelp)  m_pBack->drawOpenGuide();
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
	if (stageSelectNum == 16)
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
	if (stageSelectNum == 17)
	{
		if (!m_pManager->GetPushPauseOpen())
		{
			m_pShot->drawL(m_shotPosX, m_shotPosY);
			m_pShot->drawL2(m_shotPosX2, m_shotPosY2);
			m_pShot->drawR(m_shotPosX3, m_shotPosY3);
			m_pShot->drawB(m_shotPosX4, m_shotPosY4);
		}
	}
	if (stageSelectNum == 18)
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
	if (stageSelectNum == 19)
	{
		if (!m_pManager->GetPushPauseOpen())
		{
			m_pShot->drawB(m_shotPosX, m_shotPosY);
			m_pShot->drawR(m_shotPosX2, m_shotPosY2);
			m_pShot->drawU(m_shotPosX3, m_shotPosY3);
		}
	}
	if (stageSelectNum == 20)
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
	// 引っかかったトラップによって音が変わる
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
