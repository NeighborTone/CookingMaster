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

	struct hoge  //��
	{
		POS pos;
		int handle;
	};
	hoge h1, h2, h3;

	struct Food
	{
		int pic_carrot,	//�摜�n���h��
			pic_cabbage,
			pic_potato,
			pic_tomato,
			pic_broccoli,
			pic_onion;
	};

	Food food;

private:
	int bghandle;
	
	bool flag;
};