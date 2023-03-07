#include "SceneSelect.h"
#include "SceneTitle.h"
#include "SceneStageBase.h"
#include "../Object/Back.h"
#include "../Util/Pad.h"

namespace
{
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
	m_cursorX(0),
	m_cursorY(0),
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
	m_starTest(0),
	m_starEmpty(0),
	m_starYellow(0),
	m_starRed(0),
	m_cursorSound(0),
	m_decideSound(0),
	m_backGroundSound(0), 
	m_playSound(false),
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
	m_cursorX = 1;
	m_cursorY = 1;
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

	m_starTest = draw::MyLoadGraph("data/Star.png");

	m_cursorSound = LoadSoundMem("sound/cursorSound.mp3");
	m_decideSound = LoadSoundMem("sound/decideSound.mp3");
	m_backGroundSound = LoadSoundMem("sound/SelectSound.mp3");

	m_pushTitle = false;
	m_playSound = false;

	//ChangeVolumeSoundMem(m_volume, m_backGroundSound);

	m_stageSelectNumTest = 0;

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

	DeleteGraph(m_starTest);

	DeleteGraph(m_starEmpty);
	DeleteGraph(m_starYellow);
	DeleteGraph(m_starRed);

	DeleteSoundMem(m_cursorSound);
	DeleteSoundMem(m_decideSound);
	DeleteSoundMem(m_backGroundSound);

	m_pBack->end();
}

