#pragma once
#include "IGameObject.h"
#include "Entity.h"

class Rabbit : public Entity
{
public:
	Rabbit(Uint8 r, Uint8 g, Uint8 b);
	~Rabbit();
};

