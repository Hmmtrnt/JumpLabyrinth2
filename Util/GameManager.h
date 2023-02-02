// �Q�[���}�l�[�W���[
#pragma once
#include "common.h"

class Player;
class Shot;
class Stage;
class Back;

class GameManager
{
public:
	GameManager();
	virtual ~GameManager();

	void initCommon();			// ���ʂ̏�����
	void initP();				// �v���g�^�C�v�p������
	void init1();				// �X�e�[�W1�̏�����
	void init2();				// �X�e�[�W2�̏�����
	void init3();				// �X�e�[�W3�̏�����
	void init4();				// �X�e�[�W4�̏�����
	void end();					// �I��
	void update();				// �X�V
	void updateNoShot();		// �e�̏����������Ă��Ȃ��X�V
	void draw();				// �`��

	// �����蔻��
	// �v���C���[�Ƃ�
	void collision();			// �S��
	void collisionNoShot();		// �e�ȊO�̓����蔻��
	void collisionR();			// �E
	void collisionL();			// ��
	void collisionUP();			// ��
	void collisionBottom();		// ��
	void collisionBulge();		// �c��񂾂瑦������
	void collisionTimeLag();	// ���ԍ��Ŕ���
	void collisionEnemy();		// �G
	void collisionGameOver();	// �M�~�b�N6:��������
	void collisionGameClear();	// �Q�[���N���A

	// �G�l�~�[�Ƃ�
	void colEnemy();			// �S��
	void colEnemyR();			// �E
	void colEnemyL();			// ��
	void colEnemyUP();			// ��
	void colEnemyBottom();		// ��

	// �j�̕`��
	void drawNeedle();

	// �Q�[���I�[�o�[���[�V����
	void GameOverMotion();

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

	// �t���[���J�E���g
	int m_frameCountGameOver;

	// �j�̃O���t�B�b�N�n���h��
	int m_handleNeedle;

	// ��]�p�x
	float m_rota;

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
	Shot* m_pShot;
	Stage* m_pStage;
	Back* m_pBack;
};

