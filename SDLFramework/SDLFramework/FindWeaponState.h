#pragma once
#include "State.h"

class FindWeaponState : public State
{
public:
	FindWeaponState();
	~FindWeaponState();

	void Move(IGameObject* obj) override;
};

