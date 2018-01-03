#include "Usingheaders.h"
 
bool Sound::Initialize()
{
	
	SE[appear]   = LoadSoundMem("./Sound/�o��.ogg");
	SE[carrot]   = LoadSoundMem("./Sound/�j���W��.ogg");
	SE[onion]    = LoadSoundMem("./Sound/�^�}�l�M.ogg");
	SE[broccoli] = LoadSoundMem("./Sound/�L���x�c.ogg");
	SE[cabbage]  = LoadSoundMem("./Sound/�L���x�c.ogg");
	SE[tomato]   = LoadSoundMem("./Sound/�g�}�g.ogg");
	SE[potato]   = LoadSoundMem("./Sound/�W���K�C��.ogg");
	SE[mouse]    = LoadSoundMem("./Sound/�L���x�c.ogg");
	SE[grill]    = LoadSoundMem("./Sound/�����Ă�.ogg");
	SE[bell]     = LoadSoundMem("./Sound/���X.ogg");
	SE[bell2]    = LoadSoundMem("./Sound/�����l!.ogg");
	BGM = LoadSoundMem("./Sound/������.wav");


	flag = true;
	
	for (int i = 0; i < SENUM; ++i)
	{
		if (SE[i] == -1 || BGM == -1)
		{
			return false;
		}
	}
	return true;
}
//BGM�����͖{���͂�������ׂ�������....���}�X�^�[�A�b�v���ɏC������\��
void Sound::SetBGM(const TCHAR *FileName)
{
	BGM = LoadSoundMem(FileName);
	flag = true;
}
void Sound::InitBGM()
{
	DeleteSoundMem(BGM);
	flag = true;

}
int Sound::PlayBGM_BACK()
{
	if (flag == true)
	{
		ChangeVolumeSoundMem(255 * 90 / 100, BGM);
		PlaySoundMem(BGM, DX_PLAYTYPE_BACK);
		flag = false;
	}
	return BGM;
}
int Sound::PlayBGM_LOOP()
{
	if (flag == true)
	{
		ChangeVolumeSoundMem(255 * 90 / 100, BGM);
		PlaySoundMem(BGM, DX_PLAYTYPE_LOOP);
		flag = false;
	}
	return BGM;
}
int Sound::PlaySE(int type)
{
	switch (type)
	{
	
	case carrot:      PlaySoundMem(SE[carrot],		 DX_PLAYTYPE_BACK);	break;
	case onion:       PlaySoundMem(SE[onion],		 DX_PLAYTYPE_BACK);	break;
	case broccoli:    PlaySoundMem(SE[broccoli],	 DX_PLAYTYPE_BACK);	break;
	case cabbage:     PlaySoundMem(SE[cabbage],		 DX_PLAYTYPE_BACK);	break;
	case tomato:      PlaySoundMem(SE[tomato],		 DX_PLAYTYPE_BACK);	break;
	case potato:	  PlaySoundMem(SE[potato],		 DX_PLAYTYPE_BACK);	break;
	case mouse:       PlaySoundMem(SE[mouse],		 DX_PLAYTYPE_BACK);	break;
	case meat:        PlaySoundMem(SE[meat],		 DX_PLAYTYPE_BACK);	break;
	case cuttingboard:PlaySoundMem(SE[cuttingboard], DX_PLAYTYPE_BACK);	break;
	case simmer:      PlaySoundMem(SE[simmer],		 DX_PLAYTYPE_BACK);	break;
	case grill:		  PlaySoundMem(SE[grill],		 DX_PLAYTYPE_BACK);	break;
	case jump:		  PlaySoundMem(SE[jump],		 DX_PLAYTYPE_BACK);	break;
	case slash:		  PlaySoundMem(SE[slash],		 DX_PLAYTYPE_BACK);	break;
	case bell:		  PlaySoundMem(SE[bell],		 DX_PLAYTYPE_BACK);	break;
	case bell2:		  PlaySoundMem(SE[bell2],        DX_PLAYTYPE_BACK);	break;
	case appear:	  PlaySoundMem(SE[appear],		 DX_PLAYTYPE_BACK);	break;
					  
	}				  
	return 0;		  
}			

void Sound::Fin()	  
{					  
	for (int i = 0; i < SENUM; ++i)
	{
		DeleteSoundMem(SE[i]);
	}
	DeleteSoundMem(BGM);

}