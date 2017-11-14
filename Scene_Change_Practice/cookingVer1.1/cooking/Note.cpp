#include "DxLib.h"
#include "Input.h"
#include "Note.h"
#include "Sound.h"
#include "BezierCurve.h"

#include <cmath>


//�R���X�g���N�^
Note::Note():
		speed(17.8f*2.0f),
		time(0),
		start({0,0}),
		dir({0,0}),
		end({0,0}),
		appearFlame(0),
		hitFlame(0),
		cnt(0),
		animCnt(0),
		picHandle(),
		picWidth(100),
		picHeight(100),
		state(off),
		type(non)
{
	setPos(0, 0);
}

//�f�X�g���N�^
Note::~Note() {
	for (int i = 0; i < handleNum; ++i) {
		DeleteGraph(picHandle[i]);
	}
}

//����������
void Note::Init(float hit, Vege vege, Direction d) {
	hitFlame = hit;
	appearFlame = SetAppearFlame(hit);
	SetDirection(d);
	SetPicture(vege);
}

//�o��
void Note::Appear() {
	if (state == off) {
		state = come;
	}
}

//�X�V����
void Note::Update() {
	//�ړ�
	if (state != off) {
		pos=
		//BezierCurve2(start, dir, end);
	}

	//�����蔻��
	NoteHitCheck();
	//�؂�ꂽ��animCnt�����Z
	if (state == cut) {
		animCnt++;
	}
	//��ʊO�ɏo����
	if (pos.y>=end.y && cnt>120) { 
		state = off;
	}

	cnt++;
}

//�`�揈��
void Note::Render() {
	if (state == come) {
		DrawRotaGraph((int)pos.x, (int)pos.y, 1.0, 0.0, picHandle[0], true);
	}
	else if (state == cut) {
		DrawRotaGraph((int)pos.x, (int)pos.y, 1.0, 0.0, picHandle[animCnt / 2], true);
	}
}

//�I������
void Note::Fin() {
	Note::~Note();
}

//-------------------------------------------------------------
//�o���^�C�~���O�ݒ�֐�
//�����@hit�F�����蔻��ɗ���^�C�~���O
//�߂�l�F�o���^�C�~���O
//flame�F���t���[���O�ɏo�����邩
//-------------------------------------------------------------
float Note::SetAppearFlame(float hitFlame) {
	float flame = 120.0f;  //�Ƃ肠����2�b�O�ɏo��
	return hitFlame - flame;
}

//-------------------------------------------------------------
//�o���^�C�~���O��n���֐�
//�߂�l�F�o���^�C�~���O
//-------------------------------------------------------------
float Note::GetAppearFlame(Note n) {
	return n.appearFlame;
}


//-------------------------------------------------------------
//�o������������w��
//�o���ʒu�A�����蔻��ʒu�A�����_���Z�o���đ������
//-------------------------------------------------------------
void Note::SetDirection(Direction d) {
	switch (d) {
	case left:
		start = { (float)-picWidth, (float)SCREEN_HEIGHT / 2.0f + 160.0f };
		end = { (float)SCREEN_WIDTH / 2.0f - (float)picWidth, (float)SCREEN_HEIGHT / 2.0f + 160.0f };
		dir = { (float)(end.x - start.x) / 2.0f, (float)SCREEN_HEIGHT / 3.0f };
		break;
	case right:
		start = { (float)SCREEN_WIDTH + 50.0f, (float)SCREEN_HEIGHT / 2.0f + 160.0f };
		end = { (float)SCREEN_WIDTH / 2.0f + (float)picWidth, (float)SCREEN_HEIGHT / 2.0f + 160.0f };
		dir = { (float)(start.x - end.x + SCREEN_WIDTH) / 2.0f, (float)SCREEN_HEIGHT / 4.0f };
		break;
	case topL:  //�v����
		start = { (float)-picWidth, (float)SCREEN_HEIGHT / 2.0f };
		end = { (float)SCREEN_WIDTH / 2.0f - (float)picWidth, (float)SCREEN_HEIGHT / 2.0f };
		dir = { (float)(end.x - start.x) / 4.0f, (float)SCREEN_HEIGHT / 5.0f };
		break;
	case topR:  //�v����
		start = { (float)SCREEN_WIDTH + 50.0f, (float)SCREEN_HEIGHT / 2.0f };
		end = { (float)SCREEN_WIDTH / 2.0f + (float)picWidth, (float)SCREEN_HEIGHT / 2.0f };
		dir = { (float)(start.x - end.x) / 4.0f, (float)SCREEN_HEIGHT / 5.0f };
		break;
	case bottomL:  //�v����
		start = { (float)SCREEN_WIDTH / 3.0f, (float)SCREEN_HEIGHT + (float)(picHeight / 2) };
		end = { (float)SCREEN_WIDTH / 2.0f - (float)picWidth, (float)SCREEN_HEIGHT - 100.0f };
		dir = { 0,0 };  //��
		break;
	case bottomR:  //�v����
		start = { (float)SCREEN_WIDTH * 2.0f / 3.0f, (float)SCREEN_HEIGHT + (float)(picHeight / 2) };
		end = { (float)SCREEN_WIDTH / 2.0f - (float)picWidth, (float)SCREEN_HEIGHT - 100.0f };
		dir = { 0,0 };  //��
		break;
	default:
		break;
	}
}

