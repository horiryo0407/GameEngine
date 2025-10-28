#include "TestScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/Model.h"



TestScene::TestScene(GameObject* parent)
	:GameObject(parent, "TestScene")
	, hModel_(-1)
{
}

TestScene::~TestScene()
{
}

void TestScene::Initialize()
{
	
}

void TestScene::Update()
{

	hModel_ = Model::Load("Cube.fbx");

	transform_.scale_.x = 0.7f;
	transform_.scale_.y = 0.7f;
	transform_.scale_.z = 0.7f;
	
	static float x = 0.0f;
	float tx = sin(x) * 5.0f;
	x -= 0.02f;

	static float y = 0.0f;
	float ty = cos(y) * 5.0f;
	y -= 0.02f;
	transform_.position_.x = tx;
	transform_.position_.y = ty;
	transform_.rotate_.y -= 1.6f;
	
	//スペースキー押したらSceneManager::ChangeScene(SCENE_ID_PLAY)を呼び出す
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* sceneManager = dynamic_cast<SceneManager*>(pParent_);
		if (sceneManager)
		{
			sceneManager->ChangeScene(SCENE_ID_PLAY);
		}
	}
}


void TestScene::Draw()
{
	if (hModel_ >= 0)
	{
		Model::SetTransform(hModel_, transform_);
		Model::Draw(hModel_);
	}
}

void TestScene::Release()
{
	Model::Release();
	hModel_ = -1;
}
