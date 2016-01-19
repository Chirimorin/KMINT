#pragma once
#pragma once
#include "BaseState.h"

class CowHideState : public CowState
{
public:
	CowHideState();
	~CowHideState() {}

	void Update(Entity* obj) override;
	Vector2 CalculateForce(Entity* obj) override;
};

