// �X�e�[�W�̓����蔻��
#pragma once
#include "../Util/common.h"
#include <memory>

//class Player;
//class Stage;

class collisionStage
{
public:
	collisionStage();
	virtual ~collisionStage();

	// �����蔻��
	void collision(bool colR, bool colL, bool colUp, bool colBottom,
		const int player[kVariable::PlayerWidth][kVariable::PlayerWidth],
		int posY, int posX, 
		const int stage[kVariable::StageWidth][kVariable::StageWidth]);			// �S��
	void collisionR(bool colR, 
		const int player[kVariable::PlayerWidth][kVariable::PlayerWidth],
		int posY, int posX,
		const int stage[kVariable::StageWidth][kVariable::StageWidth]);			// �E

	void collisionL(bool colL,
		const int player[kVariable::PlayerWidth][kVariable::PlayerWidth],
		int posY, int posX,
		const int stage[kVariable::StageWidth][kVariable::StageWidth]);			// ��

	void collisionUP(bool colUp,
		const int player[kVariable::PlayerWidth][kVariable::PlayerWidth],
		int posY, int posX,
		const int stage[kVariable::StageWidth][kVariable::StageWidth]);			// ��

	void collisionBottom(bool colBottom,
		const int player[kVariable::PlayerWidth][kVariable::PlayerWidth],
		int posY, int posX,
		const int stage[kVariable::StageWidth][kVariable::StageWidth]);		// ��
private:

	/*bool colR;
	bool colL;
	bool colUp;
	bool colBottom;*/

	//std::shared_ptr<Player> m_pPlayer;
	//std::shared_ptr<Stage> m_pStage;
};