//-------------------------------------------------------------
//�摜���w��
//-------------------------------------------------------------
void Note::SetPicture(Vege vege) {
	switch (vege) {
	case carrot:
		LoadDivGraph("./Graph/carrot.png", 4, 4, 1, 100, 100, picHandle);
		break;
	case onion:
		break;
	case broccoli:
		break;
	case cabbage:
		break;
	case tomato:
		break;
	case potato:
		break;
	case mouse:
		break;
	case meat:
		break;
	default:
		break;
	}
}

//RAII�̖@��
//struct BezierCurve
//{
//	BezierCurve(__________)
//	{
//	}
//	Vec3 update()
//	{
//
//	}
//};



//-------------------------------------------------------------
//�x�W�G�Ȑ��ňړ�����
//Note�N���X�̊O�ɂ����������̐l��������
//-------------------------------------------------------------
//void Note::BezierCurve2(Vec3 start, Vec3 dir, Vec3 end) {
//	Vec3 bez;  //���鎞�_�ł̋Ȑ���̓_�̍��W
//
//	bez.x = (1 - time)*(1 - time)*start.x + 2 * (1 - time)*time*dir.x + time*time*end.x;
//	bez.y = (1 - time)*(1 - time)*start.y + 2 * (1 - time)*time*dir.y + time*time*end.y;
//
//	pos.x = bez.x;
//	pos.y = bez.y;
//	time += 1 / speed;
//	
//	if (time >= 1) {
//		time = 1;
//	}
//}


//-------------------------------------------------------------
//�����蔻��
//hitFlame �} 4 �Ő؂��(�悤�ɂ���\�肾)�恙
//-------------------------------------------------------------
void Note::NoteHitCheck() {
	if (state == come && Key(KEY_INPUT_A) == 1 && cnt > 18) {
		Sound::PlaySE(0);
		state = cut;
	}
}


//namespace Note {
//	static const int
//		SCREEN_WIDIH = 960,
//		SCREEN_HEIGHT = 540;
//	Note note_carrot;
//	POS start, dir, end;  //�Ȑ��̊J�n�_�A�����_�A�I�_���W
//	void Initialize()
//	{
//		LoadDivGraph("./Graph/carrot.png", 4, 4, 1, 100, 100, note_carrot.picHandle);
//		note_carrot.pos.x = SCREEN_WIDIH + 50;
//		note_carrot.pos.y = SCREEN_HEIGHT/2;
//		note_carrot.Cnt = 0;
//		note_carrot.animeCnt = 0;
//		note_carrot.time = 0;
//		note_carrot.type = one;
//		note_carrot.speed = 17.8f * 2.0f;
//		note_carrot.active = true;
//		note_carrot.start.x = note_carrot.pos.x;
//		note_carrot.start.y = note_carrot.pos.y;
//		note_carrot.end.x = SCREEN_WIDIH / 2;
//		note_carrot.end.y = SCREEN_HEIGHT / 2 + 160;
//		note_carrot.state = come;
//
//		note_carrot.dir.x = fabs(note_carrot.start.x - note_carrot.end.x) / 2 + note_carrot.end.x;
//		note_carrot.dir.y = 100;
//	}
//
//	void Updata()
//	{
//			if (note_carrot.state == come && note_carrot.active == true && Key(KEY_INPUT_A)==1 && note_carrot.Cnt > 18)
//			{
//				Sound::PlaySE(0);
//				note_carrot.state = cut;
//				note_carrot.active = false;
//			}
//			if (note_carrot.Cnt > 37)
//			{
//				Initialize();
//			}
//		++note_carrot.Cnt;
//		if (note_carrot.state == cut)
//		{
//			++note_carrot.animeCnt;
//		}
//		BezierCurve2(&note_carrot, note_carrot.start, note_carrot.dir, note_carrot.end);
//	}
//
//	void Draw()
//	{
//		
//		if (note_carrot.state == come && note_carrot.active == true)
//		{
//			DrawRotaGraph(int(note_carrot.pos.x), int(note_carrot.pos.y), 1.0, 0.0, note_carrot.picHandle[0], true);		//RotaGraph�͍��W�����S�ɂȂ�
//		}
//		if (note_carrot.state == cut &&  note_carrot.active == false)
//		{
//			DrawRotaGraph(int(note_carrot.pos.x), int(note_carrot.pos.y), 1.0, 0.0, note_carrot.picHandle[note_carrot.animeCnt / 2], true);		//RotaGraph�͍��W�����S�ɂȂ�
//		}
//		DrawFormatString(0, 0, GetColor(0, 0, 0), "�o�ߎ��ԁi�t���[���j%d", note_carrot.Cnt);
//	}
//
//	void Fin()
//	{
//		for (int i = 0; i < 4; ++i)
//		{
//			DeleteGraph(note_carrot.picHandle[i]);
//		}
//		
//	}
//}
