#include "Weapon.h"

Weapon::Weapon() : IGameObject()
{
	mTexture = mApplication->LoadTexture("gun.bmp");
}

Weapon::~Weapon()
{
}

void Weapon::Update(float deltaTime)
{

}
