#pragma once
#include "BaseInfo.h"
#include "Object.h"

class Player :protected Object {
protected:
	static const int	handleNum = 35;			//�摜�n���h���̐�

	int					picHandle[handleNum],	//�摜�n���h��
						animCnt;				//�A�j���[�V�����J�E���^
	PlayerState			state;					//���

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
