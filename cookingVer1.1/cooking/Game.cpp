#include "DxLib.h"
#include "Input.h"
#include "Player.h"
#include "Game.h"
#include "Note.h"
#include "Sound.h"
#include "BgAni.h"

static const int
SCREEN_WIDIH = 960,
SCREEN_HEIGHT = 540;
Game::Game(ISceneChanger* changer) : BaseScene(changer) 
{
}

//������
void Game::Initialize() {
	BgAni::Initialize();
	Note::Initialize();
	Player::Initialize();
	Sound::Initialize();
}

//�X�V
void Game::Update() {
	if (Key(KEY_INPUT_X) == 1) //X�L�[��������Ă�����
	{ 
		mSceneChanger->ChangeScene(Task_Title);//�V�[�����^�C�g���ɕύX
	}
	//Sound::PlayBGM();
	BgAni::Update();
	Note::Update();
	Player::Update();
}

//�`��
void Game::Draw()
{
	BaseScene::Draw();//�e�N���X�̕`�惁�\�b�h���Ă�
	BgAni::Draw();
	Note::Draw();
	Player::Draw();
}

//�I��
void Game::Finalize()
{
	BaseScene::Finalize();//�e�N���X�̏I�����\�b�h���Ă�
}
