#include "SceneDemo.h"
#include "SceneTitle.h"
#include "../Util/game.h"

namespace
{
	// テキスト
	const char* const kDemotext = "DEMO PLAY...";
}

SceneDemo::SceneDemo() :
	m_demoMoveHandle(0),
	m_fontHandle(0),
	m_waitingTime(0)
{
}

SceneDemo::~SceneDemo()
{
}

void SceneDemo::init()
{
	// 映像ファイル
	m_demoMoveHandle = draw::MyLoadGraph("Move/demoMove.mp4");
	m_fontHandle = CreateFontToHandle("Silver", 120, -1, 3);
	m_waitingTime = 60 * 23;
	PlayMovieToGraph(m_demoMoveHandle);// ムービーを再生状態
	SetMovieVolumeToGraph(8000, m_demoMoveHandle);
}

void SceneDemo::end()
{
	DeleteGraph(m_demoMoveHandle);
	DeleteFontToHandle(m_fontHandle);
}

SceneBase* SceneDemo::update()
{
	// 操作していない時間
	m_waitingTime--;
	// フェード処理
	if (isFading())
	{
		bool isOut = isFadingOut();
		SceneBase::updateFade(0);
		// フェードアウト終了時にシーン切り替え
		if (!isFading() && isOut)
		{
			return (new SceneTitle);
		}
	}
	if (!isFading())
	{
		if (Pad::isTrigger(PAD_INPUT_1) || Pad::isTrigger(PAD_INPUT_2) || Pad::isTrigger(PAD_INPUT_3) ||
			Pad::isTrigger(PAD_INPUT_4) || Pad::isTrigger(PAD_INPUT_UP) || Pad::isTrigger(PAD_INPUT_DOWN) ||
			Pad::isTrigger(PAD_INPUT_RIGHT) || Pad::isTrigger(PAD_INPUT_LEFT) || Pad::isTrigger(PAD_INPUT_5) ||
			Pad::isTrigger(PAD_INPUT_6) || Pad::isTrigger(PAD_INPUT_7) || Pad::isTrigger(PAD_INPUT_8))
		{
			// フェードアウト開始
			startFadeOut();
		}
		if (m_waitingTime <= 0)
		{
			// フェードアウト開始
			startFadeOut();
		}
	}
	return this;
}

void SceneDemo::draw()
{
	// 映像描画
	DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_demoMoveHandle, false);
	DrawStringToHandle(1450, 900, kDemotext, kColor::RedBlack, m_fontHandle);
	SceneBase::drawFade();
}