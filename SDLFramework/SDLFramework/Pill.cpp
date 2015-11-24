#include "Pill.h"

Pill::Pill() : IGameObject()
{
	mTexture = mApplication->LoadTexture("pill.bmp");
}

Pill::~Pill()
{
}

void Pill::Update(float deltaTime)
{

}