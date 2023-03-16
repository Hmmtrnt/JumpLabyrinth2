#include "SceneSelect.h"
#include "SceneTitle.h"
#include "SceneStageBase.h"
#include "../Object/Back.h"
#include "../Util/Pad.h"

namespace
{
	// �{�^���n���h���̈�ӂ̒���
	constexpr int kLengthHandle = 16;
	// BGM�̉���
	constexpr int kVolumeBgm = 100;
}

SceneSelect::SceneSelect() :
	m_textHandle(0),
	m_textHandle2(0),
	m_createStage(0),
	m_stageNum(0),
	m_stageNumText(0),
	m_selectPos(0),
	m_cursorPosX(0),
	m_cursorPosY(0),
	m_cursorPosW(0),
	m_cursorPosH(0),
	m_stageH1(0),
	m_stageH2(0),
	m_stageH3(0),
	m_stageH4(0),
	m_stageH5(0),
	m_stageH6(0),
	m_stageH7(0),
	m_stageH8(0),
	m_stageH9(0),
	m_stageH10(0),
	m_stageH11(0),
	m_stageH12(0),
	m_stageH13(0),
	m_stageH14(0),
	m_stageH15(0),
	m_stageH16(0),
	m_stageH17(0),
	m_stageH18(0),
	m_stageH19(0),
	m_stageH20(0),
	m_centerStageH(0),
	m_starHandle(0),
	m_buttonHandle(0),
	m_buttonHandleLeftNum(0),
	m_buttonHandleTopNum(0),
	m_buttonHandleX(0),
	m_buttonHandleY(0),
	m_buttohHandleDisplayTime(0),
	m_buttonHandleTime(0),
	m_cursorSound(0),
	m_decideSound(0),
	m_backGroundSound(0), 
	m_pushTitle(false)
{
	m_pBack = new Back;
}

SceneSelect::~SceneSelect()
{
	delete m_pBack;
}

void SceneSelect::init()
{
	// ���\�[�X�̓ǂݍ���
	LPCSTR font_path = "Font/Silver.ttf";// �ǂݍ��ރt�H���g�t�@�C���̃p�X
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0)
	{
	}
	else
	{
		// �t�H���g�ǂݍ��݃G���[����
		MessageBox(NULL, "�t�H���g�ǂݍ��ݎ��s", "", MB_OK);
	}
	m_textHandle = CreateFontToHandle("Silver", 100, -1, -1);
	m_textHandle2 = CreateFontToHandle("Silver", 50, -1, -1);
	m_createStage = 20;
	m_stageNum = 20;
	m_stageNumText = 0;
	m_selectPos = 0;
	m_cursorPosX = 910;
	m_cursorPosY = 60;
	m_cursorPosW = m_cursorPosX + 160;
	m_cursorPosH = m_cursorPosY + 190;

	m_stageH1 = draw::MyLoadGraph("data/stage/stage1.png");
	m_stageH2 = draw::MyLoadGraph("data/stage/stage2.png");
	m_stageH3 = draw::MyLoadGraph("data/stage/stage3.png");
	m_stageH4 = draw::MyLoadGraph("data/stage/stage4.png");
	m_stageH5 = draw::MyLoadGraph("data/stage/stage5.png");
	m_stageH6 = draw::MyLoadGraph("data/stage/stage6.png");
	m_stageH7 = draw::MyLoadGraph("data/stage/stage7.png");
	m_stageH8 = draw::MyLoadGraph("data/stage/stage8.png");
	m_stageH9 = draw::MyLoadGraph("data/stage/stage9.png");
	m_stageH10 = draw::MyLoadGraph("data/stage/stage10.png");
	m_stageH11 = draw::MyLoadGraph("data/stage/stage11.png");
	m_stageH12 = draw::MyLoadGraph("data/stage/stage12.png");
	m_stageH13 = draw::MyLoadGraph("data/stage/stage13.png");
	m_stageH14 = draw::MyLoadGraph("data/stage/stage14.png");
	m_stageH15 = draw::MyLoadGraph("data/stage/stage15.png");
	m_stageH16 = draw::MyLoadGraph("data/stage/stage16.png");
	m_stageH17 = draw::MyLoadGraph("data/stage/stage17.png");
	m_stageH18 = draw::MyLoadGraph("data/stage/stage18.png");
	m_stageH19 = draw::MyLoadGraph("data/stage/stage19.png");
	m_stageH20 = draw::MyLoadGraph("data/stage/stage20.png");

	m_starHandle = draw::MyLoadGraph("data/Star.png");

	m_buttonHandle = draw::MyLoadGraph("data/button.png");
	m_buttonHandleLeftNum = 1;
	m_buttonHandleTopNum = 21;
	m_buttohHandleDisplayTime = 30;
	m_buttonHandleTime = 60;

	m_cursorSound = LoadSoundMem("sound/cursorSound.mp3");
	m_decideSound = LoadSoundMem("sound/decideSound.mp3");
	m_backGroundSound = LoadSoundMem("sound/SelectSound.mp3");

	m_pushTitle = false;

	cursorSave();

	PlaySoundMem(m_backGroundSound, DX_PLAYTYPE_LOOP, true);

	m_pBack->init();
}

