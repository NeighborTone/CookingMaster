#include "Input.h"
#include "Task_Title.h"
#include "DxLib.h"
#include "titlt_aaa.h"
static const int
SCREEN_WIDIH = 960,
SCREEN_HEIGHT = 540;
Title::Title(ISceneChanger* changer) : BaseScene(changer)
{

}

//������
void Title::Initialize() 
{
	Title_G::Initialize();
}

//�X�V
void Title::Update() 
{
	if (Key(KEY_INPUT_X) == 1) //X�L�[��������Ă����� 
	{   
		mSceneChanger->ChangeScene(Task_Game);//�V�[�������j���[�ɕύX
	}
}

//�`��
void Title::Draw() 
{
	Title_G::Draw();
}

void Title::Finalize()
{
	BaseScene::Finalize();//�e�N���X�̏I�����\�b�h���Ă�
}