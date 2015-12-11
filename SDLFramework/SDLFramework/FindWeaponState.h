#pragma once
#include "BaseState.h"

class FindWeaponState : public BaseState
{
public:
	FindWeaponState();
	~FindWeaponState();

	void Move(Entity* obj, Graph* graph) override;
};

