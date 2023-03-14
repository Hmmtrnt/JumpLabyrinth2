#pragma once
#include "../Util/Vec2.h"
#include "../Util/common.h"

class ParticleBase
{
public:
	ParticleBase();
	virtual ~ParticleBase();

	void init();// 初期化
	virtual void update();// 更新
	virtual void draw();// 描画

	// 開始	とりあえず初期位置のみ設定	他のは個別設定
	void start(Vec2 pos);

	// 設定可能な項目
	void setPos(Vec2 pos) { m_pos = pos; }// 座標
	void setVec(Vec2 vec) { m_vec = vec; }// 速度
	void setRadius(float r) { m_radius = r; }// ランダム
	void setColor(unsigned int color) { m_color = color; }// 色
	void setGravity(float gravity) { m_gravity = gravity; }// 重力
	void setAlphaDec(int dec) { m_alphaDec = dec; }// アルファブレンド
	void setRadiusAcc(float acc) { m_radiusAcc = acc; }
	void setAlpha(int alpha) { m_alpha = alpha; }

	bool isExist() const { return m_isExist; }// 存在しているかどうか

protected:
	Vec2 m_pos;// 座標
	Vec2 m_vec;// 移動
	float m_radius;// ランダム
	unsigned int m_color;// 色
	int m_alpha;// アルファブレンド
	bool m_isExist;// 存在しているかどうか

	// 重力加速度	落ちない場合は0.0を指定する
	float m_gravity;

	// 透明度の減衰速度	初期255から指定した数減っていく
	int m_alphaDec;

	// 半径の変化量
	float m_radiusAcc;
};