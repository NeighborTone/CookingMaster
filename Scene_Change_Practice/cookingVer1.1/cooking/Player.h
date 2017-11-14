#pragma once
#include "BaseInfo.h"
#include "Object.h"

class Player :protected Object {
protected:
	static const int	handleNum = 35;			//画像ハンドルの数

	int					picHandle[handleNum],	//画像ハンドル
						animCnt;				//アニメーションカウンタ
	PlayerState			state;					//状態

public:
	Player();
	~Player();
	void Init();
	void Update();
	void Render();
	void Fin();
	void SetPicture();
};

//namespace Player
//{
//	const int num = 35;
//	enum State {
//		stand,
//		cutting,
//	};
//
//	struct Cock
//	{
//		int		        x,
//				        y,
//				        w,
//			            h,
//		 	      animCnt,
//			picHandle[num];
//		State	    state;
//	};
//
//	void Initialize();
//
//	void Update();
//
//	void Draw();
//
//	void Fin();
//
//}
