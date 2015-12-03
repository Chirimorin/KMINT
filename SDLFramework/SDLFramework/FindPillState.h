#pragma once
#include "BaseState.h"

class FindPillState : public BaseState
{
public:
	FindPillState();
	~FindPillState();

	void Move(IGameObject* obj) override;
};

