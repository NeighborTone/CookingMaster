#pragma once
namespace Sound {

	enum SETYPE
	{
		carrot,
	};

	void Initialize();

	void PlayBGM();

	int PlaySE(int);	//enumでIDを指定、戻り値はIDに対応したSE

	void Fin();

}