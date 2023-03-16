#pragma once
#include "../Util/common.h"
#include <array>
#include <memory>
#include <vector>

class ParticleBase;
class Back;

class ScenePause
{
public:
	ScenePause();
	virtual ~ScenePause();

	void init();			// 初期化
	void end();				// 終了
	void updatePause();		// ポーズ更新
	void drawPause();		// ポーズ表示

	void updateClearPause();// クリアポーズ更新
	void drawClearPause();	// クリアポーズ表示

	void movePause();		// ポーズ画面移動

	// 押した回数の情報取得
	int GetPushNum(){ return m_pushNum; }

private:
	void particle(int count);
	void drawParticle();

	// ポインタ
	Back* m_pBack;

	// テキストハンドル
	int m_textHandle;
	// 矢印の位置
	int m_posCursorX;		// ポーズ画面のカーソル位置
	int m_posCursorY;

	int m_posClearCursorX;	// クリアポーズ画面のカーソル位置
	int m_posClearCursorY;	
	// 押した回数
	int m_pushNum;
	// クリア時のポーズ位置
	int m_posClearPauseX;		// 左上座標
	int m_posClearPauseY;
	int m_sizeClearPauseX;		// サイズ座標
	int m_sizeClearPauseY;
	int m_posClearTextX;		// クリアポーズ画面のテキスト座標
	int m_pauseCursorNum;		// ポーズ画面のカーソル位置
	int m_clearCursorNum;		// クリア画面のカーソル位置
	int m_posClearTextY1;		// 項目1
	int m_posClearTextY2;		// 2
	int m_posClearTextY3;		// 3
	int m_itemNum;				// 選択できる範囲
	int m_CursorPosX;			// カーソル座標	X座標
	int m_CursorPosY;			// カーソル座標	Y座標
	int m_movePosX;				// 動く座標
	int m_vecPauseX;			// ポーズ画面の動く速さ

	// 音ハンドル
	int m_cursorSound;		// カーソル移動音
	int m_cursorNotSound;	// カーソル移動できない音

	// カーソルを初期化したかどうか
	bool m_isCursorInit;
	// 無理つぶされているかどうか
	bool m_FillBox;
	// ステージ20であるかどうか
	bool m_isStage20;

	// パーティクル
	std::array<std::shared_ptr<ParticleBase>, kParticle::ParticleNum> m_particle;
	int m_flowerFrame;// 花火のようなパーティクル
	int m_particleCount;// パーティクルが発生する数
	// パーティクル発生座標
	int m_particlePosX;// X座標
	int m_particlePosY;// Y座標
	bool first = true;// 一発目
	bool second = false;// 二発目
	bool third = false;// 三発目
};