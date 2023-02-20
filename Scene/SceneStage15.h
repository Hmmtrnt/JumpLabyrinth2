// �X�e�[�W14
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class GameManager;
class Back;

class SceneStage15 : public SceneBase
{
public:
	SceneStage15();
	virtual ~SceneStage15();

	virtual void init();			// ������
	virtual void end();				// �I��
	virtual SceneBase* update();	// �X�V
	virtual void draw();			// �`��

private:
	// �|�C���^
	GameManager* m_pManager;	// �Q�[���}�l�[�W���[
	Back* m_pBack;				// �w�i

	// �t���[���J�E���g
	int m_frameCount;
	// �L�����̍��W
	int m_posX;				// X���W
	int m_posY;				// Y���W
	// �L�����̈ړ��t���[��
	int m_frameX;			// X���W
	int m_frameY;			// Y���W

	// �w���v�����������̐^�U
	bool m_pushHelp;
};