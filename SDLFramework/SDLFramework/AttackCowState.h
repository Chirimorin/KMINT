#pragma once
#include "State.h"

class AttackCowState : public State
{
public:
	AttackCowState();
	~AttackCowState();

	void Move(IGameObject* obj) override;
};

