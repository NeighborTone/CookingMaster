#include "Usingheaders.h"

namespace Note {

	static const int
		SCREEN_WIDIH = 960,
		SCREEN_HEIGHT = 540,
		QUARTER_NOTE = 461;				//���Y���̍ŏ��P��(4������)
	double	second = 60.0;
	Note note;
	TYPE se_type;
	constexpr int num = 500;		//�Ƃ肠����������500�����
	POS start, dir, end;			//�Ȑ��̊J�n�_�A�����_�A�I�_���W
	

	bool LoadScore()
	{
		//���ʓǂݍ���
		ifstream ifs_noteJust("./ScoreData/Scoredata.csv");		//�����̃W���X�g�̔���^�C�~���O
		ifstream ifs_type("./ScoreData/type.csv");				//�����̉摜��SE�̃f�[�^
		
		note.notenum = 0;
		note.IDnum = 0;
		//�J���Ȃ�������G���[
		if (!ifs_noteJust || !ifs_type)
		{
			return false;
		}
		
		
		string s_just;
		string s_type;
		string s_appear;
		int i = 0;
		int j = 0;
		int s = 0;
		

		while(getline(ifs_noteJust,s_just,'\n'))
		{
			//�������int�^�ɕϊ�
			note.just_Note[i] = stoi(s_just);
			++i;
			if (i > num)
			{
				break;
			}
		}
		while (getline(ifs_type, s_type, '\n'))
		{
			//�������int�^�ɕϊ�
			note.ID[j] = stoi(s_type);
			++j;
			if (j > num)
			{
				break;
			}
		}
		return true;
	}

	bool Initialize()
	{

		int cheak = LoadDivGraph("./Graph/carrot.png", 4, 4, 1, 100, 100, note.picHandle);
		note.pos.x = SCREEN_WIDIH + 50;
		note.pos.y = SCREEN_HEIGHT / 2;
		note.Cnt = 0;
		note.animeCnt = 0;
		note.time = 0;
		note.type = one;
		note.speed = 17.0f * 2.2f;
		note.start.x = note.pos.x;
		note.start.y = note.pos.y;
		note.end.x = SCREEN_WIDIH / 2;
		note.end.y = SCREEN_HEIGHT / 2 + 160;
		note.state = come;
		note.notenum = 0;


		note.dir.x = fabs(note.start.x - note.end.x) / 2 + note.end.x;
		note.dir.y = 100;

		
		
		if (cheak == -1)
		{
			return false;
		}
		return true;
	}

	void Update()
	{
		
		Sound GetSound();
		auto sound = GetSound();
		
		note.current = GetSoundCurrentTime(sound.BGM);
		//�o��
		/*if (note.current >= appear_Time)
		{
			sound.PlaySE(appear);
			++note.notenum;
			
		}*/
		//����
		if (note.current >= note.just_Note[note.IDnum])
		{
			sound.PlaySE(carrot);
			++note.IDnum;

		}
		

		//BezierCurve2(&note, note.start, note.dir, note.end);

		


	}

	void Draw()
	{

		if (note.state == come)	//���ʑO�̉���
		{
			DrawRotaGraph(int(note.pos.x), int(note.pos.y), 1.0, 0.0, note.picHandle[0], true);		
		}
		if (note.state == cut)	//���������񂾂�A�j���[�V����
		{
			DrawRotaGraph(int(note.pos.x), int(note.pos.y), 1.0, 0.0, note.picHandle[note.animeCnt / 2], true);		
		}

		Sound GetSound();
		auto sound = GetSound();
		
		DrawFormatString(0, 80, GetColor(0, 0, 0), "(�T�E���h�N���X��)���݂̍Đ��ʒu%d", GetSoundCurrentTime(sound.BGM));
		DrawFormatString(0, 40, GetColor(0, 0, 0), "�o��������:%d", note.notenum);
		DrawFormatString(0, 20, GetColor(0, 0, 0), "����ς݂̉���:%d", note.IDnum);
		
	}

	void Fin()
	{
		for (int i = 0; i < 4; ++i)
		{
			DeleteGraph(note.picHandle[i]);
		}

	}
}
