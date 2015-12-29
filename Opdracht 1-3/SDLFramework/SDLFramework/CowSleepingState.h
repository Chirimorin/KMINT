#pragma once
#include "BaseState.h"

class CowSleepingState : public CowState
{
public:
	CowSleepingState();
	~CowSleepingState() {}

	void Move(Entity* obj, Graph* graph) override;
private:
	int sleepTimer_ = 0;
};

