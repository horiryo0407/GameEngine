#include "TestScene.h"


TestScene::TestScene(GameObject* parent)
	:GameObject(parent, "TestScene")
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
	//スペースキー押したらSceneManager::ChangeScene(SCENE_ID_PLAY)を呼び出す

     
}

void TestScene::Draw()
{
}

void TestScene::Release()
{
}
