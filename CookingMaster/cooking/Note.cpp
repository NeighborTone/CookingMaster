#include "Usingheaders.h"
extern const int
SCREEN_WIDIH,
SCREEN_HEIGHT,
quarterNote = 461,		//�l�������̒���(ms)
halfNote = 923,			//�񕪉����̒���(ms)
dottedHalfNote = 1385;	//���_2��


bool File::LoadScore()
{

	//���ʓǂݍ���
#if _DEBUG
	ifstream ifs_noteJust("./ScoreData/Scoredata_Debug.csv");	//�����̃W���X�g�̔���^�C�~���O(���t�@�C���ɏ������Ԃ͏����_�ȉ��܂ŏ�������)
	ifstream ifs_type("./ScoreData/type_Debug.csv");				//�����̉摜��SE�̃f�[�^
	ifstream ifs_appaer("./ScoreData/dir_Debug.csv");			    //���E�̕����̃f�[�^
#else
	ifstream ifs_noteJust("./ScoreData/Scoredata1.csv");	//�����̃W���X�g�̔���^�C�~���O(���t�@�C���ɏ������Ԃ͏����_�ȉ��܂ŏ�������)
	ifstream ifs_type("./ScoreData/type.csv");				    //�����̉摜��SE�̃f�[�^
	ifstream ifs_appaer("./ScoreData/dir.csv");			    //���E�̕����̃f�[�^
#endif

	
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
		if (i > noteMax)
		{
			break;
		}
	}
	while (getline(ifs_type, s_ID, '\n'))
	{
		//�������int�^�ɕϊ�
		id[i] = stoi(s_ID);
		++i;
		if (i > noteMax)
		{
			break;
		}
	}
	while (getline(ifs_appaer, s_dir, '\n'))
	{
		//�������int�^�ɕϊ�
		dir[d] = stoi(s_dir);
		++d;

		if (d > noteMax)
		{
			break;
		}
	}

	return true;

}

void Note::SetScore(int id, Note& note, const File& file) {
	note.data.judge = file.judge[id];
	note.data.ID = file.id[id];
	//note.data.d = (file.dir[id] == 1) ? RIGHT : LEFT;
	switch (file.dir[id])
	{
	case LEFT:
		note.data.d = LEFT;
		break;
	case RIGHT:
		note.data.d = RIGHT;
		break;
	case BOTTOM:
		note.data.d = BOTTOM;
		break;
	}
	//�Z�o����
	//N_Type
	SetN_Type(note);
	//appear
	SetAppearTime(note);
	//Vec start,dir,end
	SetBezierData(note);
	//speed
	//SetSpeed(note);

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
	case 7:
		note.move.note_type = N_mouse;
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
	case N_mouse:
		note.data.appear = note.data.judge - dottedHalfNote;
		//note.data.appear = note.data.judge - halfNote;
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
		note.move.dir.x = (note.move.end.x - note.move.start.x)/ 2.0f;
		//dir.y��N_Type�ɂ���ĕς��
		note.move.dir.y = (note.move.note_type == N_one) ? float(SCREEN_HEIGHT / 3) : -50/*float(SCREEN_HEIGHT / 10)*/;  //�v�ύX
		note.move.pos = note.move.start;
		break;
	case RIGHT:
		note.move.start.x = float(SCREEN_WIDIH + imageSizeX / 2);
		note.move.start.y = float(SCREEN_HEIGHT / 2);
		note.move.end.x = 630.0f;	//Player.cpp�@check�@�̍��W���R�s�y�A�摜�̈ʒu�֌W�ŗv�ύX
		note.move.end.y = 280.0f;
		note.move.dir.x = note.move.end.x + float((note.move.start.x - note.move.end.x) / 2);
		//dir.y��N_Type�ɂ���ĕς��
		note.move.dir.y = (note.move.note_type == N_one) ? float(SCREEN_HEIGHT / 3) : -50/*float(SCREEN_HEIGHT / 10)*/;  //�v�ύX
		note.move.pos = note.move.start;
		break;
	case BOTTOM:
		note.move.start.x = float(SCREEN_WIDIH + imageSizeX / 2);
		note.move.start.y = 450.0f;
		note.move.end.x = float(-imageSizeX / 2);
		note.move.end.y = 450.0f;		
		note.move.dir.x = 760;
		//dir.y��N_Type�ɂ���ĕς��
		note.move.dir.y = float(SCREEN_HEIGHT-15);
		note.move.pos = note.move.start;
		break;
	}
}

