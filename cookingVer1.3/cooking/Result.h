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
private:
	int bghandle;
	
	bool flag;
};