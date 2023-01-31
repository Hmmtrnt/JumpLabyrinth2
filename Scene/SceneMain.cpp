#include "SceneMain.h"
#include "SceneTitle.h"
#include "../Util/GameManager.h"

SceneMain::SceneMain() :
	m_frameCount(0)
{
	m_pManager = new GameManager;
}

SceneMain::~SceneMain()
{
	delete m_pManager;
}

void SceneMain::init()
{
	m_frameCount = 120;
	m_pManager->init();
}

void SceneMain::end()
{
	m_pManager->end();
}

SceneBase* SceneMain::update()
{
	m_pManager->update();

	if (m_pManager->GameOver)
	{
		return(new SceneTitle);
	}
	if (m_pManager->GameClear)
	{
		return(new SceneTitle);
	}

	return this;
}

void SceneMain::draw()
{
	m_pManager->draw();
	//DrawString(0, 0, "Main", GetColor(255, 255, 255), true);
}
