#include "Rabbit.h"

Rabbit::Rabbit(Waypoint* waypoint)
{
	waypoint_ = waypoint;
	mTexture = mApplication->LoadTexture("rabbit.bmp");

	mX = waypoint_->getPosition().x;
	mY = waypoint_->getPosition().y;
}

Rabbit::~Rabbit()
{
}

void Rabbit::Update(float deltaTime)
{

}