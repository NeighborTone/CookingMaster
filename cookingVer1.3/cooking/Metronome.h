#pragma once
namespace Metronome {
	enum State {
		up,
		down,
	};

	struct StaffAnimation {
		float BPM;				//��BPM
		float second;			//1�b
		int singlfps;		//1�t���[�����̎���[ms]

		int beat;					//���q
		float sibu;		//4������1���̏I���_
		int cnt;
		bool flag;
		int current;

	};
	struct ChefAnimation {
		int bg1;    //�L�b�`��
		int bg2;	//�e�[�u���Ə�
		int chef[3];
		int chefY;	//�R�b�N����̂x�̒l
		int mtr;
		bool anime; //�A�j���[�V�������n�߂鎞�Ԃ����
		int aniCnt; //�A�j���[�V�������Đ�����t���C��
	};
	
	struct SubAnimation {
		bool flag;		//�����̕\���t���b�O
		int x, y,		//������x,y�l
			stf,		//�����̉摜
			aniCnt,		//�A�j���[�V�����J�E���g
			food[2],	//�H�ו��̉摜
			foodNum;	//�摜�ԍ�
		State state;	//�㉺�A�j���[�V�����̂���
		bool anime;		//
	};

	bool Initialize();

	void Update();

	void Draw();

	void Fin();
}
