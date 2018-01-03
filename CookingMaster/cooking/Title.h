#pragma once

class Title : public Scene
{
public:
	bool Initialize() override;
	void Update()	  override;
	void Draw()       override;
	void Finalize()   override;

	int ��;		//���ߗ�
	bool flag;	//�t�F�[�h�A�E�g�t���O
	struct POS
	{
		void SetPOS(float x, float y)
		{
			this->x = x;
			this->y = y;
		}
		float x, y;
	};
	enum SELECT
	{
		Start,
		End
	};
	struct Cursor
	{
		POS pos;
		SELECT select;
		int handle;
	};
	Cursor cursor;			//�J�[�\��
	int bgHandle;			//�w�i�n���h��
	struct Logo
	{
		POS pos;
		int handle;		
	};
	Logo logo;				//�^�C�g�����S
	struct Startbutton
	{
		POS pos;
		int handle;
	};
	Startbutton s_button;	//�X�^�[�g�{�^��
	struct Endbutton
	{
		POS pos;
		int handle;
	};
	Endbutton e_button;		//�G���h�{�^��
};

