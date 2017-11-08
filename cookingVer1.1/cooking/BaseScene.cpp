#include "BaseScene.h"
#include "DxLib.h"

BaseScene::BaseScene(ISceneChanger* changer) :
	mImageHandle(0)
{
	mSceneChanger = changer;
}

void BaseScene::Finalize()	//�V�[���I������1�x�������s�����
{
	InitGraph();			//�ǂݍ��񂾂��ׂẲ摜�����
	InitSoundMem();			//�ǂݍ��񂾂��ׂẲ��y�t�@�C�������
}

void BaseScene::Draw()
{
	
}