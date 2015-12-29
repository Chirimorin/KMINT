#include "Rabbit.h"
#include "RabbitWanderingState.h"

#include <iostream>

Rabbit::Rabbit(Waypoint* waypoint) : Entity()
{
	mTexture = mApplication->LoadTexture("rabbit.bmp");

	// TODO: moet size van de texture zijn
	mWidth = 48;
	mHeight = 48;

	MoveTo(waypoint);

	resetState();
}

Rabbit::~Rabbit()
{
}

void Rabbit::Update(float deltaTime)
{

}

void Rabbit::Move(Graph* graph)
{
	state_->Move(this, graph);
}

void Rabbit::MoveTo(Waypoint* waypoint)
{
	Entity::MoveTo(waypoint);
	mX += mWidth/2;
}

void Rabbit::resetState()
{
	setState(new RabbitWanderingState());
}