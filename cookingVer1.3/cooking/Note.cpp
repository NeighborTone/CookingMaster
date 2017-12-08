#include "Usingheaders.h"
extern const int
SCREEN_WIDIH,
SCREEN_HEIGHT,
quarterNote = 461,		//�l�������̒���(ms)
halfNote = 923;			//�񕪉����̒���(ms)

extern int score;


bool File::LoadScore()
{

	//���ʓǂݍ���
	ifstream ifs_noteJust("./ScoreData/Scoredata1.csv");		//�����̃W���X�g�̔���^�C�~���O(���t�@�C���ɏ������Ԃ͏����_�ȉ��܂ŏ�������)
	ifstream ifs_type("./ScoreData/type.csv");				//�����̉摜��SE�̃f�[�^
	ifstream ifs_appaer("./ScoreData/dir.csv");			    //���E�̕����̃f�[�^


	
	//�J���Ȃ�������G���[
	if (!ifs_noteJust || !ifs_type || !ifs_appaer)
	{
		return false;
	}

	string s_judeg;
	string s_ID;
	string s_dir;
	//���[�v�p�ϐ�
	int j = 0;
	int i = 0;
	int d = 0;

	while (getline(ifs_noteJust, s_judeg, '\n'))
	{
		//�������int�^�ɕϊ�
		judge[j] = stoi(s_judeg);
		++j;
		if (i > 100)
		{
			break;
		}
	}
	while (getline(ifs_type, s_ID, '\n'))
	{
		//�������int�^�ɕϊ�
		id[i] = stoi(s_ID);
		++i;
		if (i > 100)
		{
			break;
		}
	}
	while (getline(ifs_appaer, s_dir, '\n'))
	{
		//�������int�^�ɕϊ�
		dir[d] = stoi(s_dir);
		++d;
		if (d > 100)
		{
			break;
		}
	}

	return true;

}

void Note::SetScore(int id, Note& note, const File& file) {
	note.data.judge = file.judge[id];
	note.data.ID = file.id[id];
	note.data.d = (file.dir[id] == 1) ? RIGHT : LEFT;

	//�Z�o����
	//N_Type
	SetN_Type(note);
	//appear
	SetAppearTime(note);
	//Vec start,dir,end
	SetBezierData(note);
	//speed
	SetSpeed(note);

}

void Note::SetN_Type(Note& note){
	switch (note.data.ID) {
	case 1:
	case 2:
	case 5:
		note.move.note_type = N_one;
		break;
	case 3:
	case 4:
	case 6:
		note.move.note_type = N_rest;
		break;
	}
}
void Note::SetAppearTime(Note& note) {
	switch (note.move.note_type) {
	case N_one:
		note.data.appear = note.data.judge - quarterNote;
		break;
	case N_rest:
		note.data.appear = note.data.judge - halfNote;
		break;

	}
}

void Note::SetBezierData(Note& note) {
	switch (note.data.d) {
	case LEFT:
		note.move.start.x = float(-imageSizeX / 2);
		note.move.start.y = float(SCREEN_HEIGHT / 2);
		note.move.end.x = 630.0f / 2.0f;	//Player.cpp�@check�@�̍��W���R�s�y�A�摜�̈ʒu�֌W�ŗv�ύX
		note.move.end.y = 280.0f;
		note.move.dir.x = note.move.end.x - note.move.start.x;
		//dir.y��N_Type�ɂ���ĕς��
		note.move.dir.y = (note.move.note_type == N_one) ? float(SCREEN_HEIGHT / 3) : float(SCREEN_HEIGHT / 5);  //�v�ύX
		break;
	case RIGHT:
		note.move.start.x = float(SCREEN_WIDIH + imageSizeX / 2);
		note.move.start.y = float(SCREEN_HEIGHT / 2);
		note.move.end.x = 630.0f;	//Player.cpp�@check�@�̍��W���R�s�y�A�摜�̈ʒu�֌W�ŗv�ύX
		note.move.end.y = 280.0f;
		note.move.dir.x = note.move.end.x + float((note.move.start.x - note.move.end.x) / 2);
		//dir.y��N_Type�ɂ���ĕς��
		note.move.dir.y = (note.move.note_type == N_one) ? float(SCREEN_HEIGHT / 3) : float(SCREEN_HEIGHT / 5);  //�v�ύX
		break;
	}
}

