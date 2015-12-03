#pragma once
#include "BaseState.h"

class WanderingStateCow : public BaseState
{
public:
	WanderingStateCow();
	~WanderingStateCow();

	void Move(IGameObject* obj) override;
};

