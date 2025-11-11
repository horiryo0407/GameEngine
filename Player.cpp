#include "Player.h"
#include "Engine/Fbx.h"
#include "ChildOden.h"
#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Engine\\Input.h"
#include <algorithm>


Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),pFbx_(nullptr)
	, pRChildOden_(nullptr), pLChildOden_(nullptr)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	/*pFbx_ = new Fbx;
	pFbx_->Load("Oden.fbx");*/
	transform_.scale_.x = 0.2f;
	transform_.scale_.y = 0.2f;
	transform_.scale_.z = 0.2f;

	transform_.position_ = { 0.0f, -3.0f, 0.0f };
	pRChildOden_ = (ChildOden*)Instantiate<ChildOden>(this);
	pLChildOden_ = (ChildOden*)Instantiate<ChildOden>(this);
	pRChildOden_->SetPosition(2.0f, 1.0f, 0.0f);
	pLChildOden_->SetPosition(-2.0f, 1.0f, 0.0f);
	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);

	SphereCollider* col = new SphereCollider(0.5f);
	AddCollider(col);
}

void Player::Update()
{

	static float x = 0.0f;
	float tx = sin(x) * 5.0f;
	x += 0.02f;
	//transform_.position_.x = tx;
	//transform_.rotate_.y += 1.6f;

	if (Input::IsKey(DIK_RIGHT))
	{
		transform_.position_.x += 0.2f;
	}
	if (Input::IsKey(DIK_LEFT))
	{
		transform_.position_.x -= 0.2f;
	}
	if (Input::IsKey(DIK_UP))
	{
		transform_.position_.y += 0.2f;
	}
	if (Input::IsKey(DIK_DOWN))
	{
		transform_.position_.y -= 0.2f;
	}
	

	fireTimer_ -= 1.0f / 60.0f; // 60FPS‘z’è
	if (Input::IsKey(DIK_SPACE) && fireTimer_ <= 0)
	{
		Bullet* b = (Bullet*)Instantiate<Bullet>(GetRootJob());
		b->SetPosition(transform_.position_);
		fireTimer_ = 0.35f; // 0.2•b‚É1”­
	}
	
	/*if (transform_.rotate_.y > 720.0f)
	{
		KillMe();
		return;

	}*/

	
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
	if (pFbx_)
	{
		pFbx_->Release();
		delete pFbx_;
		pFbx_ = nullptr;
	}
}


