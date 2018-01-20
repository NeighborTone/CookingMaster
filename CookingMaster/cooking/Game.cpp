#include "Usingheaders.h"
#include "Game_OP.h"
//���C���Q�[���V�[��
#if _DEBUG
Fps fps;		//�f�o�b�O�p��FPS��\��
#endif
Sound sound;
Note note[noteMax];
File file;
extern const int
SCREEN_WIDIH,
SCREEN_HEIGHT;



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
	for (int i = 0; i < noteMax; ++i)
	{
		note[i].SetScore(i, note[i], file);
	}
	//note[]��Initialze()�̐��ۃ`�F�b�N�͕ʂɍs��
	bool noteInitCheck[noteMax] = {};
	for (int i = 0; i < noteMax; ++i)
	{ 
		noteInitCheck[i] = note[i].Initialize();
		if (!noteInitCheck[i]) return false;
	}
	
	
	sound.PlayBGM_BACK();
	
	return true;		
}
void Game::Update()
{
	
	Metronome::Update();
	for (int i = 0; i < noteMax; ++i)
	{
		note[i].Update();
	}
	Player::Update();
#if _DEBUG
	fps.Update();
	if (Key(KEY_INPUT_X) == 1)
	{
		SceneManeger::GetInstance()->ChangeScene(new Result);
	}
	fps.Wait();
#endif
}
void Game::Draw()
{
	Metronome::Draw();
	Player::Draw();
	for (int i = 0; i < noteMax; ++i)
	{
		note[i].Draw();
	}
#if _DEBUG
	DrawFormatString(0, 0, GetColor(255, 0, 0),"���_�F%d", Score());
	
	fps.Draw();
#endif
	if (GetSoundCurrentTime(sound.BGM) >= GetSoundTotalTime(sound.BGM) - 100)	//�Ȃ��I������烊�U���g��
	{
		SceneManeger::GetInstance()->ChangeScene(new Result);
	}
}
void Game::Finalize()
{
	Metronome::Fin();
	
	sound.Fin();
	for (int i = 0; i < noteMax; ++i)
	{
		note[i].Fin();
	}
	Player::Fin();
    //���̕���������ӎ��ł���
	//�����Ə���ɑS��������Ă����

	/*InitGraph();
	InitSoundMem();*/
}
