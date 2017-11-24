#include "Usingheaders.h"
#include <math.h>

namespace BGM {
	Bgm bgm;

	int cnt;
	bool flag;
	int current;

	int bg2;	//�e�[�u���Ə�
	int chef[3];
	int chefY;	//�R�b�N����̂x�̒l
	int mtr;
	bool anime; //�A�j���[�V�������n�߂鎞�Ԃ����
	int aniCnt; //�A�j���[�V�������Đ�����t���C��

	void Play(int &SE);

	bool Initialize() {
		bgm.BPM = 130;									//��BPM
		bgm.second = 60;								//1�b
		bgm.singlfps = 1000 / 60;						//1�t���[�����̎���[ms]

		bgm.beat = 4;									//���q
		bgm.sibu = 1000 * (bgm.second / bgm.BPM);		//4������1���̏I���_

		cnt = 1;
		flag = true;

		bgm.SE = LoadSoundMem("Sound/bell.ogg");
		bgm.BGM = LoadSoundMem("Sound/new130.wav");

		PlaySoundMem(bgm.BGM, DX_PLAYTYPE_LOOP);
		PlaySoundMem(bgm.SE, DX_PLAYTYPE_BACK);

		chefY = 27;
		anime = false;
		aniCnt = 0;
		mtr = LoadDivGraph("./Graph/chef.png", 3, 3, 1, 130, 247, chef);
		bg2 = LoadGraph("./Graph/bg2.png");

		if (bgm.BGM == -1 || bgm.SE == -1)
		{
			return false;
		}

		return true;
	}

	void Updata()
	{
		current = GetSoundCurrentTime(bgm.BGM);
		if (current >= bgm.sibu && flag == true)
		{
			Play(bgm.SE);
			flag = false;
			++cnt;
		}

		if (flag == false)
		{
			bgm.sibu = 1000 * (bgm.second / bgm.BPM);
			bgm.sibu *= cnt;
			flag = true;
		}
	}

	void Draw()
	{
		int ani[7] = { 2,2,1,1,0,1,2 }; //�A�j���[�V�����Ƀf�B���C�������邽�߂ɗv�f���𑝂₵�Ă���i���ۂ�5���܁j
		if (anime == true) {
			aniCnt++;
			if (aniCnt < 5) {
				chefY += 2;
			}
			else if (aniCnt < 7) {
				chefY -= 4;
			}
			else {
				anime = false;
				aniCnt = 0;
			}
		}
		DrawGraph(40, chefY, chef[ani[aniCnt]], true);
		DrawGraph(0, 263, bg2, TRUE);
		
	}

	void Fin()
	{
		DeleteGraph(bg2);
		for (int i = 0; i < 3; i++) {
			DeleteGraph(chef[i]);
		}
	}

	void Play(int &SE)
	{
		PlaySoundMem(SE, DX_PLAYTYPE_BACK);

		anime = true;
	}
}