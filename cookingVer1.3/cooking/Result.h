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

	Food carrot;
	Food onion;
	Food cabbage;
	Food potato;
	Food tomato;
	Food brory;

private:
	int bghandle;
	
	bool flag;
};