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
    // �n���h��
    int m_demoMoveHandle;// ����
    int m_fontHandle;// �t�H���g
    // ������̎���
    int m_waitingTime;
};