void Note::SetSpeed(Note& note) {
	switch (note.move.note_type) {
	case N_one:
		note.move.speed = float(((630 / 2) - (-imageSizeX / 2)) / quarterNote);	//1ms�ŉ��s�N�Z���ړ����邩
		break;
	case N_rest:
		note.move.speed = float(((630 / 2) - (-imageSizeX / 2)) / halfNote);	//1ms�ŉ��s�N�Z���ړ����邩
		break;
	}
}

//�o�b�h����
bool Note_Check_Bad(int c, int j)
{
	static constexpr int Input_Reception_MAX = 60;
	if (c >= j - Input_Reception_MAX &&
		c >= j + Input_Reception_MAX)
	{
		return true;
	}
	return false;
}
//�O�b�h����
bool Note_Check_Good(int c, int j)
{
	static constexpr int GOOD = 55;
	
	if (c >= j - GOOD &&
		c <= j + GOOD &&
		Key(KEY_INPUT_Z) == 1)
	{
		Player::Effect_On();
		return true;
	}
	return false;
}
//�N�[������
bool Note_Check_Cool(int c, int j)
{
	static constexpr int COOL = 10;

	if (c >= j - COOL &&
		c <= j + COOL &&
		Key(KEY_INPUT_Z) == 1)
	{
		Player::Effect_On();
		
		return true;
	}
	return false;
}
//�I�[�g
bool Auto(int c, int j)
{
	if (c >= j-12 )
	{
		return true;
	}
	return false;
}
bool Note::Initialize()
{
	int check[6];
	check[0] = LoadDivGraph("./Graph/carrot.png", 4, 4, 1, 100, 100, move.pic_carrot);
	check[1] = LoadDivGraph("./Graph/onion.png", 4, 4, 1, 100, 100, move.pic_onion);
	check[2] = LoadDivGraph("./Graph/cabbage.png", 4, 4, 1, 100, 100, move.pic_cabbage);
	check[3] = LoadDivGraph("./Graph/potato.png", 4, 4, 1, 100, 100, move.pic_potato);
	check[4] = LoadDivGraph("./Graph/brory.png", 4, 4, 1, 100, 100, move.pic_broccoli);
	check[5] = LoadDivGraph("./Graph/tomato.png", 4, 4, 1, 100, 100, move.pic_tomato);
	move.animeCnt = 0;
	move.state = off;
	bez.bez = move.start;
	appearSEplayed = false;
	score = 0;
	//move.pos.x = SCREEN_WIDIH + 50;
	//move.pos.y = SCREEN_HEIGHT / 2;
	//move.note_type = N_one;
	//move.speed = 17.0f * 2.2f;
	//move.start.x = move.pos.x;
	//move.start.y = move.pos.y;
	//move.end.x = SCREEN_WIDIH / 2;
	//move.end.y = SCREEN_HEIGHT / 2 + 160;
	//move.dir.x = fabs(move.start.x - move.end.x) / 2 + move.end.x;
	//move.dir.y = 100;

	
	data.hit = Normal;
	for (int i = 0; i < 6; ++i)
	{
		if (check[i] == -1)
		{
			return false;
		}
	}
	

	return true;

}



