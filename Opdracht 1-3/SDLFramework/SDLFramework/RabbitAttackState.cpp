#include "RabbitAttackState.h"
#include "RabbitWanderingState.h"
#include "Graph.h"
#include "Cow.h"

#include <algorithm>
#include <iostream>

RabbitAttackState::RabbitAttackState(Rabbit* rabbit) : RabbitState(rabbit, 255, 0, 0)
{
	isAttacking_ = true;
	std::cout << "Haas: attack \n";
}

void RabbitAttackState::Move(Entity* obj, Graph* graph)
{
	Waypoint* waypoint = obj->getWaypoint();
	std::vector<Edge*> edges = waypoint->getEdges();

	if (graph->setShortestPath(waypoint, graph->getCow()->getWaypoint()))
	{
		obj->MoveTo(graph->getFirstWaypointShortestPath());
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

	if (seesCow && graph->getCow()->getAttacked(graph)) {
		// TODO: koe aanvallen als deze in een bepaalde range is
		
		
		// TODO: als de haas de koe heeft aangevallen, dan state aanpassen
		//if () {
			obj->setState(new RabbitWanderingState(rabbit_));
			// TODO: koe opnieuw ergens plaatsen (ver weg van haas)
			// TODO: haas heeft geen wapen meer
			// TODO: reset state koe
		//}
	}

}