#pragma once

extern const int
quarterNote,		//�l�������̒���(ms)
halfNote;			//�񕪉����̒���(ms)


struct POS
{			//���W
	float x;
	float y;
	POS(){}
	POS(float x, float y) :x(x), y(y) {}
	POS operator + (const POS& p) const {
		return POS({ x + p.x, y + p.y });
	}
	POS operator - (const POS& p) const {
		return POS({ x - p.x, y - p.y });
	}
	POS &operator += (const POS& p) {
		x += p.x;
		y += p.y;
		return (*this);
	}
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
enum Direction {	//�o���ʒu�̕���
	LEFT,
	RIGHT,
	BOTTOM,
};
struct BezierCurve {
	POS			bez;
	float		time;
	BezierCurve():
		bez({ 0,0 }), time(0) {}
	~BezierCurve() {}
	void BezTimeUpdate(N_Type nt, int current, int appear) {
		time = float(current - appear) / ((nt == N_one) ? (float)quarterNote : (float)halfNote);
	}
	POS MoveBezier2(POS start,POS dir,POS end){
		bez.x = (1 - time)*(1 - time)*start.x + 2 * (1 - time)*time*dir.x + time*time*end.x;
		bez.y = (1 - time)*(1 - time)*start.y + 2 * (1 - time)*time*dir.y + time*time*end.y;

		return bez;
	}
};
struct Move		//�����̓����i�ړ��ƃA�j���[�V�����j
{
	POS		     pos,	//���ݍ��W
			   start,	//�o���ʒu
			     dir,	//�����_
		         end;	//������W
	State	   state;	//����(��ɉ摜�̕ω��Ŏg��)
	N_Type note_type;	//�񕪁A�l��
	float      speed;	//�ړ��X�s�[�h�A�񕪂��l�����Ō��܂�
	int	    animeCnt;	//�A�j���[�V�����p�J�E���^
	int pic_carrot[4],	//�摜�n���h��
	   pic_cabbage[4],
		pic_potato[4],
		pic_tomato[4],
	  pic_broccoli[4],
		 pic_onion[4];



};
struct Data		//�����̔���Ȃǂ̏��
{
	int			judge;		//���莞�� �t�@�C������ǂݍ���
	int			   ID;		//�摜��SE�̏��	�t�@�C������ǂݍ���
	Direction	   d;		//���E�ǂ������痈�邩�@�t�@�C������ǂݍ���
	int		   appear;		//�o������	judge����Z�o
	int	      current;		//�Ȃ̍Đ��ꏊ
	////�Y����
	//int			j_cnt;		//���萔
	//int        ID_cnt;		//����ID�ɐi�߂�
	//int         a_cnt;		//�o����
	Hit	          hit;		//����p
	
	
		
};
struct File {		//���ق��ۂ��\���́B
	//�ꎞ�ۊǗp�ϐ�
	int judge[100] = {};
	int id[100] = {};
	int dir[100] = {};

	bool LoadScore();	//�t�@�C���̓ǂݍ���
};
class Note
{
	 int	imageSizeX = 100,
			imageSizeY = 100;
	 bool	appearSEplayed;
public:
	Data data;
	Move move;
	BezierCurve bez;

	//Note(){}
	void SetScore(int id, Note& note, const File& file);	//�t�@�C������ǂ񂾃f�[�^���Z�b�g����
	void SetN_Type(Note& note);			//N_Type�����߂�
	void SetAppearTime(Note& note);		//�o���^�C�~���O���Z�o
	void SetSpeed(Note& note);			//�ړ����x�����߂�
	void SetBezierData(Note& note);		//start,dir,end�����߂�
	
	bool Initialize();

	void Update();

	void Draw();

	void Fin();
};

bool Note_Check_Good(int c, int j);
bool Note_Check_Cool(int c, int j);
bool Note_Check_Bad(int c, int j);
bool Auto(int c, int j);

