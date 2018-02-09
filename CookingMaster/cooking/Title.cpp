#define _USE_MATH_DEFINES
#include "Usingheaders.h"
#include "Game_OP.h"
#include <math.h>

void Raster_Scrool(const float &X, const float &Y, float Cycle, float Shake, float speed,int handle)
{
	const float PI = 3.14159265358979323846f;
	int Width = 0;
	int Height = 0;
	static float Correction = 0;
	GetGraphSize(handle, &Width, &Height);
	for (int i = 0; i < Height; ++i)
	{
		DrawRectGraphF(X - Width / 2.0f + (float)cos((i + Correction) / 180.0f + PI + Cycle) * Shake,
			Y - Height / 2 + i, 0, i, Width, 1, handle, true, false);
	}
	Correction += speed;
}
void BackScroll(int dir, Title::POS& start, float end, float speed, int handle)
{
	enum { Up_Down, sideways };		//�c�����A������
	//�c�����X�N���[��
	if (dir == Up_Down)
	{
		start.y += speed;
		if (speed > 0)
		{
			if (start.y >= end)
			{
				start.y = 0;
			}
			DrawGraphF(start.x, start.y, handle, true);
			DrawGraphF(start.x, start.y - end, handle, true);
		}
		if (speed < 0)
		{
			if (start.y <= -end)
			{
				start.y = 0;
			}
			DrawGraphF(start.x, start.y, handle, true);
			DrawGraphF(start.x, start.y + end, handle, true);
		}
	}
	//�������X�N���[��
	if (dir == sideways)
	{
		start.x += speed;
		if (speed < 0)
		{
			if (start.x <= -end)
			{
				start.x = 0;
			}
			DrawGraphF(start.x, start.y, handle, true);
			DrawGraphF(start.x + end, start.y, handle, true);
		}
		if (speed > 0)
		{
			if (start.x >= end)
			{
				start.x = 0;
			}
			DrawGraphF(start.x, start.y, handle, true);
			DrawGraphF(start.x - end, start.y, handle, true);
		}
	}
}

bool Title::Initialize()
{
	sound.Initialize();
	sound.InitBGM();	
	sound.SetBGM("./Sound/Welcome.ogg");
	a = 255 / 3;
	startFlag = false;
	endFlag = false;
	int c[5];
	c[0] = back.handle = LoadGraph("./Graph/bg_title.png");
	c[1] = logo.handle = LoadGraph("./Graph/logo.png");
	c[2] = s_button.handle = LoadGraph("./Graph/start_button.png");
	c[3] = e_button.handle = LoadGraph("./Graph/exit_button.png");
	c[4] = cursor.handle = LoadGraph("./Graph/cursor.png");

	for (int i = 0; i < 5; ++i)
	{
		if (c[i] == -1)
		{
			return false;
		}
	}
	logo.pos.SetPOS(480, -300);
	s_button.pos.SetPOS(310, 600);
	e_button.pos.SetPOS(310, 700);
	cursor.angle = 0;
	cursor.pos.SetPOS(-5000, 0);
	cursor.select = Start;
	speed = 10;
	cycle = 10;
	shake = 10;
	return true;
}

void Title::Update()
{
	
	sound.PlayBGM_LOOP();
	float l_dy = (150.f - logo.pos.y) / 20.0f;	//�t���b�ƃ��S���ړ�������
	logo.pos.y += l_dy;
	float s_dy = (300.f - s_button.pos.y) / 20.0f;
	s_button.pos.y += s_dy;
	float e_dy = (400.f - e_button.pos.y) / 22.0f;
	e_button.pos.y += e_dy;
	float c_dx = (250.f - cursor.pos.x) / 15.0f;
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
			cursor.pos.y = s_button.pos.y +40;
			break;
		case End:
			cursor.pos.y = e_button.pos.y +40;
			break;
		}
	}
	if (startFlag == true && a < 255)
	{
		if(cursor.angle <= 45)
			++cursor.angle;
		else
		{
			float c_dx2 = (400.f - cursor.pos.x) / 15.0f;
			cursor.pos.x += c_dx2;
		}
	}
	if (endFlag == true && a < 255)
	{
		if (cursor.angle <= 45)
			++cursor.angle;
		else
		{
			float c_dx2 = (410.f - cursor.pos.x) / 15.0f;
			cursor.pos.x += c_dx2;
		}
	}
	if (a < 0 && endFlag == false)
	{
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//�u�����h���[�h���I�t
		SetDrawMode(DX_DRAWMODE_NEAREST);	//����
		SceneManeger::GetInstance()->ChangeScene(new OP);
	}

	if (a <= 255 && startFlag == false && endFlag == false)
	{
		a += 2;
	}
	//�Q�[���J�n
	if (cursor.select == Start && Key(KEY_INPUT_Z) == 1 && a >= 255)
	{
		sound.PlaySE(bell);
		startFlag = true;
	}
	//�ދ΃x��
	if (cursor.select == End && Key(KEY_INPUT_Z) == 1 && a >= 255 && CheckSoundMem(sound.SE[bell2]) == 0)
	{
		sound.InitBGM();
		sound.PlaySE(bell2);
		endFlag = true;
		++cursor.angle;
	}
	//�ދ΃x������I�������I��
	if (CheckSoundMem(sound.SE[bell2]) == 0 && endFlag == true)
	{
		Finalize();
		exit(0);
	}
	if (startFlag == true || endFlag == true)
	{
		a -= 2;
	}
	
	
}

void Title::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, a);		//�u�����h���[�h����ݒ�
	SetDrawMode(DX_DRAWMODE_BILINEAR);				//�����s�N�Z�����
	//BackScroll(1, back.pos, 960, 3, back.handle);
	DrawGraph(0, 0, back.handle, true);
	Raster_Scrool(logo.pos.x, logo.pos.y, cycle,shake,speed, logo.handle);
	DrawGraphF(s_button.pos.x, s_button.pos.y, s_button.handle, true);
	DrawGraphF(e_button.pos.x, e_button.pos.y, e_button.handle, true);
	DrawRotaGraphF(cursor.pos.x, cursor.pos.y,1, cursor.angle * static_cast<float>(M_PI) / 180.f, cursor.handle, true);
}

void Title::Finalize()
{
	InitGraph();
	InitSoundMem();
}