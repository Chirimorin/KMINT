#pragma once
#include "BaseState.h"

class RabbitAttackState : public RabbitState
{
public:
	RabbitAttackState(Rabbit* rabbit);
	~RabbitAttackState() {}

	void Move(Entity* obj, Graph* graph) override;
};

