#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include <cassert>

Bullet::Bullet(GameObject* parent)
    : GameObject(parent, "Bullet"), pFbx(nullptr), speed_(1.0f)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
    pFbx = new Fbx;
    pFbx->Load("Oden.fbx");   // おでんモデル
    transform_.scale_ = { 0.2f, 0.2f, 0.2f };
    SphereCollider* col = new SphereCollider(2.0f);
    AddCollider(col);
}

void Bullet::Update()
{
    // 前方に進む
    transform_.position_.z += speed_;

    // 画面外に行ったら消す
    if (transform_.position_.z > 100.0f)
    {
        KillMe();
    }
}

void Bullet::Draw()
{
    pFbx->Draw(transform_);
}

void Bullet::Release()
{
    if (pFbx)
    {
        pFbx->Release();
        delete pFbx;
        pFbx = nullptr;
    }
}
