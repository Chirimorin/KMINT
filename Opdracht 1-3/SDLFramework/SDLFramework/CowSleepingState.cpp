#include "CowSleepingState.h"
#include "CowChasingState.h"
#include "Cow.h"
#include "Graph.h"

#include <iostream>

CowSleepingState::CowSleepingState(Cow* cow) : CowState(cow, 0, 255, 0)
{
	isAttacking_ = false;
	std::cout << "Koe: sleeping \n";
}

void CowSleepingState::Move(Entity* obj, Graph* graph)
{
	sleepTimer_++;

	if (sleepTimer_ == 5) {
		sleepTimer_ = 0;
		obj->setState(new CowChasingState(cow_));
	}
}