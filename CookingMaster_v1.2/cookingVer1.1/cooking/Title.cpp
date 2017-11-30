#include "Usingheaders.h"

bool Title::Initialize()
{
	bghandle = LoadGraph("./Graph/�^�C�g��.bmp");
	if (bghandle == -1)
	{
		return false;
	}
	return true;
}

void Title::Update()
{
	if (Key(KEY_INPUT_X) == 1)
	{
		SceneManeger::GetInstance()->ChangeScene(new Game);
	}
}

void Title::Draw()
{
	DrawGraph(0, 0, bghandle, true);
}

void Title::Finalize()
{
	InitGraph();
	//InitSoundMem();	//���̂Ƃ��뉹���Ȃ��̂Ŏg��Ȃ�
}