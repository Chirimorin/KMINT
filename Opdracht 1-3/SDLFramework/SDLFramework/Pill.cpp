#include "Pill.h"

Pill::Pill(Waypoint* waypoint) : IGameObject()
{
	mTexture = mApplication->LoadTexture("pill.bmp");

	// TODO: moet size van de texture zijn
	mWidth = 128;
	mHeight = 128;

	setWaypoint(waypoint);
}

Pill::~Pill()
{
}

void Pill::Update(float deltaTime)
{

}

Waypoint* Pill::getWaypoint()
{
	return waypoint_;
}

void Pill::setWaypoint(Waypoint* waypoint)
{
	waypoint_ = waypoint;

	mX = waypoint_->getPosition().x;
	mY = waypoint_->getPosition().y;
}