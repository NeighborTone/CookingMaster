#include "Usingheaders.h"
#include <math.h>

namespace BGM {
	Bgm bgm;

	int cnt;
	bool flag;
	int current;

	int bg2;	//テーブルと床
	int chef[3];
	int chefY;	//コックさんのＹの値
	int mtr;
	bool anime; //アニメーションを始める時間を取る
	int aniCnt; //アニメーションが再生するフレイム

	void Play(int &SE);

	bool Initialize() {
		bgm.BPM = 130;									//曲BPM
		bgm.second = 60;								//1秒
		bgm.singlfps = 1000 / 60;						//1フレーム分の時間[ms]

		bgm.beat = 4;									//拍子
		bgm.sibu = 1000 * (bgm.second / bgm.BPM);		//4分音符1個分の終了点

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
		int ani[7] = { 2,2,1,1,0,1,2 }; //アニメーションにディレイをかけるために要素数を増やしている（実際は5こま）
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