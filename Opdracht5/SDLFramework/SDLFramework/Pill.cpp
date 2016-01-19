#include "Pill.h"

Pill::Pill() : IGameObject()
{
	mTexture = mApplication->LoadTexture("pill.bmp");

	// TODO: moet size van de texture zijn
	mWidth = 128;
	mHeight = 128;
}

Pill::~Pill()
{
}

void Pill::Update(float deltaTime)
{
}
