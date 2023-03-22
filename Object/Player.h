// �v���C���[
#pragma once
#include "../Util/common.h"
#include "../Util/Vec2.h"
#include <array>
#include <memory>

class ParticleBase;

class Player
{
public:
	Player();
	virtual ~Player();

	// �������ꗗ
	void initCommon();// ���ʂ̏�����
	void initPlayer(int posX, int posY, int frameX, int frameY);// �����p������
	void initTitle();// �^�C�g���̏�����
	void end();// �I��
	void endTitle();// �^�C�g����ʂ̏I��
	void update();// �X�V
	void updateTitle();// �^�C�g����ʂ̍X�V
	void updateInCollision(int &frameX, int &frameY);// �L�����N�^�[�̓����蔻�����X�V

	// �`��
	void DrawGamePlay();		// �v���C��
	void DrawTitle(int posX, int posY);// �^�C�g���`��
	void DrawMotionTitle();

	// �v���C���[����
	void operation(bool colL,bool colR, bool colUp, bool colDown);

	// �v���C���[�̔z��̈ʒu
	int m_posX;			// X���W
	int m_posY;			// Y���W
	// �v���C���[�̈ړ��t���[��
	int m_frameX;		// X���W
	int m_frameY;		// Y���W
	// �v���C���[�̈ړ����x
	int m_speedX;		// X���W
	int m_speedY;		// Y���W

	// �v���C���[�̔z��̎󂯓n��
	int m_player[kVariable::PlayerWidth][kVariable::PlayerWidth];

	// �v���C���[�̐؂��鍶��̒��_
	int m_verXPlayer;
	int m_verYPlayer;

private:
	// �v���C���[�̕`��
	void playerDraw(int x, int y);
	// ���[�V����
	void motion(int x, int y);
	// �v���C���[�p�[�e�B�N��
	void particleTime();// �����C���^�[�o��

	/// <summary>
	/// �p�[�e�B�N���̓���
	/// </summary>
	/// <param name="x">X���W</param>
	/// <param name="y">Y���W</param>
	/// <param name="rota">�v���C���[�̌X��</param>
	void particle(int x, int y, float rota);
	void drawParticle();// �\��

	// �v���C���[�n���h��
	int m_handle;		// �Î~
	int m_handleMove;		// �����Ă�
	int m_handleEffect;	// �G�t�F�N�g

	// �v���C���[�摜�̔ԍ�
	int m_handlenumX;
	
	// �v���C���[�̃��[�V�����t���[���J�E���g
	int m_frameCount;

	// �^�C�g����ʂ̃��[�V����
	int m_TframeCount;// �t���[���J�E���g
	int m_TposX;// X���W
	int m_TposY;// Y���W
	int m_TspeedX;// �ړ�X���W
	int m_TspeedY;// �ړ�Y���W
	int m_TverX;// �؂���X���W
	int m_TverY;// �؂���Y���W
	int m_TlandingCount;// ���n���Ă��鎞��
	int m_Trota;// �`��̉�]��

	// ���n���h��
	int m_landingSound;	// ���n

	// �v���C���[�̉�]
	float m_rota;

	// �v���C���[�̕`�攽�]
	bool m_reverse;
	// �����������ǂ����̐^�U
	bool m_sound;

	// �p�[�e�B�N��
	std::array<std::shared_ptr<ParticleBase>, kParticle::ParticleNum> m_particle;
	int m_showerFrame;// ����
	int m_particleFrame;// �\�����鎞��
	bool m_landing;// ���n�������ǂ���
};