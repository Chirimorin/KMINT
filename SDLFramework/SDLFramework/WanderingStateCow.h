#pragma once
#include "BaseState.h"

class WanderingStateCow : public BaseState
{
public:
	WanderingStateCow();
	~WanderingStateCow();

	void Move(Entity* obj, Graph* graph) override;
};

