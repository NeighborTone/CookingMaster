#pragma once
typedef enum
{
	Task_Title,		//�^�C�g��
	Task_Game,		//�Q�[�����


	Task_None,		//����
	
} Scene;

//�V�[����ύX���邽�߂̃C���^�[�t�F�C�X�N���X
class ISceneChanger
{
public:
	virtual ~ISceneChanger() = 0;
	virtual void ChangeScene(Scene NextScene) = 0;//�w��V�[���ɕύX����
};