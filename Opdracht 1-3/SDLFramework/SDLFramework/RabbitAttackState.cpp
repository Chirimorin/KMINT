#include "RabbitAttackState.h"
#include "RabbitWanderingState.h"
#include "Graph.h"
#include "Cow.h"

#include <algorithm>
#include <iostream>

RabbitAttackState::RabbitAttackState(Rabbit* rabbit) : RabbitState(rabbit, 255, 0, 0)
{
	std::cout << "Haas: attack \n";
}

void RabbitAttackState::Move(Entity* obj, Graph* graph)
{
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
		}
	});

	if (seesCow && graph->getCow()->getAttacked(graph)) {
		obj->setState(new RabbitWanderingState(rabbit_));
		return;
	}

	if (graph->setShortestPath(waypoint, graph->getCow()->getWaypoint()))
	{
		obj->MoveTo(graph->getFirstWaypointShortestPath());
	}

	std::for_each(edges.begin(), edges.end(), [&seesCow, waypoint, graph](Edge* e) {
		Waypoint* currentWaypoint = e->getWaypoint1();
		if (currentWaypoint == waypoint) {
			currentWaypoint = e->getWaypoint2();
		}

		if (graph->getCow()->getWaypoint() == currentWaypoint) {
			seesCow = true;
		}
	});

	if (seesCow && graph->getCow()->getAttacked(graph)) {
		obj->setState(new RabbitWanderingState(rabbit_));
	}
}