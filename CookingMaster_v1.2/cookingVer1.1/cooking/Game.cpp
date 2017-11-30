#include "Usingheaders.h"
//���C���Q�[���V�[��
Fps fps;		//�f�o�b�O�p��FPS��\��
Sound sound;
Note note;
static const int
SCREEN_WIDIH = 960,
SCREEN_HEIGHT = 540;
Sound GetSound()
{
	return sound;
}

bool Game::Initialize()
{

	//�������~�X�`�F�b�N
	if (
		!note.Initialize()   ||
		!Player::Initialize()||
		!sound.Initialize()  ||
		!note.LoadScore()    ||
		!Metronome::Initialize())
	{
		return false;
	}
	sound.PlayBGM();
	
	return true;		
}
void Game::Update()
{
	
	Metronome::Update();
	note.Update();
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
	
	note.Draw();
	Player::Draw();
	fps.Draw();
}
void Game::Finalize()
{
	Metronome::Fin();
	
	sound.Fin();
	note.Fin();
	Player::Fin();
    //���̕���������ӎ��ł���
	//�����Ə���ɑS��������Ă����

	/*InitGraph();
	InitSoundMem();*/
}
