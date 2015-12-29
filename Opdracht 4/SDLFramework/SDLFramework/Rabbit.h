#pragma once
#include "IGameObject.h"
#include "Entity.h"

class Rabbit : public Entity
{
public:
	Rabbit();
	~Rabbit();

	void Update(float deltaTime) override;
};