SceneBase* SceneSelect::update()
{
	// BGM�Đ�
	if (!m_playSound)
	{
		PlaySoundMem(m_backGroundSound, DX_PLAYTYPE_BACK, true);
		m_playSound = true;
	}
	// BGM����Ȃ��Ȃ����烋�[�v����悤�ɂ���
	if (CheckSoundMem(m_backGroundSound) == 0)
	{
		m_playSound = false;
	}

	//�t�F�[�h����
	if (isFading())
	{
		bool isOut = isFadingOut();
		SceneBase::updateFade(m_backGroundSound);
		if (!isFading() && isOut && m_pushTitle)		return (new SceneTitle);
		//if (!isFading() && isOut)
		//{
		//	if (m_cursorY == 1)
		//	{
		//		if (m_cursorX == 1)	return(new SceneStage1);
		//		/*if (m_cursorX == 2) return(new SceneStage2);
		//		if (m_cursorX == 3) return(new SceneStage3);
		//		if (m_cursorX == 4) return(new SceneStage4);*/
		//		if (m_cursorX == 5) return(new SceneStage5);
		//	}
		//	if (m_cursorY == 2)
		//	{
		//		/*if (m_cursorX == 1)	return(new SceneStage6);
		//		if (m_cursorX == 2) return(new SceneStage7);
		//		if (m_cursorX == 3) return(new SceneStage8);
		//		if (m_cursorX == 4) return(new SceneStage9);*/
		//		if (m_cursorX == 5) return(new SceneStage10);
		//	}
		//	if (m_cursorY == 3)
		//	{
		//		/*if (m_cursorX == 1)	return(new SceneStage11);
		//		if (m_cursorX == 2) return(new SceneStage12);
		//		if (m_cursorX == 3) return(new SceneStage13);
		//		if (m_cursorX == 4) return(new SceneStage14);*/
		//		if (m_cursorX == 5) return(new SceneStage15);
		//	}
		//	if (m_cursorY == 4)
		//	{
		//		/*if (m_cursorX == 1)	return(new SceneStage16);
		//		if (m_cursorX == 2) return(new SceneStage17);
		//		if (m_cursorX == 3) return(new SceneStage18);
		//		if (m_cursorX == 4) return(new SceneStage19);*/
		//		if (m_cursorX == 5) return(new SceneStage20);
		//	}
		//}
		
		// �����p�V�[���J��(�܂������Ȃ�)
		if (!isFading() && isOut)
		{
			if (m_cursorY == 1)
			{
				if (m_cursorX == 1)	m_stageSelectNumTest = 1;
				if (m_cursorX == 2) m_stageSelectNumTest = 2;
				if (m_cursorX == 3) m_stageSelectNumTest = 3;
				if (m_cursorX == 4) m_stageSelectNumTest = 4;
				if (m_cursorX == 5) m_stageSelectNumTest = 5;
			}
			if (m_cursorY == 2)
			{
				if (m_cursorX == 1)	m_stageSelectNumTest = 6;
				if (m_cursorX == 2) m_stageSelectNumTest = 7;
				if (m_cursorX == 3) m_stageSelectNumTest = 8;
				if (m_cursorX == 4) m_stageSelectNumTest = 9;
				if (m_cursorX == 5) m_stageSelectNumTest = 10;
			}
			if (m_cursorY == 3)
			{
				if (m_cursorX == 1)	m_stageSelectNumTest = 11;
				if (m_cursorX == 2) m_stageSelectNumTest = 12;
				if (m_cursorX == 3) m_stageSelectNumTest = 13;
				if (m_cursorX == 4) m_stageSelectNumTest = 14;
				if (m_cursorX == 5) m_stageSelectNumTest = 15;
			}
			if (m_cursorY == 4)
			{
				if (m_cursorX == 1)	m_stageSelectNumTest = 16;
				if (m_cursorX == 2) m_stageSelectNumTest = 17;
				if (m_cursorX == 3) m_stageSelectNumTest = 18;
				if (m_cursorX == 4) m_stageSelectNumTest = 19;
				if (m_cursorX == 5) m_stageSelectNumTest = 20;
			}
			return (new SceneStageBase);
		}
	}

	

	// �X�e�[�W�I��
	int cursorSpeed = 10;

	if (Pad::isTrigger(PAD_INPUT_RIGHT))
	{
		m_cursorX++;
		PlaySoundMem(m_cursorSound, DX_PLAYTYPE_BACK, true);
	}
	if (Pad::isTrigger(PAD_INPUT_LEFT))
	{
		m_cursorX--;
		PlaySoundMem(m_cursorSound, DX_PLAYTYPE_BACK, true);
	}
	if (Pad::isTrigger(PAD_INPUT_UP))
	{
		m_cursorY--;
		PlaySoundMem(m_cursorSound, DX_PLAYTYPE_BACK, true);
	}
	if (Pad::isTrigger(PAD_INPUT_DOWN))
	{
		m_cursorY++;
		PlaySoundMem(m_cursorSound, DX_PLAYTYPE_BACK, true);
	}
	if (m_cursorX <= 0)
	{
		m_cursorX = 5;
		m_cursorY--;
	}
	if (m_cursorX >= 6)
	{
		m_cursorX = 1;
		m_cursorY++;
	}
	if (m_cursorY <= 0)
	{
		m_cursorY = 4;
	}
	if (m_cursorY >= 5)
	{
		m_cursorY = 1;
	}

	// �J�[�\���ړ�
	m_cursorPosX = (180 * (m_cursorX - 1)) + 910;
	m_cursorPosW = m_cursorPosX + 160;
	m_cursorPosY = (210 * (m_cursorY - 1)) + 100;
	m_cursorPosH = m_cursorPosY + 150;

	if (m_cursorY == 1)
	{
		if (m_cursorX == 1)	m_centerStageH = m_stageH1;
		if (m_cursorX == 2) m_centerStageH = m_stageH2;
		if (m_cursorX == 3) m_centerStageH = m_stageH3;
		if (m_cursorX == 4) m_centerStageH = m_stageH4;
		if (m_cursorX == 5) m_centerStageH = m_stageH5;
	}
	if (m_cursorY == 2)
	{
		if (m_cursorX == 1)	m_centerStageH = m_stageH6;
		if (m_cursorX == 2) m_centerStageH = m_stageH7;
		if (m_cursorX == 3) m_centerStageH = m_stageH8;
		if (m_cursorX == 4) m_centerStageH = m_stageH9;
		if (m_cursorX == 5) m_centerStageH = m_stageH10;
	}
	if (m_cursorY == 3)
	{
		if (m_cursorX == 1)	m_centerStageH = m_stageH11;
		if (m_cursorX == 2) m_centerStageH = m_stageH12;
		if (m_cursorX == 3) m_centerStageH = m_stageH13;
		if (m_cursorX == 4) m_centerStageH = m_stageH14;
		if (m_cursorX == 5) m_centerStageH = m_stageH15;
	}
	if (m_cursorY == 4)
	{
		if (m_cursorX == 1)	m_centerStageH = m_stageH16;
		if (m_cursorX == 2) m_centerStageH = m_stageH17;
		if (m_cursorX == 3) m_centerStageH = m_stageH18;
		if (m_cursorX == 4) m_centerStageH = m_stageH19;
		if (m_cursorX == 5) m_centerStageH = m_stageH20;
	}

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

	DrawStringToHandle(300, 900, "B�{�^���ŃX�e�[�W��I��", kColor::White, m_textHandle2);

	int itemX = 0;
	int itemY = 100;
	int itemW = 200;
	int itemH = 250;

	int imageWidth = 910;				// �g�̉���
	int Width = 180;					// ����
	int lineHeight = 210;				// �񂲂Ƃ̏c��
	int linePosH = itemY + lineHeight;	// �񂲂Ƃ̏c���W
	int Height = itemH + lineHeight;	// �c��

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
		
		// �����
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
	//DrawGraph(0, 0, m_starEmpty, true);

	difficultyDraw();

	SceneBase::drawFade();
}

