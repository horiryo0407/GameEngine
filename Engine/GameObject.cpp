#include "GameObject.h"

GameObject::GameObject()
	:pParent_(nullptr)
{
}

GameObject::GameObject(GameObject* parent, const std::string& name)
	: pParent_(parent), objectName_(name),isDead_(false)
{
	if (pParent_ != nullptr)
	{
		transform_.pParent_ = &(pParent_->transform_);
	}
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
	for (auto it = childList_.begin(); it != childList_.end(); )
	{
		if ((*it)->isDead_)
		{
			(*it)->ReleaseSub();
			delete (*it);
			it = childList_.erase(it); // © erase‚Ì–ß‚è’l‚ð•K‚¸Žg‚¤
		}
		else
		{
			++it;
		}
	}
}

void GameObject::ReleaseSub()
{
	this->Release();
	for (auto child : childList_)
	{
		child->ReleaseSub();
		delete child;
	}
	
	
}

void GameObject::SetPosition(XMFLOAT3 position)
{
	transform_.position_ = position;

}

void GameObject::SetPosition(float x, float y, float z)
{
	transform_.position_ = { x,y,z };

}

void GameObject::KillMe()
{
	isDead_ = true;
}


