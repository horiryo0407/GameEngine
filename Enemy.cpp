#include "Enemy.h"
#include "Engine/SphereCollider.h"

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

	// timer_ ‚ðŽg‚Á‚Ä¶‰E‚É‰•œ
	transform_.position_.x = screenWidth * sin(timer_);
	transform_.position_.y = screenHeight * cos(timer_ * 0.6f);
	timer_ += Xspeed;
}

void Enemy::Draw()
{
	pFbx->Draw(transform_);
}

void Enemy::Release()
{
}

void Enemy::onCollision(GameObject* pTarget)
{
	if (pTarget->GetName() == "Bullet")
	{
		KillMe();
	}
}
