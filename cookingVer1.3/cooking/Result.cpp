#include "Usingheaders.h"
#include "easing.hpp"
#define PI 3.141592654

bool Result::Initialize()
{
	a = 0;
	c = 0;
	flag = false;
	bghandle = LoadGraph("./Graph/result.png");
	sound.SetBGM("./Sound/肉を焼く.ogg");

	
	Rcarrot = LoadGraph("./Graph/Rcarrot.png");
	Rcabbage = LoadGraph("./Graph/Rcabbage.png");
	Rpotato = LoadGraph("./Graph/Rpotato.png");
	Rtomato = LoadGraph("./Graph/Rtomato.png");
	Rbrory = LoadGraph("./Graph/Rbroccoli.png");
	Ronion = LoadGraph("./Graph/Ronion.png");

	cabbage0.pos.SetPOS(300, 0);
	cabbage1.pos.SetPOS(500, 0);
	cabbage2.pos.SetPOS(400, 0);
	cabbage3.pos.SetPOS(600, 0);

	if (bghandle == -1)
	{
		return false;
	}
	return true;
}


void Result::Update()
{
	sound.PlayBGM_BACK();
	
	if (a <= 255)
	{
		a += 3;
	}
	if (a >= 255)
	{
		
	}
	if(cabbage0.pos.y <= 400)
	cabbage0.pos.y = easing::BounceOut(c, 0, 400.f - 0, 10.f);
	//easing::BounceOut(1, cabbage0.pos.x, 300 - cabbage0.pos.x, 1);
	/*PutAni(cabbage0, 100);
	PutAni(cabbage1, 400);
	PutAni(cabbage2, 300);
	PutAni(cabbage3, 200);*/

	if (Key(KEY_INPUT_Z) == 1)
	{
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
		SceneManeger::GetInstance()->ChangeScene(new Title);
		Score() = 0;
	}
	c += 0.1f;
}

void Result::Draw()
{
	
	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, a);		//ブレンドモードαを設定
	DrawGraph(0, 0, bghandle, true);
	if (Score() >= 100 && Score() < 200)
	{
		DrawFormatString(0, 0, GetColor(0, 0, 0), "100点以上です");
	}
	if (Score() >= 200)
	{
		DrawFormatString(0, 0, GetColor(0, 0, 0), "200点以上です");
	}
	if (Score() < 100)
	{
		DrawFormatString(0, 0, GetColor(0, 0, 0), "100点未満ですm9(^Д^)ﾌﾟｷﾞｬｰ");
	}
	DrawRotaGraphF(cabbage0.pos.x, cabbage0.pos.y, 1.0, PI / 4, Rcabbage, true);
	DrawRotaGraphF(cabbage1.pos.x, cabbage1.pos.y, 1.0, 0.0, Rcabbage, true);
	DrawRotaGraphF(cabbage2.pos.x, cabbage2.pos.y, 1.0, 0.0, Rcabbage, true);
	DrawRotaGraphF(cabbage3.pos.x, cabbage3.pos.y, 1.0, 0.0, Rcabbage, true);
	DrawFormatString(0, 100, GetColor(0, 0, 0), "%.3f", cabbage0.pos.y);
}

void Result::Finalize()
{
	InitGraph();
	InitSoundMem();
}



//void Result::PutAni(Food& f, float y) 
//{
	//float l_dy = (y - f.pos.y) / 50.0f;	//フワッとロゴを移動させる
	//f.pos.y += l_dy;

	//easing::BounceOut(30, f.pos.y, y - f.pos.y, 50);

//}
