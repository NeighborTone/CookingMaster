#pragma once
#include "BaseInfo.h"
#include "Object.h"

class Note : protected Object {
protected:
	static const int handleNum = 4;  //画像ハンドルの数


	float		 speed,			  //移動速度
			   	 time,			  //ベジエ曲線使うときに使ってね☆
				 appearFlame,     //出現タイミング
				 hitFlame;        //当たり判定に来るタイミング
	Vec3		 start,			  //出現地点
				 dir,			  //ベジエ曲線の方向点
				 end;			  //ベジエ曲線の終点、大抵は当たり判定領域
	int			 cnt,			  //フレームカウント
				 animCnt,		  //アニメカウント	
				 picHandle[handleNum], 	  //画像
				 picWidth,		  //画像幅
				 picHeight;		  //画像高さ
	NoteState    state;			  //音符の状態
	Type         type;			  //音符の種類
	

public:
	Note();
	~Note();
	void Init(float hit, Vege vege, Direction d);		//初期化
	void Appear();										//出現
	void Update();										//更新
	void Render();										//描画
	void Fin();											//終了
	float SetAppearFlame(float h);						//あたり判定タイミングから出現タイミングを逆算
	float GetAppearFlame(Note);							//appearFlameを渡す
	void SetDirection(Direction d);						//出現方向を指定、start,dir,endを代入
	void SetPicture(Vege v);							//使う画像を指定
	void BezierCurve2(Vec3 start, Vec3 dir, Vec3 end);	//2次ベジエ曲線で動く
	void NoteHitCheck();								//あたり判定
};

//namespace Note {
//
//	struct Note 
//	{
//		float		 speed,
//			time;  //ベジエ曲線使うときに使ってね☆
//		POS			   pos,   //現在の座標
//			start,  //出現地点
//			dir,  //ベジエ曲線の方向点
//			end;  //ベジエ曲線の終点、大抵は当たり判定領域
//		int			   Cnt,	//フレームカウント
//			animeCnt,	//アニメカウント	
//			picHandle[4];	//画像
//		bool        active;
//		State        state;
//		Type          type;	//音符の種類
//
//	};
//
//	void Initialize();
//
//	void Updata();
//
//	void Draw();
//
//	void Fin();
//}
