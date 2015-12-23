#include "CowSleepingState.h"
#include "CowChasingState.h"
#include "Graph.h"

CowSleepingState::CowSleepingState() : CowState(0, 255, 0)
{
}

void CowSleepingState::Move(Entity* obj, Graph* graph)
{
	//TODO: als de koe 5 beurten heeft geslapen, dan wisselen naar chasing state

	/*if ()
	{
		obj->setState(new CowChasingState());
	}*/
}