#include "Usingheaders.h"


using namespace Sound;
namespace Note {

	static const int
		SCREEN_WIDIH = 960,
		SCREEN_HEIGHT = 540;
	double	second = 60.0;
	Sound::SETYPE se_type;
	Note note_carrot;
	POS start, dir, end;  //�Ȑ��̊J�n�_�A�����_�A�I�_���W

	bool Initialize()
	{
		int cheak = LoadDivGraph("./Graph/carrot.png", 4, 4, 1, 100, 100, note_carrot.picHandle);
		note_carrot.pos.x = SCREEN_WIDIH + 50;
		note_carrot.pos.y = SCREEN_HEIGHT / 2;
		note_carrot.Cnt = 0;
		note_carrot.animeCnt = 0;
		note_carrot.time = 0;
		note_carrot.type = one;
		note_carrot.speed = 17.0f * 2.2f;
		note_carrot.start.x = note_carrot.pos.x;
		note_carrot.start.y = note_carrot.pos.y;
		note_carrot.end.x = SCREEN_WIDIH / 2;
		note_carrot.end.y = SCREEN_HEIGHT / 2 + 160;
		note_carrot.state = come;

		note_carrot.dir.x = fabs(note_carrot.start.x - note_carrot.end.x) / 2 + note_carrot.end.x;
		note_carrot.dir.y = 100;

		note_carrot.BPM = 130;
		note_carrot.beat = 4;
		note_carrot.fourn_note = second / note_carrot.BPM - 0.04;
		note_carrot.eight_note = note_carrot.fourn_note / 2.0;
		note_carrot.BGM_time = note_carrot.Bar_end * 10.0;
		note_carrot.Bar_end = note_carrot.fourn_note * note_carrot.beat;
		/*note_carrot.hit_time = note_carrot.fourn_note * 2.0;*/
		//date.current_time = 0.0;
		PlaySE(apper);
		if (cheak == -1)
		{
			return false;
		}
		return true;
	}

	void Updata()
	{

		if (note_carrot.Cnt <= 0.0)
		{
			PlaySE(apper);		//�������B�������o�����鏈���Ŗ炷�B�ŏ��̔��ɍ��킹��ƃ��Y���Ƃ�₷������
		}
		
		if (note_carrot.state == come &&
			note_carrot.Cnt >= note_carrot.fourn_note
			)
		{
			
			PlaySE(carrot);
			note_carrot.state = cut;
			
		}
	
			
		/*if (date.BGM_time !=0 && date.current_time <= 0.0)
		{
			Initialize();
		}*/

		if (note_carrot.state == cut)
		{
			++note_carrot.animeCnt;
			if (note_carrot.Cnt >= note_carrot.Bar_end)
			{

				Initialize();
				note_carrot.Cnt = 0.0;

			}
		}
		note_carrot.BGM_time -= 1 / 60.0;
		note_carrot.Cnt += 1 / 60.0;
		BezierCurve2(&note_carrot, note_carrot.start, note_carrot.dir, note_carrot.end);
	}

	void Draw()
	{

		if (note_carrot.state == come)	//���ʑO�̉���
		{
			DrawRotaGraph(int(note_carrot.pos.x), int(note_carrot.pos.y), 1.0, 0.0, note_carrot.picHandle[0], true);		//RotaGraph�͍��W�����S�ɂȂ�
		}
		if (note_carrot.state == cut)	//���������񂾂�A�j���[�V����
		{
			DrawRotaGraph(int(note_carrot.pos.x), int(note_carrot.pos.y), 1.0, 0.0, note_carrot.picHandle[note_carrot.animeCnt / 2], true);		//RotaGraph�͍��W�����S�ɂȂ�
		}
		DrawFormatString(0, 0, GetColor(0, 0, 0), "�o�ߎ��ԁi�~���b�j%f", note_carrot.Cnt);
	}

	void Fin()
	{
		for (int i = 0; i < 4; ++i)
		{
			DeleteGraph(note_carrot.picHandle[i]);
		}

	}
}
