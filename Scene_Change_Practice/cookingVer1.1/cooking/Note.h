#pragma once
#include "BaseInfo.h"
#include "Object.h"

class Note : protected Object {
protected:
	static const int handleNum = 4;  //�摜�n���h���̐�


	float		 speed,			  //�ړ����x
			   	 time,			  //�x�W�G�Ȑ��g���Ƃ��Ɏg���Ăˁ�
				 appearFlame,     //�o���^�C�~���O
				 hitFlame;        //�����蔻��ɗ���^�C�~���O
	Vec3		 start,			  //�o���n�_
				 dir,			  //�x�W�G�Ȑ��̕����_
				 end;			  //�x�W�G�Ȑ��̏I�_�A���͓����蔻��̈�
	int			 cnt,			  //�t���[���J�E���g
				 animCnt,		  //�A�j���J�E���g	
				 picHandle[handleNum], 	  //�摜
				 picWidth,		  //�摜��
				 picHeight;		  //�摜����
	NoteState    state;			  //�����̏��
	Type         type;			  //�����̎��
	

public:
	Note();
	~Note();
	void Init(float hit, Vege vege, Direction d);		//������
	void Appear();										//�o��
	void Update();										//�X�V
	void Render();										//�`��
	void Fin();											//�I��
	float SetAppearFlame(float h);						//�����蔻��^�C�~���O����o���^�C�~���O���t�Z
	float GetAppearFlame(Note);							//appearFlame��n��
	void SetDirection(Direction d);						//�o���������w��Astart,dir,end����
	void SetPicture(Vege v);							//�g���摜���w��
	void BezierCurve2(Vec3 start, Vec3 dir, Vec3 end);	//2���x�W�G�Ȑ��œ���
	void NoteHitCheck();								//�����蔻��
};

//namespace Note {
//
//	struct Note 
//	{
//		float		 speed,
//			time;  //�x�W�G�Ȑ��g���Ƃ��Ɏg���Ăˁ�
//		POS			   pos,   //���݂̍��W
//			start,  //�o���n�_
//			dir,  //�x�W�G�Ȑ��̕����_
//			end;  //�x�W�G�Ȑ��̏I�_�A���͓����蔻��̈�
//		int			   Cnt,	//�t���[���J�E���g
//			animeCnt,	//�A�j���J�E���g	
//			picHandle[4];	//�摜
//		bool        active;
//		State        state;
//		Type          type;	//�����̎��
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
