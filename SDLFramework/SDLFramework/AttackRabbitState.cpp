#include "AttackRabbitState.h"
#include "WanderingStateCow.h"
#include "Graph.h"
#include "Entity.h"
#include "Pill.h"
#include "Rabbit.h"
#include <iostream>

AttackRabbitState::AttackRabbitState() : BaseState(255, 0, 0)
{
}

AttackRabbitState::~AttackRabbitState()
{
}

void AttackRabbitState::Move(Entity* obj, Graph* graph)
{
	graph->setShortestPath(obj->getWaypoint(), graph->getRabbit()->getWaypoint());
	obj->MoveTo(graph->getFirstWaypointShortestPath());

	if (obj->getWaypoint() == graph->getRabbit()->getWaypoint()) {
		std::cout << "Caught the rabbit!\n";
		obj->setState(new WanderingStateCow());
	}
}