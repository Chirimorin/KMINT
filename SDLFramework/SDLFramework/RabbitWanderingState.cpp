#include "RabbitWanderingState.h"
#include "RabbitFleeState.h"
#include "RabbitFindPillState.h"
#include "RabbitFindWeaponState.h"
#include "Rabbit.h"
#include "Graph.h"
#include "Cow.h"
#include "Random.h"

#include <algorithm>

RabbitWanderingState::RabbitWanderingState() : RabbitState(255, 255, 255)
{
	isAttacking_ = false;
	getAttacked_ = true;
}

void RabbitWanderingState::Move(Entity* obj, Graph* graph)
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
	
	bool seesCow = false;

	std::for_each(edges.begin(), edges.end(), [&seesCow, waypoint, graph](Edge* e) {
		Waypoint* currentWaypoint = e->getWaypoint1();
		if (currentWaypoint == waypoint) {
			currentWaypoint = e->getWaypoint2();
		}

		if (graph->getCow()->getWaypoint() == currentWaypoint) {
			seesCow = true;
		}
	});

	// TODO: kans op bepaalde keuze aanpassen afhankelijk van succes
	if (seesCow) {
		switch (Random::getRandomNumber(0, 2)) {
			case 0:
				obj->setState(new RabbitFleeState());
				break;
			case 1:
				obj->setState(new RabbitFindPillState());
				break;
			case 2:
				obj->setState(new RabbitFindWeaponState());
				break;
		}
	}
}