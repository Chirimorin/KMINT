#include "Cow.h"

#include <iostream>

Cow::Cow(Waypoint* waypoint) : IGameObject()
{
	waypoint_ = waypoint;
	mTexture = mApplication->LoadTexture("cow.bmp");

	// TODO: moet size van de texture zijn
	mWidth = 48;
	mHeight = 48;

	mX = waypoint_->getPosition().x;
	mY = waypoint_->getPosition().y;
	

	std::cout << "Positie koe x: " << mX << " y: " << mY << "\n";
}

Cow::~Cow()
{
}

void Cow::Update(float deltaTime)
{
	
}

void Cow::Move(Waypoint* waypoint)
{
	waypoint_ = waypoint;
	mX = waypoint_->getPosition().x;
	mY = waypoint_->getPosition().y;
	std::cout << "x: " << mX << " y: " << mY << "\n";
}

Waypoint* Cow::getWaypoint()
{
	return waypoint_;
}