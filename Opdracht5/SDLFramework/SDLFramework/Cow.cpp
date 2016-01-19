#include "Cow.h"
#include "CowWanderingState.h"
#include <SDL.h>

//#include "CowChasingState.h"

Cow::Cow(Uint8 r, Uint8 g, Uint8 b) : Entity()
{
	mTexture = mApplication->LoadTexture("cow.bmp");

	mWidth = 48;
	mHeight = 48;

	SDL_SetTextureColorMod(mTexture, r, g, b);

	mX = 350;
	mY = 250;

	state_ = new CowWanderingState();

	// TODO: goede waardes 
	position_ = { 50.f, 50.f };
	velocity_ = Vector2(75, 5);
	heading_ = Vector2(0, 0);
	side_ = Vector2(0, 0);

	mass_ = 1;
	maxSpeed_ = 150;
	maxForce_ = 100;
	maxTurnRate_ = 1000;
}

Cow::~Cow()
{
}

/*void Cow::Draw()
{
	Entity::Draw();

	// DEBUG: teken een lijn naar target
	Vector2 goal = target_->GetPosition() - position_;
	goal += target_->GetHeading() * Magnitude(goal) / 5;

	Vector2 direction = WrappedDistance(goal);
	Vector2 endPos = position_ + direction;
	mApplication->SetColor({ 255,0,0,255 });
	for (int w = -800; w <= 800; w += 800)
		for (int h = -600; h <= 600; h += 600)
			mApplication->DrawLine(position_.x + w, position_.y + h, endPos.x + w, endPos.y + h);
	mApplication->SetColor({ 255,255,255,255 });
}*/

// ----------------------------------------------------
// HOOFDSTUK 3
// https://unisalesianogames.files.wordpress.com/2011/08/programming-game-ai-by-example-mat-buckland2.pdf
// ----------------------------------------------------