void SceneSelect::end()
{
	DeleteFontToHandle(m_textHandle);
	DeleteFontToHandle(m_textHandle2);
	DeleteGraph(m_stageH1);
	DeleteGraph(m_stageH2);
	DeleteGraph(m_stageH3);
	DeleteGraph(m_stageH4);
	DeleteGraph(m_stageH5);
	DeleteGraph(m_stageH6);
	DeleteGraph(m_stageH7);
	DeleteGraph(m_stageH8);
	DeleteGraph(m_stageH9);
	DeleteGraph(m_stageH10);
	DeleteGraph(m_stageH11);
	DeleteGraph(m_stageH12);
	DeleteGraph(m_stageH13);
	DeleteGraph(m_stageH14);
	DeleteGraph(m_stageH15);
	DeleteGraph(m_stageH16);
	DeleteGraph(m_stageH17);
	DeleteGraph(m_stageH18);
	DeleteGraph(m_stageH19);
	DeleteGraph(m_stageH20);

	DeleteGraph(m_starHandle);

	DeleteGraph(m_buttonHandle);

	DeleteSoundMem(m_cursorSound);
	DeleteSoundMem(m_decideSound);
	DeleteSoundMem(m_backGroundSound);

	m_pBack->end();
}

SceneBase* SceneSelect::update()
{
	// �{�^���\������
	m_buttonHandleTime--;
	if (m_buttonHandleTime <= 0)
	{
		m_buttonHandleTime = 60;
	}

	//�t�F�[�h����
	if (isFading())
	{
		bool isOut = isFadingOut();
		SceneBase::updateFade(m_backGroundSound);
		// �^�C�g����ʂ�
		if (!isFading() && isOut && m_pushTitle)		return (new SceneTitle);
		
		// �����p�V�[���J��(�܂������Ȃ�)
		if (!isFading() && isOut)
		{
			if (cursorSelectY == 1)
			{
				if (cursorSelectX == 1)	stageSelectNum = 1;
				if (cursorSelectX == 2) stageSelectNum = 2;
				if (cursorSelectX == 3) stageSelectNum = 3;
				if (cursorSelectX == 4) stageSelectNum = 4;
				if (cursorSelectX == 5) stageSelectNum = 5;
			}
			if (cursorSelectY == 2)
			{
				if (cursorSelectX == 1)	stageSelectNum = 6;
				if (cursorSelectX == 2) stageSelectNum = 7;
				if (cursorSelectX == 3) stageSelectNum = 8;
				if (cursorSelectX == 4) stageSelectNum = 9;
				if (cursorSelectX == 5) stageSelectNum = 10;
			}
			if (cursorSelectY == 3)
			{
				if (cursorSelectX == 1)	stageSelectNum = 11;
				if (cursorSelectX == 2) stageSelectNum = 12;
				if (cursorSelectX == 3) stageSelectNum = 13;
				if (cursorSelectX == 4) stageSelectNum = 14;
				if (cursorSelectX == 5) stageSelectNum = 15;
			}
			if (cursorSelectY == 4)
			{
				if (cursorSelectX == 1)	stageSelectNum = 16;
				if (cursorSelectX == 2) stageSelectNum = 17;
				if (cursorSelectX == 3) stageSelectNum = 18;
				if (cursorSelectX == 4) stageSelectNum = 19;
				if (cursorSelectX == 5) stageSelectNum = 20;
			}
			return (new SceneStageBase);
		}
	}

	// �X�e�[�W�I��
	int cursorSpeed = 10;

	if (Pad::isTrigger(PAD_INPUT_RIGHT))
	{
		cursorSelectX++;
		PlaySoundMem(m_cursorSound, DX_PLAYTYPE_BACK, true);
	}
	if (Pad::isTrigger(PAD_INPUT_LEFT))
	{
		cursorSelectX--;
		PlaySoundMem(m_cursorSound, DX_PLAYTYPE_BACK, true);
	}
	if (Pad::isTrigger(PAD_INPUT_UP))
	{
		cursorSelectY--;
		PlaySoundMem(m_cursorSound, DX_PLAYTYPE_BACK, true);
	}
	if (Pad::isTrigger(PAD_INPUT_DOWN))
	{
		cursorSelectY++;
		PlaySoundMem(m_cursorSound, DX_PLAYTYPE_BACK, true);
	}
	if (cursorSelectX <= 0)
	{
		cursorSelectX = 5;
		cursorSelectY--;
	}
	if (cursorSelectX >= 6)
	{
		cursorSelectX = 1;
		cursorSelectY++;
	}
	if (cursorSelectY <= 0)
	{
		cursorSelectY = 4;
	}
	if (cursorSelectY >= 5)
	{
		cursorSelectY = 1;
	}

	// �J�[�\���ړ�
	m_cursorPosX = (180 * (cursorSelectX - 1)) + 910;
	m_cursorPosW = m_cursorPosX + 160;
	m_cursorPosY = (210 * (cursorSelectY - 1)) + 100;
	m_cursorPosH = m_cursorPosY + 150;

	if (cursorSelectY == 1)
	{
		if (cursorSelectX == 1) m_centerStageH = m_stageH1;
		if (cursorSelectX == 2) m_centerStageH = m_stageH2;
		if (cursorSelectX == 3) m_centerStageH = m_stageH3;
		if (cursorSelectX == 4) m_centerStageH = m_stageH4;
		if (cursorSelectX == 5) m_centerStageH = m_stageH5;
	}
	if (cursorSelectY == 2)
	{
		if (cursorSelectX == 1) m_centerStageH = m_stageH6;
		if (cursorSelectX == 2) m_centerStageH = m_stageH7;
		if (cursorSelectX == 3) m_centerStageH = m_stageH8;
		if (cursorSelectX == 4) m_centerStageH = m_stageH9;
		if (cursorSelectX == 5) m_centerStageH = m_stageH10;
	}
	if (cursorSelectY == 3)
	{
		if (cursorSelectX == 1) m_centerStageH = m_stageH11;
		if (cursorSelectX == 2) m_centerStageH = m_stageH12;
		if (cursorSelectX == 3) m_centerStageH = m_stageH13;
		if (cursorSelectX == 4) m_centerStageH = m_stageH14;
		if (cursorSelectX == 5) m_centerStageH = m_stageH15;
	}
	if (cursorSelectY == 4)
	{
		if (cursorSelectX == 1) m_centerStageH = m_stageH16;
		if (cursorSelectX == 2) m_centerStageH = m_stageH17;
		if (cursorSelectX == 3) m_centerStageH = m_stageH18;
		if (cursorSelectX == 4) m_centerStageH = m_stageH19;
		if (cursorSelectX == 5) m_centerStageH = m_stageH20;
	}

	// �^�C�g���֖߂�Ƃ��̃t���O
	if (Pad::isTrigger(PAD_INPUT_1))	m_pushTitle = true;

	if (!isFading())
	{
		if (Pad::isTrigger(PAD_INPUT_2) || Pad::isTrigger(PAD_INPUT_1))
		{
			PlaySoundMem(m_decideSound, DX_PLAYTYPE_BACK, true);
			// �t�F�[�h�A�E�g�J�n
			startFadeOut();
		}
	}
	return this;
}

