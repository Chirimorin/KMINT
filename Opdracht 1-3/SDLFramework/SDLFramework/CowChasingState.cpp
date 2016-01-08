#include "CowChasingState.h"
#include "CowSleepingState.h"
#include "Graph.h"
#include "Rabbit.h"
#include <iostream>

CowChasingState::CowChasingState(Cow* cow) : CowState(cow, 255, 0, 0)
{
	isAttacking_ = true;
	std::cout << "Koe: chasing \n";
}

void CowChasingState::Move(Entity* obj, Graph* graph)
{
	if (graph->setShortestPath(obj->getWaypoint(), graph->getRabbit()->getWaypoint())) {
		obj->MoveTo(graph->getFirstWaypointShortestPath());
	}

	if (obj->getWaypoint() == graph->getRabbit()->getWaypoint() && !graph->getRabbit()->getAttacked(graph)) {
		obj->setState(new CowSleepingState(cow_));
	}
}