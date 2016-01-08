#pragma once
#include "BaseState.h"

class RabbitFleeState : public RabbitState
{
public:
	RabbitFleeState();
	~RabbitFleeState() {}

	void Update(Entity* obj) override;
	Vector2 CalculateForce(Entity* obj) override;
};

