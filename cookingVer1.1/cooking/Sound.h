#pragma once
namespace Sound {

	enum SETYPE
	{
		carrot,			//�j���W��
		onion,			//�^�}�l�M
		broccoli,		//�u���b�R���[
		cabbage,		//�L���x�c
		tomato,			//�g�}�g
		potato,			//�W���K�C��
		mouse,			//�l�Y�~
		meat,			//��
		cuttingboard,	//�܂Ȕ�
		simmer,			//�ς�
		grill,			//�Ă�
		jump,			//�W�����v
		slash,			//�؂�
		bell,			//���X���i�x���j
		apper,			//�����o����



	};

	void Initialize();

	void PlayBGM();

	int PlaySE(int);	//enum�^��ID���w��A�߂�l��ID�ɑΉ�����SE

	void Fin();

}