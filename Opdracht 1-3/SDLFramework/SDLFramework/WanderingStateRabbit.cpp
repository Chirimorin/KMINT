#include "WanderingStateRabbit.h"
#include "FindWeaponState.h"
#include "Entity.h"
#include "Graph.h"
#include "Waypoint.h"
#include "Cow.h"
#include "Random.h"
#include <iostream>

WanderingStateRabbit::WanderingStateRabbit() : BaseState(255, 255, 255)
{
}
WanderingStateRabbit::~WanderingStateRabbit()
{
}

void WanderingStateRabbit::Move(Entity* obj, Graph* graph)
{
	Waypoint* waypoint = obj->getWaypoint();
	std::vector<Edge*> edges = waypoint->getEdges();
	Edge* edge = edges.at(Random::getRandomNumber(0, edges.size() - 1));

	if (Random::getRandomNumber(0, 1)) {
		obj->MoveTo(edge->getWaypoint1());
	}
	else {
		obj->MoveTo(edge->getWaypoint2());
	}

	if (graph->getCow()->isAttacking()) {
		std::cout << "Rabbit: Looking for weapon!\n";
		//obj->setState(new FindWeaponState());
	}
}

