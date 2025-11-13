#pragma once
#include "Engine/GameObject.h"
#include "Engine/Fbx.h"
class ResultScene :
	public GameObject
{
	Fbx* pFbx;
	float watch;

public:
	ResultScene(GameObject* parent);
	~ResultScene();
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;

};

