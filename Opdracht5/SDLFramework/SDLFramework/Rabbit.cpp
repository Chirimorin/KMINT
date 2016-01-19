#include "Rabbit.h"
//#include "RabbitWanderingState.h"
//#include "RabbitFleeState.h"

Rabbit::Rabbit() : Entity()
{
	mTexture = mApplication->LoadTexture("rabbit.png");

	mWidth = 48;
	mHeight = 39;

	mX = 250;
	mY = 250;

	//state_ = new RabbitWanderingState();

	// TODO: goede waardes 
	position_ = { 250.f,250.f };
	velocity_ = Vector2(1, 1);
	heading_ = Vector2(1, 1);
	side_ = Vector2(1, 1);

	mass_ = 0.25;
	maxSpeed_ = 200;
	maxForce_ = 100;
	maxTurnRate_ = 1;
}

Rabbit::~Rabbit()
{
}
