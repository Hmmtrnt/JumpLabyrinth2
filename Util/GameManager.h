// �Q�[���}�l�[�W���[
#pragma once
#include "common.h"
#include <memory>

class Player;
class Stage;
class Back;
class ScenePause;
class collisionStage;
class Shot;

class GameManager
{
public:
	GameManager();
	virtual ~GameManager();

	// �������ꗗ
	void initCommon();			// ���ʂ̏�����

	void initManager(int posX, int posY, int frameX, int frameY, 
		const int stage[][kVariable::StageWidth], int stageHeight, int stageWidth);			// ������

	void initManagerInShot(int posX, int posY, int frameX, int frameY,
		const int stage[][kVariable::StageWidth], int stageHeight, int stageWidth);

	void end();					// �I��
	void update();				// �X�V

	void updateTest(int &frameX, int &frameY);

	void updateNoShot();		// �e�̏����������Ă��Ȃ��X�V
	void updatePause();			// �|�[�Y��ʂ̍X�V����
	void draw();				// �`��
	void drawInShot();			// �e���������`��

	// �����蔻��
	// �v���C���[�Ƃ�
	void collision();			// �S��
	void collisionR();			// �E
	void collisionL();			// ��
	void collisionUP();			// ��
	void collisionBottom();		// ��
	void collisionBulge();		// �c��񂾂瑦������
	void collisionTimeLag();	// ���ԍ��Ŕ���
	
	void collisionGameOver();	// �M�~�b�N6:��������
	void collisionGameClear();	// �Q�[���N���A

	// �j�̕`��
	void drawNeedle();

	// �Q�[���I�[�o�[���[�V����
	void GameOverMotion();


	// �|�[�Y��ʂ̍��ڂ����������擾
	int GetPushPause() { return m_pushPause; }

	// �Q�[���I�[�o�[
	bool GameOver;
	// �Q�[���N���A
	bool GameClear;


private:
	// ���ڂ񂾂�A�c��񂾂肷�鏈��
	void EnemyElasticity();

	// �ǂ��̍��ڂ�I��������
	int m_pushPause;
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

	// �|�[�Y�{�^���������ꂽ���ǂ���
	bool m_pushFlag;

	Player* m_pPlayer;
	Stage* m_pStage;
	Back* m_pBack;
	ScenePause* m_pPause;
	std::shared_ptr<collisionStage> m_pColStage;
	Shot* m_pShot;
};

