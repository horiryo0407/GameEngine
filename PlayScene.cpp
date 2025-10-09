#include "PlayScene.h"
#include "Player.h"

PlayScene::PlayScene(GameObject* parent)
{

}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
	Player* pPlayer = new Player(this);
	pPlayer->Initialize();
	childList_.push_back(pPlayer);
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
