#pragma once
#include "BaseState.h"

struct Vector2;

class RabbitChasingState : public RabbitState
{
public:
	RabbitChasingState();
	~RabbitChasingState() {}

	void Update(Entity* obj) override {};
	Vector2 CalculateForce(Entity* obj) override;
};

