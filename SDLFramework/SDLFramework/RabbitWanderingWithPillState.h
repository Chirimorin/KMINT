#pragma once
#include "BaseState.h"

class RabbitWanderingWithPillState : public RabbitState
{
public:
	RabbitWanderingWithPillState();
	~RabbitWanderingWithPillState() {}

	void Move(Entity* obj, Graph* graph) override;
};

