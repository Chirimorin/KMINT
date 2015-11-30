#pragma once
#include "State.h"

class WanderingStateCow : public State
{
public:
	WanderingStateCow();
	~WanderingStateCow();

	void Move(IGameObject* obj) override;
};

