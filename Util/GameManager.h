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
	void collisionTimeLag();	// ���ԍ��Ŕ���
	void collisionGameOver();	// �Q�[���I�[�o�[

private:
	// �Q�[���I�[�o�[�̃J�E���g�_�E��
	int m_GameOverCount;

	// �Q�[���I�[�o�[
	bool GameOver;

	// �ׂ�ʂ������ǂ���
	bool colNextFlag;
	bool colFlagL;
	bool colFlagR;
	bool colFlagUp;
	bool colFlagDown;

	// �����蔻��
	bool colL;			// ��
	bool colR;			// �E
	bool colUp;			// ��
	bool colDown;		// ��

	Player* m_pPlayer;
	Stage* m_pStage;
};

