#pragma once
namespace Note {

	struct POS
	{			//���W
		float x;
		float y;
	};
	enum Type
	{			//�����̃^�C�v

		one,	//�P��
		rest,	//������(�x��)
		mouse,	//�l�Y�~(�����炭���)
	}; 
	enum State 
	{
		come,
		cut,
		off,
	};
	struct Note 
	{
		int			 just_Note[1000];	//�����̔���̏��
		int			 ID[1000];			//�����̉摜��SE��ID
		int			 note_appear[1000];	//�����̏o������(SE�炵��������)
		int			 current;
		int			 notenum;		//���艹����
		int			 appeared;		//�o��������
		int			 IDnum;			//�摜��SE�̃f�[�^�̃J�E���^
		float		 speed,
					  time;  //�x�W�G�Ȑ��g���Ƃ��Ɏg���Ăˁ�
		POS			   pos,   //���݂̍��W
					 start,  //�o���n�_
					   dir,  //�x�W�G�Ȑ��̕����_
					   end;  //�x�W�G�Ȑ��̏I�_�A���͓����蔻��̈�
		int		  animeCnt,	//�A�j���J�E���g	
			  picHandle[4];	//�摜
	
		
		State        state;
		Type          type;	//�����̎��

	};

	bool LoadScore();

	bool Initialize();

	//bool Note_Apper();

	void Update();

	void Draw();

	void Fin();
}
