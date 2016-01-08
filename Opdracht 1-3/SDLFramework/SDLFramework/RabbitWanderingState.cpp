#include "RabbitWanderingState.h"
#include "RabbitFleeState.h"
#include "RabbitFindPillState.h"
#include "RabbitFindWeaponState.h"
#include "Rabbit.h"
#include "Graph.h"
#include "Cow.h"
#include "Random.h"

#include <algorithm>
#include <iostream>

RabbitWanderingState::RabbitWanderingState(Rabbit* rabbit) : RabbitState(rabbit, 255, 255, 255)
{
	rabbit_->hasPill(false);
	std::cout << "Haas: wander \n";
}

void RabbitWanderingState::Move(Entity* obj, Graph* graph)
{
	timer_ = 0;
	Waypoint* waypoint = obj->getWaypoint();
	std::vector<Edge*> edges = waypoint->getEdges();
	
	bool seesCow = false;

	std::for_each(edges.begin(), edges.end(), [&seesCow, waypoint, graph](Edge* e) {
		Waypoint* currentWaypoint = e->getWaypoint1();
		if (currentWaypoint == waypoint) {
			currentWaypoint = e->getWaypoint2();
		}

		if (graph->getCow()->getWaypoint() == currentWaypoint) {
			seesCow = true;
			std::cout << "Haas: ziet koe \n";
		}
	});

	// TODO: kans op bepaalde keuze aanpassen afhankelijk van succes
	if (seesCow) {
		switch (Random::getRandomNumber(0, 2)) {
			case 0:
				obj->setState(new RabbitFleeState(rabbit_), graph);
				break;
			case 1:
				obj->setState(new RabbitFindPillState(rabbit_), graph); // TODO: als pil in de buurt is en koe daar niet is
				break;
			case 2:
				obj->setState(new RabbitFindWeaponState(rabbit_), graph); // TODO: als wapen in de buurt is en koe daar niet is
				break;
		}

		return;
	}

	Edge* edge = edges.at(Random::getRandomNumber(0, edges.size() - 1));

	if (Random::getRandomNumber(0, 1)) {
		obj->MoveTo(edge->getWaypoint1());
	}
	else {
		obj->MoveTo(edge->getWaypoint2());
	}
}