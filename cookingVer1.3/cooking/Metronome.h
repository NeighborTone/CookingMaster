#pragma once
namespace Metronome {
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
	
	bool Initialize();

	void Update();

	void Draw();

	void Fin();
}
