#pragma once
#include "State.h"

class AttackRabbitState : public State
{
public:
	AttackRabbitState();
	~AttackRabbitState();

	void Move(IGameObject* obj) override;
};

