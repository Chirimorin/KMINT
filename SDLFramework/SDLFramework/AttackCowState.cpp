#include "AttackCowState.h"
#include "WanderingStateRabbit.h"
#include "Graph.h"
#include "Entity.h"
#include "Cow.h"
#include <iostream>

AttackCowState::AttackCowState() : BaseState(255, 0, 0)
{
}

AttackCowState::~AttackCowState()
{
}

void AttackCowState::Move(Entity* obj, Graph* graph)
{
	if (graph->setShortestPath(obj->getWaypoint(), graph->getCow()->getWaypoint()))
	{
		obj->MoveTo(graph->getFirstWaypointShortestPath());
	}

	if (obj->getWaypoint() == graph->getCow()->getWaypoint()) {
		std::cout << "Rabbit: Attacked the cow!\n";
		obj->setState(new WanderingStateRabbit());
		graph->getCow()->resetState();
	}
}

