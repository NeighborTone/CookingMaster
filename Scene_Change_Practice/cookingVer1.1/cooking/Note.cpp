#include "Usingheaders.h"

namespace Note {

	static const int
		SCREEN_WIDIH = 960,
		SCREEN_HEIGHT = 540;
	double	second = 60.0;
	Note note;
	TYPE se_type;
	constexpr int num = 500;		//�Ƃ肠����������500�܂�
	POS start, dir, end;			//�Ȑ��̊J�n�_�A�����_�A�I�_���W
	int notetime;	//��������^�C�~���O�A��Œ���
	bool flag = false;	//����p

	bool LoadScore()
	{
		//���ʓǂݍ���
		ifstream ifs_appear("./ScoreData/test.csv");
		ifstream ifs_type("./ScoreData/type.csv");
		note.notenum = 0;
		note.notetype = 0;
		//�J���Ȃ�������G���[
		if (!ifs_appear || !ifs_type)
		{
			return false;
		}
		
		
		string s_appper;
		string s_type;
		int i = 0;
		int j = 0;
		note.appear_note[num];

		while(getline(ifs_appear,s_appper,'\n'))
		{
			//�������int�^�ɕϊ�
			note.appear_note[i] = stoi(s_appper);
			++i;
			if (i > num)
			{
				break;
			}
		}
		while (getline(ifs_type, s_type, '\n'))
		{
			//�������int�^�ɕϊ�
			note.play_note_type[j] = stoi(s_type);
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
		

		note.dir.x = fabs(note.start.x - note.end.x) / 2 + note.end.x;
		note.dir.y = 100;
		notetime = 3692;
		
		
		if (cheak == -1)
		{
			return false;
		}
		return true;
	}

	void Updata()
	{
		Sound GetSound();
		auto sound = GetSound();

		note.current = GetSoundCurrentTime(sound.BGM);

		if (note.current >= note.appear_note[note.notenum] && note.play_note_type[note.notetype] == appear) //�o��
		{
			++note.notenum;
			++note.notetype;
			notetime += 461;
			sound.PlaySE(appear);
			flag = false;
		}

	
		if (note.current >= notetime - 100 && flag == false)
		{
			
			if (Key(KEY_INPUT_Z) == 1)
			{
				flag = true;
				sound.PlaySE(carrot);
			}
			
		}
		if (note.current >= notetime + 100)
		{
			if (Key(KEY_INPUT_Z) == 1 && flag == false)
			{
				sound.PlaySE(carrot);
				flag = true;
			}
			++note.notenum;
			++note.notetype;
			notetime += 461;
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
		DrawFormatString(0, 40, GetColor(0, 0, 0), "�o��������%d", note.notenum);
		DrawFormatString(0, 20, GetColor(0, 0, 0), "�����̎��%d", note.play_note_type[note.notetype]);
		
	}

	void Fin()
	{
		for (int i = 0; i < 4; ++i)
		{
			DeleteGraph(note.picHandle[i]);
		}

	}
}
