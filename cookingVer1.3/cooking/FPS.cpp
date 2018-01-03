#include "Usingheaders.h"
#if _DEBUG
Fps::Fps():
mStartTime(0),
mCount(0),          //�J�E���^
mFps(0)
{}

bool Fps::Update()
{
	//1�t���[���ڂȂ玞�����L��
	if (mCount == 0)
	{
		mStartTime = GetNowCount();
	}
	//60�t���[���ڂȂ畽�ς��v�Z����
	if (mCount == N)
	{
		int t = GetNowCount();
		mFps = 1000.f / ((t - mStartTime) / (float)N);
		mCount = 0;
		mStartTime = t;
	}
	++mCount;
	return true;
}

void Fps::Draw()
{
	DrawFormatString(0, 520, GetColor(0, 0, 0), "%.1f", mFps);
}

void Fps::Wait()
{
	int tookTime = GetNowCount() - mStartTime;		//������������
	int waitTime = mCount * 1000 / FPS - tookTime;	//�҂ׂ�����
	if (waitTime > 0)
	{
		Sleep(waitTime);							//�ҋ@
	}

}
#endif