// �Q�[���}�l�[�W���[
#pragma once
#include "common.h"

class Player;
class Enemy;
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
	// �v���C���[�Ƃ�
	void collision();			// �S��
	void collisionR();			// �E
	void collisionL();			// ��
	void collisionUP();			// ��
	void collisionBottom();		// ��
	void collisionBulge();		// �c��񂾂瑦������
	void collisionTimeLag();	// ���ԍ��Ŕ���
	void collisionEnemy();		// �G
	void collisionGameOver();	// �Q�[���I�[�o�[
	void collisionGameClear();	// �Q�[���N���A

	// �G�l�~�[�Ƃ�
	void colEnemy();			// �S��
	void colEnemyR();			// �E
	void colEnemyL();			// ��
	void colEnemyUP();			// ��
	void colEnemyBottom();		// ��

	// �Q�[���I�[�o�[
	bool GameOver;
	// �Q�[���N���A
	bool GameClear;


private:
	// ���ڂ񂾂�A�c��񂾂肷�鏈��
	void EnemyElasticity();

	// �M�~�b�N�̓����蔻�肪�ς�鎞��
	int m_gimmickFrame;
	// ���ڂ�ł��鎞��
	int m_shrink;
	// �c���Ă��鎞��
	int m_inflate;

	// �Q�[���I�[�o�[�̃J�E���g�_�E��
	int m_GameOverCount;

	

	// �ׂ�ʂ������ǂ���
	bool colNextFlag;
	bool colFlagL;
	bool colFlagR;
	bool colFlagUp;
	bool colFlagBottom;

	// �v���C���[�����蔻��
	bool colL;			// ��
	bool colR;			// �E
	bool colUp;			// ��
	bool colBottom;		// ��

	// �G�l�~�[�����蔻��
	bool colNL;			// ��
	bool colNR;			// �E
	bool colNUp;		// ��
	bool colNBottom;	// ��

	Player* m_pPlayer;
	Enemy* m_pEnemy;
	Stage* m_pStage;
};

