#include "Entity.h"
#include "Waypoint.h"
#include "BaseState.h"


Entity::Entity()
{
}


Entity::~Entity()
{
	delete state_;
}

void Entity::MoveTo(Waypoint* waypoint)
{
	waypoint_ = waypoint;
	mX = waypoint_->getPosition().x;
	mY = waypoint_->getPosition().y;
}

void Entity::setState(BaseState* state)
{
	delete state_;
	state_ = state;
	state->setColor(mTexture);
}