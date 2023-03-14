#pragma once
#include "SceneBase.h"

class SceneDemo : public SceneBase
{
public:
    SceneDemo();
    virtual ~SceneDemo();

    virtual void init();
    virtual void end();
    virtual SceneBase* update();
    virtual void draw();

private:
    // ハンドル
    int m_demoMoveHandle;// 動画
    int m_fontHandle;// フォント
    // 無操作の時間
    int m_waitingTime;
};