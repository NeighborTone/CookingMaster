#include "Usingheaders.h"

namespace Player {
	static const int
		SCREEN_WIDIH = 960,
		SCREEN_HEIGHT = 540;
	const int num = 7;
	Cock cock;
	Cock check;	//�����蔻��̉����ɗp����A�s�v�ɂȂ�����폜
	Effect effect;
	Metronome::StaffAnimation staff;

	void Stand_Animation();
	void RCut_Animation();
	void LCut_Animation();
	void BHit_Animation();
	void Effect_draw();

	bool Initialize()
	{
		staff.BPM = 130;									//��BPM
		staff.second = 60;									//1�b
		staff.singlfps = 1000 / 60;							//1�t���[�����̎���[ms]

		staff.beat = 4;										//���q
		staff.sibu = 1000 * (staff.second / staff.BPM);		//4������1���̏I���_

		staff.cnt = 1;
		staff.flag = true;

		cock.x = SCREEN_WIDIH / 2;
		cock.y = SCREEN_WIDIH / 4 + 90;
		cock.w = 512;
		cock.h = 512;
		check.x = 630;
		check.y = 280;
		cock.state = down;
		cock.animCnt = 0;
		cock.dir = LEFT;

		effect.flag = false;
		effect.Cnt = 0;

		//c1,c2,c3�̓G���[�`�F�b�N�p�ϐ��B
		int c = LoadDivGraph("./Graph/stand.png", 3, 3, 1, 277, 524, cock.Gstand);
		int c2 =LoadDivGraph("./Graph/cutR.png", 3, 3, 1, 394, 495, cock.GcutR);
		int c3 = LoadDivGraph("./Graph/cutL.png", 3, 3, 1, 388, 517, cock.GcutL);
		int c4 = LoadDivGraph("./Graph/bottom.png", 3, 3, 1, 336, 521, cock.GcutB);
		cock.e_pic = LoadGraph("./Graph/effect.png", true);

		if (c == -1 || c2 == -1 || c3 == -1)
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

		if (Key(KEY_INPUT_Z) == 1)
		{
			cock.state = cut;
		}
	}

	void Draw()
	{
		Stand_Animation();

		RCut_Animation();
		LCut_Animation();
		BHit_Animation();

		//�����蔻��̉���
		DrawCircle(check.x + 10, check.y + 100, 50, GetColor(255, 0, 0), false);			//�E (x+10,y+90)
		DrawCircle((check.x / 2) + 10, check.y + 90, 50, GetColor(255, 0, 0), false);		//�� (x+10,y+90)
		DrawCircle(check.x - 145, check.y - 110, 50, GetColor(255, 0, 0), false);//��(x+10,y+90)
		DrawCircle(check.x - 145, check.y + 240, 50, GetColor(255, 0, 0), false);//��(x+10,y+90)
	}

	void Fin()
	{
		for (int i = 3; i < num; ++i)
		{
			DeleteGraph(cock.Gstand[i]);
			DeleteGraph(cock.GcutR[i]);
			DeleteGraph(cock.GcutL[i]);
			DeleteGraph(cock.GcutB[i]);
		}
		DeleteGraph(cock.e_pic);
	}


	void Stand_Animation()
	{
		//���ҋ@��Ԃ����`��
		int anime[num * 2] = { 2,2,2,1,1,0,0,0,0,0,1,1,2,2 };
		if (cock.state == down && cock.flag == true) {
			++cock.animCnt;
			if (cock.animCnt > num) {
				cock.state = up;
				cock.flag = false;
			}
		}
		if (cock.state == up && cock.flag == true) {
			++cock.animCnt;
			if (cock.animCnt > num * 2 - 1) {
				cock.animCnt = 0;
				cock.state = down;
				cock.flag = false;
			}
		}
		if (cock.state == up || cock.state == down)
		{
			DrawRotaGraph(int(cock.x), int(cock.y), 0.6, 0.0, cock.Gstand[anime[cock.animCnt]], true);
		}
		//��
	}

	void RCut_Animation()
	{
		if (cock.state == cut && cock.dir == RIGHT) {
			int anime[num] = { 0,0,1,1,2,2,2 };
			DrawRotaGraph(int(cock.x), int(cock.y), 0.6, 0.0, cock.GcutR[anime[cock.animCnt / 3]], true);
			cock.animCnt++;
			if (effect.flag == true) {
				Effect_draw();
			}
			if (cock.animCnt > num * 3 - 1) {
				cock.state = down;
				cock.animCnt = 0;
			}
		}
	}
	void LCut_Animation()
	{
		if (cock.state == cut && cock.dir == LEFT) {
			int anime[num] = { 0,0,1,1,2,2,2 };
			DrawRotaGraph(int(cock.x), int(cock.y), 0.6, 0.0, cock.GcutL[anime[cock.animCnt / 3]], true);
			cock.animCnt++;
			if (effect.flag == true) { //�G�t�F�N�g
				Effect_draw();
			}
			if (cock.animCnt > num * 3 - 1) {
				cock.state = down;
				cock.animCnt = 0;
			}
		}
	}
	void BHit_Animation()
	{
		if (cock.state == cut && cock.dir == BOTTOM) {
			int anime[num] = { 0,0,1,1,2,2,2 };
			DrawRotaGraph(int(cock.x), int(cock.y), 0.6, 0.0, cock.GcutB[anime[cock.animCnt / 3]], true);
			cock.animCnt++;
			if (effect.flag == true) { //�G�t�F�N�g
				Effect_draw();
			}
			if (cock.animCnt > num * 3 - 1) {
				cock.state = down;
				cock.animCnt = 0;
			}
		}
	}

	void Effect_draw()
	{
		if (effect.Cnt <= 5) {			//cut�n�߂Ă���5�t���C����܂�
			if (cock.dir == RIGHT) {	//�E�����̃G�t�F�N�g
				DrawRotaGraph(check.x - 20, check.y + 80, 1.0, 0.0, cock.e_pic, true);
			}
			if (cock.dir == LEFT) {		 //�������̃G�t�F�N�g
				DrawRotaGraph((check.x / 2) + 10, check.y + 90, 1.0, 0.0, cock.e_pic, true);
			}
			if (cock.dir == BOTTOM) {		 //�������̃G�t�F�N�g
				DrawRotaGraph(check.x - 145, check.y + 240, 1.0, 0.0, cock.e_pic, true);
			}
		}
		else
		{
			effect.flag = false;
			effect.Cnt = 0;
		}
		effect.Cnt++;
	}


	void Player_Animation(int data)
	{
		if (data == LEFT) {
			Player::CutL_On();
		}
		if (data == RIGHT) {
			Player::CutR_On();
		}
		if (data == BOTTOM) {
			Player::HitB_On();
		}
	}

	void Effect_On()
	{
		effect.flag = true;
	}

	void CutL_On()		//�v���C���[����������
	{
		cock.dir = LEFT;
	}
	void CutR_On()		//�v���C���[���E������
	{
		cock.dir = RIGHT;
	}
	void HitB_On()		//�v���C���[���E������
	{
		cock.dir = BOTTOM;
	}

	void Set_Cut() //�I�[�g���[�h�p
	{
		cock.state = cut;
	}

}
