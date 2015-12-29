#include "AttackRabbitState.h"
#include "WanderingStateCow.h"
#include "Graph.h"
#include "Entity.h"
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
	if (graph->setShortestPath(obj->getWaypoint(), graph->getRabbit()->getWaypoint()))
	{
		obj->MoveTo(graph->getFirstWaypointShortestPath());
	}

	if (obj->getWaypoint() == graph->getRabbit()->getWaypoint()) {
		if (graph->getRabbit()->isAttacking())
		{
			std::cout << "Cow: Lost to the rabbit!\n";
		}
		else
		{
			std::cout << "Cow: Caught the rabbit!\n";
		}
		
		//obj->setState(new WanderingStateCow());
		graph->getRabbit()->resetState();
	}
}
