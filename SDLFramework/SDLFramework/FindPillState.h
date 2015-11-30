#pragma once
#include "State.h"

class FindPillState : public State
{
public:
	FindPillState();
	~FindPillState();

	void Move(IGameObject* obj) override;
};

