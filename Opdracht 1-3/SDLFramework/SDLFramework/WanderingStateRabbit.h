#pragma once
#include "BaseState.h"

class WanderingStateRabbit : public BaseState
{
public:
	WanderingStateRabbit();
	~WanderingStateRabbit();

	void Move(Entity* obj, Graph* graph) override;
};

