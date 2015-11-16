#include "Rabbit.h"

#include <iostream>

Rabbit::Rabbit(Waypoint* waypoint) : IGameObject()
{
	waypoint_ = waypoint;
	mTexture = mApplication->LoadTexture("rabbit.bmp");

	// TODO: moet size van de texture zijn
	mWidth = 48;
	mHeight = 48;

	mX = waypoint_->getPosition().x;
	mY = waypoint_->getPosition().y;
	std::cout << "Positie haas x: " << mX << " y: " << mY << "\n";
}

Rabbit::~Rabbit()
{
}

void Rabbit::Update(float deltaTime)
{

}

void Rabbit::Move(Waypoint* waypoint)
{
	waypoint_ = waypoint;
	mX = waypoint_->getPosition().x;
	mY = waypoint_->getPosition().y;

	std::cout << "Move haas x: " << mX << " y: " << mY << "\n";
}

Waypoint* Rabbit::getWaypoint()
{
	return waypoint_;
}