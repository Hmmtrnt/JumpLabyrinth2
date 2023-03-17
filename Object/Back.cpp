#include "Back.h"

namespace
{
	// �X�e�[�W�ɃM�~�b�N��������Ȃ��Ƃ��̕`����W
	constexpr int kTrapOnlyHandleX = 200;
	constexpr int kTrapOnlyHandleY = 200;
	constexpr int kTrapOnlyTextX = 50;
	constexpr int kTrapOnlyTextY = 300;
	// �X�e�[�W�ɖc��񂾂肷��M�~�b�N�����Ȃ��Ƃ��̕`����W
	constexpr int kTrapOnlyInflateHandleX = 300;
	constexpr int kTrapOnlyInflateHandleY = 200;
	constexpr int kTrapOnlyInflateHandleX2 = 150;
	constexpr int kTrapOnlyInflateHandleY2 = 200;

	// �X�e�[�W�M�~�b�N�̐����`����W
	// ����
	constexpr int kTrapDeathHandleX = 200;		// �摜
	constexpr int kTrapDeathHandleY = 200;
	constexpr int kTrapDeathTextX = 50;			// �e�L�X�g
	constexpr int kTrapDeathTextY = 300;
	// ���ԍ��
	constexpr int kTrapLagHandleX = 200;		// �摜
	constexpr int kTrapLagHandleY = 650;
	constexpr int kTrapLagTextX = 50;			// �e�L�X�g
	constexpr int kTrapLagTextY = 750;
	// �c����
	constexpr int kTrapInflateHandleX = 1750;	// �摜
	constexpr int kTrapInflateHandleY = 200;
	constexpr int kTrapInflateHandleX2 = 1600;
	constexpr int kTrapInflateHandleY2 = 200;
	constexpr int kTrapInflateTextX = 1550;		// �e�L�X�g
	constexpr int kTrapInflateTextY = 300;
	// �V���b�g
	constexpr int kTrapShotHandleX = 1700;		// �摜
	constexpr int kTrapShotHandleY = 650;
	constexpr int kTrapShotTextX = 1550;		// �e�L�X�g
	constexpr int kTrapShotTextY = 750;

	// �`���[�g���A���`��̍��W
	// ��{�^��
	constexpr int kUpButtonHandleX = 200;// �摜
	constexpr int kUpButtonHandleY = 200;
	// ���{�^��
	constexpr int kDownButtonHandleX = 200;// �摜
	constexpr int kDownButtonHandleY = 650;
	// �E�{�^��
	constexpr int kRightButtonHandleX = 1700;// �摜
	constexpr int kRightButtonHandleY = 200;
	// ���{�^��
	constexpr int kLeftButtonHandleX = 1700;// �摜
	constexpr int kLeftButtonHandleY = 650;
	// �e�L�X�g����
	constexpr int kFirstButtonTextX = 100;
	constexpr int kUpButtonTextY = 300;
	constexpr int kDownButtonTextY = 750;
	// �e�L�X�g����
	constexpr int kSecondButtonTextX = 1600;
	constexpr int kRightButtonTextY = 300;
	constexpr int kLeftButtonTextY = 750;

	// �{�^���摜�̍�����W
	constexpr int kButtonHandlePosX = 3;
	constexpr int kUpButtonHandlePosY = 31;// ��
	constexpr int kDownButtonHandlePosY = 35;// ��
	constexpr int kRightButtonHandlePosY = 33;// �E
	constexpr int kLeftButtonHandlePosY = 37;// ��

	// �w�i�̕`��T�C�Y
	constexpr float kSize = 3.3f;

	// �{�^���n���h���̈��
	constexpr int kLengthHandle = 16;

	// �e�L�X�g
	const char* const kGuideOpenText = ":�M�~�b�N����";
	const char* const kGuideCloseText = ":����";
	const char* const kExplanGimmickDeath = "�������Ă͂����܂���";
	const char* const kExplanGimmickTimeRug = "���E�㉺�Ɉ�莞�Ԃ����\n����ł��܂��܂�";
	const char* const kExplanGimmickInflate = "�c���ł���Ƃ���\n�������Ă͂����܂���";
	const char* const kExplanGimmickArrow = "����˂���܂�";
	const char* const kUpTutorialText = "������֐i��";
	const char* const kDownTutorialText = "�������֐i��";
	const char* const kRightTutorialText = "�E�����֐i��";
	const char* const kLeftTutorialText = "�������֐i��";
	const char* const kTutorialText = "�����������";
}

