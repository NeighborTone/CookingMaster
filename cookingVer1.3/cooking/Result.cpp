#include "Usingheaders.h"

bool Result::Initialize()
{
	
	h1.pos.SetPOS(1200, 200);
	h2.pos.SetPOS(2000, 250);
	h3.pos.SetPOS(3000, 300);
	a = 0;
	flag = false;
	bghandle = LoadGraph("./Graph/���U���g.png");
	sound.SetBGM("./Sound/�����Ă�.ogg");

	food.pic_carrot = LoadGraph("./Graph/carrot.png");
	food.pic_cabbage = LoadGraph("./Graph/cabbage.png");
	food.pic_potato = LoadGraph("./Graph/potato.png");
	food.pic_tomato = LoadGraph("./Graph/tomato.png");
	food.pic_broccoli = LoadGraph("./Graph/broccoli.png");
	food.pic_onion = LoadGraph("./Graph/onion.png");
	if (bghandle == -1)
	{
		return false;
	}
	return true;
}

void Result::Update()
{
	float l_dy = (150.f - h1.pos.x) / 20.0f;	//�t���b�ƃ��S���ړ�������
	h1.pos.x += l_dy;
	float s_dy = (150.f - h2.pos.x) / 20.0f;
	h2.pos.x += s_dy;
	float e_dy = (150.f - h3.pos.x) / 20.0f;
	h3.pos.x += e_dy;
	sound.PlayBGM_BACK();
	if (a <= 255)
	{
		a += 3;
	}
	if (a >= 255)
	{
		
	}
	
	if (Key(KEY_INPUT_Z) == 1)
	{
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//�u�����h���[�h���I�t
		SceneManeger::GetInstance()->ChangeScene(new Title);
		Score() = 0;
	}
}

void Result::Draw()
{
	
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, a);		//�u�����h���[�h����ݒ�
	DrawGraph(0, 0, bghandle, true);
	if (Score() >= 100 && Score() < 200)
	{
		DrawFormatString(0, 0, GetColor(0, 0, 0), "100�_�ȏ�ł�");
	}
	if (Score() >= 200)
	{
		DrawFormatString(0, 0, GetColor(0, 0, 0), "200�_�ȏ�ł�");
	}
	if (Score() < 100)
	{
		DrawFormatString(0, 0, GetColor(0, 0, 0), "100�_�����ł�m9(^�D^)�߷ެ�");
	}
	DrawFormatStringF(h1.pos.x, h1.pos.y, GetColor(0, 0, 0), "�Ȃ񂩂������z");
	DrawFormatStringF(h2.pos.x, h2.pos.y, GetColor(0, 0, 0), "�Ȃ񂩂������z");
	DrawFormatStringF(h3.pos.x, h3.pos.y, GetColor(0, 0, 0), "�Ȃ񂩂������z");
}

void Result::Finalize()
{
	InitGraph();
	InitSoundMem();
}