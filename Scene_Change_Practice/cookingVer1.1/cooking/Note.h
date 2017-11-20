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
		int apper_note[1000];
		int play_note_type[1000];
		float		 speed,
					  time;  //�x�W�G�Ȑ��g���Ƃ��Ɏg���Ăˁ�
		POS			   pos,   //���݂̍��W
					 start,  //�o���n�_
					   dir,  //�x�W�G�Ȑ��̕����_
					   end;  //�x�W�G�Ȑ��̏I�_�A���͓����蔻��̈�
		double		   Cnt;	//�t���[���J�E���g
		int		  animeCnt,	//�A�j���J�E���g	
			  picHandle[4];	//�摜
	
		
		State        state;
		Type          type;	//�����̎��

	};

	bool LoadScore();

	bool Initialize();

	void Updata();

	void Draw();

	void Fin();
}
