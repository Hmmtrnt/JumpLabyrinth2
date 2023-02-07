// �X�e�[�W�̓����蔻��
#pragma once
#include "../Util/common.h"
#include <memory>

class Player;
class Stage;

class collisionStage
{
public:
	collisionStage();
	virtual ~collisionStage();

	// �����蔻��
	void collision(bool colR, bool colL, bool colUp, bool colBottom);			// �S��
	void collisionR(bool colR);			// �E
	void collisionL(bool colL);			// ��
	void collisionUP(bool colUp);			// ��
	void collisionBottom(bool colBottom);		// ��
private:

	/*bool colR;
	bool colL;
	bool colUp;
	bool colBottom;*/

	std::shared_ptr<Player> m_pPlayer;
	std::shared_ptr<Stage> m_pStage;
};