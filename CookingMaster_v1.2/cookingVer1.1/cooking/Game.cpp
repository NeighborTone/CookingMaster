#include "Usingheaders.h"
//���C���Q�[���V�[��
Fps fps;		//�f�o�b�O�p��FPS��\��
Sound sound;

Sound GetSound()
{
	return sound;
}

bool Game::Initialize()
{

	//�������~�X�`�F�b�N
	if (
		!Note::Initialize()  ||
		!Player::Initialize()||
		!sound.Initialize()  ||
		!Note::LoadScore()   ||
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
	Note::Update();
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
	
	Note::Draw();
	Player::Draw();
	fps.Draw();
}
void Game::Finalize()
{
	Metronome::Fin();
	
	sound.Fin();
	Note::Fin();
	Player::Fin();
    //���̕���������ӎ��ł���
	//�����Ə���ɑS��������Ă����

	/*InitGraph();
	InitSoundMem();*/
}
