#include "CowChasingState.h"
#include "CowSleepingState.h"
#include "Graph.h"
#include "Rabbit.h"
#include <iostream>

CowChasingState::CowChasingState(Cow* cow) : CowState(cow, 255, 0, 0)
{
	isAttacking_ = true;
}

void CowChasingState::Move(Entity* obj, Graph* graph)
{
	if (graph->setShortestPath(obj->getWaypoint(), graph->getRabbit()->getWaypoint())) {
		obj->MoveTo(graph->getFirstWaypointShortestPath());
	}

	if (obj->getWaypoint() == graph->getRabbit()->getWaypoint()) {
		if (!graph->getRabbit()->getAttacked()) {
			obj->setState(new CowSleepingState(cow_));
		}
		else {
			// TODO: reset state haas
		}
	}
}