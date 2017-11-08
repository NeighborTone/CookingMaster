#include "DxLib.h"
#include "Task_Title.h"
#include "Input.h"
#include "Game.h"
#include "SceneManager.h"

SceneMgr::SceneMgr() :
	nextscene(Task_None)							//���̃V�[���Ǘ��ϐ�
{
	scene = (BaseScene*) new Title(this);
}

//������
void SceneMgr::Initialize() {
	scene->Initialize();
}

//�I������
void SceneMgr::Finalize()
{
	scene->Finalize();
}

//�X�V
void SceneMgr::Update() 
{
	if (nextscene != Task_None)						 //���̃V�[�����Z�b�g����Ă�����
	{    
		scene->Finalize();							 //���݂̃V�[���̏I�����������s
		delete scene;

		switch (nextscene)							 //�V�[���ɂ���ď����𕪊�
		{       
		case Task_Title:					         //���̉�ʂ��^�C�g���Ȃ�
			scene = (BaseScene*) new Title(this);    //�^�C�g����ʂ̃C���X�^���X�𐶐�����
			break;									 //�ȉ���
		case Task_Game:
			scene = (BaseScene*) new Game(this);
			break;
		}
		nextscene = Task_None;						 //���̃V�[�������N���A
		scene->Initialize();						 //1�x�����V�[����������
	}
	scene->Update();								 //�V�[���̍X�V
}

//�`��
void SceneMgr::Draw()
{
	scene->Draw();									 //�V�[���̕`��
}

// ����NextScene�ɃV�[����ύX����
void SceneMgr::ChangeScene(Scene NextScene) {
	nextscene = NextScene;    //���̃V�[�����Z�b�g����
}
