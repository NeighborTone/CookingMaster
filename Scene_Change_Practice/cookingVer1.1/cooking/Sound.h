#pragma once
namespace Sound {

	enum SETYPE
	{
		apper,			//�����o����0
		carrot,			//�j���W��1
		onion,			//�^�}�l�M2
		broccoli,		//�u���b�R���[3
		cabbage,		//�L���x�c4
		tomato,			//�g�}�g5
		potato,			//�W���K�C��6
		mouse,			//�l�Y�~7
		meat,			//��8
		cuttingboard,	//�܂Ȕ�9
		simmer,			//�ς�10
		grill,			//�Ă�11
		jump,			//�W�����v12
		slash,			//�؂�13
		bell,			//���X���i�x���j13
		



	};

	bool Initialize();

	void PlayBGM();

	int PlaySE(int);	//enum�^��ID���w��A�߂�l��ID�ɑΉ�����SE

	void Fin();

}