#pragma once
#include "BaseState.h"

class RabbitFleeState : public RabbitState
{
public:
	RabbitFleeState(Rabbit* rabbit);
	~RabbitFleeState() {}

	void Move(Entity* obj, Graph* graph) override;
};

