#pragma once
#include "BaseState.h"

class RabbitFindPillState : public RabbitState
{
public:
	RabbitFindPillState(Rabbit* rabbit);
	~RabbitFindPillState() {}

	void Move(Entity* obj, Graph* graph) override;
};

