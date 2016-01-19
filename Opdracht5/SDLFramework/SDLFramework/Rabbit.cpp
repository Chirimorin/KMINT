#include "Rabbit.h"
#include "RabbitChasingState.h"
#include <SDL.h>

//#include "RabbitWanderingState.h"
//#include "RabbitFleeState.h"

Rabbit::Rabbit(Uint8 r, Uint8 g, Uint8 b) : Entity()
{
	mTexture = mApplication->LoadTexture("rabbit.bmp");

	mWidth = 48;
	mHeight = 48;
	 
	SDL_SetTextureColorMod(mTexture, r, g, b);

	//mX = 250;
	//mY = 250;

	state_ = new RabbitChasingState();

	// TODO: goede waardes 
	position_ = { 250.f, 250.f };
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

