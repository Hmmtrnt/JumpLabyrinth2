// ステージの当たり判定
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

	// 当たり判定
	void collision(bool colR, bool colL, bool colUp, bool colBottom);			// 全体
	void collisionR(bool colR);			// 右
	void collisionL(bool colL);			// 左
	void collisionUP(bool colUp);			// 上
	void collisionBottom(bool colBottom);		// 下
private:

	/*bool colR;
	bool colL;
	bool colUp;
	bool colBottom;*/

	std::shared_ptr<Player> m_pPlayer;
	std::shared_ptr<Stage> m_pStage;
};