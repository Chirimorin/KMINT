#include "Pill.h"
#include <SDL.h>

Pill::Pill(Uint8 r, Uint8 g, Uint8 b) : IGameObject()
{
	mTexture = mApplication->LoadTexture("pill.bmp");

	// TODO: moet size van de texture zijn
	mWidth = 48;
	mHeight = 48;

	SDL_SetTextureColorMod(mTexture, r, g, b);

	mX = 250;
	mY = 350;
}

Pill::~Pill()
{
}

void Pill::Update(float deltaTime)
{
}
