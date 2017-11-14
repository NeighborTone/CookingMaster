#include "DxLib.h"
#include "Input.h"
#include "Note.h"
#include "Sound.h"
#include "BezierCurve.h"

#include <cmath>


//コンストラクタ
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

//デストラクタ
Note::~Note() {
	for (int i = 0; i < handleNum; ++i) {
		DeleteGraph(picHandle[i]);
	}
}

//初期化処理
void Note::Init(float hit, Vege vege, Direction d) {
	hitFlame = hit;
	appearFlame = SetAppearFlame(hit);
	SetDirection(d);
	SetPicture(vege);
}

//出現
void Note::Appear() {
	if (state == off) {
		state = come;
	}
}

//更新処理
void Note::Update() {
	//移動
	if (state != off) {
		pos=
		//BezierCurve2(start, dir, end);
	}

	//あたり判定
	NoteHitCheck();
	//切られたらanimCntを加算
	if (state == cut) {
		animCnt++;
	}
	//画面外に出たら
	if (pos.y>=end.y && cnt>120) { 
		state = off;
	}

	cnt++;
}

//描画処理
void Note::Render() {
	if (state == come) {
		DrawRotaGraph((int)pos.x, (int)pos.y, 1.0, 0.0, picHandle[0], true);
	}
	else if (state == cut) {
		DrawRotaGraph((int)pos.x, (int)pos.y, 1.0, 0.0, picHandle[animCnt / 2], true);
	}
}

//終了処理
void Note::Fin() {
	Note::~Note();
}

//-------------------------------------------------------------
//出現タイミング設定関数
//引数　hit：当たり判定に来るタイミング
//戻り値：出現タイミング
//flame：何フレーム前に出現するか
//-------------------------------------------------------------
float Note::SetAppearFlame(float hitFlame) {
	float flame = 120.0f;  //とりあえず2秒前に出現
	return hitFlame - flame;
}

//-------------------------------------------------------------
//出現タイミングを渡す関数
//戻り値：出現タイミング
//-------------------------------------------------------------
float Note::GetAppearFlame(Note n) {
	return n.appearFlame;
}


//-------------------------------------------------------------
//出現する方向を指定
//出現位置、当たり判定位置、方向点を算出して代入する
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
	case topL:  //要調整
		start = { (float)-picWidth, (float)SCREEN_HEIGHT / 2.0f };
		end = { (float)SCREEN_WIDTH / 2.0f - (float)picWidth, (float)SCREEN_HEIGHT / 2.0f };
		dir = { (float)(end.x - start.x) / 4.0f, (float)SCREEN_HEIGHT / 5.0f };
		break;
	case topR:  //要調整
		start = { (float)SCREEN_WIDTH + 50.0f, (float)SCREEN_HEIGHT / 2.0f };
		end = { (float)SCREEN_WIDTH / 2.0f + (float)picWidth, (float)SCREEN_HEIGHT / 2.0f };
		dir = { (float)(start.x - end.x) / 4.0f, (float)SCREEN_HEIGHT / 5.0f };
		break;
	case bottomL:  //要調整
		start = { (float)SCREEN_WIDTH / 3.0f, (float)SCREEN_HEIGHT + (float)(picHeight / 2) };
		end = { (float)SCREEN_WIDTH / 2.0f - (float)picWidth, (float)SCREEN_HEIGHT - 100.0f };
		dir = { 0,0 };  //仮
		break;
	case bottomR:  //要調整
		start = { (float)SCREEN_WIDTH * 2.0f / 3.0f, (float)SCREEN_HEIGHT + (float)(picHeight / 2) };
		end = { (float)SCREEN_WIDTH / 2.0f - (float)picWidth, (float)SCREEN_HEIGHT - 100.0f };
		dir = { 0,0 };  //仮
		break;
	default:
		break;
	}
}

//-------------------------------------------------------------
//画像を指定
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

//RAIIの法則
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
//ベジエ曲線で移動する
//Noteクラスの外にしたいだけの人生だった
//-------------------------------------------------------------
//void Note::BezierCurve2(Vec3 start, Vec3 dir, Vec3 end) {
//	Vec3 bez;  //ある時点での曲線上の点の座標
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
//あたり判定
//hitFlame ± 4 で切れる(ようにする予定だ)よ☆
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
//	POS start, dir, end;  //曲線の開始点、方向点、終点座標
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
//			DrawRotaGraph(int(note_carrot.pos.x), int(note_carrot.pos.y), 1.0, 0.0, note_carrot.picHandle[0], true);		//RotaGraphは座標が中心になる
//		}
//		if (note_carrot.state == cut &&  note_carrot.active == false)
//		{
//			DrawRotaGraph(int(note_carrot.pos.x), int(note_carrot.pos.y), 1.0, 0.0, note_carrot.picHandle[note_carrot.animeCnt / 2], true);		//RotaGraphは座標が中心になる
//		}
//		DrawFormatString(0, 0, GetColor(0, 0, 0), "経過時間（フレーム）%d", note_carrot.Cnt);
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
