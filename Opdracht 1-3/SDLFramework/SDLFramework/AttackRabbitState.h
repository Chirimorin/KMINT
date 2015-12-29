#pragma once
#include "BaseState.h"

class AttackRabbitState : public BaseState
{
public:
	AttackRabbitState();
	~AttackRabbitState();

	void Move(Entity* obj, Graph* graph) override;
	bool isAttacking() override { return true; }
};

