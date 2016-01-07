#include "Entity.h"
#include "Waypoint.h"

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
	mX = static_cast<uint32_t>(waypoint_->getPosition().x);
	mY = static_cast<uint32_t>(waypoint_->getPosition().y);
}

void Entity::setState(BaseState* state)
{
	delete state_;
	state_ = state;
	state->setColor(mTexture);
}
