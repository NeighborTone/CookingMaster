#pragma once
namespace BGM {
	struct Bgm {
		float BPM ;				//��BPM
		float second ;			//1�b
		int singlfps ;		//1�t���[�����̎���[ms]

		int beat ;					//���q
		float sibu ;		//4������1���̏I���_
		int SE;
		int BGM;

	};

	bool Initialize();

	void Updata();

	void Draw();

	void Fin();
}