//�o�b�h����
bool Note_Check_Bad(int c, int j)
{
	static constexpr int Input_Reception_MAX = 65;
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
	static constexpr int GOOD = 60;
	
	if (c >= j - GOOD &&
		c <= j + GOOD &&
		Key(KEY_INPUT_Z)==1)
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
int& Score(int s)
{
	static int score;
	
	score += s;
	return score;
}
bool Note::Initialize()
{
	int check[7];
	check[0] = LoadDivGraph("./Graph/carrot.png",  4, 4, 1, 100, 100, move.pic_carrot);
	check[1] = LoadDivGraph("./Graph/onion.png",   4, 4, 1, 100, 100, move.pic_onion);
	check[2] = LoadDivGraph("./Graph/cabbage.png", 4, 4, 1, 100, 100, move.pic_cabbage);
	check[3] = LoadDivGraph("./Graph/potato.png",  4, 4, 1, 100, 100, move.pic_potato);
	check[4] = LoadDivGraph("./Graph/brory.png",   4, 4, 1, 100, 100, move.pic_broccoli);
	check[5] = LoadDivGraph("./Graph/tomato.png",  4, 4, 1, 100, 100, move.pic_tomato);
	check[6] = LoadDivGraph("./Graph/rat.png",     5, 5, 1, 141, 47, move.pic_mouse);
	move.animeCnt = 0;
	move.state = off;
	bez.bez = move.start;
	appearSEplayed = false;
	data.hit = Normal;
	start = false;
	for (int i = 0; i < 7; ++i)
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
	//�J�n���ゾ��data.appear��-461�������Ă��܂��̂ŋ����ɏo�������ɓ���Ȃ��悤�ɂ��Ă���(�L�E�ցE`)
	if (start == false && data.appear > 0)
	{
		start = true;
	}
	//�o��
	if (start == true && !appearSEplayed && move.state == off && data.current >= data.appear)
	{
		sound.PlaySE(appear);
		appearSEplayed = true;
		move.state = come;
	}

	if (move.state != off) {
		//�ړ�
		bez.BezTimeUpdate(move.note_type, data.current, data.appear);
		move.pos = bez.MoveBezier2(move.start, move.dir, move.end);

	}
		if (move.state == come) {
		//����
		switch (data.hit)
		{
		case Normal:
			//�I�[�g���[�h(�f�o�b�O�p�A�����[�X���ɂ͏���) 
#if _DEBUG
			if (Auto(data.current, data.judge) && data.hit == Normal)
			{
				sound.PlaySE(data.ID);
				Player::Set_Cut();
				data.hit = hit;
				move.state = cut;
				Player::Effect_On();
				Player::Player_Animation(data.d);
				Score(10);
			}
#endif
			//
			if (Note_Check_Cool(data.current, data.judge) && data.hit == Normal)
			{
				sound.PlaySE(data.ID);
				Score(10);
				data.hit = hit;
				move.state = cut;
				Player::Player_Animation(data.d);
			}
			if (Note_Check_Good(data.current, data.judge) && data.hit == Normal)
			{
				sound.PlaySE(data.ID);

				Score(5);
				data.hit = hit;
				move.state = cut;
				Player::Player_Animation(data.d);
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

		if (move.pos.y >= SCREEN_HEIGHT) {
			move.state = off;
		}
		else if (data.d == BOTTOM && move.pos.x <= 0) {
			move.state = off;
		}


}

void Note::Draw()
{

	SetDrawMode(DX_DRAWMODE_BILINEAR);	//�����s�N�Z�����
	if (move.state == come)	//���ʑO�̉���
	{
		int animTable[] = { 0,1,2,3 };
		switch (data.ID)
		{
		case carrot:  DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_carrot[0],   true); break;
		case onion:   DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_onion[0],    true); break;
		case tomato:  DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_tomato[0],   true); break;
		case cabbage: DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_cabbage[0],  true); break;
		case potato:  DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_potato[0],   true); break;
		case broccoli:DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_broccoli[0], true); break;
		case mouse:
			move.animeCnt++;
			DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_mouse[animTable[(move.animeCnt /3 )% 4]], true);
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
				DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_carrot[animTable[move.animeCnt / 3]], true);
			}
			else {
				move.state = off;
			}
			break;
		case onion:
			if ((move.animeCnt / 3) <= 3) {
				DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_onion[animTable[move.animeCnt / 3]], true);
			}
			else {
				move.state = off;
			}
			break;
		case tomato:
			if ((move.animeCnt / 3) <= 3) {
				DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_tomato[animTable[move.animeCnt / 3]], true);
			}
			else {
				move.state = off;
			}
			break;
		case cabbage:
			if ((move.animeCnt / 3) <= 3) {
				DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_cabbage[animTable[move.animeCnt / 3]], true);
			}
			else {
				move.state = off;
			}
			break;
		case potato:
		if ((move.animeCnt / 3) <= 3) {
			DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_potato[animTable[move.animeCnt / 3]], true);
		}
		else {
			move.state = off;
		}
		break;
		case broccoli:
		if ((move.animeCnt / 3) <= 3) {
			DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_broccoli[animTable[move.animeCnt / 3]], true);
		}
		else {
			move.state = off;
		}
		break;
		case mouse:
			DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_mouse[4], true);
			move.state = off; break;
		}
		
	}
	SetDrawMode(DX_DRAWMODE_NEAREST);	//����

#if _DEBUG
	Sound GetSound();
	auto sound = GetSound();
	DrawFormatString(0, 80, GetColor(0, 0, 0), "���݂̍Đ��ʒu%d", GetSoundCurrentTime(sound.BGM));
#endif

}

void Note::Fin()
{
	InitGraph();
}
