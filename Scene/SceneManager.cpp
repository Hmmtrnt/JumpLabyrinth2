#include <cassert>
#include "SceneManager.h"
#include "SceneTitle.h"
#include "SceneSelect.h"
#include "SceneStage1.h"
#include "SceneStage2.h"
#include "SceneStage3.h"
#include "SceneStage4.h"
#include "SceneStage5.h"
#include "SceneStage6.h"
#include "SceneStage7.h"
#include "SceneStage8.h"
#include "SceneStage9.h"
#include "SceneStage10.h"
#include "SceneStage11.h"
#include "SceneStage12.h"
#include "SceneStage13.h"
#include "SceneStage14.h"
#include "SceneStage15.h"
#include "SceneStage16.h"
#include "SceneStage17.h"
#include "SceneStage18.h"
#include "SceneStage19.h"
#include "SceneStage20.h"
#include "../Util/Pad.h"

SceneManager::SceneManager()
{
	m_pScene = nullptr;
}
// 初期化
void SceneManager::init()
{
#ifdef _DEBUG
	m_pScene = new SceneSelect;
#else
	m_pScene = new SceneTitle;
#endif
	m_pScene->init();
}
// 終了
void SceneManager::end()
{
	// 確認処理
	assert(m_pScene);
	if (!m_pScene)	return;

	m_pScene->end();
	delete m_pScene;
}
// 毎フレームの処理
void SceneManager::update()
{
	Pad::update();
	// 確認処理
	assert(m_pScene);
	if (!m_pScene)	return;
	// SceneBaseのupdate処理呼び出し
	SceneBase* pScene = m_pScene->update();
	if (pScene != m_pScene)
	{
		m_pScene->end();
		delete m_pScene;
		// 初期化
		m_pScene = pScene;
		m_pScene->init();
	}
}
// 描画
void SceneManager::draw()
{
	assert(m_pScene);
	if (!m_pScene)	return;
	m_pScene->draw();
}