#include "PlayScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene")
{

}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	Instantiate<Enemy>(this);
}

void PlayScene::Update()
{
	/*if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* sceneManager = dynamic_cast<SceneManager*>(pParent_);
		if (sceneManager)
		{
			sceneManager->ChangeScene(SCENE_ID_RESULT);
		}
	}*/
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
