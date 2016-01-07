#pragma once
#include "BaseState.h"

class RabbitFindWeaponState : public RabbitState
{
public:
	RabbitFindWeaponState(Rabbit* rabbit);
	~RabbitFindWeaponState() {}

	void Move(Entity* obj, Graph* graph) override;
};

