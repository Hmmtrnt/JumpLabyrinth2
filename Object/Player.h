// プレイヤー
#pragma once
#include "../Util/common.h"
#include "../Util/Vec2.h"
#include <array>
#include <memory>

class CharParticle;

class Player
{
public:
	Player();
	virtual ~Player();

	// 初期化一覧
	void initCommon();// 共通の初期化

	void initPlayer(int posX, int posY, int frameX, int frameY);// 実験用初期化

	void initTitle();// タイトルの初期化
	
	void end();// 終了

	void endTitle();// タイトル画面の終了

	void update();// 更新

	void updateInCollision(int &frameX, int &frameY);	// キャラクターの当たり判定入り更新

	// 描画
	void DrawGamePlay();		// プレイ中
	void DrawTitle(int posX, int posY);// タイトル描画

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
	int m_player[kVariable::PlayerWidth][kVariable::PlayerWidth];

	// プレイヤーの切り取る左上の頂点
	int m_verXPlayer;
	int m_verYPlayer;

private:
	// プレイヤーの描画
	void playerDraw(int x, int y);
	// モーション
	void motion(int x, int y);
	// プレイヤーパーティクル
	void particleTime();						// 発生インターバル
	void particle(int x, int y, float rota);	// 動き:プレイヤーとは反対方向に
	void drawParticle();						// 表示

	// プレイヤーハンドル
	int m_handle;		// 静止
	int m_handle2;		// 動いてる
	int m_handleEffect;	// エフェクト

	// プレイヤー画像の番号
	int m_handlenumX;
	
	// フレームカウント
	int m_frameCount;

	// 音ハンドル
	int m_jumpSound;	// ジャンプ
	int m_landingSound;	// 着地

	// プレイヤーの回転
	float m_rota;

	// 音が鳴ったかどうかの真偽
	bool m_sound;

	// パーティクル
	std::array<std::shared_ptr<CharParticle>, kParticle::ParticleNum> m_particle;
	int m_showerFrame;// 動き
	int m_particleFrame;// 表示する時間
	bool m_landing;// 着地したかどうか
};