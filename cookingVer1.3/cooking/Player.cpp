#include "Usingheaders.h"

namespace Player {
	static const int
		SCREEN_WIDIH = 960,
		SCREEN_HEIGHT = 540;
	const int num = 7;
	Cock cock;
	Cock check;	//�����蔻��̉����ɗp����A�s�v�ɂȂ�����폜
	Metronome::StaffAnimation staff;

	int Gstand[3];
	int GcutR[3];
	bool Initialize()
	{
		cock.x = SCREEN_WIDIH/2;
		cock.y = SCREEN_WIDIH/4 + 90;
		cock.w = 512;
		cock.h = 512;
		check.x = 630;
		check.y = 280;
		cock.state = stand;
		cock.animCnt = 0;

		cock.picHandle[0] = LoadGraph("./Graph/512.png");
		LoadDivGraph("./Graph/stand.png", 3, 3, 1, 277, 502, Gstand);
		LoadDivGraph("./Graph/cutR.png", 3, 3, 1, 394, 495, GcutR);
		cock.e_pic=LoadGraph("./Graph/test_E.png", true);

		if (cock.picHandle[0] == -1)
		{
			return false;
		}
		return true;
	}

	void Update()
	{
		Sound GetSound();
		auto sound = GetSound();
		staff.current = GetSoundCurrentTime(sound.BGM);
		if (staff.current >= staff.sibu && staff.flag == true)
		{
			staff.flag = false;
			cock.flag = true;
			++staff.cnt;
		}

		if (staff.flag == false)
		{
			staff.sibu = 1000 * (staff.second / staff.BPM);
			staff.sibu *= staff.cnt;
			staff.flag = true;
		}

		if (Key(KEY_INPUT_RIGHT) >= 1)
		{
			cock.x += 5;
		}
		if (Key(KEY_INPUT_LEFT) >= 1)
		{
			cock.x -= 5;
		}
		if (Key(KEY_INPUT_Z) == 1)
		{
			cock.state = cut;
		}
	}

	void Draw()
	{
		if (cock.state == stand) {
			if (cock.flag == false) {
				DrawRotaGraph(int(cock.x), int(cock.y), 0.6, 0.0, Gstand[0], true);
			}
			if (cock.flag == true) {
				int anime[num] = { 2,2,1,1,0,1,2 };
				DrawRotaGraph(int(cock.x), int(cock.y), 0.6, 0.0, Gstand[anime[cock.animCnt]], true);
				cock.animCnt++;
			}
			if (cock.animCnt > num-1) {
				cock.flag = false;
				cock.animCnt = 0;
			}
		}
		if (cock.state == cut) {
			int anime[num] = { 0,0,1,2,2,2 ,2};
			DrawRotaGraph(int(cock.x), int(cock.y), 0.6, 0.0,GcutR[anime[cock.animCnt]], true);
			cock.animCnt++;
			if (cock.animCnt <= 3) {
				DrawRotaGraph(check.x-20, check.y +80, 1.0, 0.0, cock.e_pic, true);
			}
			if (cock.animCnt > num-1) {
				cock.state = stand;
				cock.animCnt = 0;
			}
		}

		
		//���̃L����

		//�����蔻��̉���
		DrawCircle(check.x+10, check.y +100, 50, GetColor(255, 0, 0), false);			//�E (x+10,y+90)
		DrawCircle((check.x / 2)+10, check.y + 90, 50, GetColor(255, 0, 0), false);		//�� (x+10,y+90)
		DrawCircle(check.x - 145, check.y - 110, 50, GetColor(255, 0, 0), false);//��(x+10,y+90)
		DrawCircle(check.x - 145, check.y + 240, 50, GetColor(255, 0, 0), false);//��(x+10,y+90)
	}

	void Fin()
	{
		for (int i = 0; i < num; ++i)
		{
			DeleteGraph(cock.picHandle[i]);
		}
	}
}
