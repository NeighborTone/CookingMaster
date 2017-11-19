#include "Usingheaders.h"
//���C���Q�[���V�[��

bool Game::Initialize()
{
	//�������~�X�`�F�b�N
	if (!BgAni::Initialize() ||
		!Note::Initialize()  ||
		!Player::Initialize()||
		!Sound::Initialize())
	{
		return false;
	}
	return true;		
}
void Game::Update()
{
	Sound::PlayBGM();
	BgAni::Updata();
	Note::Updata();
	Player::Updata();
	if (Key(KEY_INPUT_X) == 1)
	{
		SceneManeger::GetInstance()->ChangeScene(new Title);
	}

}
void Game::Draw()
{
	BgAni::Draw();
	Note::Draw();
	Player::Draw();

}
void Game::Finalize()
{
	BgAni::Fin();
	Sound::Fin();
	Note::Fin();
	Player::Fin();
    //���̕���������ӎ��ł���
	//�����Ə���ɑS��������Ă����

	/*InitGraph();
	InitSoundMem();*/

}
