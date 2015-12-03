#pragma once
#include "BaseState.h"

class AttackRabbitState : public BaseState
{
public:
	AttackRabbitState();
	~AttackRabbitState();

	void Move(IGameObject* obj) override;
};

