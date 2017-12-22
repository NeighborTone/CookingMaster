#include "Usingheaders.h"

bool Result::Initialize()
{
	
	bghandle = LoadGraph("./Graph/���U���g.png");
	if (bghandle == -1)
	{
		return false;
	}
	return true;
}

void Result::Update()
{
	if (Key(KEY_INPUT_X) == 1)
	{
		SceneManeger::GetInstance()->ChangeScene(new Title);
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
	if (Score() <= 50)
	{
		DrawFormatString(0, 0, GetColor(0, 0, 0), "50�_�ȉ��ł�m9(^�D^)�߷ެ�");
	}
}

void Result::Finalize()
{
	InitGraph();
	//InitSoundMem();	//���̂Ƃ��뉹���Ȃ��̂Ŏg��Ȃ�
}