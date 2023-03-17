// �V�[���̊��N���X
#pragma once

class SceneBase
{
public:
	SceneBase();
	virtual ~SceneBase(){}

	virtual void init() = 0;// ������
	virtual void end() = 0;// �I������
	virtual SceneBase* update() { return this; }// �X�V����
	virtual void draw() = 0;// �`��

	// �t�F�[�h�֘A
	void updateFade(int sound);// �t�F�[�h�X�V
	void drawFade() const;// �t�F�[�h�`��
	bool isFadingIn() const;// �t�F�[�h�C����
	bool isFadingOut() const;// �t�F�[�h�A�E�g��
	bool isFading() const { return isFadingIn() || isFadingOut(); }// �t�F�[�h�C��or�A�E�g��

	void startFadeOut();		// �t�F�[�h�A�E�g�J�n

protected:
	// �t�F�[�h�֘A����
	int m_fadeColor;
	int m_fadeBright;
	int m_fadeSpeed;
	int m_volume;
	int m_volumeSpeed;
};