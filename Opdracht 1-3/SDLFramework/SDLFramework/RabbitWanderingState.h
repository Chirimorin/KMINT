#pragma once
#include "BaseState.h"

class RabbitWanderingState : public RabbitState
{
public:
	RabbitWanderingState(Rabbit* rabbit);
	~RabbitWanderingState() {}

	void Move(Entity* obj, Graph* graph) override;
};

