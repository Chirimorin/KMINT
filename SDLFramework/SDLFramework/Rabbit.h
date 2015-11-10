#pragma once
#include "IGameObject.h"

class Rabbit : public IGameObject
{
public:
	Rabbit();
	~Rabbit();

	void Update(float deltaTime);
};

