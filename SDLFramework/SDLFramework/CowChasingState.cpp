#include "CowChasingState.h"
#include <iostream>
#include "Graph.h"
#include "Rabbit.h"


CowChasingState::CowChasingState() : BaseState(255, 0, 0)
{
}


CowChasingState::~CowChasingState()
{
}

void CowChasingState::Move(Entity* obj, Graph* graph)
{
	if (graph->setShortestPath(obj->getWaypoint(), graph->getRabbit()->getWaypoint()))
	{
		obj->MoveTo(graph->getFirstWaypointShortestPath());
	}

	if (obj->getWaypoint() == graph->getRabbit()->getWaypoint()) {
		if (!graph->getRabbit()->getAttacked())
		{
			// TODO: sleepstate maken
			//obj->setState();
		}
	}
}