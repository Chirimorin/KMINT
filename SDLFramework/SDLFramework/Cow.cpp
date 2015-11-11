#include "Cow.h"

Cow::Cow(Waypoint* waypoint)
{
	waypoint_ = waypoint;
	mTexture = mApplication->LoadTexture("cow.bmp");

	mX = waypoint_->getPosition().x;
	mY = waypoint_->getPosition().y;
}

Cow::~Cow()
{
}

void Cow::Update(float deltaTime)
{
	
}