#pragma once
#include "BaseState.h"

class RabbitWanderingState : public RabbitState
{
public:
	RabbitWanderingState();
	~RabbitWanderingState() {}

	void Move(Entity* obj) override;
};

