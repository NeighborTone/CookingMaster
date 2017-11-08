#include "DxLib.h"
#include "Input.h"
#include "Note.h"
#include "Sound.h"
#include "BezierCurve.h"

#include <cmath>
using namespace Sound;
namespace Note {

	static const int
	SCREEN_WIDIH = 960,
	SCREEN_HEIGHT = 540;
	Sound::SETYPE se_type;
	Note note_carrot;
	POS start, dir, end;  //�Ȑ��̊J�n�_�A�����_�A�I�_���W

	void Initialize()
	{
		LoadDivGraph("./Graph/carrot.png", 4, 4, 1, 100, 100, note_carrot.picHandle);
		note_carrot.pos.x = SCREEN_WIDIH + 50;
		note_carrot.pos.y = SCREEN_HEIGHT/2;
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

		PlaySE(apper);		//�������B�������o�����鏈���Ŗ炷�B�ŏ��̔��ɍ��킹��ƃ��Y���Ƃ�₷������
	}

	void Updata()
	{
			if (note_carrot.state == come  &&
				Key(KEY_INPUT_A)==1  &&		
				note_carrot.Cnt > 20 &&
				note_carrot.Cnt < 30)
			{
				PlaySE(carrot);
				note_carrot.state = cut;
			}
			if (note_carrot.Cnt > 37)
			{
				Initialize();
			}
		++note_carrot.Cnt;
		if (note_carrot.state == cut)
		{
			++note_carrot.animeCnt;
		}
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
		DrawFormatString(0, 0, GetColor(0, 0, 0), "�o�ߎ��ԁi�t���[���j%d", note_carrot.Cnt);
	}

	void Fin()
	{
		for (int i = 0; i < 4; ++i)
		{
			DeleteGraph(note_carrot.picHandle[i]);
		}
		
	}
}
