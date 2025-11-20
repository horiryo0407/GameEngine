#include "Enemy.h"
#include "Engine/SphereCollider.h"
#include "Engine/SceneManager.h"
#include "ResultScene.h"

Enemy::Enemy(GameObject* parent)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	pFbx = new Fbx;
	pFbx->Load("Oden.fbx");
	transform_.position_ = { 0.0f,0.0f,50.0f };

	SphereCollider* col = new SphereCollider(1.0f);
	AddCollider(col);

}

void Enemy::Update()
{
	float screenWidth = 30.0f; 
	float screenHeight = 5.0f;
	float Xspeed = 0.05f;   
	float Yspeed = 0.03f;

	//timer_ を使って左右に往復
	transform_.position_.x = screenWidth * sin(timer_);
	transform_.position_.y = screenHeight * cos(timer_ * 0.6f);
	timer_ += Xspeed;
}

void Enemy::Draw()
{
	//for(int i = 0; i < 3; i++)
	//{
	//	transform_.position_.z = 50.0f + i * 5.0f; 
	//	// 少しずつ手前に配置
	//	pFbx->Draw(transform_);
	//}
	pFbx->Draw(transform_);
}

void Enemy::Release()
{
	if (pFbx)
	{
		pFbx->Release();
		delete pFbx;
		pFbx = nullptr;
	}
}

void Enemy::onCollision(GameObject* pTarget)
{
	if (pTarget->GetName() == "Bullet")
	{
		KillMe();

		// シーン遷移処理
		SceneManager* pSceneManager = SceneManager::GetInstance();
		pSceneManager->ChangeScene(SCENE_ID_RESULT);
	}
}
