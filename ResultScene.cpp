#include "ResultScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include <iostream>

ResultScene::ResultScene(GameObject* parent)
	:GameObject(parent, "ResultScene")
{
}

ResultScene::~ResultScene()
{
}

void ResultScene::Initialize()
{
	pFbx = new Fbx;
	pFbx->Load("Cube.fbx");
	transform_.scale_ = { 0.2f, 0.2f, 0.2f };
}

void ResultScene::Update()
{
	float screenWidth = 4.0f;
	float screenHeight = 4.0f;
	float Xspeed = 0.05f;
	float Yspeed = 0.03f;

	//watch ‚ğg‚Á‚Ä¶‰E‚É‰•œ
	transform_.position_.x = screenWidth * sin(watch);
	transform_.position_.y = screenHeight * cos(watch * 0.6f);
	watch += Xspeed;
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* sceneManager = dynamic_cast<SceneManager*>(pParent_);
		if (sceneManager)
		{
			sceneManager->ChangeScene(SCENE_ID_TEST);
		}
	}
}

void ResultScene::Draw()
{
	pFbx->Draw(transform_);
}

void ResultScene::Release()
{
}
