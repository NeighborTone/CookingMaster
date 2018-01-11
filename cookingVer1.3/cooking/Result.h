#pragma once

class Result : public Scene
{
public:
	bool Initialize() override;
	void Update()	  override;
	void Draw()       override;
	void Finalize()   override;
	struct POS
	{
		void SetPOS(float x, float y)
		{
			this->x = x;
			this->y = y;
		}
		float x, y;
	};
	int a;
	Sound sound;

	struct hoge  //‰¼
	{
		POS pos;
		int handle;
	};
	hoge h1, h2, h3;

	

	struct Food
	{
		int pic;
		POS pos;
	};
	float c;
	int Rcarrot, Ronion, Rcabbage, Rpotato, Rtomato, Rbrory;

	Food carrot;
	Food onion;
	Food cabbage0;
	Food cabbage1;
	Food cabbage2;
	Food cabbage3;
	Food cabbage4;
	Food potato;
	Food tomato;
	Food brory;

	//void PutAni(Food& f, float y);

private:
	int bghandle;
	
	bool flag;
};