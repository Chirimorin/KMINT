#include "Weapon.h"
#include <SDL.h>

Weapon::Weapon(Uint8 r, Uint8 g, Uint8 b) : IGameObject()
{
	mTexture = mApplication->LoadTexture("gun.bmp");

	// TODO: moet size van de texture zijn
	mWidth = 48;
	mHeight = 48;

	SDL_SetTextureColorMod(mTexture, r, g, b);

	mX = 350;
	mY = 350;
}

Weapon::~Weapon()
{
}

void Weapon::Update(float deltaTime)
{
}