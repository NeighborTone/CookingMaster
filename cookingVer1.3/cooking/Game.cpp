#include "Usingheaders.h"
//���C���Q�[���V�[��
Fps fps;		//�f�o�b�O�p��FPS��\��
Sound sound;
Note note[100];
Player::Cock cock;
File file;
extern const int
SCREEN_WIDIH,
SCREEN_HEIGHT;

extern int score = 0;

Sound GetSound()
{
	return sound;
}

bool Game::Initialize()
{
	//�������~�X�`�F�b�N
	if (
		!Player::Initialize() ||
		!sound.Initialize() ||
		!file.LoadScore() ||
		!Metronome::Initialize())
	{
		return false;
	}
	for (int i = 0; i < 100; ++i)
	{
		note[i].SetScore(i, note[i], file);
	}
	//note[]��Initialze()�̐��ۃ`�F�b�N�͕ʂɍs��
	bool noteInitCheck[100] = {};
	for (int i = 0; i < 100; ++i) 
	{ 
		noteInitCheck[i] = note[i].Initialize();
		if (!noteInitCheck[i]) return false;
	}
	
	
	sound.PlayBGM();
	
	return true;		
}
void Game::Update()
{
	
	Metronome::Update();
	for (int i = 0; i < 100; ++i)
	{
		note[i].Update();
	}
	Player::Update();
	fps.Update();
	if (Key(KEY_INPUT_X) == 1)
	{
		SceneManeger::GetInstance()->ChangeScene(new Title);
	}
	fps.Wait();
}
void Game::Draw()
{
	Metronome::Draw();
	Player::Draw();
	for (int i = 0; i < 100; ++i)
	{
		note[i].Draw();
	}
	//���Ƃŏ���
	DrawFormatString(0, 0, GetColor(255, 0, 0),"���_�F%d", score);
	
	fps.Draw();
}
void Game::Finalize()
{
	Metronome::Fin();
	
	sound.Fin();
	for (int i = 0; i < 100; ++i) 
	{
		note[i].Fin();
	}
	Player::Fin();
    //���̕���������ӎ��ł���
	//�����Ə���ɑS��������Ă����

	/*InitGraph();
	InitSoundMem();*/
}
