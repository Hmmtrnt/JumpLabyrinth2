// プレイヤー
#pragma once
#include "../Util/common.h"

class Player
{
public:
	Player();
	virtual ~Player();

	void init();		// 初期化
	void end();			// 終了
	void update();		// 更新
	void draw();		// 描画

	// プレイヤー操作
	void operation(bool colL,bool colR, bool colUp, bool colDown);

	// モーション
	void motion();
	// 立ちモーション
	void standMotion();
	// ジャンプモーション
	void jumpMotion();

	// プレイヤーの配列の位置
	int m_posX;			// X座標
	int m_posY;			// Y座標
	// プレイヤーの移動フレーム
	int m_frameX;		// X座標
	int m_frameY;		// Y座標
	// プレイヤーの移動速度
	int m_speedX;		// X座標
	int m_speedY;		// Y座標

	// プレイヤーの配列の受け渡し
	int m_player[PLAYER_HEIGHT][PLAYER_WIDTH];

private:
	// プレイヤーハンドル
	int m_handle;
	int m_handle2;
	// プレイヤー画像の番号
	int m_handlenumX;
	// プレイヤーの切り取る左上の頂点
	int m_verXPlayer;
	int m_verYPlayer;
	// フレームカウント
	int m_frameCount;

	// プレイヤーの回転
	float m_rota;
};