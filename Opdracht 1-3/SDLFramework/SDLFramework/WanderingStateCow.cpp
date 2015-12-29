#include "WanderingStateCow.h"
#include "FindPillState.h"
#include "Entity.h"
#include "Graph.h"
#include "Waypoint.h"
#include "Random.h"
#include <iostream>

WanderingStateCow::WanderingStateCow() : BaseState(255,255,255)
{
}

WanderingStateCow::~WanderingStateCow()
{
}

void WanderingStateCow::Move(Entity* obj, Graph* graph)
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

	if (Random::getRandomNumber(0,4) == 4) {
		std::cout << "Cow: Looking for pill!\n";
		//obj->setState(new FindPillState());
	}
}

