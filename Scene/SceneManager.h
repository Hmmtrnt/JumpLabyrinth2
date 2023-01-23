// シーンマネージャー
#pragma once

class SceneBase;

class SceneManager
{
public:
	SceneManager();
	virtual ~SceneManager() {}

	void init();		// 初期化
	void end();			// 終了
	void update();		// 毎フレームの処理
	void draw();		// 描画

private:
	// シーンベースポインタ
	SceneBase* m_pScene;
};