#include "Rabbit.h"
#include "WanderingStateRabbit.h"

#include <iostream>

Rabbit::Rabbit(Waypoint* waypoint) : Entity()
{
	waypoint_ = waypoint;
	mTexture = mApplication->LoadTexture("rabbit.bmp");

	// TODO: moet size van de texture zijn
	mWidth = 48;
	mHeight = 48;

	mX = waypoint_->getPosition().x;
	mY = waypoint_->getPosition().y;

	state_ = new WanderingStateRabbit();

	std::cout << "Positie haas x: " << mX << " y: " << mY << "\n";
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
