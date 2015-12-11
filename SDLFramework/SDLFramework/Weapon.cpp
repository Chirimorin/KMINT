#include "Weapon.h"

Weapon::Weapon(Waypoint* waypoint) : IGameObject()
{
	waypoint_ = waypoint;
	mTexture = mApplication->LoadTexture("gun.bmp");

	// TODO: moet size van de texture zijn
	mWidth = 128;
	mHeight = 128;

	mX = waypoint_->getPosition().x;
	mY = waypoint_->getPosition().y;
}

Weapon::~Weapon()
{
}

void Weapon::Update(float deltaTime)
{

}

Waypoint* Weapon::getWaypoint()
{
	return waypoint_;
}

void Weapon::setWaypoint(Waypoint* waypoint)
{
	waypoint_ = waypoint;

	mX = waypoint_->getPosition().x;
	mY = waypoint_->getPosition().y;
}