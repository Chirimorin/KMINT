#include "Weapon.h"

Weapon::Weapon() : IGameObject()
{
	mTexture = mApplication->LoadTexture("gun.bmp");

	// TODO: moet size van de texture zijn
	mWidth = 128;
	mHeight = 128;
}

Weapon::~Weapon()
{
}

void Weapon::Update(float deltaTime)
{
}