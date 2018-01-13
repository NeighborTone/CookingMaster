#pragma once

//�V�[���Ǘ��̊��N���X
class Scene
{
public:
	virtual bool Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Finalize() = 0;
};