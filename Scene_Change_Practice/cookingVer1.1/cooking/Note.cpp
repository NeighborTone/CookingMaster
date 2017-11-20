#include "Usingheaders.h"


using namespace Sound;

namespace Note {

	static const int
		SCREEN_WIDIH = 960,
		SCREEN_HEIGHT = 540;
	double	second = 60.0;
	Sound::SETYPE se_type;
	Note note;
	POS start, dir, end;  //�Ȑ��̊J�n�_�A�����_�A�I�_���W

	bool LoadScore()
	{
		//���ʓǂݍ���
		ifstream ifs_apper("./ScoreData/test.csv");
		ifstream ifs_type("./ScoreData/type.csv");

		//�J���Ȃ�������G���[
		if (!ifs_apper || !ifs_type)
		{
			return false;
		}
		
		constexpr int num = 500;		//�Ƃ肠����������500�܂�
		string s_appper;
		string s_type;
		int i = 0;
		int j = 0;
		note.apper_note[num];

		while(getline(ifs_apper,s_appper,'\n'))
		{
			//�������int�^�ɕϊ�
			note.apper_note[i] = stoi(s_appper);
			++i;
			if (i < num)
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

	
		if (cheak == -1)
		{
			return false;
		}
		return true;
	}

	void Updata()
	{
	

		BezierCurve2(&note, note.start, note.dir, note.end);
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
		DrawFormatString(0, 0, GetColor(0, 0, 0), "�o�ߎ��ԁi�~���b�j%f", note.Cnt);
	}

	void Fin()
	{
		for (int i = 0; i < 4; ++i)
		{
			DeleteGraph(note.picHandle[i]);
		}

	}
}
