#include "Cow.h"

#include <iostream>
#include <SDL.h>
#include "WanderingStateCow.h"

Cow::Cow(Waypoint* waypoint) : Entity()
{
	waypoint_ = waypoint;
	mTexture = mApplication->LoadTexture("cow.bmp");

	// TODO: moet size van de texture zijn
	mWidth = 48;
	mHeight = 48;

	mX = waypoint_->getPosition().x;
	mY = waypoint_->getPosition().y;
	
	state_ = new WanderingStateCow();
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
