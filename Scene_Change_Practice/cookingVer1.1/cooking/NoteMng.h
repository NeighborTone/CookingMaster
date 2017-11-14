#pragma once
#include "BaseInfo.h"
#include "Note.h"
#include <vector>

using namespace std;

//Note�N���X�̃C���X�^���X�̑���������
class NoteMng {
private:
	int timeCnt;		//�Q�[�������Ԃ��J�E���g
	vector<Note> note;	//Note�N���X�̃C���X�^���X�𓮓I�z��Ő���
	size_t size;		//�o�^����Ă���f�[�^�̐�

public:
	NoteMng();											//�R���X�g���N�^
	~NoteMng();											//�f�X�g���N�^
	void Init();										//������
	void AddNote(float hitFlame, Vege v, Direction d);	//note�R���e�i�̖��[�Ƀf�[�^��ǉ�
	void Update();										//���Ԍo�߃J�E���^
	void NoteAppear();									//Note���o��������
	void Render();										//Note�̕`��
};