void SceneSelect::draw()
{
	m_pBack->draw();

	SetDrawBlendMode(DX_BLENDMODE_MULA, 150);
	// �Z���N�g�X�e�[�W
	DrawBox(900, 90, 1800, 930, kColor::Black, true);
	// �Z���^�[�X�e�[�W
	DrawBox(100, 100, 800, 750, kColor::Black, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	DrawStringToHandle(400, 910, ":�X�e�[�W��I��", kColor::White, m_textHandle2);

	int itemX = 0;
	int itemY = 100;
	int itemW = 200;
	int itemH = 250;

	int imageWidth = 910;// �g�̉���
	int Width = 180;// ����
	int lineHeight = 210;// �񂲂Ƃ̏c��
	int linePosH = itemY + lineHeight;// �񂲂Ƃ̏c���W
	int Height = itemH + lineHeight;// �c��

	// �e�X�e�[�W�̕`��
	DrawExtendGraph(imageWidth + (Width * 0), itemY, (imageWidth + (Width * 0)) + 160, itemH, m_stageH1, true);
	DrawExtendGraph(imageWidth + (Width * 1), itemY, (imageWidth + (Width * 1)) + 160, itemH, m_stageH2, true);
	DrawExtendGraph(imageWidth + (Width * 2), itemY, (imageWidth + (Width * 2)) + 160, itemH, m_stageH3, true);
	DrawExtendGraph(imageWidth + (Width * 3), itemY, (imageWidth + (Width * 3)) + 160, itemH, m_stageH4, true);
	DrawExtendGraph(imageWidth + (Width * 4), itemY, (imageWidth + (Width * 4)) + 160, itemH, m_stageH5, true);
	DrawExtendGraph(imageWidth + (Width * 0), linePosH, (imageWidth + (Width * 0)) + 160, Height, m_stageH6, true);
	DrawExtendGraph(imageWidth + (Width * 1), linePosH, (imageWidth + (Width * 1)) + 160, Height, m_stageH7, true);
	DrawExtendGraph(imageWidth + (Width * 2), linePosH, (imageWidth + (Width * 2)) + 160, Height, m_stageH8, true);
	DrawExtendGraph(imageWidth + (Width * 3), linePosH, (imageWidth + (Width * 3)) + 160, Height, m_stageH9, true);
	DrawExtendGraph(imageWidth + (Width * 4), linePosH, (imageWidth + (Width * 4)) + 160, Height, m_stageH10, true);
	DrawExtendGraph(imageWidth + (Width * 0), linePosH + lineHeight, (imageWidth + (Width * 0)) + 160, Height + lineHeight, m_stageH11, true);
	DrawExtendGraph(imageWidth + (Width * 1), linePosH + lineHeight, (imageWidth + (Width * 1)) + 160, Height + lineHeight, m_stageH12, true);
	DrawExtendGraph(imageWidth + (Width * 2), linePosH + lineHeight, (imageWidth + (Width * 2)) + 160, Height + lineHeight, m_stageH13, true);
	DrawExtendGraph(imageWidth + (Width * 3), linePosH + lineHeight, (imageWidth + (Width * 3)) + 160, Height + lineHeight, m_stageH14, true);
	DrawExtendGraph(imageWidth + (Width * 4), linePosH + lineHeight, (imageWidth + (Width * 4)) + 160, Height + lineHeight, m_stageH15, true);
	DrawExtendGraph(imageWidth + (Width * 0), linePosH + lineHeight + lineHeight, (imageWidth + (Width * 0)) + 160, Height + lineHeight + lineHeight, m_stageH16, true);
	DrawExtendGraph(imageWidth + (Width * 1), linePosH + lineHeight + lineHeight, (imageWidth + (Width * 1)) + 160, Height + lineHeight + lineHeight, m_stageH17, true);
	DrawExtendGraph(imageWidth + (Width * 2), linePosH + lineHeight + lineHeight, (imageWidth + (Width * 2)) + 160, Height + lineHeight + lineHeight, m_stageH18, true);
	DrawExtendGraph(imageWidth + (Width * 3), linePosH + lineHeight + lineHeight, (imageWidth + (Width * 3)) + 160, Height + lineHeight + lineHeight, m_stageH19, true);
	DrawExtendGraph(imageWidth + (Width * 4), linePosH + lineHeight + lineHeight, (imageWidth + (Width * 4)) + 160, Height + lineHeight + lineHeight, m_stageH20, true);

	// �X�e�[�W���̏�����
	m_stageNumText = 0;
	// �g�̕`��@
	for (int y = 0; y < m_stageNum; y++)
	{
			m_stageNumText++;
		
		// �񂲂Ƃɂ����
		itemX = imageWidth + (Width * y);
		if (y > 4)
		{
			itemY = linePosH;
			itemH = Height;
			itemX = imageWidth + (Width * (y - 5));
		}
		if (y > 9)
		{
			itemY = linePosH + lineHeight;
			itemH = Height + lineHeight;
			itemX = imageWidth + (Width * (y - 10));
		}
		if (y > 14)
		{
			itemY = linePosH + lineHeight + lineHeight;
			itemH = Height + lineHeight + lineHeight;
			itemX = imageWidth + (Width * (y - 15));
		}
		// �g�̕`��
		DrawBox(itemX, itemY, itemX + 160, itemH, kColor::White, false);
		DrawFormatStringToHandle(itemX + 10, itemY + 157, kColor::Black, m_textHandle2, "%d�X�e�[�W", m_stageNumText);
		DrawFormatStringToHandle(itemX + 8, itemY + 155, kColor::White, m_textHandle2, "%d�X�e�[�W", m_stageNumText);
	}

	// �J�[�\���\��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(m_cursorPosX, m_cursorPosY, m_cursorPosW, m_cursorPosH, kColor::Yellow, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	// �I�΂�Ă���X�e�[�W���\�������
	DrawExtendGraph(120, 120, 780, 730, m_centerStageH, true);
	DrawBox(120, 120, 780, 730, kColor::White, false);

	difficultyDraw();

	// �{�^���`��
	for (int i = 0; i < 3; i++)
	{
		draw::MyDrawRectRotaGraph(m_buttonHandleX, m_buttonHandleY,
			m_buttonHandleLeftNum * kLengthHandle, m_buttonHandleTopNum * kLengthHandle,
			kLengthHandle, kLengthHandle,
			2.0f, 0.0f, m_buttonHandle, true, false);
		// YellowButton
		if (i == 0)
		{
			m_buttonHandleX = 350;
			m_buttonHandleY = 900;
			m_buttonHandleTopNum = 21;
		}
		// BlueButton
		if (i == 1)
		{
			m_buttonHandleX = 350 - 25;
			m_buttonHandleY = 900 + 25;
			m_buttonHandleTopNum = 19;
		}
		// GreenButton
		if (i == 2)
		{
			m_buttonHandleX = 350;
			m_buttonHandleY = 900 + 50;
			m_buttonHandleTopNum = 20;
		}
	}
	
	// �����ׂ��{�^���`��
	if (m_buttonHandleTime <= m_buttohHandleDisplayTime)
	{
		draw::MyDrawRectRotaGraph(m_buttonHandleX + 27, m_buttonHandleY - 25,
			m_buttonHandleLeftNum + 4 * kLengthHandle, (m_buttonHandleTopNum + 2) * kLengthHandle,
			kLengthHandle, kLengthHandle,
			2.0f, 0.0f, m_buttonHandle, true, false);
	}
	else
	{
		draw::MyDrawRectRotaGraph(m_buttonHandleX + 25, m_buttonHandleY - 25,
			m_buttonHandleLeftNum * kLengthHandle, (m_buttonHandleTopNum + 2) * kLengthHandle,
			kLengthHandle, kLengthHandle,
			2.0f, 0.0f, m_buttonHandle, true, false);
	}
	// �X�e�[�W�P�ɃJ�[�\�������킹���Ƃ�
	if (cursorSelectX == 1 && cursorSelectY == 1)
	{
		m_pBack->drawTutorialText();
	}
	SceneBase::drawFade();
}

void SceneSelect::cursorSave()
{
	if (stageSelectNum == 1 || stageSelectNum == 6 || stageSelectNum == 11 || stageSelectNum == 16) cursorSelectX = 1;
	if (stageSelectNum == 2 || stageSelectNum == 7 || stageSelectNum == 12 || stageSelectNum == 17) cursorSelectX = 2;
	if (stageSelectNum == 3 || stageSelectNum == 8 || stageSelectNum == 13 || stageSelectNum == 18) cursorSelectX = 3;
	if (stageSelectNum == 4 || stageSelectNum == 9 || stageSelectNum == 14 || stageSelectNum == 19) cursorSelectX = 4;
	if (stageSelectNum == 5 || stageSelectNum == 10 || stageSelectNum == 15 || stageSelectNum == 20) cursorSelectX = 5;
	if (stageSelectNum >= 1 && stageSelectNum <= 5) cursorSelectY = 1;
	if (stageSelectNum >= 6 && stageSelectNum <= 10) cursorSelectY = 2;
	if (stageSelectNum >= 11 && stageSelectNum <= 15) cursorSelectY = 3;
	if (stageSelectNum >= 16 && stageSelectNum <= 20) cursorSelectY = 4;
}

// ��Փx�\��
void SceneSelect::difficultyDraw()
{
	int starPosX = 250;
	// ��Փx��\�����`��
	for (int i = 0; i < 5; i++)
	{
		draw::MyDrawRectRotaGraph(starPosX, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starHandle, true, false);
		starPosX += 100;
	}

	// �X�e�[�W���Ƃɓ�Փx�`���ύX
	if (cursorSelectY == 1)
	{
		if (cursorSelectX == 1 || cursorSelectX == 2 || cursorSelectX == 3)
		{
			difficulty1Draw();
		}
		if (cursorSelectX == 4 || cursorSelectX == 5)
		{
			difficulty2Draw();
		}
	}
	if (cursorSelectY == 2)
	{
		if (cursorSelectX == 1)
		{
			difficulty1Draw();
		}
		if (cursorSelectX == 2 || cursorSelectX == 3)
		{
			difficulty2Draw();
		}
		if (cursorSelectX == 4 || cursorSelectX == 5)
		{
			difficulty3Draw();
		}
	}
	if (cursorSelectY == 3)
	{
		if (cursorSelectX == 1)
		{
			difficulty2Draw();
		}
		if (cursorSelectX == 2)
		{
			difficulty3Draw();
		}
		if (cursorSelectX == 3 || cursorSelectX == 4)
		{
			difficulty4Draw();
		}
		if (cursorSelectX == 5)
		{
			difficulty5Draw();
		}
	}
	if (cursorSelectY == 4)
	{
		if (cursorSelectX == 1)
		{
			difficulty3Draw();
		}
		if (cursorSelectX == 2 || cursorSelectX == 3)
		{
			difficulty5Draw();
		}
		if (cursorSelectX == 4 || cursorSelectX == 5)
		{
			difficulty6Draw();
		}
	}
}

void SceneSelect::difficulty1Draw()
{
	SetDrawBright(255, 255, 0);
	draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starHandle, true, false);
	SetDrawBright(255, 255, 255);
}

