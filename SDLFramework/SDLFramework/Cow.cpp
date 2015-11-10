#include "Cow.h"

Cow::Cow()
{
	mTexture = mApplication->LoadTexture("cow.bmp");
	mX = 30;
	mY = 10;
}

Cow::~Cow()
{
}

void Cow::Update(float deltaTime)
{
	
}