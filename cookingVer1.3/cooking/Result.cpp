#include "Usingheaders.h"

bool Result::Initialize()
{
	flag = false;
	bghandle = LoadGraph("./Graph/���U���g.png");
	sound.SetBGM("./Sound/�����Ă�.ogg");
	if (bghandle == -1)
	{
		return false;
	}
	return true;
}

void Result::Update()
{
	sound.PlayBGM_BACK();
	if (Key(KEY_INPUT_X) == 1)
	{
		SceneManeger::GetInstance()->ChangeScene(new Title);
		Score() = 0;
	}
}

void Result::Draw()
{
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
}

void Result::Finalize()
{
	InitGraph();
	InitSoundMem();
}