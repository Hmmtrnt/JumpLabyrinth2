#pragma once
#include "../Util/Vec2.h"
#include "../Util/common.h"

class ParticleBase
{
public:
	ParticleBase();
	virtual ~ParticleBase();

	void init();// ������
	virtual void update();// �X�V
	virtual void draw();// �`��

	// �p�[�e�B�N���J�n
	void start(Vec2 pos);

	// �ݒ�\�ȍ���
	void setPos(Vec2 pos) { m_pos = pos; }// ���W
	void setVec(Vec2 vec) { m_vec = vec; }// ���x
	void setRadius(float r) { m_radius = r; }// �����_��
	void setColor(unsigned int color) { m_color = color; }// �F
	void setGravity(float gravity) { m_gravity = gravity; }// �d��
	void setAlphaDec(int dec) { m_alphaDec = dec; }// �t�F�[�h�A�E�g���x
	void setRadiusAcc(float acc) { m_radiusAcc = acc; }// �~�̔��a
	void setAlpha(int alpha) { m_alpha = alpha; }// �A���t�@�u�����h

	bool isExist() const { return m_isExist; }// ���݂��Ă��邩�ǂ���

protected:
	Vec2 m_pos;// ���W
	Vec2 m_vec;// �ړ�
	float m_radius;// �~�̔��a
	unsigned int m_color;// �F
	int m_alpha;// �A���t�@�u�����h
	bool m_isExist;// ���݂��Ă��邩�ǂ���

	// �d�͉����x	�����Ȃ��ꍇ��0.0���w�肷��
	float m_gravity;

	// �����x�̌������x	����255����w�肵���������Ă���
	int m_alphaDec;

	// ���a�̕ω���
	float m_radiusAcc;
};