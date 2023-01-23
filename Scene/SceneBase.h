// シーンの基底クラス
#pragma once

class SceneBase
{
public:
	SceneBase();
	virtual ~SceneBase();

	virtual void init();		// 初期化
	virtual void end();			// 終了処理
	virtual SceneBase* update();		// 更新処理
	virtual void draw();		// 描画
};