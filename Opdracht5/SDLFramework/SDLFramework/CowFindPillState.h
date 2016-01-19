#pragma once
#include "BaseState.h"

class CowFindPillState : public CowState
{
public:
	CowFindPillState();
	~CowFindPillState() {}

	void Update(Entity* obj) override;
	Vector2 CalculateForce(Entity* obj) override;
};

