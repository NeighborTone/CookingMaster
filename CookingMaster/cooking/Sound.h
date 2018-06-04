#pragma once
constexpr int SENUM = 11;
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
	grill,			//�Ă�8
	bell,			//���X���i�x���j9
	bell2,			//�ދΉ�10

};


class Sound 
{
private:

	
	bool   flag;

public:

	TYPE se_type;
	int  SE[SENUM];
	int  BGM;
	bool Initialize();
	void SetBGM(const TCHAR *FileName);	//BGM�Ƃ��Ďg�������t�@�C���̃p�X���w��
	int  PlayBGM_BACK();				//BGM���o�b�N�O���E���h�Đ��i���[�v�Ȃ��j
	int  PlayBGM_LOOP();				//BGM�����[�v�Đ�
	void InitBGM();						//���݊i�[����Ă���BGM�f�[�^��������A�Đ��t���O�̍ăZ�b�g
	void PlaySE(int);					//enum�^��ID���w��
	void Fin();							//�S�f�[�^�J��

};