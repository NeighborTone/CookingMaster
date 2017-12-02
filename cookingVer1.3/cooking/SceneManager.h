#pragma once

//�V�[���Ǘ����N���X

class SceneManeger
{
protected:
	static SceneManeger* instance;
	std::stack<Scene*> scenes;
private:
	static void DestroyThis()
	{
		delete instance;		//�V�[���̃������������
	}
public:
	explicit SceneManeger() {}
	virtual ~SceneManeger() {}

	static SceneManeger* GetInstance()			
	{
		if (!instance)
		{
			instance = new SceneManeger();		//�C���X�^���X����Ȃ�V�����V�[����o�^
			atexit(DestroyThis);				//�v���O�������I������Ƃ��Ɏ��s�����
		}
		return instance;
	}
		
	//�V�[���̒ǉ�
	//�����͌Ăяo�������V�[���̃|�C���^
	//���C�����[�v�O�ɌĂяo�����AChangeScene�Ŏw�肵���V�[����ǉ�����
	//�V�[���̏��������������s���Ă���Ȃ�true
	bool PushScene(Scene* s_)
	{
		if (s_ && !s_->Initialize())	
		{
			return false;
		}
		scenes.push(s_);		//�V�����V�[����ǉ�
		return true;
	}

	//�V�[���̍폜
	//ChangeScene�Ŏ��̃V�[���Ɉڍs����Ƃ��ɍs����
	//�폜�ɐ���������true
	bool PullScene()
	{
		if (scenes.empty())
		{
			return false;		//�V�[�����Ȃ����false
		}
		auto s = scenes.top();	//�O�̃V�[�����Q��
		s->Finalize();			//�O�̃V�[���̏I������
		delete s;				//�O�̃V�[�����̃������̊J��
		return true;
	}

	//�V�[���̐؂�ւ�
	//�����ɃV�[������new�Ŏw�肷��
	//PullScene��PushScene���s����
	void ChangeScene(Scene* s_)
	{
		PullScene();
		PushScene(s_);
	}

	//���݉f���Ă���V�[�����Q�Ƃ���
	//���C�����[�v�ɏ����ׂ�����
	//��ɍX�V�����A�`�揈�����Q�Ƃ���
	Scene* GetCurrentScene() const
	{
		return scenes.top();
	}

	//���ݍĐ�����V�[�����X�^�b�N�̒��Ɏc���Ă��邩���ׂ�
	//���[�v�̏����ɒǉ�����
	//
	bool isEmpty()
	{
		return scenes.empty();		//�v�f���i�V�[���j���󂩂ǂ������ׂ�
	}

};