#define _USE_MATH_DEFINES
#include "Usingheaders.h"
#include <math.h>
extern const int
SCREEN_WIDIH,
SCREEN_HEIGHT;
float OutBounce(float t, float totaltime, float max, float min)
{
	max -= min;
	t /= totaltime;

	if (t < 1 / 2.75f)
		return max*(7.5625f*t*t) + min;
	else if (t < 2 / 2.75f)
	{
		t -= 1.5f / 2.75f;
		return max*(7.5625f*t*t + 0.75f) + min;
	}
	else if (t< 2.5f / 2.75f)
	{
		t -= 2.25f / 2.75f;
		return max*(7.5625f*t*t + 0.9375f) + min;
	}
	else
	{
		t -= 2.625f / 2.75f;
		return max*(7.5625f*t*t + 0.984375f) + min;
	}
}
bool Title::Initialize()
{
	�� = 255 / 3;
	flag = false;
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
	float l_dy = (100.f - logo.pos.y) / 20.0f;	//�t���b�ƃ��S���ړ�������
	logo.pos.y += l_dy;
	float s_dy = (300.f - s_button.pos.y) / 20.0f;
	s_button.pos.y += s_dy;
	float e_dy = (400.f - e_button.pos.y) / 22.0f;
	e_button.pos.y += e_dy;
	float c_dx = (290.f - cursor.pos.x) / 15.0f;
	cursor.pos.x += c_dx;
	if (flag == false)
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
	if (�� < 0)
	{
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//�u�����h���[�h���I�t
		SceneManeger::GetInstance()->ChangeScene(new Game);
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
	if (�� <= 255 && flag == false)
	{
		�� += 2;
	}
	if (cursor.select == Start && Key(KEY_INPUT_Z) == 1 && �� >= 255)
	{
		flag = true;
	}
	if (cursor.select == End && Key(KEY_INPUT_Z) == 1)
	{
		Finalize();
		exit(0);
	}
	if (flag == true)
	{
		�� -= 2;
	}

}

void Title::Finalize()
{
	InitGraph();
	//InitSoundMem();	//���̂Ƃ��뉹���Ȃ��̂Ŏg��Ȃ�
}