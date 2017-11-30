#pragma once

struct POS
{			//���W
	float x;
	float y;
};
enum N_Type
{			//�����̃^�C�v

	N_one,	//�P��
	N_rest,	//������(�x��)
	N_mouse,	//�l�Y�~(�����炭���)
}; 
enum State 
{
	come,
	cut,
	off,
};
enum Hit
{
	Normal,
	hit,
	miss,
};
struct Move		//�����̓����i�ړ��ƃA�j���[�V�����j
{
	POS		     pos,
			   start,
			     dir,
		         end;
	State	   state;
	N_Type note_type;
	int			time;
	float      speed;
	int	    animeCnt;
	int picHandle[4];

};
struct Data		//�����̔���Ȃǂ̏��
{
	int	   judge[100];		//���莞��
	int	      ID[100];		//�摜��SE�̏��
	int	  appear[100];		//�o������
	int	      current;		//�Ȃ̍Đ��ꏊ
	//�Y����
	int			j_cnt;		//���萔
	int        ID_cnt;		//����ID�ɐi�߂�
	int         a_cnt;		//�o����
	
	int	        score;		//���_
	Hit	          hit;		//����p
		
};
class Note
{
public:
	Data data;
	Move move;
	

	bool LoadScore();

	bool Initialize();

	void Update();

	void Draw();

	void Fin();
};

bool Note_Check_Good(int c, int j);
bool Note_Check_Cool(int c, int j);
bool Note_Check_Bad(int c, int j);