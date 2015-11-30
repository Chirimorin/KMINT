#include "Pill.h"

Pill::Pill(Waypoint* waypoint) : IGameObject()
{
	waypoint_ = waypoint;
	mTexture = mApplication->LoadTexture("pill.bmp");

	// TODO: moet size van de texture zijn
	mWidth = 128;
	mHeight = 128;

	mX = waypoint_->getPosition().x;
	mY = waypoint_->getPosition().y;
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