#pragma once
#include "BaseState.h"

class CowFindWeaponState : public CowState
{
public:
	CowFindWeaponState();
	~CowFindWeaponState() {}

	void Update(Entity* obj) override;
	Vector2 CalculateForce(Entity* obj) override;
};