void SceneSelect::difficulty2Draw()
{
	int starPosX = 250;
	SetDrawBright(255, 255, 0);
	for (int i = 0; i < 2; i++)
	{
		draw::MyDrawRectRotaGraph(starPosX, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starHandle, true, false);
		starPosX += 100;
	}
	SetDrawBright(255, 255, 255);
}

void SceneSelect::difficulty3Draw()
{
	int starPosX = 250;
	SetDrawBright(255, 255, 0);
	for (int i = 0; i < 3; i++)
	{
		draw::MyDrawRectRotaGraph(starPosX, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starHandle, true, false);
		starPosX += 100;
	}
	SetDrawBright(255, 255, 255);
}

void SceneSelect::difficulty4Draw()
{
	int starPosX = 250;
	SetDrawBright(255, 255, 0);
	for (int i = 0; i < 4; i++)
	{
		draw::MyDrawRectRotaGraph(starPosX, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starHandle, true, false);
		starPosX += 100;
	}
	SetDrawBright(255, 255, 255);
}

void SceneSelect::difficulty5Draw()
{
	int starPosX = 250;
	SetDrawBright(255, 255, 0);
	for (int i = 0; i < 5; i++)
	{
		draw::MyDrawRectRotaGraph(starPosX, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starHandle, true, false);
		starPosX += 100;
	}
	SetDrawBright(255, 255, 255);
}

void SceneSelect::difficulty6Draw()
{
	int starPosX = 250;
	SetDrawBright(255, 255, 0);
	for (int i = 0; i < 5; i++)
	{
		draw::MyDrawRectRotaGraph(starPosX, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starHandle, true, false);
		starPosX += 100;
	}
	SetDrawBright(255, 0, 0);
	draw::MyDrawRectRotaGraph(750, 50, 0, 0, 32, 32, 2.5f, 0.0f, m_starHandle, true, false);
	SetDrawBright(255, 255, 255);
}