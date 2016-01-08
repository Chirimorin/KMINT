#pragma once
#include "BaseState.h"

struct Vector2;

class CowChasingState : public CowState
{
public:
	CowChasingState();
	~CowChasingState() {}

	void Update(Entity* obj) override {};
	Vector2 CalculateForce(Entity* obj) override;
};

