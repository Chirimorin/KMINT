#include "FindPillState.h"
#include "AttackRabbitState.h"
#include "Graph.h"
#include "Entity.h"
#include "Pill.h"
#include <iostream>

FindPillState::FindPillState() : BaseState(0, 255, 0)
{
}

FindPillState::~FindPillState()
{
}

void FindPillState::Move(Entity* obj, Graph* graph)
{
	if (graph->setShortestPath(obj->getWaypoint(), graph->getPill()->getWaypoint()))
	{
		obj->MoveTo(graph->getFirstWaypointShortestPath());
	}

	if (obj->getWaypoint() == graph->getPill()->getWaypoint()) {
		graph->movePill();
		std::cout << "Cow: Found pill!\n";
		obj->setState(new AttackRabbitState());
	}
}
