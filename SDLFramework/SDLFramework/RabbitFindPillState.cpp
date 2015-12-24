#include "RabbitFindPillState.h"
#include "RabbitWanderingWithPillState.h"
#include "Rabbit.h"
#include "Graph.h"
#include "Pill.h"

RabbitFindPillState::RabbitFindPillState() : RabbitState(225, 255, 0) // TODO: misschien kleur aanpassen in verband met veel states
{
}

void RabbitFindPillState::Move(Entity* obj, Graph* graph)
{
	if (graph->setShortestPath(obj->getWaypoint(), graph->getPill()->getWaypoint())) {
		obj->MoveTo(graph->getFirstWaypointShortestPath());
	}

	if (obj->getWaypoint() == graph->getPill()->getWaypoint()) {
		
		// TODO: haas kan niet meer worden aangevallen zo lang hij de slaap pil heeft
		
		obj->setState(new RabbitWanderingWithPillState());
	}
}
