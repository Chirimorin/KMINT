#pragma once
#include "BaseState.h"

class AttackCowState : public BaseState
{
public:
	AttackCowState();
	~AttackCowState();

	void Move(Entity* obj, Graph* graph) override;
	bool isAttacking() override { return true; }
};