Back::Back() :
	m_handle(-1),
	m_verX(0),
	m_verY(0),
	m_textHandle(0),
	m_gimmickHandle(0),
	m_gimmickHandle2(0),
	m_buttonHandle(0),
	m_buttonPauseLeftNum(0),
	m_buttonPauseTopNum(0),
	m_buttonHandleLeftNum(0),
	m_buttonHandleTopNum(0),
	m_buttonHandleX(0),
	m_buttonHandleY(0),
	m_buttohHandleDisplayTime(0),
	m_buttonHandleTime(0),
	m_D_padButtonHandle(0),
	m_D_padPosX(0),
	m_D_padPosY(0)
{
	for (int y = 0; y < kVariable::BackHeight; y++)
	{
		for (int x = 0; x < kVariable::BackWidth; x++)
		{
			m_back[y][x] = 0;
		}
	}
}

Back::~Back()
{
}

// ������
void Back::init()
{
	// �w�i�n���h��
	m_handle = draw::MyLoadGraph("data/tileset/inca_back2.png");
	// �؂��鍶��̒��_
	m_verX = 0;
	m_verY = 0;

	// �t�H���g
	m_textHandle = CreateFontToHandle("Silver", 50, -1, -1);

	// �X�e�[�W�����p�`��
	m_gimmickHandle = draw::MyLoadGraph("data/tileset/stage.png");// �����ȊO
	m_gimmickHandle2 = draw::MyLoadGraph("data/Trap.png");// �����g���b�v

	// �{�^���`��
	m_buttonHandle = draw::MyLoadGraph("data/button.png");

	// �؂��蒸�_
	// �|�[�Y�{�^��
	m_buttonPauseLeftNum = 10;// ��
	m_buttonPauseTopNum = 14;// ��
	// ABXY1�{�^��
	m_buttonHandleLeftNum = 1;// ��
	m_buttonHandleTopNum = 21;// ��
	// �`�掞��
	m_buttohHandleDisplayTime = 30;// �`��
	m_buttonHandleTime = 60;// �S��
	m_D_padButtonHandle = kUpButtonHandlePosY;// �\���L�[�`�捶��؂�����W
	m_D_padPosX = kUpButtonHandleX;// �\���L�[�`��X���W
	m_D_padPosY = kUpButtonHandleY;// �\���L�[�`��Y���W


	// �w�i�z��̃T�C�Y�擾
	for (int y = 0; y < kVariable::BackHeight; y++)
	{
		for (int x = 0; x < kVariable::BackWidth; x++)
		{
			m_back[y][x] = kBack::backs[y][x];
		}
	}
}

// �I��
void Back::end()
{
	DeleteGraph(m_handle);
	DeleteFontToHandle(m_textHandle);
	DeleteGraph(m_gimmickHandle);
	DeleteGraph(m_gimmickHandle2);
	DeleteGraph(m_buttonHandle);
}

void Back::update()
{
	// �{�^���\������
	m_buttonHandleTime--;
	if (m_buttonHandleTime <= 0)
	{
		m_buttonHandleTime = 60;
	}
}

// �`��
void Back::draw()
{
	for (int y = 0; y < kVariable::BackHeight; y++)
	{
		for (int x = 0; x < kVariable::BackWidth; x++)
		{
			if (m_back[y][x] == 0)
			{
				m_verX = 4;
				m_verY = 1;
			}
			if (m_back[y][x] == 1)
			{
				m_verX = 0;
				m_verY = 1;
			}
			draw::MyDrawRectRotaGraph((x * kVariable::DrawBackWidth) + (kVariable::DrawBackWidth / 2),
				(y * kVariable::DrawBackWidth) + (kVariable::DrawBackWidth / 2),
				m_verX * 32, m_verY * 32,
				32, 32,
				kSize, 0.0f,
				m_handle, true, false);
		}
	}
}

void Back::drawMenuGuide()
{
	draw::MyDrawRectRotaGraph(1550, 70, 
		m_buttonPauseLeftNum * kLengthHandle, m_buttonPauseTopNum * kLengthHandle,
		kLengthHandle, kLengthHandle,
		5.0f, 0.0f, m_buttonHandle, true, false);
	DrawFormatStringToHandle(1600, 50, kColor::White, m_textHandle, ":���j���[���");
}

void Back::drawCloseGuide()
{
	DrawFormatStringToHandle(150, 50, kColor::White, 
		m_textHandle, kGuideCloseText);
	// �{�^���`��
	drawButton(100, 50);
	drawPushButton(2, 0, m_buttonHandleTopNum);
}

