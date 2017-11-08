#include "DxLib.h"
#include "Task_Title.h"
#include "Input.h"
#include "Game.h"
#include "SceneManager.h"

SceneMgr::SceneMgr() :
	mNextScene(Task_None) //���̃V�[���Ǘ��ϐ�
{
	mScene = (BaseScene*) new Title(this);
}

//������
void SceneMgr::Initialize() {
	mScene->Initialize();
}

//�I������
void SceneMgr::Finalize()
{
	mScene->Finalize();
}

//�X�V
void SceneMgr::Update() {
	if (mNextScene != Task_None)				     //���̃V�[�����Z�b�g����Ă�����
	{    
		mScene->Finalize();							 //���݂̃V�[���̏I�����������s
		delete mScene;
		switch (mNextScene)							 //�V�[���ɂ���ď����𕪊�
		{       
		case Task_Title:					         //���̉�ʂ��^�C�g���Ȃ�
			mScene = (BaseScene*) new Title(this);   //�^�C�g����ʂ̃C���X�^���X�𐶐�����
			break;									 //�ȉ���
		case Task_Game:
			mScene = (BaseScene*) new Game(this);
			break;
		}
		mNextScene = Task_None;						 //���̃V�[�������N���A
		mScene->Initialize();						 //�V�[����������
	}

	mScene->Update();								 //�V�[���̍X�V
}

//�`��
void SceneMgr::Draw() {
	mScene->Draw(); //�V�[���̕`��
}

// ���� nextScene �ɃV�[����ύX����
void SceneMgr::ChangeScene(Scene NextScene) {
	mNextScene = NextScene;    //���̃V�[�����Z�b�g����
}
