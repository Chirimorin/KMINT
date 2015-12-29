#pragma once
#include "BaseState.h"

class RabbitFindWeaponState : public RabbitState
{
public:
	RabbitFindWeaponState();
	~RabbitFindWeaponState() {}

	void Move(Entity* obj, Graph* graph) override;
};