void Note::Update()
{
	Sound GetSound();
	auto sound = GetSound();

	data.current = GetSoundCurrentTime(sound.BGM);
	//�o��
	if (!appearSEplayed && move.state == off && data.current >= data.appear)
	{
		sound.PlaySE(appear);
		appearSEplayed = true;
		move.state = come;
	}

	if (move.state != off) {
		//�ړ�
		bez.BezTimeUpdate(move.note_type, data.current, data.appear);
		//if (data.d == LEFT) {
		move.pos = bez.MoveBezier2(move.start, move.dir, move.end);
		//}
		//else {
		//	move.pos = bez.MoveBezier2(move.start, move.dir, move.end);
		//}

	}
		if (move.state == come) {
		//����
		switch (data.hit)
		{
		case Normal:
			//�I�[�g���[�h(�f�o�b�O�p�A�����[�X���ɂ͏���)
		/*	if (Auto(data.current, data.judge) && data.hit == Normal)
			{
				sound.PlaySE(data.ID);
				
				data.hit = hit;
				move.state = cut;
			}*/
			//
			if (Note_Check_Cool(data.current, data.judge) && data.hit == Normal)
			{
				sound.PlaySE(data.ID);
				score += 10;
				data.hit = hit;
				move.state = cut;
			}
			if (Note_Check_Good(data.current, data.judge) && data.hit == Normal)
			{
				sound.PlaySE(data.ID);

				score += 2;
				data.hit = hit;
				move.state = cut;
			}
			//���莞�ԓ��ɓ��͂��Ȃ��ꍇ
			else if (Note_Check_Bad(data.current, data.judge) && data.hit == Normal)
			{
				data.hit = miss;
			}
			break;

		case hit:
			data.hit = Normal;
			break;

		case miss:
			data.hit = Normal;
			break;

		default:

			break;
		}

	}

		if (move.state == cut) {
			move.animeCnt++;
		}

		if (move.pos.y >= 500) {
			move.state = off;
		}

		if (score >= 2 ) {
			Metronome::bgAni();
		}

}

void Note::Draw()
{

	if (move.state == come)	//���ʑO�̉���
	{
		switch (data.ID)
		{
		case carrot:
			DrawRotaGraph(int(move.pos.x), int(move.pos.y), 1.0, 0.0, move.pic_carrot[0], true);
			break;
		case onion:
			DrawRotaGraph(int(move.pos.x), int(move.pos.y), 1.0, 0.0, move.pic_onion[0], true);
			break;
		case tomato:
			DrawRotaGraph(int(move.pos.x), int(move.pos.y), 1.0, 0.0, move.pic_tomato[0], true);
			break;
		case cabbage:
			DrawRotaGraph(int(move.pos.x), int(move.pos.y), 1.0, 0.0, move.pic_cabbage[0], true);
			break;
		}
		
	}
	if (move.state == cut)	//���������񂾂�A�j���[�V����
	{
		int animTable[] = { 0,1,2,3 };
		switch (data.ID)
		{
		case carrot:
			if ((move.animeCnt / 3) <= 3) {
				DrawRotaGraph(int(move.pos.x), int(move.pos.y), 1.0, 0.0, move.pic_carrot[animTable[move.animeCnt / 3]], true);
			}
			else {
				move.state = off;
			}
			break;
		case onion:
			if ((move.animeCnt / 3) <= 3) {
				DrawRotaGraph(int(move.pos.x), int(move.pos.y), 1.0, 0.0, move.pic_onion[animTable[move.animeCnt / 3]], true);
			}
			else {
				move.state = off;
			}
			break;
		case tomato:
			if ((move.animeCnt / 3) <= 3) {
				DrawRotaGraph(int(move.pos.x), int(move.pos.y), 1.0, 0.0, move.pic_tomato[animTable[move.animeCnt / 3]], true);
			}
			else {
				move.state = off;
			}
			break;
		case cabbage:
			if ((move.animeCnt / 3) <= 3) {
				DrawRotaGraph(int(move.pos.x), int(move.pos.y), 1.0, 0.0, move.pic_cabbage[animTable[move.animeCnt / 3]], true);
			}
			else {
				move.state = off;
			}
			break;
		}
		
	}

	Sound GetSound();
	auto sound = GetSound();


	//�f�o�b�O�p�����A�����[�X���ɂ͏���
	DrawFormatString(0, 80, GetColor(0, 0, 0), "���݂̍Đ��ʒu%d", GetSoundCurrentTime(sound.BGM));
	//DrawFormatString(0, 60, GetColor(0, 0, 0), "����ID:%d", data.ID[data.ID_cnt]);
	//DrawFormatString(0, 40, GetColor(0, 0, 0), "�o��������:%d", data.a_cnt);
	//DrawFormatString(0, 20, GetColor(0, 0, 0), "����ς݂̉���:%d", data.j_cnt);

}

void Note::Fin()
{
	for (int i = 0; i < 4; ++i)
	{
		DeleteGraph(move.pic_carrot[i]);
	}
}