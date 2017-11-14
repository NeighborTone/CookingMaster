#pragma once
#include "BaseInfo.h"
#include <vector>

using namespace std;

class Object {
protected:
	Vec3		pos;		//���W
	vector<int>	picHandle;	//�摜�n���h��
	int			animCnt;	//�A�j���[�V�����p�J�E���^

public:
	Object() {};
	virtual ~Object() {};
	virtual void Init() {};
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Fin() {};

	void setPos(float x, float y) {
		pos.x = x;
		pos.y = y;
	}
};