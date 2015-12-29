#pragma once
#include "BaseState.h"

class RabbitWanderingState : public RabbitState
{
public:
	RabbitWanderingState();
	~RabbitWanderingState() {}

	void Move(Entity* obj, Graph* graph) override;
};

