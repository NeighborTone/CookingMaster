#include "DxLib.h"
#include "titlt_aaa.h"
namespace Title_G
{
	int pic;
	void Initialize()
	{
		
		pic = LoadGraph("./Graph/�^�C�g��.bmp");
		
	}
	void Draw()
	{
		DrawGraph(0, 0, pic, true);
	}
}