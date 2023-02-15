#include "SceneStage8.h"
#include "SceneSelect.h"
#include "../Util/GameManager.h"

SceneStage8::SceneStage8() :
	m_frameCount(0),
	m_posX(0),
	m_posY(0),
	m_frameX(0),
	m_frameY(0)
{
	m_pManager = new GameManager;
}

SceneStage8::~SceneStage8()
{
	delete m_pManager;
}

void SceneStage8::init()
{
	m_frameCount = 90; 
	m_posX = 11;
	m_posY = 1;
	/*m_frameX = 440;
	m_frameY = 40;*/

	m_frameX = 748;
	m_frameY = 68;

	m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
		kStage::stage8, kVariable::StageWidth, kVariable::StageWidth);
}

void SceneStage8::end()
{
	m_pManager->end();
}

SceneBase* SceneStage8::update()
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
			(m_pManager->GetPushPause() == 3 || m_pManager->GameOver))	return (new SceneStage8);
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

void SceneStage8::draw()
{
	m_pManager->draw();

	SceneBase::drawFade();
}
