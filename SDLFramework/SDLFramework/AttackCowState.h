#pragma once
#include "BaseState.h"

class AttackCowState : public BaseState
{
public:
	AttackCowState();
	~AttackCowState();

	void Move(IGameObject* obj) override;
};

