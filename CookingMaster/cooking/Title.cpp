#include "Usingheaders.h"
#include "Game_OP.h"
bool Title::Initialize()
{
	sound.Initialize();
	sound.InitBGM();	//����
	sound.SetBGM("./Sound/��������Ⴂ�܂�!.ogg");
	�� = 255 / 3;
	startFlag = false;
	endFlag = false;
	int c[5];
	c[0] = bgHandle = LoadGraph("./Graph/�w�i(��).png");
	c[1] = logo.handle = LoadGraph("./Graph/���S(��).png");
	c[2] = s_button.handle = LoadGraph("./Graph/�X�^�[�g(��).png");
	c[3] = e_button.handle = LoadGraph("./Graph/�G���h(��).png");
	c[4] = cursor.handle = LoadGraph("./Graph/�J�[�\��(��).png");
	for (int i = 0; i < 5; ++i)
	{
		if (c[i] == -1)
		{
			return false;
		}
	}
	logo.pos.SetPOS(480, -300);
	s_button.pos.SetPOS(350, 600);
	e_button.pos.SetPOS(350, 700);
	cursor.pos.SetPOS(-5000, 0);
	cursor.select = Start;
	return true;
}

void Title::Update()
{
	sound.PlayBGM_LOOP();
	float l_dy = (100.f - logo.pos.y) / 20.0f;	//�t���b�ƃ��S���ړ�������
	logo.pos.y += l_dy;
	float s_dy = (300.f - s_button.pos.y) / 20.0f;
	s_button.pos.y += s_dy;
	float e_dy = (400.f - e_button.pos.y) / 22.0f;
	e_button.pos.y += e_dy;
	float c_dx = (290.f - cursor.pos.x) / 15.0f;
	cursor.pos.x += c_dx;
	if (startFlag == false && endFlag == false)
	{
		if (cursor.select == Start && Key(KEY_INPUT_DOWN) == 1)
		{
			cursor.select = End;
		}
		if (cursor.select == End && Key(KEY_INPUT_UP) == 1)
		{
			cursor.select = Start;
		}
		switch (cursor.select)
		{
		case Start:
			cursor.pos.y = s_button.pos.y +10;
			break;
		case End:
			cursor.pos.y = e_button.pos.y +10;
			break;
		}
	}
	if (�� < 0 && endFlag == false)
	{
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//�u�����h���[�h���I�t
		SceneManeger::GetInstance()->ChangeScene(new OP);
	}

	if (�� <= 255 && startFlag == false && endFlag == false)
	{
		�� += 2;
	}
	//�Q�[���J�n
	if (cursor.select == Start && Key(KEY_INPUT_Z) == 1 && �� >= 255)
	{
		sound.PlaySE(bell);
		startFlag = true;
	}
	//�ދ΃x��
	if (cursor.select == End && Key(KEY_INPUT_Z) == 1 && �� >= 255 && CheckSoundMem(sound.SE[bell2]) == 0)
	{
		sound.InitBGM();
		sound.PlaySE(bell2);
		endFlag = true;
		
	}
	//�ދ΃x������I�������I��
	if (CheckSoundMem(sound.SE[bell2]) == 0 && endFlag == true)
	{
		Finalize();
		exit(0);
	}
	if (startFlag == true || endFlag == true)
	{
		�� -= 2;
	}
}

void Title::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, ��);		//�u�����h���[�h����ݒ�
	DrawGraph(0, 0, bgHandle, true);
	DrawRotaGraphF(logo.pos.x, logo.pos.y, 1, 0, logo.handle, true);
	DrawGraphF(s_button.pos.x, s_button.pos.y, s_button.handle, true);
	DrawGraphF(e_button.pos.x, e_button.pos.y, e_button.handle, true);
	DrawGraphF(cursor.pos.x, cursor.pos.y, cursor.handle, true);
}

void Title::Finalize()
{
	InitGraph();
	InitSoundMem();
}