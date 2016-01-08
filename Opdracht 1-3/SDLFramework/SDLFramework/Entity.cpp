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

void Entity::setState(BaseState* state, Graph* graph)
{
	delete state_;
	state_ = state;
	state->setColor(mTexture);

	if (graph)
		state->Move(this, graph);
}
