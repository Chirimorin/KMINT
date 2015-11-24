#pragma once
#include "IGameObject.h"

class Weapon : public IGameObject
{
public:
	Weapon();
	~Weapon();

	void Update(float deltaTime);
};