void Back::drawOpenGuide()
{
	DrawFormatStringToHandle(150, 50, kColor::White, 
		m_textHandle, kGuideOpenText);

	// �{�^���`��
	drawButton(100, 50);
	drawPushButton(2, 0, m_buttonHandleTopNum);
	drawMenuGuide();
}

void Back::drawExplan2_5()
{
	drawMenuGuide();
	drawCloseGuide();

	drawExplanDeath(kTrapDeathHandleX, kTrapDeathHandleY, 
		kTrapDeathTextX, kTrapDeathTextY);
}

void Back::drawExplan6And10()
{
	drawMenuGuide();
	drawCloseGuide();

	drawExplanLagTrap(kTrapOnlyHandleX, kTrapOnlyHandleY,
		kTrapOnlyTextX, kTrapOnlyTextY);
}

void Back::drawExplan7_9()
{
	drawMenuGuide();
	drawCloseGuide();

	drawExplanDeath(kTrapDeathHandleX, kTrapDeathHandleY,
		kTrapDeathTextX, kTrapDeathTextY);
	drawExplanLagTrap(kTrapLagHandleX, kTrapLagHandleY,
		kTrapLagTextX, kTrapLagTextY);
}

void Back::drawExplan11()
{
	drawMenuGuide();
	drawCloseGuide();

	drawExplanInflateTrap(kTrapOnlyInflateHandleX, kTrapOnlyInflateHandleY,
		kTrapOnlyInflateHandleX2, kTrapOnlyInflateHandleY2,
		kTrapOnlyTextX, kTrapDeathTextY);
}

void Back::drawExplan12_15()
{
	drawMenuGuide();
	drawCloseGuide();

	drawExplanDeath(kTrapDeathHandleX, kTrapDeathHandleY,
		kTrapDeathTextX, kTrapDeathTextY);
	drawExplanLagTrap(kTrapLagHandleX, kTrapLagHandleY,
		kTrapLagTextX, kTrapLagTextY);
	drawExplanInflateTrap(kTrapInflateHandleX, kTrapInflateHandleY,
		kTrapInflateHandleX2, kTrapInflateHandleY2,
		kTrapInflateTextX, kTrapInflateTextY);
}

void Back::drawExplan16()
{
	drawMenuGuide();
	drawCloseGuide();

	drawExplanShotTrap(kTrapOnlyHandleX, kTrapOnlyHandleY, 
		kTrapOnlyTextX, kTrapOnlyTextY);
}

void Back::drawExplan17_20()
{
	drawMenuGuide();
	drawCloseGuide();

	drawExplanDeath(kTrapDeathHandleX, kTrapDeathHandleY, 
		kTrapDeathTextX, kTrapDeathTextY);
	drawExplanLagTrap(kTrapLagHandleX, kTrapLagHandleY, 
		kTrapLagTextX, kTrapLagTextY);
	drawExplanInflateTrap(kTrapInflateHandleX, kTrapInflateHandleY, 
		kTrapInflateHandleX2, kTrapInflateHandleY2, 
		kTrapInflateTextX, kTrapInflateTextY);
	drawExplanShotTrap(kTrapShotHandleX, kTrapShotHandleY, 
		kTrapShotTextX, kTrapShotTextY);
}

void Back::drawTutorial()
{
	// �{�^���`��
	for (int i = 0; i < 4; i++)
	{
		draw::MyDrawRectRotaGraph(m_D_padPosX, m_D_padPosY,
			kButtonHandlePosX * kLengthHandle, m_D_padButtonHandle * kLengthHandle,
			kLengthHandle * 2, kLengthHandle * 2,
			4.0f, 0.0f, m_buttonHandle, true, false);
		if (i == 0)
		{// ��
			m_D_padButtonHandle = kUpButtonHandlePosY;
			m_D_padPosX = kUpButtonHandleX;
			m_D_padPosY = kUpButtonHandleY;
		}
		if (i == 1)
		{// ��
			m_D_padButtonHandle = kDownButtonHandlePosY;
			m_D_padPosX = kDownButtonHandleX;
			m_D_padPosY = kDownButtonHandleY;
		}
		if (i == 2)
		{// �E
			m_D_padButtonHandle = kRightButtonHandlePosY;
			m_D_padPosX = kRightButtonHandleX;
			m_D_padPosY = kRightButtonHandleY;
		}
		if (i == 3)
		{// ��
			m_D_padButtonHandle = kLeftButtonHandlePosY;
			m_D_padPosX = kLeftButtonHandleX;
			m_D_padPosY = kLeftButtonHandleY;
		}
	}

	// ��{�^���`��
	DrawStringToHandle(kFirstButtonTextX, kUpButtonTextY, kUpTutorialText, kColor::White, m_textHandle);

	// ���{�^���`��
	DrawStringToHandle(kFirstButtonTextX, kDownButtonTextY, kDownTutorialText, kColor::White, m_textHandle);

	// �E�{�^���`��
	DrawStringToHandle(kSecondButtonTextX, kRightButtonTextY, kRightTutorialText, kColor::White, m_textHandle);

	// ���{�^���`��
	DrawStringToHandle(kSecondButtonTextX, kLeftButtonTextY, kLeftTutorialText, kColor::White, m_textHandle);
}

