#pragma once
#include "BaseInfo.h"
#include "Note.h"
#include <vector>

using namespace std;

//Noteクラスのインスタンスの総括をする
class NoteMng {
private:
	int timeCnt;		//ゲーム内時間をカウント
	vector<Note> note;	//Noteクラスのインスタンスを動的配列で生成
	size_t size;		//登録されているデータの数

public:
	NoteMng();											//コンストラクタ
	~NoteMng();											//デストラクタ
	void Init();										//初期化
	void AddNote(float hitFlame, Vege v, Direction d);	//noteコンテナの末端にデータを追加
	void Update();										//時間経過カウンタ
	void NoteAppear();									//Noteを出現させる
	void Render();										//Noteの描画
};