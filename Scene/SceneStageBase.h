// �V�[���X�e�[�W�̊��N���X
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class GameManager;
class Back;

class SceneStageBase : public SceneBase
{
public:
	SceneStageBase();
	virtual ~SceneStageBase();

	virtual void init() = 0;			// ������
	virtual void end() = 0;				// �I��
	virtual SceneBase* update() = 0;	// �X�V
	virtual void draw() = 0;			// �`��

protected:
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
};