// ��Փx�\��
void SceneSelect::difficultyDraw()
{
	draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starTest, true, false);
	//SetDrawBright(255, 255, 0);
	draw::MyDrawRectRotaGraph(350, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starTest, true, false);
	//SetDrawBright(255, 255, 255);
	draw::MyDrawRectRotaGraph(450, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starTest, true, false);
	draw::MyDrawRectRotaGraph(550, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starTest, true, false);
	draw::MyDrawRectRotaGraph(650, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starTest, true, false);

	if (m_cursorY == 1)
	{
		if (m_cursorX == 1)
		{
			difficulty1Draw();
		}
		if (m_cursorX == 2)
		{
			difficulty1Draw();
		}
		if (m_cursorX == 3)
		{
			difficulty1Draw();
		}
		if (m_cursorX == 4)
		{
			difficulty2Draw();
		}
		if (m_cursorX == 5)
		{
			difficulty2Draw();
		}
	}
	if (m_cursorY == 2)
	{
		if (m_cursorX == 1)
		{
			difficulty1Draw();
		}
		if (m_cursorX == 2)
		{
			difficulty2Draw();
		}
		if (m_cursorX == 3)
		{
			difficulty2Draw();
		}
		if (m_cursorX == 4)
		{
			difficulty3Draw();
		}
		if (m_cursorX == 5)
		{
			difficulty3Draw();
		}
	}
	if (m_cursorY == 3)
	{
		if (m_cursorX == 1)
		{
			difficulty2Draw();
		}
		if (m_cursorX == 2)
		{
			difficulty3Draw();
		}
		if (m_cursorX == 3)
		{
			difficulty4Draw();
		}
		if (m_cursorX == 4)
		{
			difficulty4Draw();
		}
		if (m_cursorX == 5)
		{
			difficulty5Draw();
		}
	}
	if (m_cursorY == 4)
	{
		if (m_cursorX == 1)
		{
			difficulty3Draw();
		}
		if (m_cursorX == 2)
		{
			difficulty5Draw();
		}
		if (m_cursorX == 3)
		{
			difficulty5Draw();
		}
		if (m_cursorX == 4)
		{
			difficulty6Draw();
		}
		if (m_cursorX == 5)
		{
			difficulty6Draw();
		}
	}
}

void SceneSelect::difficulty1Draw()
{
	SetDrawBright(255, 255, 0);
	draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starTest, true, false);
	SetDrawBright(255, 255, 255);
}

void SceneSelect::difficulty2Draw()
{
	SetDrawBright(255, 255, 0);
	draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starTest, true, false);
	draw::MyDrawRectRotaGraph(350, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starTest, true, false);
	SetDrawBright(255, 255, 255);
}

void SceneSelect::difficulty3Draw()
{
	SetDrawBright(255, 255, 0);
	draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starTest, true, false);
	draw::MyDrawRectRotaGraph(350, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starTest, true, false);
	draw::MyDrawRectRotaGraph(450, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starTest, true, false);
	SetDrawBright(255, 255, 255);
}

void SceneSelect::difficulty4Draw()
{
	SetDrawBright(255, 255, 0);
	draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starTest, true, false);
	draw::MyDrawRectRotaGraph(350, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starTest, true, false);
	draw::MyDrawRectRotaGraph(450, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starTest, true, false);
	draw::MyDrawRectRotaGraph(550, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starTest, true, false);
	SetDrawBright(255, 255, 255);
}

void SceneSelect::difficulty5Draw()
{
	SetDrawBright(255, 255, 0);
	draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starTest, true, false);
	draw::MyDrawRectRotaGraph(350, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starTest, true, false);
	draw::MyDrawRectRotaGraph(450, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starTest, true, false);
	draw::MyDrawRectRotaGraph(550, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starTest, true, false);
	draw::MyDrawRectRotaGraph(650, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starTest, true, false);
	SetDrawBright(255, 255, 255);
}

void SceneSelect::difficulty6Draw()
{
	SetDrawBright(255, 255, 0);
	draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starTest, true, false);
	draw::MyDrawRectRotaGraph(350, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starTest, true, false);
	draw::MyDrawRectRotaGraph(450, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starTest, true, false);
	draw::MyDrawRectRotaGraph(550, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starTest, true, false);
	draw::MyDrawRectRotaGraph(650, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starTest, true, false);
	SetDrawBright(255, 0, 0);
	draw::MyDrawRectRotaGraph(750, 50, 0, 0, 32, 32, 2.5f, 0.0f, m_starTest, true, false);
	SetDrawBright(255, 255, 255);
}
