// プレイヤー
#pragma once
#include "../Util/common.h"

class Player
{
public:
	Player();
	virtual ~Player();

	// 初期化一覧
	void initCommon();	// 共通の初期化

	void initTest(int posX, int posY, int frameX, int frameY );	// 実験用初期化

	void initP();		// プロトタイプ用初期化
	void init1();		// ステージ1の初期化
	void init2();		// ステージ2の初期化
	void init3();		// ステージ3の初期化
	void init4();		// ステージ4の初期化
	void init5();		// ステージ5の初期化
	void init6();		// ステージ6の初期化
	void init7();		// ステージ7の初期化
	void init8();		// ステージ8の初期化
	void init9();		// ステージ9の初期化
	void init10();		// ステージ10の初期化

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
	int m_player[kVariable::PlayerHeight][kVariable::PlayerWidth];

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