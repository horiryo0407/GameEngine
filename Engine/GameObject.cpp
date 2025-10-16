#include "GameObject.h"

GameObject::GameObject()
	:pParent_(nullptr)
{
}

GameObject::GameObject(GameObject* parent, const std::string& name)
	: pParent_(parent), objectName_(name)
{
}

GameObject::~GameObject()
{
}

void GameObject::DrawSub()
{
	Draw();

	for (auto child : childList_)
	{
		child->DrawSub();
	}
}

void GameObject::UpdateSub()
{
	this->Update();

	for (auto child : childList_)
	{
		child->UpdateSub();
	}
}

void GameObject::ReleaseSub()
{
	for (auto child : childList_)
	{
		child->ReleaseSub();
		delete child;
	}
	childList_.clear();
	this->Release();
}


