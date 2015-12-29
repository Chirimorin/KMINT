#pragma once
#include "BaseState.h"

class RabbitFleeState : public RabbitState
{
public:
	RabbitFleeState();
	~RabbitFleeState() {}

	void Move(Entity* obj) override;
};

