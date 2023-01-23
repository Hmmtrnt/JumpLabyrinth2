// �Q�[���}�l�[�W���[
#pragma once
#include "common.h"

class Player;
class Stage;

class GameManager
{
public:
	GameManager();
	virtual ~GameManager();

	void init();
	void end();
	void update();
	void draw();

	// �����蔻��
	void collision();			// �S��
	void collisionR();			// �E
	void collisionL();			// ��
	void collisionUP();			// ��
	void collisionBottom();		// ��

private:

	bool colL;
	bool colR;
	bool colUp;
	bool colDown;

	Player* m_pPlayer;
	Stage* m_pStage;
};

