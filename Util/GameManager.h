// �Q�[���}�l�[�W���[
#pragma once
#include "common.h"

class Player;
class Stage;
class Back;
class ScenePause;
class Shot;

class GameManager
{
public:
	GameManager();
	virtual ~GameManager();

	// �������ꗗ
	void initCommon();// ���ʂ̏�����

	/// <summary>
	/// ������
	/// </summary>
	/// <param name="posX">�v���C���[�̔z���X���W</param>
	/// <param name="posY">�v���C���[�̔z���Y���W</param>
	/// <param name="frameX">�v���C���[�̃t���[�����W��X���W</param>
	/// <param name="frameY">�v���C���[�̃t���[�����W��Y���W</param>
	/// <param name="stage">�X�e�[�W�̔z��</param>
	/// <param name="stageHeight">�X�e�[�W�̍���</param>
	/// <param name="stageWidth">�X�e�[�W�̉���</param>
	void initManager(int posX, int posY, int frameX, int frameY, 
		const int stage[][kVariable::StageWidth], int stageHeight, int stageWidth);

	void end();// �I��

	/// <summary>
	/// �S�̓I�ȍX�V����
	/// </summary>
	/// <param name="frameX">�v���C���[��X���W</param>
	/// <param name="frameY">�v���C���[��Y���W</param>
	void update(int &frameX, int &frameY);

	void updatePause();// �|�[�Y��ʂ̍X�V����
	void draw();// �`��

	// �����蔻��
	// �v���C���[�Ƃ�
	void collision();// �S��
	void collisionR();// �E
	void collisionL();// ��
	void collisionUP();// ��
	void collisionBottom();// ��
	void collisionBulge();// �M�~�b�N5:�c��񂾂瑦������
	void collisionTimeLag();// �M�~�b�N7:���ԍ��Ŕ���
	void collisionGameOver();// �M�~�b�N6:��������
	void collisionGameClear();// �Q�[���N���A

	// �j�̕`��
	void drawNeedle();

	// �Q�[���I�[�o�[���[�V����
	void GameOverMotion();


	// �|�[�Y��ʂ̍��ڂ����������擾
	int GetPushPause() { return m_pushPause; }
	// �|�[�Y�{�^���������ꂽ���̏��擾
	int GetPushPauseOpen() { return m_pushFlag; }

	// �Q�[���I�[�o�[
	bool GameOver;
	// �Q�[���N���A
	bool GameClear;

	// �v���C���[���ǂ̃g���b�v�ɂ��ꂽ��
	bool m_burnTrap;
	bool m_needleTrap;
	bool m_inflateTrap;

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

	// ���ԍ��g���b�v�̃J�E���g�_�E��
	int m_timeLagCount;
	// �Q�[���I�[�o�[�ɂȂ��Ă���̃J�E���g
	int m_gameOverCount;
	// �t���[���J�E���g
	int m_frameCountGameOver;

	// �j�̃O���t�B�b�N�n���h��
	int m_handleNeedle;

	// ���̃n���h��
	int m_goalSound;	// �S�[����
	int m_decideSound;	// ���艹

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

	// �|�[�Y�{�^���������ꂽ���ǂ����̐^�U
	bool m_pushFlag;

	// �������ꂽ���ǂ����̐^�U
	bool m_playSound;

	Player* m_pPlayer;
	Stage* m_pStage;
	Back* m_pBack;
	ScenePause* m_pPause;
	Shot* m_pShot;
};