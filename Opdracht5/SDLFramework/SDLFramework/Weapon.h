#pragma once
#include "IGameObject.h"

class Weapon : public IGameObject
{
public:
	Weapon(Uint8 r, Uint8 g, Uint8 b);
	~Weapon();

	void Update(float deltaTime);
};