void Back::drawTutorialText()
{
	DrawStringToHandle(350, 800, kTutorialText, kColor::White, m_textHandle);
}

void Back::drawButton(int x, int y)
{
	// �{�^���`��
	for (int i = 0; i < 4; i++)
	{
		draw::MyDrawRectRotaGraph(m_buttonHandleX, m_buttonHandleY,
			m_buttonHandleLeftNum * kLengthHandle, m_buttonHandleTopNum * kLengthHandle,
			kLengthHandle, kLengthHandle,
			2.0f, 0.0f, m_buttonHandle, true, false);
		if (i == 0)
		{
			m_buttonHandleX = x + 25;
			m_buttonHandleY = y + 25;
			m_buttonHandleTopNum = 22;
		}
		if (i == 1)
		{
			m_buttonHandleX = x - 25;
			m_buttonHandleY = y + 25;
			m_buttonHandleTopNum = 19;
		}
		if (i == 2)
		{
			m_buttonHandleX = x;
			m_buttonHandleY = y + 50;
			m_buttonHandleTopNum = 20;
		}
		if (i == 3)
		{
			m_buttonHandleX = x;
			m_buttonHandleY = y;
			m_buttonHandleTopNum = 21;
		}
	}
}

void Back::drawPushButton(int x, int y, int handleNum)
{
	// �����ׂ��{�^���`��
	if (m_buttonHandleTime <= m_buttohHandleDisplayTime)
	{
		draw::MyDrawRectRotaGraph(m_buttonHandleX + x, m_buttonHandleY + y,
			m_buttonHandleLeftNum + 4 * kLengthHandle, handleNum * kLengthHandle,
			kLengthHandle, kLengthHandle,
			2.0f, 0.0f, m_buttonHandle, true, false);
	}
}

void Back::drawExplanDeath(int posXHandle, int posYHandle,
	int posXText, int posYText)
{
	draw::MyDrawRectRotaGraph(posXHandle, posYHandle,
		13 * 16, 13 * 16,
		16, 16,
		4.2f, 0.0f,
		m_gimmickHandle2, true, false);

	DrawFormatStringToHandle(posXText, posYText,
		kColor::White, m_textHandle,
		kExplanGimmickDeath);
}

void Back::drawExplanLagTrap(int posXHandle, int posYHandle,
	int posXText, int posYText)
{
	draw::MyDrawRectRotaGraph(posXHandle, posYHandle,
		0, 0,
		32, 32,
		2.0f, 0.0f,
		m_gimmickHandle, true, false);

	DrawFormatStringToHandle(posXText, posYText,
		kColor::White, m_textHandle,
		kExplanGimmickTimeRug);
}

void Back::drawExplanInflateTrap(int posXHandle, int posYHandle,
	int posXHandle2, int posYHandle2,
	int posXText, int posYText)
{
	draw::MyDrawRectRotaGraph(posXHandle, posYHandle,
		64, 0,
		32, 32,
		4.0f, 0.0f,
		m_gimmickHandle, true, false);
	draw::MyDrawRectRotaGraph(posXHandle2, posYHandle2,
		96, 0,
		32, 32,
		2.0f, 0.0f,
		m_gimmickHandle, true, false);

	DrawFormatStringToHandle(posXText, posYText,
		kColor::White, m_textHandle,
		kExplanGimmickInflate);
}

void Back::drawExplanShotTrap(int posXHandle, int posYHandle,
	int posXText, int posYText)
{
	draw::MyDrawRectRotaGraph(posXHandle, posYHandle,
		32, 0,
		32, 32,
		2.0f, 0.0f,
		m_gimmickHandle, true, false);

	DrawFormatStringToHandle(posXText, posYText,
		kColor::White, m_textHandle,
		kExplanGimmickArrow);
}