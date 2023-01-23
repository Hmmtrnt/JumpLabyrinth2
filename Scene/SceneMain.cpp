#include "SceneMain.h"
#include "../Util/GameManager.h"

SceneMain::SceneMain()
{
	m_pManager = new GameManager;
}

SceneMain::~SceneMain()
{
	delete m_pManager;
}

void SceneMain::init()
{
	m_pManager->init();
}

void SceneMain::end()
{
	m_pManager->end();
}

SceneBase* SceneMain::update()
{
	m_pManager->update();
	return this;
}

void SceneMain::draw()
{
	m_pManager->draw();
	//DrawString(0, 0, "Main", GetColor(255, 255, 255), true);
}
