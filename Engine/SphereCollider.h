#pragma once

class SphereCollider
{
public:
	SphereCollider(float radius);
	float GetRadius()  { return radius_; }
	void setRadius(float r) { radius_ = r; }

private:
	float radius_;
};
