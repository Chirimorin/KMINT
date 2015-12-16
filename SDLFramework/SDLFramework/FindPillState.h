#pragma once
#include "BaseState.h"

class FindPillState : public BaseState
{
public:
	FindPillState();
	~FindPillState();

	void Move(Entity* obj, Graph* graph) override;
};

