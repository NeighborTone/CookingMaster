#pragma once
enum TYPE
{

	appear,			//�����o����0
	carrot,			//�j���W��1
	onion,			//�^�}�l�M2
	broccoli,		//�u���b�R���[3
	cabbage,		//�L���x�c4
	tomato,			//�g�}�g5
	potato,			//�W���K�C��6
	mouse,			//�l�Y�~7




	meat,			//��8
	cuttingboard,	//�܂Ȕ�9
	simmer,			//�ς�10
	grill,			//�Ă�11
	jump,			//�W�����v12
	slash,			//�؂�13
	bell,			//���X���i�x���j14
	bell2,			//�ދΉ�15

};


class Sound 
{
private:

	static constexpr int SENUM = 20;
	bool   flag;

public:

	TYPE se_type;
	int    SE[SENUM];
	int    BGM;
	bool Initialize();
	void SetBGM(const TCHAR *FileName);	//BGM�Ƃ��Ďg�������t�@�C���̃p�X���w��
	int  PlayBGM_BACK();				//BGM���o�b�N�O���E���h�Đ��i���[�v�Ȃ��j
	int  PlayBGM_LOOP();				//BGM�����[�v�Đ�
	void InitBGM();						//���݊i�[����Ă���BGM�f�[�^��������A�Đ��t���O�̍ăZ�b�g
	int  PlaySE(int);					//enum�^��ID���w��A�߂�l��0
	void Fin();							//�S�f�[�^�J��

};