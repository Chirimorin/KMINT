#include "Cow.h"

#include <iostream>
#include <SDL.h>
#include "CowChasingState.h"

Cow::Cow(Waypoint* waypoint) : Entity()
{
	mTexture = mApplication->LoadTexture("cow.bmp");

	// TODO: moet size van de texture zijn
	mWidth = 48;
	mHeight = 48;

	MoveTo(waypoint);
	
	resetState();
}

Cow::~Cow()
{
}

void Cow::Update(float deltaTime)
{

}

void Cow::Move(Graph* graph)
{
	state_->Move(this, graph);
}

void Cow::MoveTo(Waypoint* waypoint)
{
	Entity::MoveTo(waypoint);
	mX -= mWidth/2;
}

void Cow::resetState()
{
	setState(new CowChasingState(this));
}