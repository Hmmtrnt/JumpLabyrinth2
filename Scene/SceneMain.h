// ���C�����
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"
#include <memory>

class GameManager;

class SceneMain : public SceneBase
{
public:
	SceneMain();
	virtual ~SceneMain();

	virtual void init();			// ������
	virtual void end();				// �I������
	virtual SceneBase* update();	// �X�V����
	virtual void draw();			// �`�揈��

private:
	// �Q�[���}�l�[�W���[�|�C���^
	//GameManager* m_pManager;

	// �t���[���J�E���g
	int m_frameCount;
	

	std::shared_ptr<GameManager> m_pManager;
};