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
		float		 speed,
					  time;  //�x�W�G�Ȑ��g���Ƃ��Ɏg���Ăˁ�
		POS			   pos,   //���݂̍��W
					 start,  //�o���n�_
					   dir,  //�x�W�G�Ȑ��̕����_
					   end;  //�x�W�G�Ȑ��̏I�_�A���͓����蔻��̈�
		double			   Cnt;	//�t���[���J�E���g
		int		  animeCnt,	//�A�j���J�E���g	
			  picHandle[4];	//�摜
		double BPM;									//�e���|
		double BGM_time;							//�Ȃ̎���
		double beat;								//��
		double fourn_note;// = BPM / 60;			//4������
		double eight_note;
		double hit_time;// fourn_note * 2.0;		//���ۂɔ�������n�߂�^�C�~���O
		double Bar_end;// = fourn_note * beat;			//1���߂̒���(�I�[
		State        state;
		Type          type;	//�����̎��

	};

	bool Initialize();

	void Updata();

	void Draw();

	void Fin();
}
