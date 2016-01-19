#pragma once
#include "BaseState.h"

class CowFleeState : public CowState
{
public:
	CowFleeState();
	~CowFleeState() {}

	void Update(Entity* obj) override;
	Vector2 CalculateForce(Entity* obj) override;
};

