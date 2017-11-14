#include "DxLib.h"
#include "Input.h"
#include "Player.h"
#include "Game.h"
#include "Note.h"
#include "Sound.h"
#include "BaseInfo.h"
#include "NoteMng.h"

namespace Game {
	int back;

	NoteMng noteMng;
	Player player;

	void Initialize()
	{
		back = LoadGraph("./Graph/bg.png");
		noteMng.Init();
		noteMng.AddNote(180,carrot,right);
		noteMng.AddNote(240, carrot, left);
		player.Init();
		Sound::Initialize();
	}
	void Update()
	{
		//Sound::PlayBGM();
		noteMng.Update();
		player.Update();

	}
	void Draw()
	{
		
		DrawGraph(0, 0, back, true);
		noteMng.Render();
		player.Render();
	
	}
	void Fin()
	{
		Sound::Fin();
		player.Fin();
		DeleteGraph(back);
	}
}