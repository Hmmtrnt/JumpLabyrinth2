// ステージの当たり判定
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

	// 当たり判定
	void collision(bool colR, bool colL, bool colUp, bool colBottom,
		const int player[kVariable::PlayerWidth][kVariable::PlayerWidth],
		int posY, int posX, 
		const int stage[kVariable::StageWidth][kVariable::StageWidth]);			// 全体
	void collisionR(bool colR, 
		const int player[kVariable::PlayerWidth][kVariable::PlayerWidth],
		int posY, int posX,
		const int stage[kVariable::StageWidth][kVariable::StageWidth]);			// 右

	void collisionL(bool colL,
		const int player[kVariable::PlayerWidth][kVariable::PlayerWidth],
		int posY, int posX,
		const int stage[kVariable::StageWidth][kVariable::StageWidth]);			// 左

	void collisionUP(bool colUp,
		const int player[kVariable::PlayerWidth][kVariable::PlayerWidth],
		int posY, int posX,
		const int stage[kVariable::StageWidth][kVariable::StageWidth]);			// 上

	void collisionBottom(bool colBottom,
		const int player[kVariable::PlayerWidth][kVariable::PlayerWidth],
		int posY, int posX,
		const int stage[kVariable::StageWidth][kVariable::StageWidth]);		// 下
private:

	/*bool colR;
	bool colL;
	bool colUp;
	bool colBottom;*/

	//std::shared_ptr<Player> m_pPlayer;
	//std::shared_ptr<Stage> m_pStage;
};