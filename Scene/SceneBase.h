// シーンの基底クラス
#pragma once

class SceneBase
{
public:
	SceneBase();
	virtual ~SceneBase(){}

	virtual void init() = 0;// 初期化
	virtual void end() = 0;// 終了処理
	virtual SceneBase* update() { return this; }// 更新処理
	virtual void draw() = 0;// 描画

	// フェード関連
	void updateFade(int sound);// フェード更新
	void drawFade() const;// フェード描画
	bool isFadingIn() const;// フェードイン中
	bool isFadingOut() const;// フェードアウト中
	bool isFading() const { return isFadingIn() || isFadingOut(); }// フェードインorアウト中

	void startFadeOut();		// フェードアウト開始

protected:
	// フェード関連処理
	int m_fadeColor;
	int m_fadeBright;
	int m_fadeSpeed;
	int m_volume;
	int m_volumeSpeed;
};