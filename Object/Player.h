// プレイヤー
#pragma once
#include "../Util/common.h"

class Player
{
public:
	Player();
	virtual ~Player();

	void initCommon();	// 共通の初期化
	void initP();		// プロトタイプ用初期化
	void init1();		// ステージ1の初期化
	void end();			// 終了
	void update();		// 更新
	void draw();		// 描画

	// プレイヤー操作
	void operation(bool colL,bool colR, bool colUp, bool colDown);

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

	// プレイヤーの切り取る左上の頂点
	int m_verXPlayer;
	int m_verYPlayer;

private:
	// プレイヤーの描画
	void playerDraw(int x, int y);
	// モーション
	void motion(int x, int y);

	// プレイヤーハンドル
	int m_handle;		// 静止
	int m_handle2;		// 動いてる
	int m_handleEffect;	// エフェクト

	// プレイヤー画像の番号
	int m_handlenumX;
	
	// フレームカウント
	int m_frameCount;

	// プレイヤーの回転
	float m_rota;
};