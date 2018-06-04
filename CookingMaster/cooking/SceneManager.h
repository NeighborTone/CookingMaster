#pragma once
//�V�[���Ǘ����N���X
#include "Scene.h"
#include <stack>

class SceneManeger
{
protected:
	static SceneManeger* instance;
	Scene* currentScene = nullptr;


private:

public:
	explicit SceneManeger() {}
	virtual ~SceneManeger() { }

	static void DestroyThis()
	{
		if (instance != nullptr)
		{
			delete instance;		//�V�[���̃����������
		}

	}

	static SceneManeger* GetInstance()
	{
		if (!instance)
		{
			instance = new SceneManeger();		//�C���X�^���X����Ȃ�V�����V�[����o�^
			atexit(DestroyThis);					//�v���O�������I������Ƃ��Ɏ��s�����
		}
		return instance;
	}

	//�V�[���̒ǉ�
	//�����͌Ăяo�������V�[���̃|�C���^
	//���C�����[�v�O�ɌĂяo�����AChangeScene�Ŏw�肵���V�[����ǉ�����
	//�V�[���̏��������������s���Ă���Ȃ�true
	bool InsertScene(Scene* s_)
	{
		if (s_ && !s_->Initialize())
		{
			return false;
		}
		currentScene = s_;
		return true;
	}

	//�V�[���̐؂�ւ�
	//�����ɃV�[������new�Ŏw�肷��
	//PullScene��PushScene���s����
	bool ChangeScene(Scene* s_)
	{
		if (currentScene != nullptr) {
			currentScene->Finalize();
			delete currentScene;
			currentScene = nullptr;
		}
		return InsertScene(s_);
	}

	//���݉f���Ă���V�[�����Q�Ƃ���
	//���C�����[�v�ɏ����ׂ�����
	//��ɍX�V�����A�`�揈�����Q�Ƃ���
	Scene* GetCurrentScene() const
	{
		return currentScene;
	}

};