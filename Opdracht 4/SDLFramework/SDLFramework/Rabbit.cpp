#include "Rabbit.h"
#include "RabbitWanderingState.h"

Rabbit::Rabbit() : Entity()
{
	mTexture = mApplication->LoadTexture("rabbit.bmp");

	mWidth = 48;
	mHeight = 48;

	mX = 100;
	mY = 100;

	state_ = new RabbitWanderingState();
}

Rabbit::~Rabbit()
{
}

void Rabbit::Update(float deltaTime)
{
	state_->Move(this);
	// Vector2 stForce = steering_.Calculate();
	// Calc new position, Check p 90.
}