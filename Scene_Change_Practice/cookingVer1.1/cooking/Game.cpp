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
	if (!BgAni::Initialize() ||
		!Note::Initialize()  ||
		!Player::Initialize()||
		!sound.Initialize()  ||
		!Note::LoadScore()   ||
		!BGM::Initialize() )
	{
		return false;
	}
	sound.PlayBGM();
	
	return true;		
}
void Game::Update()
{
	BgAni::Updata();
	
	Note::Updata();
	Player::Updata();
	fps.Update();
	BGM::Updata();
	if (Key(KEY_INPUT_X) == 1)
	{
		SceneManeger::GetInstance()->ChangeScene(new Title);
	}
	fps.Wait();
}
void Game::Draw()
{
	BgAni::Draw();
	BGM::Draw();
	Note::Draw();
	Player::Draw();
	fps.Draw(); 
}
void Game::Finalize()
{
	BgAni::Fin();
	sound.Fin();
	Note::Fin();
	Player::Fin();
	BGM::Fin();
    //���̕���������ӎ��ł���
	//�����Ə���ɑS��������Ă����

	/*InitGraph();
	InitSoundMem();*/
}
