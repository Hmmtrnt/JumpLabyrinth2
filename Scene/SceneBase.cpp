#include "SceneBase.h"
#include "../Util/common.h"
#include "../Util/game.h"

namespace
{
	// フェード速度
	constexpr int kFadeSpeed = 5;
	constexpr int kVolumeSpeed = 5;
}

SceneBase::SceneBase()
{
	// 初期設定はフェードアウト状態
	m_fadeColor = kColor::Black;
	m_fadeBright = 255;
	m_fadeSpeed = -kFadeSpeed;
	m_volume = 255;
	m_volumeSpeed = kVolumeSpeed;
}

void SceneBase::updateFade(int sound)
{
	m_fadeBright += m_fadeSpeed;
	if (m_fadeBright >= 255)
	{
		m_fadeBright = 255;
		if (m_fadeSpeed > 0)
		{
			m_fadeSpeed = 0;
		}
	}
	if (m_fadeBright <= 0)
	{
		m_fadeBright = 0;
		if (m_fadeSpeed < 0)
		{
			m_fadeSpeed = 0;
		}
	}
	m_volume += m_volumeSpeed;
	if (m_volume >= 255)
	{
		m_volume = 255;
		if (m_volumeSpeed > 0)
		{
			m_volumeSpeed = 0;
		}
	}
	if (m_volume <= 0)
	{
		m_volume = 0;
		if (m_volumeSpeed < 0)
		{
			m_volumeSpeed = 0;
		}
	}
	ChangeVolumeSoundMem(m_volume, sound);
}

void SceneBase::drawFade() const
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_fadeBright);
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_fadeColor, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

bool SceneBase::isFadingIn() const
{
	if (m_fadeSpeed < 0)	return true;
	return false;
}

bool SceneBase::isFadingOut() const
{
	if (m_fadeSpeed > 0)	return true;
	return false;
}

void SceneBase::startFadeOut()
{
	m_fadeSpeed = kFadeSpeed;
	m_volumeSpeed = -kVolumeSpeed;
}
