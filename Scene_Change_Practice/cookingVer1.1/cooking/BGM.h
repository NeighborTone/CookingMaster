#pragma once
namespace BGM {
	struct Bgm {
		float BPM ;				//��BPM
		float second ;			//1�b
		int singlfps ;		//1�t���[�����̎���[ms]

		int beat ;					//���q
		float sibu ;		//4������1���̏I���_
		int SE;
		int BGM;
		int cnt;
		bool flag;
		int current;

		int bg2;	//�e�[�u���Ə�
		int chef[3];
		int chefY;	//�R�b�N����̂x�̒l
		int mtr;
		bool anime; //�A�j���[�V�������n�߂鎞�Ԃ����
		int aniCnt; //�A�j���[�V�������Đ�����t���C��
	};
	
	bool Initialize();

	void Updata();

	void Draw();

	void Fin();
}
