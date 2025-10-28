#include "Player.h"
#include "Engine/Fbx.h"
#include "ChildOden.h"
#include "Engine/Model.h"


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
	transform_.scale_.x = 0.7f;
	transform_.scale_.y = 0.7f;
	transform_.scale_.z = 0.7f;
	pRChildOden_ = (ChildOden*)Instantiate<ChildOden>(this);
	pLChildOden_ = (ChildOden*)Instantiate<ChildOden>(this);
	pRChildOden_->SetPosition(2.0f, 1.0f, 0.0f);
	pLChildOden_->SetPosition(-2.0f, 1.0f, 0.0f);
	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);
}

void Player::Update()
{

	static float x = 0.0f;
	float tx = sin(x) * 5.0f;
	x += 0.02f;
	transform_.position_.x = tx;
	transform_.rotate_.y += 1.6f;
	if (transform_.rotate_.y > 720.0f)
	{
		KillMe();
		return;

	}

	
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
