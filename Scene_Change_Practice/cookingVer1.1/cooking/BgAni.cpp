#include "Usingheaders.h"

namespace BgAni {

	int background;
	int chef[3];
	int aniCnt;
	int check;
	bool Initialize()
	{
		background = LoadGraph("./Graph/bg.png");
		aniCnt = 0;
			if (background == -1 || check == -1)
			{
				return false;
			}

		return true;
	}

	void Updata()
	{
		++aniCnt;
		if (aniCnt >= 90) {
			aniCnt = 0;
		}
	}

	void Draw()
	{
		DrawGraph(0, 0, background, true);
	}

	void Fin()
	{
		DeleteGraph(background);
	
		for (int i = 0; i < 2; ++i)
		{
			DeleteGraph(chef[i]);
		}
	}
}