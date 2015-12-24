#include "CowChasingState.h"
#include "CowSleepingState.h"
#include "Graph.h"
#include "Rabbit.h"
#include <iostream>

CowChasingState::CowChasingState() : CowState(255, 0, 0)
{
}

void CowChasingState::Move(Entity* obj, Graph* graph)
{
	if (graph->setShortestPath(obj->getWaypoint(), graph->getRabbit()->getWaypoint())) {
		obj->MoveTo(graph->getFirstWaypointShortestPath());
	}

	if (obj->getWaypoint() == graph->getRabbit()->getWaypoint() && 
		!graph->getRabbit()->getAttacked()) {
			obj->setState(new CowSleepingState());
			// TODO: haas heeft geen slaap pil meer, want die is gebruikt (pil ergens anders plaatsen)
	}
}