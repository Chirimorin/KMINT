#pragma once
#include "BaseState.h"
#include "Vector2.h"

class RabbitWanderingState : public RabbitState
{
public:
	RabbitWanderingState();
	~RabbitWanderingState() {}

	void Update(Entity* obj) override;
	Vector2 CalculateForce(Entity* obj) override;
private:
	Vector2 destination_;

	void SetRandomDestination();
};

